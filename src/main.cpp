#include "./headers/ActiveDebt.hpp"
#include "./headers/Transaction.hpp"
#include "./headers/CRUD.hpp"

#include "./implementations/ActiveDebt.cpp"
#include "./implementations/Transaction.cpp"
#include "./implementations/CRUD.cpp"

#include <iostream>

using namespace std;

int main() {

    CRUD crud;

    ActiveDebt d(123, 10.0, child_support);
    d.update_for_interest(12);
    crud.add_transaction(d);
    ActiveDebt d1(12300, 10.0, child_support);
    crud.add_transaction(d1);
    ActiveDebt d2(1, 0, child_support);
    crud.add_transaction(d2);
    // ActiveDebt x = crud.get_transaction(d.get_id()); 
    // cout << "get t: " << x;
    // crud.update_transaction(d.get_id());
    // ActiveDebt y = crud.get_transaction(d.get_id()); 
    // cout << "update t: " << y;
    // crud.delete_transaction(d.get_id());
    // ActiveDebt z = crud.get_transaction(d.get_id()); 
    // cout << "del: " << z;

    crud.sort_by_value();
    crud.print_transactions();

    return 0;
}