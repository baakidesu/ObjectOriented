#include <iostream>

template <typename T>
class myArray {
    int size; //representing the number of elements
    T* data;

    public:
    myArray() {
        size = 0;
        data = NULL;
    }

    myArray(int _size) {
        if (_size > 0) {
            size = _size;
            data = new T[size]; //creates a dynamically allocated array.
        }
    }

    void assign_value_at_index(int index, T value) {
        std::cout << "[DEBUG] ASSIGN VALUE AT INDEX"<< std::endl;
        if(index >= 0 && index < size) {
            data[index] = value;
        }
    }

    T retrieve_value_at_index(int index){
        std::cout << "[DEBUG] RETRIEVE VALUE AT INDEX  ";
        if(index >= 0 && index < size) {
            return data[index];
        }else {
            return T();
        }
    }

    int getSize() {
        std::cout << "[DEBUG] GET SIZE  " << std::endl;
        return size;
    }

    void printArray() {
        std::cout << "[DEBUG] PRINT ARRAY  ";
        for(int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    myArray<int> intArray(2);

    intArray.assign_value_at_index(0, 5);
    intArray.assign_value_at_index(1, 10);
    std::cout << "Get data from index 1: " << intArray.retrieve_value_at_index(1) << std::endl;
    intArray.printArray();
    intArray.getSize();

    std::cout <<"------------------" << std::endl;

    myArray<double> doubleArray(2);

    doubleArray.assign_value_at_index(0, 1.1);
    doubleArray.assign_value_at_index(1, 2.2);
    std::cout << "Get data from index 1: " << doubleArray.retrieve_value_at_index(1) << std::endl;
    doubleArray.printArray();
    doubleArray.getSize();

    return 0;
}
