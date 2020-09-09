#include "../headers/ActiveDebt.hpp"
#pragma once

ActiveDebt::ActiveDebt() : Transaction() {
    this->debtType = unspecified;
}

ActiveDebt::ActiveDebt(int value, double monthly_interest, SpendingType type) : Transaction(value, monthly_interest) {
    this->debtType = type;
}

void ActiveDebt::make_payment(int payment) {
    this->set_value(value - payment);
}

void ActiveDebt::update_for_interest(int months_elapsed) {
    int new_value = (int) (value + monthly_interest*value*months_elapsed / 100);
    this->set_value(new_value);
}

bool operator== (ActiveDebt& l, ActiveDebt& r) {
    return l.debtType == r.debtType 
        && l.value == r.value
        && l.monthly_interest == r.monthly_interest
        && l.id == r.id;
}

bool operator> (ActiveDebt& l, ActiveDebt& r) {
    return l.value > r.value;
}

bool operator< (ActiveDebt& l, ActiveDebt& r) {
    return l.value < r.value;
}

ActiveDebt& ActiveDebt::operator= (ActiveDebt& s) {
    this->id = s.id;
    this->debtType = s.debtType;
    this->value = s.value;
    this->monthly_interest = s.monthly_interest;
    return *this;
}