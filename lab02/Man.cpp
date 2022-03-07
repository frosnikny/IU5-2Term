// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#include "Man.h"

Man::Man(size_t size) {
    p_name = new char[size];
}

Man::~Man() {
    delete[] p_name;
}


void Man::SetName(char* name) {
    strcpy(p_name, name);
}

void Man::SetBirthYear(int b) {
    birth_year = b;
}

void Man::SetPay(float p) {
    pay = p;
}

const char* Man::GetName() {
    return p_name;
}

int Man::GetBirthYear() {
    return birth_year;
}

float Man::GetPay() {
    return pay;
}
