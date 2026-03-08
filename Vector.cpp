
#include "Vector.h"

#include <cstdlib>
#include <stdexcept>
#include <iostream>

Vector::Vector()
    : data{new int[0]}, size{0}, capacity{0} {}

Vector::Vector(int capacity)
: data{new int[capacity]}, size{0}, capacity{capacity} {
    for (int i = 0; i < size; i++)
        data[i] = 0;
}

Vector::Vector(const Vector &other)
    : data{new int[other.capacity]}, size{other.size}, capacity{other.capacity} {
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

Vector::~Vector() {
    delete[] data;
}


int Vector::getSize() const { return size; }
int Vector::getCapacity() const { return capacity; }
bool Vector::isEmpty() const { return size == 0; }

void Vector::push_back(int element) {
    if (size >= capacity)
        reallocate();

    data[size++] = element;
}

void Vector::pop_back() {
    if (isEmpty())
        throw std::out_of_range("Vector is empty");
    size--;
}

void Vector::clear() {
    size = 0;
}

void Vector::resize(int newSize) {
    if (newSize < 0)
        throw std::out_of_range("Invalid vector size");

    if (newSize >= capacity)
        reserve(newSize);

    for (int i = size; i < newSize; i++)
        data[i] = 0;

    size = newSize;
}

void Vector::reserve(int newCapacity) {
    if (newCapacity <= capacity)
        return;

    int *newData = new int[newCapacity];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

int& Vector::at(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return data[index];
}

const int& Vector::at(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return data[index];
}

int& Vector::operator[](int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return data[index];
}

const int& Vector::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    return data[index];
}

void Vector::sort() {
    sort(true);
}

void Vector::sort(bool ascending) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool swap = ascending ? data[j] > data[i] : data[i] < data[j];
            if (swap) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void Vector::reverse() {
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int temp = data[right];
        data[right] = data[left];
        data[left] = temp;
        right--;
        left++;
    }
}

int Vector::find(int value) const
{
    if (isEmpty())
        return -1;

    for (int i = 0; i < size; i++)
        if (data[i] == value) return i;

    return -1;
}

bool Vector::contains(int value) const
{
    if (isEmpty())
        return false;

    for (int i = 0; i < size; i++)
        if (data[i] == value) return true;

    return false;
}

void Vector::insert(int index, int value) {
    if (isEmpty() || index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    if (size >= capacity)
        reallocate();

    for (int i = size; i > index; i--)
        data[i] = data[i - 1];

    data[index] = value;
    size++;
}

void Vector::erase(int index) {
    if (isEmpty() || index < 0 || index >= size)
        throw std::out_of_range("Invalid index");

    for (int i = index; i < size - 1; i++)
        data[i] = data[i + 1];

    size--;
}



Vector& Vector::operator=(const Vector& other)
{
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << "[";

    for (int i = 0; i < v.size; i++) {
        os << v.data[i];
        if (i != v.size - 1) os << ", ";
    }

    os << "]";
    return  os;
}


bool Vector::operator==(const Vector& other) const {
    if (size != other.size)
        return false;

    for (int i = 0; i < size; i++)
        if (data[i] != other.data[i]) return false;

    return true;
}


void Vector::reallocate() {
    capacity = capacity == 0 ? 1 : capacity * 2;

    int* newFirst = new int[capacity];

    for (int i = 0; i < size; i++)
        newFirst[i] = data[i];

    delete[] data;
    data = newFirst;
}









