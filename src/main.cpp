#include "./headers/ActiveDebt.hpp"
#include "./headers/Transaction.hpp"
#include "./headers/CRUD.hpp"

#include "./implementations/ActiveDebt.cpp"
#include "./implementations/Transaction.cpp"
#include "./implementations/CRUD.cpp"

#include <iostream>

using namespace std;

void print_menu() {
    cout << "1 -- add a transaction" 
         << endl << "2 -- alter transaction by id" 
         << endl << "3 -- print 'em all" 
         << endl << "4 -- sort 'em by id" 
         << endl << "5 -- sort 'em by value"
         << endl << "6 -- drop some"
         << endl;
}

int mega_input_protector() {
    char user_input = ' ';
    while(true) {
        cin >> user_input;
        user_input -= 48;
        if(user_input >= 1 && user_input <= 6) return (int)user_input;
        else 
            cout <<
             "/$$     /$$                        /$$                                              " << endl <<
             "|  $$   /$$/                       | $$                                              " << endl <<
              " \\  $$ /$$//$$$$$$  /$$   /$$      | $$        /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$ " << endl << 
              "  \\  $$$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$" << endl <<
              "   \\  $$/| $$  \\ $$| $$  | $$      | $$      | $$  \\ $$| $$  \\ $$|  $$$$$$ | $$$$$$$$" << endl <<
              "    | $$ | $$  | $$| $$  | $$      | $$      | $$  | $$| $$  | $$ \\____  $$| $$_____/" << endl <<
              "    | $$ |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/ /$$$$$$$/|  $$$$$$$" << endl <<
              "    |__/  \\______/  \\______/       |________/ \\______/  \\______/ |_______/  \\_______/"
            << endl << "go again ";
    }
}

int main() {

    CRUD crud;
    int selection = 0;
    while(1) {
        cout << "what are we doing?" << endl;
        print_menu();
        selection = mega_input_protector();
        switch (selection) {
            case 1: {
                ActiveDebt d;
                cout << d.get_id() << endl;
                cin >> d;
                crud.add_transaction(d);
                break;
            }
            case 2: {
                long id = 0;
                cin >> id;
                crud.update_transaction(id);
                break;
            }
            case 3:
                crud.print_transactions();
                break;
            case 4:
                crud.sort_by_id();
                break;
            case 5:
                crud.sort_by_value();
                break;
            case 6: {
                long id = 0;
                cin >> id;
                crud.delete_transaction(id);
                break;
            }
            default:
                break;
        }
        selection = 0;
    }

    return 0;
}