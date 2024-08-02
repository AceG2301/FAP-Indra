/// @file ce23_exam_main.cpp
/// @brief main() function executing the test cases for automatic evaluation in VPL

/// @attention DO NOT CHANGE THIS FILE - automatic evaluation depends on this content

#include "main_exam.h"

using namespace std;

/// @brief main() function builds the basic data structures, reads test case number
/// and executes the requested test case
int main()
{
    // create car >>> test case 1
    car chrysler("Chrysler");
    // create and delete rental cars >>> test cases 2 & 3
    rental_car toyota("Toyota");
    rental_car mercedes("Mercedes");
    {
        rental_car audi("Audi");
    } 
    rental_car porsche("Porsche");

    // create customers >>> test cases 5 & 6
    customer frank("Frank", "Sinatra");
    customer liza("Liza", "Minelli");

    // create and work with car rentals >>> test cases 4, 7 to 16
    car_rental avis("Avis");
    car_rental herz("Herz");
    rental_car tesla("Tesla", &avis);
    avis.list(mercedes);
    avis.list(porsche);
    avis.list(frank);
    avis.list(liza);

    int testcase{0};
    cin >> testcase;
    switch (testcase)
    {
        case 1: // Car creation
            cout << chrysler.toString() << endl;
            break;
        case 2: // Rental car creation
            cout << toyota.toString() << endl;
            break;      
        case 3: // Rental car creation after deletion                   
            cout << porsche.toString() << endl;
            break;
        case 4: // Rental car creation with direct link to agency
            cout << tesla.toString() << endl;
            break;
        case 5: // Customer creation
            cout << frank << endl;
            break;
        case 6: // Customer creation failing
            try
            {
                customer elvis("Elvis", "P");
                cout << elvis << endl;
            }
            catch(const std::exception& e)
            {
                std::cerr <<  "Exception: " << e.what() << '\n';
            }
            break;
        case 7: // Agency car no 
            cout << avis.cars_no() << endl;
            break;
        case 8: // Agency car list  
            cout << avis.cars_list() << endl;
            break;
        case 9: // Agency car list after delisting
            avis.delist(mercedes);
            cout << avis.cars_list() << endl;
            break;
        case 10: // Agency customer no
            cout << avis.customers_no() << endl;
            break;
        case 11: // Agency customer list
            cout << avis.customers_list() << endl;
            break;
        case 12: // Agency customer list after adding existing customer
            avis.list(frank);
            cout << frank.agency_no() << endl;
            cout << avis.customers_list() << endl;
            break;
        case 13: // Agency name
            cout << herz.name() << endl;
            break;
        case 14: // Agency customer list after adding customer of  other agency
            herz.list(liza);
            cout << liza.agency_no() << endl;
            cout << herz.customers_list() << endl;
            cout << avis.customers_list() << endl;
            break;
        case 15: // Agency car list after adding delisted car from other agency
            avis.delist(mercedes);
            herz.list(mercedes);
            cout << herz.cars_list() << endl;
            break;
        case 16: // Agency failing to list car already listed with other agency
            try 
            {
                herz.list(mercedes);
            }
            catch(const std::exception& e)
            {
                std::cerr <<  "Exception: " << e.what() << '\n';
            }
            break;

    }
}
