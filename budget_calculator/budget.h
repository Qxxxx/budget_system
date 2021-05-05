#ifndef BUDGET_CALCULATOR_BUDGET_H
#define BUDGET_CALCULATOR_BUDGET_H
#include "budget_calculator/date.h"

using date::year_month;
using date::year_month_day;

struct Budget
{
    int CalculateIntersectionDays(const year_month_day &start_date, const year_month_day& end_date) const;
    year_month yearmonth;
    int amount;
};

#endif // BUDGET_CALCULATOR_BUDGET_H
