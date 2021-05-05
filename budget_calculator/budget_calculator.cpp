#include "budget_calculator/budget_calculator.h"
#include <iostream>


int BudgetCalculator::QueryBudget(date::year_month_day start_date, date::year_month_day end_date) {
    const auto budgets = budget_repo_.FindAll();
    int total_amount = 0;
    for (const auto &budget : budgets) {
        int day_num = budget.CalculateIntersectionDays(start_date, end_date);
        total_amount += budget.CalculateDailyBudget() * day_num;
    }
    return total_amount;
}