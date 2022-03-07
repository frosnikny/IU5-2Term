// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

template<>
void MyVector<char*>::resize() {
    if (size >= maxsize) {
        maxsize = static_cast<int>(maxsize * 1.5);
    } else if (size <= static_cast<int>(maxsize / 2) && size >= 5) {
        maxsize = static_cast<int>(maxsize / 1.5);
    } else {
        return;
    }
    auto** new_data = new char* [maxsize];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = new char[std::strlen(pdata[i]) + 1];
        std::strcpy(new_data[i], pdata[i]);
        delete[] pdata[i];
    }
    delete[] pdata;
    pdata = new_data;
}

template<class T>
void MyVector<T>::resize() {
    if (size >= maxsize) {
        maxsize = static_cast<int>(maxsize * 1.5);
    } else if (size <= static_cast<int>(maxsize / 2) && size >= 5) {
        maxsize = static_cast<int>(maxsize / 1.5);
    } else {
        return;
    }
    T* new_data = new T [maxsize];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = pdata[i];
    }
    delete[] pdata;
    pdata = new_data;
}

template<>
MyVector<char*>::MyVector(char* el, int maxsz) : maxsize{maxsz}, size{0} {
    pdata = new char* [maxsize];
    if (el != nullptr) {
        size = 1;
        pdata[0] = new char[std::strlen(el) + 1];
        std::strcpy(pdata[0], el);
    }
}

template<class T>
MyVector<T>::MyVector(int maxsz) : maxsize{maxsz}, size{0} {
    pdata = new T[maxsize];
}

template<>
MyVector<char*>::MyVector(MyVector<char*>& v) {
    if (this != &v) {
        size = v.size;
        maxsize = v.maxsize;
        pdata = new char* [maxsize];
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = new char[std::strlen(v.pdata[i]) + 1];
            std::strcpy(pdata[i], v.pdata[i]);
        }
    }
}

template<class T>
MyVector<T>::MyVector(MyVector<T>& v) {
    if (this != &v) {
        size = v.size;
        maxsize = v.maxsize;
        pdata = new T[maxsize];
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }
}

template<>
MyVector<char*>::~MyVector() {
    if (pdata != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            if (pdata[i] != nullptr) {
                delete[] pdata[i];
            }
        }
        delete[] pdata;
    }
}

template<class T>
MyVector<T>::~MyVector() = default;

template<>
void MyVector<char*>::add_element(char* el) {
    if (size >= maxsize) {
        resize();
    }
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    ++size;
}

template<class T>
void MyVector<T>::add_element(T el) {
    if (size >= maxsize) {
        resize();
    }
    pdata[size] = el;
    ++size;
}

template<>
bool MyVector<char*>::delete_element(int i) {
    if ((i < 0) || (i >= size)) {
        return false;
    }
    delete pdata[i];
    for (size_t j = i; j < size - 1; ++j) {
        pdata[j] = pdata[j + 1];
    }
    pdata[size--] = nullptr;

    if (size <= static_cast<int>(maxsize / 2)) {
        resize();
    }

    return true;
}

template<class T>
bool MyVector<T>::delete_element(int i) {
    if ((i < 0) || (i >= size)) {
        return false;
    }
    for (size_t j = i; j < size - 1; ++j) {
        pdata[j] = pdata[j + 1];
    }
    pdata[size--] = 0;

    if (size <= static_cast<int>(maxsize / 2)) {
        resize();
    }

    return true;
}

template<>
char* MyVector<char*>::operator[](int i) {
    if (i >= size) {
        return nullptr;
    }
    return pdata[i];
}

template<class T>
T MyVector<T>::operator[](int i) {
    if (i >= size) {
        return nullptr;
    }
    return pdata[i];
}

template<>
void MyVector<char*>::sort() {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; (j > 0) && (strcmp(pdata[j - 1], pdata[j])) > 0; --j) {
            std::swap(pdata[j - 1], pdata[j]);
        }
    }
}

template<class T>
void MyVector<T>::sort() {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; (j > 0) && (pdata[j - 1] > pdata[j]); --j) {
            std::swap(pdata[j - 1], pdata[j]);
        }
    }
}

template<>
int MyVector<char*>::find(const char* el) {
    int i = 0;
    while ((strcmp(pdata[i], el) != 0) && (i < size)) {
        ++i;
    }
    if (i == size) {
        return -1;
    }
    return i;
}

template<class T>
int MyVector<T>::find(const char* el) {
    int i = 0;
    while ((pdata[i] != el) && (i < size)) {
        ++i;
    }
    if (i == size) {
        return -1;
    }
    return i;
}

template<>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& v) {
    if (this != &v) {
        delete this;
        size = v.size;
        maxsize = v.maxsize;
        pdata = new char* [maxsize];
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(v.pdata[i]) + 1];
            strcpy(pdata[i], v.pdata[i]);
        }
    }
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
    if (this != &v) {
        delete this;
        size = v.size;
        maxsize = v.maxsize;
        pdata = new char* [maxsize];
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }
    return *this;
}

template<class T1>
std::ostream& operator<<(std::ostream& out, const MyVector<T1>& v) {
    for (size_t i = 0; i < v.size; ++i) {
        out << v.pdata[i] << " ";
    }
    out << std::endl;
    return out;
}
