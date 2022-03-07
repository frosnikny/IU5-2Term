// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB02_12_PLANET_HPP
#define LAB02_12_PLANET_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

class Planet {
    char* name {};
    int diameter;
    bool life;
    size_t satellites_number;
public:
    Planet(const Planet& pl);

    explicit Planet(size_t name_length = 30, int diameter_new = -1, bool life_new = -1, size_t satellites_new = -1);

    Planet& operator=(const Planet& pl);

    friend bool operator<(const Planet& pl1, const Planet& pl2);

    friend bool operator==(const Planet& pl1, const Planet& pl2);

    friend std::istream& operator>>(std::istream&, Planet&);

    friend std::ostream& operator<<(std::ostream&, const Planet&);

    friend void add_one(Planet*, size_t&);

    friend void delete_one(Planet*, size_t&);

    friend void change_bd(Planet*, size_t);

    void set_name(char*);
};

size_t read_bd(Planet*, char* filename);

void write_bd(Planet*, char* filename, size_t n);

void duplicate_one(Planet* pls, size_t n);

void sort_bd(Planet*, size_t);

void display(Planet*, size_t n);

#endif //LAB02_12_PLANET_HPP
