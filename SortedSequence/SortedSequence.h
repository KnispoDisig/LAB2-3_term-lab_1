//
// Created by fell2 on 13.11.2020.
//

#ifndef PROGLAB2_SORTEDSEQUENCE_H
#define PROGLAB2_SORTEDSEQUENCE_H

#include "../Sorter/Sorter.h"

template<class T>
class SortedSequence {
private:
    Sequence<T> *baseSeq;
    int (*compare)(T, T);

    int binarySearch(T elem, bool goldenSectionOn = false);

public:
    SortedSequence(Sequence<T> *sequence, int (*comparisonFunction)(T elem1, T elem2));

    int length();

    bool isEmpty();

    T get(int index);

    T getFirst();

    T getLast();

    int indexOf(T elem);

    SortedSequence<T> *getSubsequence(int startIndex, int endIndex);

    void add(T elem);

    void print();
};




#endif //PROGLAB2_SORTEDSEQUENCE_H
