#include "budget_calculator/budget_calculator.h"
#include <iostream>

int BudgetCalculator::QueryBudget(date::year_month_day start_date, date::year_month_day end_date) {
    const auto budgets = budget_repo_.FindAll();
    const date::year_month start_year_month{date::year{start_date.year()}, date::month{start_date.month()}};
    int res_amount = 0;
    for (const auto &budget : budgets) {
        if (budget.year_month == start_year_month && budget.year_month == start_year_month) {
            int day_num = (end_date.day() - start_date.day()).count() + 1;

            auto month_days = (unsigned) date::year_month_day_last(end_date.year(),
                                                                   date::month_day_last{end_date.month()}).day();
            res_amount += budget.amount / month_days * day_num;
        }
    }
    return res_amount;
}