//
// Created by fell2 on 16.10.2020.
//
#include "IIterator.h"
#include "../Sequence/Sequence.h"

#ifndef PROGLAB2_SEQITERATOR_H
#define PROGLAB2_SEQITERATOR_H

template<class T>
class SeqIterator : public IIterator<T> {
private:
    int elemNumber;
    Sequence<T>* sequence = nullptr;
public:
    explicit SeqIterator(Sequence<T>* seq);

    T getCurrentItem() override;

    bool hasNext() override;

    bool next() override;

    bool tryGetCurrentItem(T& elem);

    bool inRange();

    int getIndex();
};


#endif //PROGLAB2_SEQITERATOR_H
