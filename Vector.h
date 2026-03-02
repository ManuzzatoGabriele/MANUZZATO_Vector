#ifndef MANUZZATO_VECTOR_VECTOR_H
#define MANUZZATO_VECTOR_VECTOR_H
class Vector {
public:
    Vector();
    Vector(int capacity);
    Vector(const Vector& other);
    ~Vector() = default;

    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;

    void push_back(int value);
    int pop_back();
    void clear();
    void resize(int newSize);
    void reserve(int newCapacity);

private:
    int *first;
    int size;
    int capacity;

    void reallocate();
};
#endif