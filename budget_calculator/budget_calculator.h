#ifndef BUDGET_CALCULATOR_BUDGET_CALCULATOR_H
#define BUDGET_CALCULATOR_BUDGET_CALCULATOR_H

#include "budget_calculator/budget_repo.h"

class BudgetCalculator
{
public:
    BudgetCalculator(BudgetRepo &budget_repo) : budget_repo_(budget_repo) {}
    int QueryBudget(date::year_month_day start_date, date::year_month_day end_date);

private:
    BudgetRepo &budget_repo_;
};

#endif // BUDGET_CALCULATOR_BUDGET_CALCULATOR_H
