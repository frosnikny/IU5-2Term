/*� ��������� ����� �������� ���� ������ ������ �����������. �� ����������� �� ����� 100 �����������.
������ ������ ����� �������� ������ �� ����� ����������. ������ ������ � ����� �
����������� ����� �����������. ������ ������:
	������� (�� ����� 20 �������),
	��� �������� (4 �������),
	����� (�� ����� 8 �������).
�������� ���������, ������� ��������� �� �������� �� ����� �������� � �����������,
��������� � ������� ����������� �� ��, �������������� ������ � �����������.
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

//----------------------------------------  ������� �������
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 100;
    Man arr[N];
    char* filename = new char[10];
    strcpy(filename, "dbase.txt");
    int n;
    //������ �� � ��
    if (read_dbase(filename, arr, n)) {
        cout << "������ ������ ��" << endl;
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
                cout << " ������������ ����� ��������" << endl;
                break;
        }
    }
    return 0;
}

////////////////////////////////////////////////////////
int menu() {
    cout << " ============== ������� ���� ========================\n";
    cout << "1 - ���������� ����������\t 4 - ������������� ��������" << endl;
    cout << "2 - �������� co�py����a\t\t 5 - ����� ���� �� �����" << endl;
    cout << "3 - ����� ����������\t\t 6 - ����� ���� � ����" << endl;
    cout << "\t\t\t 7 - �����" << endl;
    cout << "��� ������ �������� ������� ����� �� 1 �� 7" << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

int add(Man* arr, int n) {
    cout << "������� ���: ";
    cin >> arr[n].p_name;
    cout << "������� ��� ��������: ";
    cin >> arr[n].birth_year;
    cout << "������� ������: ";
    cin >> arr[n].pay;
    return ++n;
}
int edit(Man* arr, int n) {
    print_dbase(arr, n);
    int person;
    cout << "������� ����� ��������, �������� ������ �������:";
    cin >> person;
    --person;

    int number;
    cout << "��� ������ ��������?" << std::endl;
    cout << "1. ���" << std::endl;
    cout << "2. ��� ��������" << std::endl;
    cout << "3. ��������" << std::endl;
    cin >> number;
    switch (number) {
        case 1:
            cout << "������� ����� ���:";
            cin >> arr[person].p_name;
            break;
        case 2:
            cout << "������� ����� ��� ��������:";
            cin >> arr[person].birth_year;
            break;
        case 3:
            cout << "������� ����� ��������:";
            cin >> arr[person].pay;
            break;
        default:
            cout << "����� �������������� �����";
            break;
    }
    return 0;
}
int remove(Man* arr, int n) {
//    --n;
    print_dbase(arr, n);
    int del;
    cout << "������� ����� ��������, �������� ������ �������:";
    cin >> del;
    --del;
    for (size_t i = del+1; i < n; ++i) {
        arr[i-1] = arr[i];
    }
    return n-1;
}

// ------------------------------------	������ ���� �� �����
int read_dbase(char* filename, Man* arr, int& n) {
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "He� ����� " << filename << endl;
        return 1;
    }
    fin >> n;
    if (n > 100) {
        cout << "������������ ��. n= " << n << endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
        fin >> arr[i].p_name >> arr[i].birth_year >> arr[i].pay;

    fin.close();
    return 0;
}

//------------------------------------	����� ���� � ����
int write_dbase(char* filename, Man* arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "������ �������� �����" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i].p_name << ' ' << arr[i].birth_year << ' ' << arr[i].pay << endl;

    fout.close();
    return 0;
}

//------------------------------ ����� ���� �� �����
void print_dbase(Man* arr, int n) {
    cout << " ���� ������ " << endl;
    for (int i = 0; i < n; ++i)
        cout << setw(3) << i + 1 << ". " << arr[i].p_name << setw(20 - strlen(arr[i].p_name) + 6)
             << arr[i].birth_year << setw(10) << arr[i].pay << endl;
}

//-----------------------------����� ���������� � ������ �� �������
int find(Man* arr, int n, char* name) //���������� ����� �������� � ������� �
//���������� � ��,������������� � ���� �������
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

//------- ����� � ����� ����� ������� �� �������� �����������
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

//-------- ����� � ����� ����������� � �������, ������� ��� "pay"
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
    cout << "\n----------------- ����� -----------------\n";
    cout << "1 - ����� �� �������	 2 - �� ���� ��������\n"
         << "3 - �� ������		 4 - ����� ������\n ";
    cout << "��� ������ �������� ������� ����� �� 1 �� 4\n";
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

//-------------------------------------	 �����
void find_man(Man* arr, int n) {
    char* buf;
    int birth_year;
    float pay;

    while (true) {
        switch (menu_f()) {
            case 1:
                cout << "������� ������� ����������\n";
                buf = new char[100];
                cin >> buf;
                if (find(arr, n, buf) < 0)
                    cout << "���������� � �������� " << buf << " � ������ ���\n";
                break;
            case 2:
                cout << "������� ��� ��������" << endl;
                cin >> birth_year;
                if (find(arr, n, birth_year) < 0)
                    cout << "� ������ ��� �����������, ���������� �� "
                         << birth_year << " ����\n";
                break;
            case 3:
                cout << "������� �����" << endl;
                cin >> pay;
                if (find(arr, n, pay) < 0)
                    cout << "� ������ ��� ����������� � �������, ������� "
                         << pay << " ���.\n";
                break;
            case 4:
                return;
            default:
                cout << "�������� ����\n";
        }

    }
}
