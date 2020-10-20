//
// Created by fell2 on 16.10.2020.
//

#ifndef PROGLAB2_DICTIONARY_H
#define PROGLAB2_DICTIONARY_H


template<class Key, class Value>
class Dictionary {
private:
    template<class K, class V>
    class DictionaryTree {
    public:
        Key selfKey;
        Value value;
        DictionaryTree *next;

        DictionaryTree(K key, V val, DictionaryTree<K, V> *next) {
            this->selfKey = key;
            this->value = val;
            this->next = next;
        }

        DictionaryTree(DictionaryTree<K, V> &tree) {
            this->selfKey = tree.selfKey;
            this->value = tree.value;
            this->next = tree.next;
        }
    };

    DictionaryTree<Key, Value> *node;

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

    void print();
};


#endif //PROGLAB2_DICTIONARY_H
