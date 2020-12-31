#include <hpp/employee.hpp>
#include <hpp/hrms.hpp>

Employee::Employee() {

}

Employee::Employee(string ID, string NAME, string SURNAME, string POSITION) {

    id = ID;
    name = NAME;
    surname = SURNAME;
    departmentId = departmentId;
    position = POSITION;
}

string Employee::e_departmentId() {

    return departmentId;
}

string Employee::e_id() 
{
    return id;
}

string Employee::e_name() {

    return name;
}

string Employee::e_surname() {

    return surname;
}

string Employee::e_position() {

    return position;
}

void Employee::print() {

    cout << id << endl;
    cout << name << endl;
    cout << surname << endl;
    cout << departmentId << endl;
    cout << position << endl;
}

void Employee::d_set(string departementID) {

    departmentId = departementID;
}
