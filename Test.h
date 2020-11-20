//
// Created by fell2 on 15.11.2020.
//

#ifndef PROGLAB2_TEST_H
#define PROGLAB2_TEST_H

#include "SortedSequence/SortedSequence.cpp"
#include "AlphabetPointer/AlphabetPointer.h"

class Test {
// auxiliary functions
private:
    static bool strIsNull(string str);

    static void check(bool expression);

// SortedSequence tests
private:
    static bool creating_SortedSequenceTest();

    static bool add_SortedSequenceTest();

    static bool length_SortedSequenceTest();

    static bool get_SortedSequenceTest();

    static bool getFirst_SortedSequenceTest();

    static bool getLast_SortedSequenceTest();

    static bool indexOf_SortedSequenceTest();

    static bool subseq_SortedSequenceTest();

public:
    static pair<int, int> sortedSequenceTests();


// Dictionary tests
private:
    static bool add_DictionaryTest();

    static bool get_DictionaryTest();

    static bool contains_DictionaryTest();

    static bool containsNullValue_DictionaryTest();

    static bool remove_DictionaryTest();

    static bool getCount_DictionaryTest();

    static bool concat_DictionaryTest();

    static bool updateValue_DictionaryTest();

public:
    static pair<int, int> dictionaryTests();


public:
    static void launchAllTests();
};


#endif //PROGLAB2_TEST_H
