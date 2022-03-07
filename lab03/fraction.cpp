// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#include "fraction.hpp"

fraction& fraction::operator+=(const fraction& value) {
//    const fraction& new_fr(value);
    *this = *this + value;
    return *this;
}

fraction& fraction::operator+=(int value) {
    fraction new_fr(value);
    *this = *this + new_fr;
    return *this;
}

fraction& fraction::operator+=(double value) {
    fraction new_fr(value);
    *this = *this + new_fr;
    return *this;
}

fraction::fraction(const fraction& fr) {
    numerator = fr.numerator;
    denominator = fr.denominator;
}

fraction::fraction(int numerator_int, int denominator_int) {
    numerator = numerator_int;
    denominator = denominator_int;
}

fraction::fraction(double dbl) {
    numerator = static_cast<int>(dbl * 10000);
    denominator = 10000;
}

fraction::fraction(const char* str_old) {
    char* str = new char[strlen(str_old) + 1];
    strcpy(str, str_old);
    char* str_temp = new char[strlen(str) + 1];
    size_t i = 0;
    while (*str != ' ' && *str != '/') {
        str_temp[i] = *str;
        ++i;
        ++str;
    }
    str_temp[i] = '\0';
    int whole_value = 0;
    if (*str == ' ') {
        whole_value = std::stoi(str_temp);
        i = 0;
        ++str;
        while (*str != '/') {
            str_temp[i] = *str;
            ++i;
            ++str;
        }
        str_temp[i] = '\0';
    }
    numerator = std::stoi(str_temp);
    i = 0;
    ++str;
    while (*str != '\0') {
        str_temp[i] = *str;
        ++i;
        ++str;
    }
    str_temp[i] = '\0';
    denominator = std::stoi(str_temp);
    numerator += abs(whole_value * denominator);
    numerator = (whole_value >= 0) ? numerator : -numerator;
    delete[] str_temp;
}

std::ostream& operator<<(std::ostream& out, fraction& fr) {
    int whole = fr.reduction();
    if (whole == 0) {
        if (fr.numerator == 0) {
            out << 0;
            return out;
        }
        out << fr.numerator << '/' << fr.denominator;
        return out;
    }
    if (fr.numerator % fr.denominator != 0) {
        if (fr.numerator > 0) {
            out << whole << ' ' << fr.numerator - whole * fr.denominator << '/' << fr.denominator;
            return out;
        }

        out << -whole << ' ' << -(fr.numerator + whole * fr.denominator) << '/' << fr.denominator;
        return out;
    }
    out << whole;
    return out;
}

std::istream& operator>>(std::istream& in, fraction& fr) {
    char* str = new char[100];
    in.getline(str, 100);
    fraction fr_new(str);
    fr = fr_new;
    return in;
}

int fraction::reduction() {
    if (numerator == 0) {
        return 0;
    }
    int whole_part = static_cast<int>(numerator / denominator);
    numerator = numerator - denominator * whole_part;
    if (numerator == 0) {
        numerator = denominator * whole_part;
        return whole_part;
    }

    int temp_numerator = abs(numerator);
    int temp_denominator = abs(denominator);
//    int mod = 0;
//    mod = temp_numerator % temp_denominator;
    while (temp_numerator != temp_denominator) {
        temp_denominator -= temp_numerator;
        if (temp_numerator > temp_denominator) {
            std::swap(temp_denominator, temp_numerator);
        }
//        mod = temp_numerator % temp_denominator;
    }

    denominator = denominator / temp_numerator;
    numerator = numerator / temp_numerator + whole_part * denominator;
    return abs(whole_part);
}

fraction operator+(const fraction& fr1, const fraction& fr2) {
    fraction new_fr;
    if (fr1.denominator == fr2.denominator) {
        new_fr.denominator = fr1.denominator;
        new_fr.numerator = fr1.numerator + fr2.numerator;
        return new_fr;
    }
    new_fr.denominator = fr1.denominator * fr2.denominator;
    new_fr.numerator = fr1.numerator * fr2.denominator + fr2.numerator * fr1.denominator;
    return new_fr;
}


fraction operator+(double dbl, const fraction& fr) {
    fraction new_fr(dbl);
    return new_fr + fr;
}

fraction operator+(int value, const fraction& fr) {
    fraction new_fr(value, 1);
    return new_fr + fr;
}

fraction operator+(const fraction& fr, double dbl) {
    return dbl + fr;
}

fraction operator+(const fraction& fr, int value) {
    return value + fr;
}
