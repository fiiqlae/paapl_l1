#include "./Transaction.hpp"
#include "./Categories.hpp"

#pragma once

class ActiveDebt : public Transaction {
    SpendingType debtType;
public: 
    ActiveDebt();
    ActiveDebt(int value, double monthly_interest, SpendingType type);
    void make_payment(int payment);
    void update_for_interest(int months_elapsed);

    friend bool operator== (ActiveDebt& l, ActiveDebt &r);
    friend bool operator< (ActiveDebt& l, ActiveDebt &r);
    friend bool operator> (ActiveDebt& l, ActiveDebt &r);
    ActiveDebt& operator= (ActiveDebt& s);
};