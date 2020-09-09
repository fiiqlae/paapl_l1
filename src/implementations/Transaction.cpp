#include <iostream>
#include "../headers/Transaction.hpp"
#include <chrono>

#pragma once

using namespace std::chrono;


Transaction::Transaction(int value, double interest) {
    this->value = value;
    monthly_interest = interest;
    id = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Transaction::Transaction() {
    value = 0;
    monthly_interest = 0;
    id = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

Transaction::Transaction(const Transaction &source) {
    this->value = source.value;
    this->monthly_interest = source.monthly_interest;
    id = source.id;
}

Transaction::~Transaction() {
    //why?
}

void Transaction::set_value(int value) {
    this->value = value;
}

void Transaction::set_monthly_interest(double interest) {
    this->monthly_interest = interest;
}

long Transaction::get_id() {return id;}

int Transaction::get_value() {return value;}

double Transaction::get_interest() {return monthly_interest;}

ostream& operator<< (ostream& os, Transaction& t) {
    os << "Transaction # " << t.get_id() << ", ¢" << t.get_value() << ", %" << t.get_interest() << endl;
    return os;
}

istream& operator>> (istream& is, Transaction& t) {
    int value;
    int interest;
    cout << "value in cents: ";
    is >> value;
    cout << "monthly interest, %: ";
    is >> interest;
    t.set_value(value);
    t.set_monthly_interest(interest);
    return is;
}