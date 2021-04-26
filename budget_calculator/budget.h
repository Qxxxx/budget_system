#ifndef BUDGET_CALCULATOR_BUDGET_H
#define BUDGET_CALCULATOR_BUDGET_H
#include "budget_calculator/date.h"

struct Budget
{
    date::year_month year_month;
    int amount;
};

#endif // BUDGET_CALCULATOR_BUDGET_H
