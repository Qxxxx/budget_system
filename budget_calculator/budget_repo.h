#ifndef BUDGET_CALCULATOR_BUDGET_REPO_H
#define BUDGET_CALCULATOR_BUDGET_REPO_H

#include "budget_calculator/budget.h"
#include <vector>
using Budgets = std::vector<Budget>;
class BudgetRepo
{
public:
    Budgets &FindAll()
    {
        return budgets;
    }
    void add_budget(date::year_month year_month, int ammout)
    {
        budgets.push_back({year_month, ammout});
    }

protected:
    Budgets budgets;
};

#endif // BUDGET_CALCULATOR_BUDGET_REPO_H
