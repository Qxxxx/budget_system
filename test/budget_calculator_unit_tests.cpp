#include "budget_calculator/budget_calculator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace date;
using namespace testing;

class StubBudgetRepo : public BudgetRepo {
public:
    MOCK_METHOD(Budgets &, FindAll, ());
};

class BudgetCalculatorFixture : public Test {
protected:
    void SetQueryStartEndDate(const year_month_day &start_date_input, const year_month_day &end_date_input) {
        start_date = start_date_input;
        end_date = end_date_input;
    }

    void ReturnFindAll(Budgets &budgets_input) {
        ON_CALL(stub_budget_repo, FindAll()).WillByDefault(ReturnRef(budgets_input));
    }

    StubBudgetRepo stub_budget_repo;
    year_month_day start_date;
    year_month_day end_date;

};

TEST_F(BudgetCalculatorFixture, QueryBudget) {
    SetQueryStartEndDate(2019_y / 5 / 6, 2019_y / 5 / 20);
    Budgets budgets_input{{2019_y / 5, 31},
                          {2019_y / 6, 30}};
    ReturnFindAll(budgets_input);
    BudgetCalculator budget_calculator{stub_budget_repo};

    EXPECT_EQ(budget_calculator.QueryBudget(start_date, end_date), 15);
}


TEST_F(BudgetCalculatorFixture, NoBudget) {
    SetQueryStartEndDate(2019_y / 5 / 6, 2019_y / 5 / 20);
    Budgets budgets_input{};
    ReturnFindAll(budgets_input);
    BudgetCalculator budget_calculator{stub_budget_repo};

    EXPECT_EQ(budget_calculator.QueryBudget(start_date, end_date), 0);
}