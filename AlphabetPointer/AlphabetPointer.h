//
// Created by fell2 on 20.10.2020.
//


#include <string>

using namespace std;

#ifndef PROGLAB2_ALPHABETPOINTER_H
#define PROGLAB2_ALPHABETPOINTER_H

#include "../Dictionary/Dictionary.cpp"

class AlphabetPointer {
private:
    Dictionary<string, Sequence<int> *> *storage = nullptr;

    static Sequence<string> *split(const string &str);   // разбивает строку на Sequence слов по пробелам

    static Sequence<Sequence<string> *> *divideIntoPages(Sequence<string> *seq, int pageSize, bool inChars);    // разделяет список слов на страницы

    static int pageCount(Sequence<string> *seq, int pageSize, bool inChars);    // возвращает количество страниц

    static Dictionary<string, Sequence<int> *> *makeDictionary(Sequence<Sequence<string> *> *dividedSeq);   // собирает словарь

public:
    AlphabetPointer(const string& str, int pageSize, bool inChars = false);

    void print();
};


#endif //PROGLAB2_ALPHABETPOINTER_H
