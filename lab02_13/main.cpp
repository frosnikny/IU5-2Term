#include "header.hpp"

int main() {
    auto* ats = new AviaTicket[100];
    auto filename = new char[20];
    strcpy(filename, "file.txt");
    size_t length = read_bd(ats, filename);
    display(ats, length);

   int menu_point;
   while (true) {
       std::cout << "MENU" << std::endl;
       std::cout << "1. Add new raice" << std::endl;
       std::cout << "2. Delete old raice" << std::endl;
       std::cout << "3. Change raice" << std::endl;
       std::cout << "4. Duplicate raice" << std::endl;
       std::cout << "5. Sort raices" << std::endl;
       std::cout << "6. Display raices" << std::endl;
       std::cout << "7. Save raices to file" << std::endl;
       std::cout << "8. Exit" << std::endl;
       std::cin >> menu_point;
       switch (--menu_point) {
           case ADD:
               add_one(ats, length);
               break;
           case DELETE:
               delete_one(ats, length);
               break;
           case CHANGE:
               change_bd(ats, length);
               break;
           case DUPLICATE:
               duplicate_one(ats, length);
               break;
           case SORT:
               sort_bd(ats, length);
               break;
           case DISPLAY:
               display(ats, length);
               break;
           case SAVE:
               write_bd(ats, filename, length);
               break;
           case EXIT:
               delete[] ats;
               return 0;
           default:
               std::cout << "Error menu point" << std::endl;
               break;
       }
   }
}

void add_one(AviaTicket* ats, size_t& n) {
    std::cout << "Input new race name:";
    char* str = new char[100];
    std::cin >> str;
    ats[n].set_race_name(str);
    delete[] str;
    std::cout << "Input new price:";
    int new_price;
    std::cin >> new_price;
    std::cout << "Input answer on question \"Is this ticket for business class?\" (0 - no, 1 - yes):";
    bool new_is_business;
    std::cin >> new_is_business;
    std::cout << "Input number of persons:";
    size_t new_persons_number;
    std::cin >> new_persons_number;
    ats[n].set_price(new_price);
    ats[n].set_business(new_is_business);
    ats[n].set_persons_number(new_persons_number);
    ++n;
}

void delete_one(AviaTicket* ats, size_t& n) {
    display(ats, n);
    size_t deleting_number;
    std::cout << "Input number(N) for delete:";
    std::cin >> deleting_number;
    if (deleting_number > n) {
        return;
    }
    for (size_t i = deleting_number; i < n; ++i) {
        ats[i - 1] = ats[i];
    }
    --n;
}

void change_bd(AviaTicket* ats, size_t n) {
    display(ats, n);
    size_t changing_number;
    std::cout << "Input number(N) for change:";
    std::cin >> changing_number;
    if (changing_number > n) {
        return;
    }
    std::cout << "What do you want to change?" << std::endl;
    std::cout << "1. Race name" << std::endl;
    std::cout << "2. Price" << std::endl;
    std::cout << "3. Business" << std::endl;
    std::cout << "4. Persons number" << std::endl;
    int change_point;
    std::cin >> change_point;

    std::cout << "Input new:" << std::endl;
    switch (change_point) {
        case 1: {
            char* str = new char[100];
            std::cin >> str;
            ats[changing_number-1].set_race_name(str);
            delete[] str;
            break;
        }
        case 2: {
            int new_price;
            std::cin >> new_price;
            ats[changing_number-1].set_price(new_price);
            break;
        }
        case 3: {
            bool new_is_business;
            std::cin >> new_is_business;
            ats[changing_number-1].set_business(new_is_business);
            break;
        }
        case 4: {
            size_t new_persons_number;
            std::cin >> new_persons_number;
            ats[changing_number-1].set_persons_number(new_persons_number);
            break;
        }
        default: {
            std::cout << "Error number" << std::endl;
            break;
        }
    }
}
