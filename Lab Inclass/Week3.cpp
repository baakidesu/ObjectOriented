#include <iostream>

class Student {
public:
    Student(const std::string& _name, int _studentID, const std::string _classesTaken[3]) {
        name = _name;
        studentID = _studentID;
        for (int i = 0; i < 3; i++) {
            classesTaken[i] = _classesTaken[i];
        }
    }
    void DisplayParameters() {
        std::cout << "[DEBUG] Displaying Parameters" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Classes Taken: ";
        for (const auto & i : classesTaken) {
            std::cout <<" " << i << std::endl;
        }
    }
    void AddClasses(const std::string& newClass) {
        std::cout << "[DEBUG] Adding Classes" << std::endl;
        for (auto & i : classesTaken) {
            if (i == "Not-Set") {
                i = newClass;
            }
        }
    }
    void UpdateStudentID(const int& newID) {
        std::cout << "[DEBUG] Updating Student ID" << std::endl;
        studentID = newID;
    }

private:
    std::string name = "No-Name";
    int studentID = -1;
    std::string classesTaken[3] = {"Not-Set", "Not-Set", "Not-Set"};


};

int main() {

    std::string classes[] ={"C++", "Calculus", "Not-Set"};
    Student student1("Burak Foto", 2, classes);

    student1.DisplayParameters();
    student1.UpdateStudentID(2366699);
    student1.AddClasses("Phy");
    student1.DisplayParameters();

    return 0;
}

