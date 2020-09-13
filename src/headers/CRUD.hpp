#include "./ActiveDebt.hpp"
#include "./Transaction.hpp"
#include <vector>

#pragma once

using namespace std;

class CRUD {
    vector<ActiveDebt> transactions;
public:
    void add_transaction(ActiveDebt& t);
    void update_transaction(long id, ActiveDebt& t);
    void update_transaction(long id);
    ActiveDebt get_transaction(long id);
    void delete_transaction(long id);
    void print_transactions();
    void sort_by_id();
    void sort_by_value();
};