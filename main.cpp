#include <iostream>
#include "Vector.h"
#include <string>

using namespace std;

int main() {
    Vector v1;
    Vector v2;

    for (int i = 0; i < 10; i++)
        v1.push_back(i);
    cout << "Vector 1:" << v1 << endl;

    cout << "copiando v1 in v2"<< endl;
    v2 = v1;

    if (v1 == v2)
        cout << "sono uguali" << endl;

    cout << "moltiplicando dati in v2" << endl;
    for (int i = 0; i < 10; i++)
        v2[i] = i * 10;
    cout << "Vector 2:" << v2 << endl;

    cout << "popping v2...";
    v2.pop_back();
    cout << v2 << endl;

    cout << "inserimento e erase..." << endl;
    v1.insert(3, 82);
    cout << v1 << endl;
    v1.erase(3);
    cout << v1 << endl;

    cout << "resizing v1..." << endl;

    v1.resize(3);
    cout << v1 << endl;

}
