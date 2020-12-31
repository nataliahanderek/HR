#ifndef hrms_hpp
#define hrms_hpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "employee.hpp"

class HRMS {
    
    private:
    map<string, Employee> map_employee;             // klucz to ID pracownika, wartosc to employee
    map<string, vector<string> > map_department; 
    map<string, double> map_salary;
    
    public:
    void add(Employee employee, string departmentid, double salary);
    void printSalaries();
    void printDepartment(string departmentid);
    void changeSalary(string employeeId, double salary);
    void printSalariesSorted();

};

#endif