#include "../headers/CRUD.hpp"

#include "../headers/Categories.hpp"
#include "../headers/ActiveDebt.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#pragma once

void CRUD::add_transaction(ActiveDebt& t) {
    transactions.push_back(t);
}

void CRUD::update_transaction(long id, ActiveDebt& t) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i].get_id() == id) {
            transactions[i].set_value(t.get_value());
            transactions[i].set_monthly_interest(t.get_interest());
            return;
        }
    }
}

void CRUD::update_transaction(long id) {
    ActiveDebt d;
    std::cin >> d;
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i].get_id() == id) {
            transactions[i].set_value(d.get_value());
            transactions[i].set_monthly_interest(d.get_interest());
            return;
        }
    }
}

ActiveDebt CRUD::get_transaction(long id) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i].get_id() == id) {
            return transactions[i];
        }
    }
}

void CRUD::delete_transaction(long id) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i].get_id() == id) {
            // gotta be efficient af, we're in c++, so efficiency and shooting myself in the foot
            transactions[i] = transactions.back();
            transactions.pop_back();
            return;
        }
    }
}

void CRUD::sort_by_id() {
    std::sort(transactions.begin(), transactions.end());
}

void CRUD::sort_by_value() {
    std::sort(transactions.begin(), transactions.end());
}

void CRUD::print_transactions() {
    for(auto i = transactions.begin(); i != transactions.end(); i++) {
        cout << *(i.base());
    }
}

