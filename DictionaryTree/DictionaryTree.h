//
// Created by fell2 on 08.11.2020.
//
#include <utility>
#include "../Sequence/LinkedListSequence/LinkedListSequence.cpp"

#ifndef PROGLAB2_DICTIONARYTREE_H
#define PROGLAB2_DICTIONARYTREE_H

template<class Key, class Value>
class DictionaryTree {
private:
    Key selfKey;
    Value value;
    DictionaryTree *right;
    DictionaryTree *left;

    bool hasLeft();

    bool hasRight();

    DictionaryTree<Key, Value> *minTree();

    DictionaryTree<Key, Value> *getTreeByKey(Key key);

    DictionaryTree<Key, Value> *getParent(Key key);

public:
    DictionaryTree(Key k, Value v);

    DictionaryTree(DictionaryTree<Key, Value> &tree);

    bool isEmpty();

    Sequence<std::pair<Key, Value>> *toSeq();

    void add(Key k, Value val);

    Value get(Key key);

    bool contains(Key key);

    void remove(Key key);

    bool containsNullValue(bool (*isNull)(Value));

    bool isLeaf();

    Sequence<Key> *keyList();

    void updateValue(Key key, Value newValue);

    int size();

    DictionaryTree<Key, Value> *unitedWith(DictionaryTree<Key, Value> *tree1);

    Sequence<std::pair<Key, Value>> *thread(std::string order);

};


#endif //PROGLAB2_DICTIONARYTREE_H
