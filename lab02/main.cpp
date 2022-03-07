/*В текстовом файле хранится база отдела кадров предприятия. На предприятии не более 100 сотрудников.
Каждая строка файла содержит запись об одном сотруднике. Первая запись в файле –
фактическое число сотрудников. Формат записи:
	фамилия (не более 20 позиций),
	год рождения (4 позиции),
	оклад (не более 8 позиций).
Написать программу, которая позволяла бы выводить на экран сведения о сотрудниках,
добавлять и удалять сотрудников из БД, корректировать данные о сотрудниках.
*/

#include "Man.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

int menu();

int menu_f();

//----------------------------------------  Главная функция
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 100;
    Man arr[N];
    char* filename = new char[10];
    strcpy(filename, "dbase.txt");
    int n;
    //чтение БД в ОП
    if (read_dbase(filename, arr, n)) {
        cout << "Ошибка чтения БД" << endl;
        return 1;
    }
    print_dbase(arr, n);
    while (true) {
        switch (menu()) {
            case 1:
                n = add(arr, n);
                break;
            case 2:
                n = remove(arr, n);
                break;
            case 3:
                find_man(arr, n);
                break;
            case 4:
                edit(arr, n);
                break;
            case 5:
                print_dbase(arr, n);
                break;
            case 6:
                write_dbase(filename, arr, n);
                break;
            case 7:
                return 0;
            default:
                cout << " Недопустимый номер операции" << endl;
                break;
        }
    }
    return 0;
}

////////////////////////////////////////////////////////
int menu() {
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - добавление сотрудника\t 4 - корректировка сведений" << endl;
    cout << "2 - удаление coтpyдникa\t\t 5 - вывод базы на экран" << endl;
    cout << "3 - поиск сотрудника\t\t 6 - вывод базы в файл" << endl;
    cout << "\t\t\t 7 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 7" << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

int add(Man* arr, int n) {
    cout << "Введите имя: ";
    cin >> arr[n].p_name;
    cout << "Введите год рождения: ";
    cin >> arr[n].birth_year;
    cout << "Введите оплату: ";
    cin >> arr[n].pay;
    return ++n;
}
int edit(Man* arr, int n) {
    print_dbase(arr, n);
    int person;
    cout << "Введите номер человека, которого хотите удалить:";
    cin >> person;
    --person;

    int number;
    cout << "Что хотите изменить?" << std::endl;
    cout << "1. Имя" << std::endl;
    cout << "2. Год рождения" << std::endl;
    cout << "3. Зарплата" << std::endl;
    cin >> number;
    switch (number) {
        case 1:
            cout << "Введите новое имя:";
            cin >> arr[person].p_name;
            break;
        case 2:
            cout << "Введите новый год рождения:";
            cin >> arr[person].birth_year;
            break;
        case 3:
            cout << "Введите новую зарплату:";
            cin >> arr[person].pay;
            break;
        default:
            cout << "Введён несуществующий номер";
            break;
    }
    return 0;
}
int remove(Man* arr, int n) {
//    --n;
    print_dbase(arr, n);
    int del;
    cout << "Введите номер человека, которого хотите удалить:";
    cin >> del;
    --del;
    for (size_t i = del+1; i < n; ++i) {
        arr[i-1] = arr[i];
    }
    return n-1;
}

// ------------------------------------	Чтение базы из файла
int read_dbase(char* filename, Man* arr, int& n) {
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Heт файла " << filename << endl;
        return 1;
    }
    fin >> n;
    if (n > 100) {
        cout << "Переполнение БД. n= " << n << endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
        fin >> arr[i].p_name >> arr[i].birth_year >> arr[i].pay;

    fin.close();
    return 0;
}

//------------------------------------	Вывод базы в файл
int write_dbase(char* filename, Man* arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i].p_name << ' ' << arr[i].birth_year << ' ' << arr[i].pay << endl;

    fout.close();
    return 0;
}

//------------------------------ Вывод базы на экран
void print_dbase(Man* arr, int n) {
    cout << " База Данных " << endl;
    for (int i = 0; i < n; ++i)
        cout << setw(3) << i + 1 << ". " << arr[i].p_name << setw(20 - strlen(arr[i].p_name) + 6)
             << arr[i].birth_year << setw(10) << arr[i].pay << endl;
}

//-----------------------------Поиск сотрудника в списке по фамилии
int find(Man* arr, int n, char* name) //возвращает индес элемента с данными о
//сотруднике в БД,реализованной в виде массива
{
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (!strcmp(arr[i].p_name, name)) {
            cout << arr[i].p_name << setw(20 - strlen(arr[i].p_name) + 6)
                 << arr[i].birth_year << setw(10) << arr[i].pay << endl;
            ind = i;
        }
    return ind;
}

//------- Поиск и вывод более старших по возрасту сотрудников
int find(Man* arr, int n, int birth_year) {
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (arr[i].birth_year < birth_year) {
            ind = i;
            cout << arr[i].p_name << setw(20 - strlen(arr[i].p_name) + 6)
                 << arr[i].birth_year << setw(10) << arr[i].pay << endl;
        }
    return ind;
}

//-------- Поиск и вывод сотрудников с окладом, большим чем "pay"
int find(Man* arr, int n, float pay) {
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (arr[i].pay > pay) {
            ind = i;
            cout << arr[i].p_name << setw(20 - strlen(arr[i].p_name) + 6)
                 << arr[i].birth_year << setw(10) << arr[i].pay << endl;
        }
    return ind;
}

//--------------------------------------
int menu_f() {
    cout << "\n----------------- ПОИСК -----------------\n";
    cout << "1 - поиск по фамилии	 2 - по году рождения\n"
         << "3 - по окладу		 4 - конец поиска\n ";
    cout << "Для выбора операции введите число от 1 до 4\n";
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

//-------------------------------------	 Поиск
void find_man(Man* arr, int n) {
    char* buf;
    int birth_year;
    float pay;

    while (true) {
        switch (menu_f()) {
            case 1:
                cout << "Введите фамилию сотрудника\n";
                buf = new char[100];
                cin >> buf;
                if (find(arr, n, buf) < 0)
                    cout << "Сотрудника с фамилией " << buf << " в списке нет\n";
                break;
            case 2:
                cout << "Введите год рождения" << endl;
                cin >> birth_year;
                if (find(arr, n, birth_year) < 0)
                    cout << "В списке нет сотрудников, родившихся до "
                         << birth_year << " года\n";
                break;
            case 3:
                cout << "Введите оклад" << endl;
                cin >> pay;
                if (find(arr, n, pay) < 0)
                    cout << "В списке нет сотрудников с окладом, большим "
                         << pay << " руб.\n";
                break;
            case 4:
                return;
            default:
                cout << "Неверный ввод\n";
        }

    }
}
