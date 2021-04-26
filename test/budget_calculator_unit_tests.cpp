#include "budget_calculator/budget_calculator.h"
#include <gtest/gtest.h>

class FakeBudgetRepo : public BudgetRepo
{
public:
    FakeBudgetRepo()
    {
        const date::year_month may{date::year{2019}, date::month{5}};
        const date::year_month jun{date::year{2019}, date::month{6}};
        budgets.push_back({may, 31});
        budgets.push_back({jun, 30});
    }
};

TEST(BudgetCalculator, QueryBudget)
{
    const date::year_month_day start_date{date::year{2019}, date::month{5}, date::day{6}};
    const date::year_month_day end_date{date::year{2019}, date::month{5}, date::day{20}};
    FakeBudgetRepo budget_repo;
    BudgetCalculator budget_calculator{budget_repo};

    EXPECT_EQ(budget_calculator.QueryBudget(start_date, end_date), 15);
}