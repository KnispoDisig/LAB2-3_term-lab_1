//
// Created by fell2 on 17.10.2020.
//
#include "SparseSeq.h"

template<class T>
SparseSeq<T>::SparseSeq(Sequence<T> *seq, bool (*isNull)(T), bool mapReduceOn) {
    if (!mapReduceOn) {
        for (int i = 0; i < seq->getLength(); i++) {
            if (!isNull(seq->get(i))) {
                if (storage == nullptr) {
                    storage = new Dictionary<int, T>();
                }
                storage->add(i, seq->get(i));
            }
        }
    } else {
        storage = reduce<Dictionary<int, T>*>(indexing(seq), reducingFunction(isNull));
    }
}

template<class T>
void SparseSeq<T>::print() {
    storage->print();
}

template<class T>
template<typename Q>
Sequence<Q> *SparseSeq<T>::map(Sequence<T> *seq, std::function<Q(T)> f) {
    Sequence<Q> *newSeq = new ArraySequence<Q>();
    for (int i = 0; i < seq->getLength(); i++) {
        newSeq->prepend(f(seq->get(i)));
    }

    return newSeq->getSubsequence(1, newSeq->getLength());
}

template<class T>
template<typename Q>
Q SparseSeq<T>::reduce(Sequence<Q> *seq, std::function<Q(Q, Q)> f) {
    Q result;

    for (int i = 1; i < seq->getLength(); i++) {
        if (i == 1) {
            result = f(seq->get(i - 1), seq->get(i));
        } else {
            result = f(result, seq->get(i));
        }
    }

    return result;
}

template<class T>
SparseSeq<T>::SparseSeq(const SparseSeq<T> &seq) {
    this->storage = new Dictionary<int, T>(*seq.storage);
}

template<class T>
Sequence<Dictionary<int, T>*> *SparseSeq<T>::indexing(Sequence<T> *seq) {
    Sequence<Dictionary<int, T>*> *result = new ArraySequence<Dictionary<int, T>*>();

    for (int i = 0; i < seq->getLength(); i++) {
        Dictionary<int, T> *dictionary = new Dictionary<int, T>();
        dictionary->add(i, seq->get(i));
        result->prepend(dictionary);
    }

    return result->getSubsequence(1, result->getLength() - 1);
}

template<class T>
std::function<Dictionary<int, T>*(Dictionary<int, T>*, Dictionary<int, T>*)>
SparseSeq<T>::reducingFunction(bool (*isNull)(T)) {
    return [isNull] (Dictionary<int, T> *d1, Dictionary<int, T> *d2) {
        if (d2->containsNullValue(isNull)) {
            return d1;
        } else if (d1->containsNullValue(isNull) && !d2->containsNullValue(isNull)) {
            return d2;
        } else {
            return d1->concat(d2);
        }
    };
}

