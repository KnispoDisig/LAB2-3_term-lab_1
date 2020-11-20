//
// Created by fell2 on 16.10.2020.
//
#pragma once
#ifndef PROGLAB2_DICTIONARY_H
#define PROGLAB2_DICTIONARY_H

#include "../DictionaryTree/DictionaryTree.cpp"

template<class Key, class Value>
class Dictionary {
private:
    DictionaryTree<Key, Value> *dictionaryTree;

public:
    Dictionary();

    Dictionary(const Dictionary<Key, Value> &dictionary);

    bool isEmpty();

    Value get(Key key);

    void add(Key key, Value val);

    bool contains(Key key);

    bool containsNullValue(bool (*isNull)(Value));

    void remove(Key key);

    int getCount();

    Dictionary<Key, Value> *concat(Dictionary<Key, Value> *dictionary);

    void updateValue(Key key, Value newValue);

    Sequence<Key> *keyList();

    Sequence<std::pair<Key, Value>> *listOfPairs();

};



#endif //PROGLAB2_DICTIONARY_H
