#include "budget_calculator/budget.h"

int Budget::CalculateIntersectionDays(const year_month_day &start_date, const year_month_day &end_date) const {
    const year_month_day ymd_first{yearmonth / 1};
    const date::year_month_day ymd_last{yearmonth / date::last};
    const auto start_within_month = ymd_first < start_date ? start_date : ymd_first;
    const auto end_within_month = ymd_last < end_date ? ymd_last : end_date;
    return start_within_month <= end_within_month ? (end_within_month.day() - start_within_month.day()).count() + 1 : 0;
}

int Budget::CalculateDailyBudget() const {
    const date::year_month_day ymd_last{yearmonth / date::last};
    const auto days_num = (unsigned)ymd_last.day();
    return amount/static_cast<int>(days_num);
}

