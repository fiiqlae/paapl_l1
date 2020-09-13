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

    bool operator == (const ActiveDebt &r);
    bool operator < (const ActiveDebt &r);
    bool operator > (const ActiveDebt &r);
    ActiveDebt& operator= (const ActiveDebt& s);
};