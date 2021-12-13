//
// Created by fell2 on 16.10.2020.
//

#ifndef PROGLAB2_SEQUENCE_H
#define PROGLAB2_SEQUENCE_H

template<class T>
class Sequence {
public:
    virtual int getLength() const = 0;

    virtual T getFirst() const = 0;

    virtual T getLast() const = 0;

    virtual T get(const int i) const = 0;

    virtual Sequence<T> *getSubsequence(const int startIndex, const int endIndex) const = 0;

    virtual void append(T value) = 0;

    virtual void prepend(T value) = 0;

    virtual void set(int index, T value) = 0;

    virtual void insertAt(const int index, T value) = 0;

    virtual Sequence<T> *concat(Sequence<T> *list) = 0;

    virtual bool contains(T item) = 0;

};


#endif //PROGLAB2_SEQUENCE_H
