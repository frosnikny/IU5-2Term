// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB02_12_HEADER_HPP
#define LAB02_12_HEADER_HPP

#include <iostream>
#include "planet.hpp"

enum Menu {
    ADD,
    DELETE,
    CHANGE,
    DUPLICATE,
    SORT,
    DISPLAY,
    SAVE,
    EXIT
};

void add_one(AviaTicket*, size_t&);

void delete_one(AviaTicket*, size_t&);

void change_bd(AviaTicket*, size_t);

#endif //LAB02_12_HEADER_HPP
