#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

template<typename T>
class Employee {
protected:
    char name[50];
    int seniority;
    double salary;
    char project[50];
public:
    Employee(char* _name, int _seniority, double _salary, char* _project) {
        strcpy(name, _name);
        seniority = _seniority;
        salary = _salary;
        strcpy(project, _project);
    }

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Seniority: " << seniority << " months" << endl;
        cout << "Salary: " << salary << " USD" << endl;
        cout << "Project: " << project << endl;
    }
};

class Programmer : public Employee<Programmer> {
    char language[50];
public:
    Programmer(char* _name, int _seniority, double _salary, char* _project, char* _language)
        : Employee(_name, _seniority, _salary, _project) {
        strcpy(language, _language);
    }

    void printInfo() {
        Employee::printInfo();
        cout << "Type: Programmer" << endl;
        cout << "Programming Language: " << language << endl;
    }
};

class QA : public Employee<QA> {
    bool automation;
public:
    QA(char* _name, int _seniority, double _salary, char* _project, bool _automation)
        : Employee(_name, _seniority, _salary, _project) {
        automation = _automation;
    }

    void printInfo() {
        Employee::printInfo();
        cout << "Type: QA" << endl;
        cout << "Tester Type: " << (automation ? "Automation" : "Manual") << endl;
    }
};

class Manager : public Employee<Manager> {
    int num_of_employees;
public:
    Manager(char* _name, int _seniority, double _salary, char* _project, int _num_of_employees)
        : Employee(_name, _seniority, _salary, _project) {
        num_of_employees = _num_of_employees;
    }

    void printInfo() {
        Employee::printInfo();
        cout << "Type: Manager" << endl;
        cout << "Number of employees managed: " << num_of_employees << endl;
    }
};

main() {
    return 0;
}