/// @file ce23_exam.h
/// @brief Header file for the "car rental" exam topic

/// @attention DO NOT CHANGE THIS FILE - automatic evaluation depends on this content

/// @todo Write a car rental management system by implementing all 
/// constructors, destructors and member functions declared in this header file 

/// @remarks A rental car agency holds a list of owned rental cars and a list of customers.
/// Rental cars are either not registered, or registered with only one  single rental car agency. 
/// Customers can be customers of zero, one, or more car rental agencies.

/// @remarks Both, rental cars and customers are "doubly linked" to rental car agencies, i.e.,
/// agencies hold pointers to rental cars and customers, and rental cars / customers hold pointers
/// to agencies. These reciprocal links must be properly maintained when creating, linking, de-linking,
/// and deleting objects. 

#include <string>
#include <iostream>
#include <vector>

using namespace std;

/// @brief car is a general class describing a vehicle
class car
{
public:
    car(const string& model);

    /// @brief Returns a description of the car, consisting of it's unique id and its model name
    /// The returned string shall follow the form "001(Audi)", 
    /// i.e., unique id with 3 digits and leading zero's,the model in round brackets, without spaces.
    /// @return string with the car description, e.g., "003(Mercedes)"
    virtual string toString() const;
private:
    string m_model;

    /// @brief m_unique_id shall hold a unique car serial number. The first car shall be assigned 
    /// number 1. For each of the following cars, the unique id shall be incremented by 1.
    /// No unique id shall be re-used (i.e., if a car is deleted, it's id shall not be re-used) 
    int m_unique_id;
    static int s_id_counter;
};

class car_rental;

class rental_car: public car
{
public:
    /// @brief Contructs a rental car, and potentially registers it with a car rental agency
    /// @param model string naming the car model
    /// @param agency pointer to car_rental.
    /// @todo If @param agency is not nullptr, then register this rental_car with the agency  
    rental_car(const string& model, car_rental* agency = nullptr);

    /// @brief Cleans-up all links of this rental car with its car rental agency
    /// @todo If this rental car is linked to a car rental agency, deregister the car
    ~rental_car();

    /// @brief Registers the car with the rental car agency
    /// @param cr rental car agency
    /// @throws runtime_error("Car already registered with other agency.") if the car is already
    /// registered with a different agency
    void register_with(const car_rental& cr);

    /// @brief Deregisters the car with the rental car agency
    /// @param cr rental car agency
    void deregister_with(const car_rental& cr);

    /// @brief Returns a description of the rental car, including car description and rental agency name
    /// The returned string shall follow the form "001(Audi) - Herz", 
    /// i.e., the car description, followed by space, '-', space, and the rental agency name
    /// @return string with the car description, e.g., "003(Mercedes) - Avis"
    virtual string toString() const;
private:
    car_rental* m_car_rental;
};

class person
{
public:
    /// @brief Constructs a person
    /// @param first_name given name
    /// @param name family name
    /// @throws invalid_argument("Name too short.") if firstName or name are shorter than 2 letters
    person(const string& first_name, const string& name);

    /// @brief Writes the person's name to the output stream
    /// @param os output stream
    /// @param person person
    /// @return output stream
    friend ostream& operator<<(ostream& os, const person& person);

private:
    string m_name;
    string m_first_name;
};

class customer: public person
{
public:
    customer(const string& first_name, const string& name);

    /// @brief Cleans-up all links of this customer with car rental agencies
    /// @todo Deregister with all car rental agencies this customer is linked to
    ~customer();

    /// @brief Registers customer as customer with the car rental agency
    /// Agency must remember the customer, and customer must memorize the agency 
    /// @param cr car rental
    void register_with(car_rental& cr);   

    /// @brief Deregisters customer with the car rental agency
    /// Customer must be erased from the agency's customer list, and agency must be deleted
    /// from the customers car rental list.
    /// @param cr car rental
    void deregister_with(car_rental& cr);

    /// @brief Returns the number of car rental agencies this customer is currently registered with 
    /// @return number of car rental agencies
    int agency_no() const;
private:
    vector<car_rental*> m_car_rentals;
};

class car_rental
{
public:
    car_rental(const string& name);

    /// @brief Cleans-up all links with rental cars and customers
    ~car_rental();

    /// @brief Returns name of car rental agency
    /// @return name of agency
    string name() const;

    /// @brief Register rental car with this agency
    /// @param c rental car
    void list(rental_car& c);

    /// @brief Deregister rental with this agency
    /// @param c 
    void delist(rental_car& c);

    /// @brief Returns number of cars registered with this car rental agency
    /// @return number of cars
    int cars_no() const;

    /// @brief Returns list of cars registered with this car rental agency
    /// @return list of cars (using car::toString), separated by spaces
    /// e.g., "001(Audi) 007(Porsche)" 
    string cars_list() const;

    /// @brief Registers customer with this agency
    /// @param p customer
    void list(customer& p);

    /// @brief Deregisters customer with this agency
    /// @param p customer
    void delist(customer& p);

    /// @brief Returns number of customers registered with this car rental agency
    /// @return number of customers
    int customers_no() const;

    /// @brief Returns list of customers registered with this car rental agency
    /// @return list of customers, separated by spaces, e.g., "Elvis Presley Liza Minelli" 
    string customers_list() const;
private:
    string m_name;
    vector<rental_car*> m_cars;
    vector<customer*> m_customers;
};
