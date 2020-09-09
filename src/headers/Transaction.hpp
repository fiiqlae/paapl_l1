#include <iostream>

#pragma once

class Transaction {
protected:
    int value; // value in cents
    double monthly_interest; // interest, percent
    long id;
public:
    Transaction();
    Transaction(int value, double monthly_interest);
    Transaction(const Transaction &t);
    ~Transaction();
    virtual void update_for_interest(int months_elapsed) = 0;

    friend std::ostream& operator<< (std::ostream& os, Transaction& t);
    friend std::istream& operator>> (std::istream& is, Transaction& t);

    long get_id();
    int get_value();
    double get_interest();

    void set_value(int value);
    void set_monthly_interest(double interest);
};