//
// Created by fell2 on 16.10.2020.
//

#ifndef PROGLAB2_IITERATOR_H
#define PROGLAB2_IITERATOR_H

template<class T>
class IIterator {
    virtual int getCurrentItem() = 0;

    virtual bool hasNext() = 0;

    virtual bool next() = 0;

    virtual bool tryGetCurrentItem(T& elem) = 0;

    virtual bool inRange() = 0;

};

#endif //PROGLAB2_IITERATOR_H
