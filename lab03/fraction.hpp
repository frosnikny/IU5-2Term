// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB03_FRACTION_HPP
#define LAB03_FRACTION_HPP

#include <iostream>
#include <cstring>

class fraction {
    int numerator{};
    int denominator{1};
public:
    fraction() = default;

    fraction(const fraction&);

    fraction(const char*);

    explicit fraction(int, int);

    fraction(double);

    friend fraction operator+(const fraction&, const fraction&);

    friend fraction operator+(const fraction&, double);

    friend fraction operator+(const fraction&, int);

    friend fraction operator+(double, const fraction&);

    friend fraction operator+(int, const fraction&);

    fraction& operator+=(const fraction&);

    fraction& operator+=(int);

    fraction& operator+=(double);

    friend std::ostream& operator<<(std::ostream&, fraction&);

    friend std::istream& operator>>(std::istream&, fraction&);

    int reduction();
};


#endif //LAB03_FRACTION_HPP
