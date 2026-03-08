#ifndef MANUZZATO_VECTOR_VECTOR_H
#define MANUZZATO_VECTOR_VECTOR_H
#include <iosfwd>

class Vector {
public:
    Vector();
    Vector(int capacity);
    Vector(const Vector& other);
    ~Vector();

    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;

    void push_back(int value);
    void pop_back();
    void clear();
    void resize(int newSize);
    void reserve(int newCapacity);

    int& at(int index);
    const int& at(int index) const;
    int& operator[](int index);
    const int& operator [](int index) const;

    void sort();
    void sort(bool ascending);
    void reverse();
    int find(int value) const;
    bool contains(int value) const;

    Vector& operator=(const Vector& other);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    void insert(int index, int value);
    void erase(int index);
    bool operator==(const Vector& other) const;

private:
    int *data;
    int size;
    int capacity;

    void reallocate();
};
#endif