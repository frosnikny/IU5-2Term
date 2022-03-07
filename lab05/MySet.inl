// Copyright 2021 Nikita_Rasskazov <frosnikny@yandex.ru>

template <class T>
std::ostream& operator<<(std::ostream& out, MySet<T>& s) {
    for (int i = 0; i < s.size; ++i) {
        out << s[i] << ' ';
    }
    out << std::endl;
    return out;
}

template <>
bool MySet<char*>::operator==(MySet<char*>& s) {
    if (size != s.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (strcmp(pdata[i], s[i]) != 0) {
            return false;
        }
    }
    return true;
}

template <>
int MySet<char*>::q_find_str(char* el) {
    int left = 0;
    int right = size - 1;
    while (true) {
        int middle = left + static_cast<int>((right - left) / 2);
        if (strcmp(el, pdata[middle]) > 0) {
            left = middle + 1;
        } else if (strcmp(el, pdata[middle]) < 0) {
            right = middle - 1;
        } else {
            return middle;
        }

        if (left > right) {
            return -1;
        }
    }
}


template <>
void MySet<char*>::delete_element(char* el) {
    MyVector<char*>::delete_element(q_find_str(el));
}

//template <>
MySet<char*> operator+(MySet<char*>& s1, MySet<char*>& s2) {
    MySet<char*> sum(s1);
    int j = 0;
    for (int i = 0; i < s2.size; ++i) {
        while (std::strcmp(s1[j], s2[i]) < 0) {
            ++j;
        }
        if (strcmp(s2[i], s1[j]) != 0) {
            sum.add_element(s2[i]);
        }
    }

    return sum;
}

template <class T>
MySet<T> operator+(MySet<T>& s1, MySet<T>& s2) {
    MySet<T> sum(s1);
    int j = 0;
    for (int i = 0; i < s2.size; ++i) {
        while (s1[j] < s2[i]) {
            ++j;
        }
        if (s2[i] != s1[j]) {
            sum.add_element(s2[i]);
        }
    }

    return sum;
}

template <>
MySet<char*> operator-(MySet<char*>& s1, MySet<char*>& s2) {
    MySet<char*> difference(s1);
    for (int i = 0; i < s2.size; ++i) {
        difference.delete_element(s2[i]);
    }
    return difference;
}

template <class T>
MySet<T> operator-(MySet<T>& s1, MySet<T>& s2) {
    MySet<T> difference(s1);
    for (int i = 0; i < s2.size; ++i) {
        difference.delete_element(s2[i]);
    }
    return difference;
}

template <>
bool MySet<char*>::is_element_char(char* el) {
    int finded = q_find_str(el);
    return finded != -1;
}

template <>
MySet<char*> operator*(MySet<char*>& s1, MySet<char*>& s2) {
    MySet<char*> composition;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.is_element_char(s1[i]) > 0) {
            composition.add_element(s1[i]);
        }
    }
    return composition;
}

template <class T>
MySet<T> operator*(MySet<T>& s1, MySet<T>& s2) {
    MySet<T> composition;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.is_element(s1[i]) > 0) {
            composition.add_element(s1[i]);
        }
    }
    return composition;
}

template <class T>
bool MySet<T>::operator==(MySet<T>& s) {
    if (MyVector<T>::size != s.size) {
        return false;
    }
    for (int i = 0; i < MyVector<T>::size; ++i) {
        if (MyVector<T>::pdata[i] != s[i]) {
            return false;
        }
    }
    return true;
}

template <class T1>
MySet<T1>& MySet<T1>::operator+=(MySet<T1>& s) {
    *this = *this + s;
    return *this;
}

template <class T1>
MySet<T1>& MySet<T1>::operator-=(MySet<T1>& s) {
    *this = *this - s;
    return *this;
}

template <class T1>
MySet<T1>& MySet<T1>::operator*=(MySet<T1>& s) {
    *this = *this * s;
    return *this;
}

template <class T>
void MySet<T>::add_element(T el) {
    MyVector<T>::add_element(el);
    MyVector<T>::sort();
}

template <class T>
void MySet<T>::delete_element(T el) {
    MyVector<T>::delete_element(q_find(el));
}

template <class T>
bool MySet<T>::is_element(T el) {
    int finded = q_find(el);
    return finded != -1;
}

template <class T>
int MySet<T>::q_find(const T& el) {
    int left = 0;
    int right = MyVector<T>::size - 1;
    while (true) {
        int middle = left + static_cast<int>((right - left) / 2);
        if (el > MyVector<T>::pdata[middle]) {
            left = middle + 1;
        } else if (el < MyVector<T>::pdata[middle]) {
            right = middle - 1;
        } else {
            return middle;
        }

        if (left > right) {
            return -1;
        }
    }
}
