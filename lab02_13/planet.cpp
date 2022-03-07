// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#include "planet.hpp"

AviaTicket::AviaTicket(size_t name_length, int diameter_new, bool life_new, size_t satellites_new) {
    race_name = new char[name_length];
//    strcpy(race_name, name_new);
    price = diameter_new;
    is_business = life_new;
    persons_number = satellites_new;
}

void display(AviaTicket* ats, size_t n) {
    std::cout << std::setw(3) << "N" << std::setw(13) << "Name" << std::setw(12) << "Diameter" << std::setw(7)
              << std::noboolalpha << "Life" << std::setw(14) << "Satellites" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << std::setw(3) << i + 1 << ats[i] << std::endl;
    }
}

size_t read_bd(AviaTicket* pl, char* filename) {
    std::fstream f(filename, std::ios::in);
    if (!f) {
        std::cout << "Error file opening" << std::endl;
        return 0;
    }
    size_t i = 0;
    while (!f.eof()) {
        f >> pl[i];
        ++i;
    }

    return i;
}

void write_bd(AviaTicket* ats, char* filename, size_t n) {
    std::fstream f(filename, std::ios::out);
    size_t i = 0;
    f << ats[i];
    for (i = i + 1; i < n; ++i) {
        f << std::endl << ats[i];
    }
}

AviaTicket::AviaTicket(const AviaTicket& at) {
    race_name = new char[strlen(at.race_name) + 1];
    strcpy(race_name, at.race_name);
    price = at.price;
    is_business = at.is_business;
    persons_number = at.persons_number;
}

AviaTicket& AviaTicket::operator=(const AviaTicket& at) {
    if (this != &at) {
        delete[] race_name;
        race_name = new char[strlen(at.race_name)+1];
        strcpy(race_name, at.race_name);
        price = at.price;
        is_business = at.is_business;
        persons_number = at.persons_number;
    }

    return *this;
}

std::istream& operator>>(std::istream& in, AviaTicket& pl) {
    in >> pl.race_name >> pl.price >> pl.is_business >> pl.persons_number;
    return in;
}

std::ostream& operator<<(std::ostream& out, const AviaTicket& pl) {
    out << std::setw(13) << pl.race_name << std::setw(12) << pl.price << std::setw(7)
        << std::noboolalpha << pl.is_business << std::setw(14) << pl.persons_number;
    return out;
}

bool operator<(const AviaTicket& at1, const AviaTicket& at2) {
    return (strcmp(at1.race_name, at2.race_name) < 0);
}

bool operator==(const AviaTicket& at1, const AviaTicket& at2) {
    return (strcmp(at1.race_name, at2.race_name) == 0) && (at1.price == at2.price) &&
           (at1.is_business == at2.is_business) &&
           (at1.persons_number == at2.persons_number);
}

//void AviaTicket::set_name(char* str) {
//    delete[] race_name;
//    race_name = new char[strlen(str) + 1];
//    strcpy(race_name, str);
//}

void sort_bd(AviaTicket* ats, size_t n) {
    std::sort(ats, ats + n);
}

void duplicate_one(AviaTicket* ats, size_t n) {
    display(ats, n);
    size_t duplicate_number;
    std::cout << "Input number to duplicate:";
    std::cin >> duplicate_number;
    if (duplicate_number > n) {
        std::cout << "Invalid number" << std::endl;
        return;
    }
    ats[duplicate_number] = ats[duplicate_number - 1];
    ++n;
}
