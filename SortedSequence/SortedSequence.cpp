//
// Created by fell2 on 13.11.2020.
//

#include <iostream>
#include "SortedSequence.h"

template<class T>
int SortedSequence<T>::length() {
    return baseSeq->getLength();
}

template<class T>
SortedSequence<T>::SortedSequence(Sequence<T> *sequence, int (*comparisonFunction)(T elem1, T elem2)) {
    Sorter<T> *sorter = new MergeSorter<T>(comparisonFunction);
    baseSeq = new LinkedListSequence<T>();
    this->compare = comparisonFunction;

    for (int i = 0; i < sequence->getLength(); i++) {
        baseSeq->prepend(sequence->get(i));
    }

    sorter->sort(baseSeq);
}

template<class T>
bool SortedSequence<T>::isEmpty() {
    return baseSeq->getLength() == 0;
}

template<class T>
T SortedSequence<T>::get(int index) {
    if (!this->isEmpty()) {
        if (index >= 0 && index < this->length()) {
            return baseSeq->get(index);
        } else {
            std::cout << "Index out of range\n";
            throw std::exception();
        }
    } else {
        std::cout << "Sequence is empty\n";
        throw std::exception();
    }
}

template<class T>
T SortedSequence<T>::getFirst() {
    if (!this->isEmpty()) {
        return baseSeq->getFirst();
    } else {
        std::cout << "Sequence is empty\n";
        throw std::exception();
    }
}

template<class T>
T SortedSequence<T>::getLast() {
    if (!this->isEmpty()) {
        return baseSeq->getLast();
    } else {
        std::cout << "Sequence is empty\n";
        throw std::exception();
    }
}

template<class T>
int SortedSequence<T>::binarySearch(T elem, bool goldenSectionOn) {
    int left = 0;
    int right = baseSeq->getLength() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (baseSeq->get(mid) < elem) {
            left = mid + 1;
        } else if (baseSeq->get(mid) > elem) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

template<class T>
int SortedSequence<T>::indexOf(T elem) {
    return binarySearch(elem);
}

template<class T>
SortedSequence<T> *SortedSequence<T>::getSubsequence(int startIndex, int endIndex) {
    if (0 <= startIndex && startIndex < length() && 0 <= endIndex && endIndex < length() && startIndex <= endIndex) {
        return new SortedSequence<T>(baseSeq->getSubsequence(startIndex, endIndex), compare);
    } else {
        std::cout << "Index out of range\n";
        throw std::exception();
    }
}

template<class T>
void SortedSequence<T>::add(T elem) {
    if (!this->isEmpty() && elem < baseSeq->get(0)) {
        baseSeq->append(elem);
        return;
    }

    for (int i = 0; i < length(); i++) {
        if (elem <= get(i)) {
            baseSeq->insertAt(i, elem);
            return;
        }
    }

    baseSeq->prepend(elem);
}

template<class T>
void SortedSequence<T>::print() {
    for (int i = 0; i < length(); i++) {
        std::cout << get(i) << " ";
    }
    std::cout << "\n";
}


