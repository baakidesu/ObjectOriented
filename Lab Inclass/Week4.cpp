#include <iostream>

class employee {
private:
    std::string name;
    std::string surname;
    int year;
    double salary;

public:
    employee() {
        name = "NOT-SET";
        surname = "NOT-SET";
        year = 0;
        salary = 0.0;
    }
    employee(std::string _name, std::string _surname, int year): name(_name),
    surname(_surname), year(year){}

    void calculate_salary() {
        std::cout << "[DEBUG] Calculating Salary" << std::endl;
        salary = 2310 + 2310 * year * 12 / 100;
    }

    void printInfo() {
        std::cout << name << " " << surname << " (" << year << ") " << salary << " TL/month"<<std::endl;
    }
};

int main() {

    employee e1 = employee("Burak", "Foto", 2004);
    e1.calculate_salary();
    e1.printInfo();

    return 0;
}