#include "../headers/CRUD.hpp"

#include "../headers/Categories.hpp"
#include "../headers/ActiveDebt.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#pragma once

void CRUD::add_transaction() {
    ActiveDebt d;
    std::cin >> d;
    transactions.push_back(&d);
}

void CRUD::add_transaction(ActiveDebt& t) {
    transactions.push_back(&t);
}

void CRUD::update_transaction(long id, ActiveDebt& t) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i]->get_id() == id) {
            transactions[i]->set_value(t.get_value());
            transactions[i]->set_monthly_interest(t.get_interest());
            return;
        }
    }
}

void CRUD::update_transaction(long id) {
    ActiveDebt d;
    std::cin >> d;
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i]->get_id() == id) {
            transactions[i]->set_value(d.get_value());
            transactions[i]->set_monthly_interest(d.get_interest());
            return;
        }
    }
}

ActiveDebt CRUD::get_transaction(long id) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i]->get_id() == id) {
            return *transactions[i];
        }
    }
}

void CRUD::delete_transaction(long id) {
    for(int i = 0; i < transactions.size(); i++) {
        if(transactions[i]->get_id() == id) {
            transactions.erase(transactions.begin() + i);
            return;
        }
    }
}

bool id_comparator(ActiveDebt* lhs, ActiveDebt* rhs) {
   return lhs->get_id() < rhs->get_id();
}

bool value_comparator(ActiveDebt* lhs, ActiveDebt* rhs) {
   return lhs->get_value() < rhs->get_value();
}

void CRUD::sort_by_id() {
    sort(transactions.begin(), transactions.end(), &id_comparator);
}

void CRUD::sort_by_value() {
    sort(transactions.begin(), transactions.end(), &value_comparator);
}

void CRUD::print_transactions() {
    for(int i = 0; i < transactions.size(); i++) {
        cout << *transactions[i];
    }
}

