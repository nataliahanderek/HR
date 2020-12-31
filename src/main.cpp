#include <iostream>
#include <hpp/employee.hpp>
#include <hpp/hrms.hpp>
using namespace std;

int main()
{
    Employee Kowalska("1010", "Natalia", "Kowalska", "kierownik");
    Employee Nowak("2034", "Zenek", "Nowak", "szef");
    Employee Kot("3982", "Aleksandra", "Kot", "kierownik");
    Employee Szat("4000", "Olaf", "Szat", "kierownik");
    Employee Pies("5550", "Milosz", "Pies", "sprzatacz");
    Employee Kawka("6543", "Monika", "Kawka", "recepja");
    Employee Len("7986", "Oliwa", "Len", "szef");
    Employee Onyks("8099", "Artur", "Onyks", "kierownik");
    Employee Halat("9088", "Jolanta", "Halat", "sprzatacz");
    Employee Malysz("10002", "Adam", "Malysz", "recepcja");

    HRMS hrms;
    hrms.add(Kowalska, "obrony", 4000);
    hrms.add(Nowak, "mowy", 9800);
    hrms.add(Szat, "rozliczen", 6540.89);
    hrms.add(Pies, "obrony", 2400);
    hrms.add(Kawka, "kryzysu", 1234.56);
    hrms.add(Kot, "mowy", 9876.54);
    hrms.add(Len, "obrony", 6354);
    hrms.add(Onyks, "rozliczen", 4010);
    hrms.add(Halat, "kryzysu", 3999);
    hrms.add(Malysz, "obrony", 2300.98);

    cout << "\n----------------" << endl;
    hrms.printSalaries();

    try {

        hrms.printDepartment("obrony");
    }
    catch(exception &e) {

        cout << e.what() << endl;
    }

    cout << "\n\n----------------" << endl;
    cout << "ZMIANA WYNAGRODZNIA" << endl;

    try {

        hrms.changeSalary("1010", 4001);
        hrms.changeSalary("6543", 4002);
        hrms.changeSalary("10002", 4003);
        hrms.changeSalary("7986", 4004);
        hrms.changeSalary("9088", 4005);
        hrms.changeSalary("0", 0);
    }
    catch(exception &e) {

        cout << e.what() << endl;
    }
    
    //hrms.printSalaries();
    hrms.printSalariesSorted();

    return 0;
}