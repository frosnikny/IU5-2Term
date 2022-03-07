// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB05_MYVECTOR_HPP
#define LAB05_MYVECTOR_HPP

#include <iostream>
#include <cstring>

const int MAX_SIZE = 5;

template<class T>
class MyVector {
public:
//    explicit MyVector(char* el = nullptr, int maxsz = MAX_SIZE);

    MyVector() {
        maxsize = MAX_SIZE;
        size = 0;
        pdata = new T[maxsize];
    }

    explicit MyVector(char* el, int maxsz = MAX_SIZE);

    explicit MyVector(int maxsz);

    MyVector(MyVector& v);

    ~MyVector();

    void add_element(T el);

    bool delete_element(int i);

    T operator[](int i);

    void sort();

    int Size() const { return size; }

    int Maxsize() const { return maxsize; }

    int find(const char* el);

    MyVector& operator=(const MyVector<T>& v);

    template<class T1>
    friend std::ostream& operator<<(std::ostream& out, const MyVector<T1>& v);

protected:
    int maxsize{};
    int size{};
    T* pdata{};
private:
    void resize();
};

#include "MyVector.inl"

#endif //LAB05_MYVECTOR_HPP
