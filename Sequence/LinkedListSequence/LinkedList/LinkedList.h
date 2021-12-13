//
// Created by fell2 on 16.10.2020.
//
#pragma once
#ifndef PROGLAB2_LINKEDLIST_H
#define PROGLAB2_LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    typedef struct Element {
        T value;
        Element *next;
    } Element;

    Element *head;
    int count;
public:
    LinkedList(T *items, int count);

    LinkedList();

    LinkedList(const LinkedList<T> &list);

    T getFirst();

    T getLast();

    T get(int index);

    LinkedList<T> *getSubList(int startIndex, int endIndex);

    int getLength();

    void append(T item);

    void prepend(T item);

    void set(int index, T value);

    void insertAt(int index, T item);

    LinkedList<T> *concat(LinkedList<T> *list);

    T *getItems();

    ~LinkedList() = default;
};



#endif //PROGLAB2_LINKEDLIST_H
