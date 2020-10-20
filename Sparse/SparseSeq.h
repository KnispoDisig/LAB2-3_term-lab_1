//
// Created by fell2 on 17.10.2020.
//
#include <functional>
#include "../Dictionary/Dictionary.cpp"
#include "../Sequence/Sequence.h"
#include "../Sequence/ArraySequence/ArraySequence.h"
#include "../Iterator/SeqIterator.cpp"

#ifndef PROGLAB2_SPARSESEQ_H
#define PROGLAB2_SPARSESEQ_H

template<class T>
class SparseSeq {
private:
    Dictionary<int, T> *storage = nullptr;

    template<typename Q>
    Sequence<Q> *map(Sequence<T> *seq, std::function<Q(T)> f);

    template<typename Q>
    Q reduce(Sequence<Q>* seq, std::function<Q(Q, Q)> f);

    Sequence<Dictionary<int, T>*> *indexing(Sequence<T> *seq);      // работает как map, только именно для данной задачи

    static std::function<Dictionary<int, T>*(Dictionary<int, T>*, Dictionary<int, T>*)> reducingFunction(bool (*isNull)(T));

public:

    SparseSeq(Sequence<T> *seq, bool (*isNull)(T), bool mapReduceOn = false);

    SparseSeq(const SparseSeq<T> &seq);

    void print();
};


#endif //PROGLAB2_SPARSESEQ_H
