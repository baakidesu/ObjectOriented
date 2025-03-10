#include <iostream>
#include <string>
using namespace std;

class employee {
private:
    int id;
    string name;
    static int employeeCount;

public:
    employee() : id(0), name("No-Name") { employeeCount++; }
    
    employee(int _id, string _name) : id(_id), name(_name) { employeeCount++; }
    
    int getID() const { 
        return id; 
        
    }
    
    string getName() const { 
        return name; 
        
    }
    
    static int get_numberOfEmployees() { 
        return employeeCount; 
        
    }
};

int employee::employeeCount = 0;

class employeeList {
private:
    int size;
    int length;
    employee* arr;

public:
    employeeList() {
        size = 1;
        length = 0;
        arr = new employee[size];
    }

    employeeList(int _size) {
        if (_size > 0) {
            size = _size;
            length = 0;
            arr = new employee[size];
        } else {
            size = 1;
            length = 0;
            arr = new employee[size];
            cout << "Size must be positive!" << endl;
        }
    }

    employee retrieve_employeeFromIndex(int index) {
        if (index >= 0 && index < length) {
            return arr[index];
        } else {
            cout << "Invalid index!" << endl;
            return employee();
        }
    }

    void addToList(employee& item) {
        if (length < size) {
            arr[length] = item;
            length++;
        } else {
            cout << "List is full!" << endl;
        }
    }

    int listLength() { 
        
        return length; 
        
    }

    ~employeeList() {
        delete[] arr;
    }
};

void printEmployees(employeeList& empList) {
    for (int i = 0; i < empList.listLength(); i++) {
        employee emp = empList.retrieve_employeeFromIndex(i);
        cout << "ID: " << emp.getID() << ", Name: " << emp.getName() << endl;
    }
}

int main() {
    employee a;
    employee b(5, "John Doe");
    employee c(3, "Sue Doe");

    employeeList empList(employee::get_numberOfEmployees());

    empList.addToList(a);
    empList.addToList(b);
    empList.addToList(c);

    printEmployees(empList);
    cout << "List length: " << empList.listLength() << endl;

    return 0;
}