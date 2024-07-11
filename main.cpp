#include <iostream>

class DynamicArray {
    int* data;
    int size;
    int capacity;

public:
    explicit DynamicArray(const int cap) : size(0), capacity(cap) {
        data = new int[capacity];
    };
    ~DynamicArray() {
        delete[] data;
    }
    DynamicArray(const DynamicArray& arr) {
        size = arr.size;
        capacity = arr.capacity;
        data = new int[capacity];

        for (int i = 0; i < size; i++) {
            data[i] = arr.data[i];
        }

    }

    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];

        for (int i = 0; i < getSize(); ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    int getCapacity() const {
        return capacity;
    }

    int getIndex(const int value) const {
        for (int i = 0; i < getSize(); i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int getValue(const int index) const {

        if (index >= getSize()) {
            return -1;
        }

        for (int i = 0; i < getSize(); i++) {
            if (i == index) {
                return data[i];
            }
        }
        return -1;
    }

    int getSize() const {
        return size;
    }

    void append(const int value) {
        if (getSize() >= capacity) {
            resize();
        }

        data[size++] = value;

    }

    int pop() {
        const int removed_val = data[size - 1];
        size--;

        return removed_val;

    }

    void remove(int index) {

        if (index >= getSize()) {
            return;
        }

        for(int i = index; i < getSize(); i++) {
            data[i] = data[i + 1];
        }

        size--;

    }

    int removeReturn(int index) {

        if (index >= getSize()) {
            return -1;
        }

        int removed_val = data[index];

        for(int i = index; i < getSize(); i++) {
            data[i] = data[i + 1];
        }

        size--;
        return removed_val;
    }

    int min() const {
        int least = data[0];

        for (int i = 0; i < getSize(); i++) {
            if (least > data[i]) {
                least = data[i];
            }
        }

        return least;

    }

    int max() const {
        int greatest = data[0];

        for (int i = 0; i < getSize(); i++) {
            if (greatest < data[i]) {
                greatest = data[i];
            }
        }

        return greatest;

    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << std::endl;
        }
    }

};

int main() {

    auto* arr = new DynamicArray(4);

    arr->append(7);
    arr->append(10);
    arr->append(24);
    arr->append(36);
    arr->append(1);
    arr->append(45);

    delete arr;

    return 0;
}
