#include "header.hpp"

int main() {
    int n = 0;
    std::cout << "Input your number:" << std::endl;
    std::cin >> n;

    MyStack<int> stack;
    Multipliers(n, stack);

    MyStack<int> new_stack;
    std::cout << n << " = ";
    while (!stack.empty()) {
        std::cout << *(stack.top_inf()) << " * ";
        new_stack.push(*(stack.top_inf()));
        stack.pop();
    }
    std::cout << "\b\b \b\b;" << std::endl;

    std::cout << n << " = ";
    while (!new_stack.empty()) {
        std::cout << *(new_stack.top_inf()) << " * ";
        new_stack.pop();
    }
    std::cout << "\b\b \b\b;" << std::endl;

    MyStack<int> test_stack;
    test_stack.push(1);
    test_stack.push(2);
    MyStack<int> test_new(test_stack);
    MyStack<int> test2_new;
    test2_new = test_stack;
    while (!test_stack.empty()) {
        std::cout << *(test_stack.top_inf()) << " ";
        test_stack.pop();
    }
    std::cout << std::endl;
    while (!test_new.empty()) {
        std::cout << *(test_new.top_inf()) << " ";
        test_new.pop();
    }
    std::cout << std::endl;
    while (!test2_new.empty()) {
        std::cout << *(test2_new.top_inf()) << " ";
        test2_new.pop();
    }
    std::cout << std::endl;
    return 0;
}

void Multipliers(int n, MyStack<int>& stack) {
    int i = 2;
    while (i*i <= n) {
        while (n % i == 0) {
            n /= i;
            stack.push(i);
        }
        ++i;
    }
    if (n != 1) {
        stack.push(n);
    }
}
