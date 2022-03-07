// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#include "planet.hpp"

Planet::Planet(size_t name_length, int diameter_new, bool life_new, size_t satellites_new) {
    name = new char[name_length];
//    strcpy(name, name_new);
    diameter = diameter_new;
    life = life_new;
    satellites_number = satellites_new;
}

void add_one(Planet* pls, size_t& n) {
    std::cout << "Input new name:";
    std::cin >> pls[n].name;
    std::cout << "Input new diameter:";
    std::cin >> pls[n].diameter;
    std::cout << "Input answer on question \"Is there life on this planet?\" (0 - no, 1 - yes):";
    std::cin >> pls[n].life;
    std::cout << "Input number of satellites of this planet:";
    std::cin >> pls[n].satellites_number;
    ++n;
}

void delete_one(Planet* pls, size_t& n) {
    display(pls, n);
    size_t deleting_number;
    std::cout << "Input number(N) for delete:";
    std::cin >> deleting_number;
    if (deleting_number > n) {
        return;
    }
    for (size_t i = deleting_number; i < n; ++i) {
        pls[i - 1] = pls[i];
    }
    --n;
}

void change_bd(Planet* pls, size_t n) {
    display(pls, n);
    size_t changing_number;
    std::cout << "Input number(N) for change:";
    std::cin >> changing_number;
    if (changing_number > n) {
        return;
    }
    std::cout << "What do you want to change?" << std::endl;
    std::cout << "1. Name" << std::endl;
    std::cout << "2. Diameter" << std::endl;
    std::cout << "3. Life" << std::endl;
    std::cout << "4. Satellites number" << std::endl;
    int change_point;
    std::cin >> change_point;

    std::cout << "Input new:" << std::endl;
    switch (change_point) {
        case 1:
            std::cin >> pls[changing_number - 1].name;
            break;
        case 2:
            std::cin >> pls[changing_number].diameter;
            break;
        case 3:
            std::cin >> pls[changing_number].life;
            break;
        case 4:
            std::cin >> pls[changing_number].satellites_number;
            break;
        default:
            std::cout << "Error number" << std::endl;
            break;
    }
}

void display(Planet* pls, size_t n) {
    std::cout << std::setw(3) << "N" << std::setw(13) << "Name" << std::setw(12) << "Diameter" << std::setw(7)
              << std::noboolalpha << "Life" << std::setw(14) << "Satellites" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << std::setw(3) << i + 1 << pls[i] << std::endl;
    }
}

size_t read_bd(Planet* pl, char* filename) {
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

void write_bd(Planet* pls, char* filename, size_t n) {
    std::fstream f(filename, std::ios::out);
    size_t i = 0;
    f << pls[i];
    for (i = i + 1; i < n; ++i) {
        f << std::endl << pls[i];
    }
}

Planet::Planet(const Planet& pl) {
//    if (this != &pl) {
        name = new char[30];
        strcpy(name, pl.name);
        diameter = pl.diameter;
        life = pl.life;
        satellites_number = pl.satellites_number;
//    }
}

Planet& Planet::operator=(const Planet& pl) {
    if (this != &pl) {
        strcpy(name, pl.name);
        diameter = pl.diameter;
        life = pl.life;
        satellites_number = pl.satellites_number;
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Planet& pl) {
    in >> pl.name >> pl.diameter >> pl.life >> pl.satellites_number;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Planet& pl) {
    out << std::setw(13) << pl.name << std::setw(12) << pl.diameter << std::setw(7)
              << std::noboolalpha << pl.life << std::setw(14) << pl.satellites_number;
    return out;
}

bool operator<(const Planet& pl1, const Planet& pl2) {
    return (strcmp(pl1.name, pl2.name) < 0);
}

bool operator==(const Planet& pl1, const Planet& pl2) {
    return (strcmp(pl1.name, pl2.name) == 0) && (pl1.diameter == pl2.diameter) && (pl1.life == pl2.life) &&
           (pl1.satellites_number == pl2.satellites_number);
}

void Planet::set_name(char* str) {
    strcpy(name, str);
}

void sort_bd(Planet* pls, size_t n) {
    std::sort(pls, pls + n);
}

void duplicate_one(Planet* pls, size_t n) {
    display(pls, n);
    size_t duplicate_number;
    std::cout << "Input number to duplicate:";
    std::cin >> duplicate_number;
    if (duplicate_number > n) {
        std::cout << "Invalid number" << std::endl;
        return;
    }
    pls[duplicate_number] = pls[duplicate_number - 1];
    ++n;
}
