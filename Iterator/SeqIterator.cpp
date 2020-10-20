//
// Created by fell2 on 16.10.2020.
//

#include <exception>
#include "SeqIterator.h"

template<class T>
inline SeqIterator<T>::SeqIterator(Sequence<T>* seq)
{
    if (seq->getLength() == 0) {
        throw std::exception();
    }
    else {
        sequence = seq;
        elemNumber = 0;
    }
}

template<class T>
T SeqIterator<T>::getCurrentItem() {
    if (elemNumber >= sequence->getLength() || elemNumber < 0) {
        throw std::exception();
    }
    else {
        return sequence->get(elemNumber);
    }
}

template<class T>
bool SeqIterator<T>::hasNext() {
    return elemNumber != sequence->getLength() - 1;
}

template<class T>
bool SeqIterator<T>::next() {
    elemNumber++;
    return true;
}

template<class T>
bool SeqIterator<T>::tryGetCurrentItem(T& elem) {
    try {
        elem = this->getCurrentItem();
    } catch (...) {
        return false;
    }

    return true;
}

template<class T>
bool SeqIterator<T>::inRange() {
    return elemNumber < sequence->getLength() && elemNumber > -1;
}

template<class T>
int SeqIterator<T>::getIndex() {
    return this->elemNumber;
}
