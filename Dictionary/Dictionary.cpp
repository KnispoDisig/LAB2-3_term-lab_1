//
// Created by fell2 on 16.10.2020.
//

#include <exception>
#include <iostream>
#include "Dictionary.h"

template<class Key, class Value>
Dictionary<Key, Value>::Dictionary() {
    node = nullptr;
}

template<class Key, class Value>
int Dictionary<Key, Value>::getCount() {
    int count = 0;
    DictionaryTree<Key, Value>* temp = node;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

template<class Key, class Value>
bool Dictionary<Key, Value>::isEmpty() {
    return node == nullptr;
}

template<class Key, class Value>
Value Dictionary<Key, Value>::get(Key key) {
    DictionaryTree<Key, Value>* temp = node;
    while (temp != nullptr) {
        if (temp->selfKey == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    throw std::exception();
}

template<class Key, class Value>
void Dictionary<Key, Value>::add(Key key, Value val) {
    if (this->isEmpty()) {
        node = new DictionaryTree<Key, Value>(key, val, nullptr);
    } else {
        if (this->contains(key)) {
            std::cout << "Such key already exists\n";
            throw std::exception();
        } else {
            auto* newElem = new DictionaryTree<Key, Value>(key, val, nullptr);
            DictionaryTree<Key, Value>* temp = node;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newElem;
        }
    }
}

template<class Key, class Value>
bool Dictionary<Key, Value>::contains(Key key) {
    DictionaryTree<Key, Value>* temp = node;
    while (temp != nullptr) {
        if (temp->selfKey == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class Key, class Value>
void Dictionary<Key, Value>::remove(Key key) {
    if (!this->contains(key)) {
        std::cout << "No such element with given key\n";
        throw std::exception();
    }
    if (this->isEmpty()) {                  // если пусто, то исключение
        throw std::exception();
    } else if (node->next == nullptr) {     // если только один элемент
        if (node->selfKey == key) {         // если первый элемент совпадает
            DictionaryTree<Key, Value>* temp = node;
            delete node;
            node = temp;
        } else {                            // если нет, то исключение
            throw std::exception();
        }
    } else {                                // элементов не меньше двух
        DictionaryTree<Key, Value>* temp1 = node;
        DictionaryTree<Key, Value>* temp2 = node->next;

        if (temp1->selfKey == key) {        // проверяем первый элемент отдельно
            node = temp2;
            delete temp1;
        } else {                            // если не первый, идем дальше
            while (temp2->selfKey != key && temp2 != nullptr) {    // пока не встретим элемент с нужным ключом
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if (temp2 == nullptr) {
                throw std::exception();
            } else {                        // достигли положения, что temp2 указывает на найденный элемент, а temp1 на предыдущий
                temp1->next = temp2->next;
                delete temp2;
            }
        }
    }
}

template<class Key, class Value>
Dictionary<Key, Value> *Dictionary<Key, Value>::concat(Dictionary<Key, Value> *dictionary) {
    Dictionary<Key, Value> *result = new Dictionary<Key, Value>(*this);
    DictionaryTree<Key, Value> *temp = dictionary->node;

    while (temp != nullptr) {
        result->add(temp->selfKey, temp->value);
        temp = temp->next;
    }

    return result;
}

template<class Key, class Value>
void Dictionary<Key, Value>::print() {
    if (this->isEmpty()) {
        std::cout << "No elements\n";
    } else {
        DictionaryTree<Key, Value>* temp = node;
        while (temp != nullptr) {
            std::cout << temp->selfKey << " -> " << temp->value << "\n";
            temp = temp->next;
        }
    }
}

template<class Key, class Value>
Dictionary<Key, Value>::Dictionary(const Dictionary<Key,Value> &dictionary) {
    this->node = new DictionaryTree<Key, Value>(*dictionary.node);
}

template<class Key, class Value>
bool Dictionary<Key, Value>::containsNullValue(bool (*isNull)(Value)) {
    DictionaryTree<Key, Value> *temp = this->node;
    while (temp != nullptr && !isNull(temp->value)) {
        temp = temp->next;
    }

    return temp != nullptr;
}
