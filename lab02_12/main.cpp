#include "header.hpp"

int main() {
    auto* pls = new Planet[100];
    auto filename = new char[20];
    strcpy(filename, "file.txt");
    size_t length = read_bd(pls, filename);
    display(pls, length);

    int menu_point;
    while (true) {
        std::cout << "MENU" << std::endl;
        std::cout << "1. Add new planet" << std::endl;
        std::cout << "2. Delete old planet" << std::endl;
        std::cout << "3. Change planet" << std::endl;
        std::cout << "4. Duplicate planet" << std::endl;
        std::cout << "5. Sort planets" << std::endl;
        std::cout << "6. Display planets" << std::endl;
        std::cout << "7. Save planets to file" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cin >> menu_point;
        switch (--menu_point) {
            case ADD:
                add_one(pls, length);
                break;
            case DELETE:
                delete_one(pls, length);
                break;
            case CHANGE:
                change_bd(pls, length);
                break;
            case DUPLICATE:
                duplicate_one(pls, length);
                break;
            case SORT:
                sort_bd(pls, length);
                break;
            case DISPLAY:
                display(pls, length);
                break;
            case SAVE:
                write_bd(pls, filename, length);
                break;
            case EXIT:
                delete[] pls;
                return 0;
            default:
                std::cout << "Error menu point" << std::endl;
                break;
        }
    }
//
//    char* str = new char[20];
//    strcpy(str, "Hello");
//    Planet pl (30, 10, false, 30);
//    pl.setname("Hello");
//    Planet pl1 (pl);
//    display(&pl1, 1);
}
