#ifndef BUDGET_CALCULATOR_BUDGET_REPO_H
#define BUDGET_CALCULATOR_BUDGET_REPO_H

#include "budget_calculator/budget.h"
#include <vector>
using Budgets = std::vector<Budget>;
class BudgetRepo
{
public:
    virtual Budgets &FindAll()
    {
        return budgets;
    }

protected:
    Budgets budgets;
};

#endif // BUDGET_CALCULATOR_BUDGET_REPO_H
