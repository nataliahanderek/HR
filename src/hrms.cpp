#include <hpp/employee.hpp>
#include <hpp/hrms.hpp>

class No_Employee : public exception {

    virtual const char *what() const throw() {
        return "Brak pracownikow w podanym departamencie!";
    }
};

class No_Id : public exception {
    
    virtual const char *what() const throw() {
        return "Id, ktore podales nie istnieje!";
    }
};

void HRMS::add(Employee employee, string departmentid, double salary) {

    string employee_id = employee.e_id();                   //ID to klucz
    employee.d_set(departmentid);                           
    map_employee[employee_id] = employee;                   //dodanie pracownika do mapy
    map_department[departmentid].push_back(employee_id);    //dodanie departamentu dp mapy, push.back dodaje element do kontenera
    map_salary[employee_id] = salary;                       //dodanie wynagrodzenia
    
}

void HRMS::printSalaries()
{
    cout << "WYPLATY I DANE PRACOWNIKOW:" << endl << endl;

    for (auto& n: map_employee) {
        Employee write = n.second;
        cout << "ID: " << write.e_id() << endl;
        cout << "name: " << write.e_name() << endl;
        cout << "surname: " << write.e_surname() << endl;
        cout << "department: " << write.e_departmentId() << endl;
        cout << "position: " << write.e_position() << endl;
        cout << "salary: " << map_salary[write.e_id()] << endl << endl;
    }
}

void HRMS::printDepartment(string departmentid) {

    cout << "\n\n----------------" << endl;
    cout << "PRACPWNICY Z DEPARTAMENTU " << departmentid << ":" << endl << endl;

    if(map_department.find(departmentid) == map_department.end()) {
        
        throw No_Employee();
    }

    auto who_works = map_department[departmentid];
    for(auto &n: who_works) {
        cout << map_employee[n].e_name() << " " << map_employee[n].e_surname() << endl;
    }

}

void HRMS::changeSalary(string employeeId, double salary) {

    if (map_salary.find(employeeId) == map_salary.end()) {

        throw No_Id();
    }
    
    map_salary[employeeId] = salary;
}

void HRMS::printSalariesSorted() {

    cout << "\n\n----------------" << endl;
    cout << "PRACOWNICY W KOLEJNOSCI WYNAGRODZENIA MALEJACO:" << endl << endl;

    vector<std::pair<Employee, double>> pair;
    for(auto &n: map_employee) {
        Employee a = n.second; 
        pair.push_back(std::make_pair(a,map_salary[a.e_id()]));
    }
    
    sort(pair.begin(), pair.end(), [=](std::pair<Employee, double>&a, std::pair<Employee, double>&b ) { 
        return a.second > b.second;
    });

    for (auto& n: pair) {
        Employee write = n.first;
        cout << "ID :" << write.e_id() << endl;
        cout << "name: " << write.e_name() << endl;
        cout << "surname: " << write.e_surname() << endl;
        cout << "department: " << write.e_departmentId() << endl;
        cout << "position: " << write.e_position() << endl;
        cout << "salary: " << map_salary[write.e_id()] << endl << endl;
    }
}