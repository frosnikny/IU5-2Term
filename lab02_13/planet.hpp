// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB02_12_PLANET_HPP
#define LAB02_12_PLANET_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

class AviaTicket {
    char* race_name{};
    int price;
    bool is_business;
    size_t persons_number;
public:
    AviaTicket(const AviaTicket& at);

    explicit AviaTicket(size_t name_length = 30, int diameter_new = -1, bool life_new = -1, size_t satellites_new = -1);

    AviaTicket& operator=(const AviaTicket& at);

    friend bool operator<(const AviaTicket& at1, const AviaTicket& at2);

    friend bool operator==(const AviaTicket& at1, const AviaTicket& at2);

    friend std::istream& operator>>(std::istream&, AviaTicket&);

    friend std::ostream& operator<<(std::ostream&, const AviaTicket&);

    void set_race_name(char* new_value) {
        delete[] race_name;
        race_name = new char[strlen(new_value) + 1];
        strcpy(race_name, new_value);
    };

    void set_price(int new_value) { price = new_value; };

    void set_business(bool new_value) { is_business = new_value; };

    void set_persons_number(size_t new_value) { persons_number = new_value; };

    char* get_race_name() { return race_name; };

    int get_price() { return price; };

    bool get_business() { return is_business; };

    size_t get_persons_number() { return persons_number; };

//    void set_name(char*);
};

size_t read_bd(AviaTicket*, char* filename);

void write_bd(AviaTicket*, char* filename, size_t n);

void duplicate_one(AviaTicket* ats, size_t n);

void sort_bd(AviaTicket*, size_t);

void display(AviaTicket*, size_t n);

#endif //LAB02_12_PLANET_HPP
