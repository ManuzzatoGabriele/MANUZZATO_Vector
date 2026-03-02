
#include "Vector.h"

#include <cstdlib>

Vector::Vector()
    : first{new int[0]}, size{0}, capacity{0} {}

Vector::Vector(int capacity)
: first{new int[capacity]}, size{0}, capacity{capacity} {
    for (int i = 0; i < size; i++)
        first[i] = 0;
}

Vector::Vector(const Vector &other)
    : first{other.first}, size{other.size}, capacity{other.capacity} {}

int Vector::getSize() const { return capacity; }
int Vector::getCapacity() const { return capacity; }

void Vector::push_back(int element) {
    if (size >= capacity)
        reallocate();

    first[size++] = element;
}

int Vector::pop_back() {
    return first[size--];
}

void Vector::clear() {
    size = 0;
}

void Vector::reallocate() {
    capacity = capacity == 0 ? 1 : capacity * 2;

    int* newFirst = new int[capacity];

    for (int i = 0; i < size; i++)
        newFirst[i] = first[i];

    delete[] first;
    first = newFirst;
}









