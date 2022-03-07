// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB02_MAN_H
#define LAB02_MAN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


class Man {
    char* p_name;
    int birth_year{};
    float pay{};
public:
    explicit Man(size_t size = 20);
    ~Man();

    void SetName(char* name);
    void SetBirthYear(int b);
    void SetPay(float p);

    const char* GetName();
    int GetBirthYear();
    float GetPay();

    friend int read_dbase(char* filename, Man* arr, int& n);

//    friend int menu();

//    friend int menu_f();

    friend void print_dbase(Man* arr, int n);

    friend int write_dbase(char* filename, Man* arr, int n);

    friend int add(Man* arr, int n);
    friend int edit(Man* arr, int n);
    friend int remove(Man* arr, int n);

    friend int find(Man* arr, int n, char* name);

    friend int find(Man* arr, int n, int birth_year);

    friend int find(Man* arr, int n, float pay);

    friend void find_man(Man* arr, int n);
};

#endif //LAB02_MAN_H
