// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB05_MYSET_HPP
#define LAB05_MYSET_HPP

#include <iostream>
#include "MyVector.hpp"

template <class T>
class MySet : public MyVector<T> {
public:
    MySet() = default;
    explicit MySet(int size) : MyVector<T>(size) {};
    explicit MySet(char* el, int size = MAX_SIZE) : MyVector<char*>(el, size) {};

    template<class T1>
    friend std::ostream& operator<<(std::ostream& out, MySet<T1>& s);

    template<class T1>
    friend MySet<T1> operator+(MySet<T1>& s1, MySet<T1>& s2);

    friend MySet<char*> operator+(MySet<char*>& s1, MySet<char*>& s2);

    template<class T1>
    friend MySet<T1> operator-(MySet<T1>& s1, MySet<T1>& s2);

    template<class T1>
    friend MySet<T1> operator*(MySet<T1>& s1, MySet<T1>& s2);

    bool operator==(MySet& s);

    MySet& operator+=(MySet& s);

    MySet& operator-=(MySet& s);

    MySet& operator*=(MySet& s);

    void add_element(T el);

    void delete_element(T el);

    bool is_element_char(char* el);
    bool is_element(T el);

private:
    int q_find_str(char* el);
    int q_find(const T& el);
};

#include "MySet.inl"

#endif //LAB05_MYSET_HPP
