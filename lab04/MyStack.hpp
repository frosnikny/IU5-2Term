// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

#ifndef LAB04_MYSTACK_HPP
#define LAB04_MYSTACK_HPP

//Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode                //узел списка
{
private:
    INF d;                        //информационная часть узла
    ListNode* next;         //указатель на следующий узел списка
    ListNode() { next = nullptr; } //конструктор
    friend FRIEND;
};

//Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;
public:
    MyStack();        // конструктор
    MyStack(MyStack<INF> const&);

    MyStack& operator=(const MyStack<INF>&);

    ~MyStack();            // освободить динамическую память
    bool empty();        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop();        // удалить узел из вершины стека
    INF* top_inf();        //считать информацию из вершины стека
};

#endif //LAB04_MYSTACK_HPP

template<class INF>
MyStack<INF>::MyStack() {
    top = nullptr;
}

template<class INF>
MyStack<INF>::~MyStack() {
    bool is_deleted = this->pop();
    while (is_deleted) {
        is_deleted = this->pop();
    }
}

template<class INF>
bool MyStack<INF>::empty() {
    return top == nullptr;
}

template<class INF>
bool MyStack<INF>::push(INF n) {
    Node* new_node = nullptr;
    new_node = new Node;
    if (new_node == nullptr) {
        return false;
    }
    new_node->d = n;
    new_node->next = top;
    top = new_node;
    return true;
}

template<class INF>
bool MyStack<INF>::pop() {
    if (this->empty()) {
        return false;
    }

    Node* old_node = top;
    top = top->next;
    delete old_node;
    return true;
}

template<class INF>
INF* MyStack<INF>::top_inf() {
    return &(top->d);
}

template<class INF>
MyStack<INF>::MyStack(const MyStack<INF>& old_stack) {
    Node* node = old_stack.top;
    if (node == nullptr) {
        top = nullptr;
    }
    Node* old_node = new Node;
    top = old_node;
    old_node->d = node->d;
    node = node->next;
    while (node != nullptr) {
        Node* new_node = new Node;
        new_node->d = node->d;
        old_node->next = new_node;
        old_node = new_node;
        node = node->next;
    }
    old_node->next = nullptr;
}

template<class INF>
MyStack<INF>& MyStack<INF>::operator=(const MyStack<INF>& old) {
    Node* node = old.top;
    if (node == nullptr) {
        top = nullptr;
    }
    Node* old_node = new Node;
    top = old_node;
    old_node->d = node->d;
    node = node->next;
    while (node != nullptr) {
        Node* new_node = new Node;
        new_node->d = node->d;
        old_node->next = new_node;
        old_node = new_node;
        node = node->next;
    }
    old_node->next = nullptr;
    return *this;
}
