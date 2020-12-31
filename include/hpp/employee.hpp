#ifndef employee_hpp
#define employee_hpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
    private:
    string id;
    string name;
    string surname; 
    string departmentId;
    string position;

    public:
    Employee();                                     //konstruktor domyslny
    Employee(string, string, string, string);       //
    string e_id();
    string e_name();
    string e_surname();
    string e_departmentId();
    string e_position();
    void print();
    void d_set(string);
};

#endif