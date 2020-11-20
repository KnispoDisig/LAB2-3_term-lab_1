//
// Created by fell2 on 15.11.2020.
//

#include "Test.h"

void success() {
    std::cout << "test is successful\n";
}

void error() {
    std::cout << "ERROR. Test not passed\n";
}

void space() {
    std::cout << "\n";
}

bool Test::creating_SortedSequenceTest() {
    std::cout << "creatingTest: ";

    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);

    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);
    for (int i = 1; i < sortedSequence->length(); i++) {
        if (sortedSequence->get(i - 1) > sortedSequence->get(i)) {
            error();
            space();
            return false;
        }
    }

    success();
    space();
    return true;
}

bool Test::add_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);

    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "addingToMiddleTest: ";
    sortedSequence->add(6);
    bool test1 = sortedSequence->get(4) == 6;
    check(test1);

    std::cout << "addingToBeginTest: ";
    sortedSequence->add(-2);
    bool test2 = sortedSequence->get(0) == -2;
    check(test2);

    std::cout << "addingToEndTest: ";

    sortedSequence->add(11);
    bool test3 = sortedSequence->getLast() == 11;
    check(test3);

    return test1 && test2 && test3;
}

bool Test::length_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "usualLengthTest: ";
    bool test1 = sortedSequence->length() == 6;
    check(test1);

    std::cout << "nullLengthTest: ";
    Sequence<int> *nullSeq = new LinkedListSequence<int>();
    SortedSequence<int> *nullSortedSeq = new SortedSequence<int>(nullSeq, Ordering::int_ascending);
    bool test2 = nullSortedSeq->length() == 0;
    check(test2);

    return test1 && test2;
}

bool Test::get_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "usualGetTest: ";
    bool test1 = sortedSequence->get(2) == 4;
    check(test1);

    std::cout << "outOfRangeGetTest: ";
    bool test2 = false;
    try {
        int n = sortedSequence->get(-1);
    } catch (...) {
        success();
        test2 = true;
    }

    space();

    return test2 && test1;
}

bool Test::getFirst_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "usualGetFirstTest: ";
    bool test1 = sortedSequence->getFirst() == 2;
    check(test1);

    std::cout << "emptySeqGetFirstTest: ";
    SortedSequence<int> *nullSortSeq = new SortedSequence<int>(new LinkedListSequence<int>(), Ordering::int_ascending);
    bool test2 = false;
    try {
        int n = nullSortSeq->getFirst();
    } catch (...) {
        success();
        test2 = true;
    }
    space();

    return test1 && test2;
}

bool Test::getLast_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "usualGetLastTest: ";
    bool test1 = sortedSequence->getLast() == 9;
    check(test1);

    std::cout << "emptySeqGetLastTest: ";
    SortedSequence<int> *nullSortSeq = new SortedSequence<int>(new LinkedListSequence<int>(), Ordering::int_ascending);
    bool test2 = false;
    try {
        int n = nullSortSeq->getLast();
    } catch (...) {
        test2 = true;
        success();
    }
    space();

    return test1 && test2;
}

bool Test::indexOf_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending);

    std::cout << "usualIndexOfTest: ";
    bool test1 = sortedSequence->indexOf(5) == 3;
    check(test1);

    std::cout << "firstElemIndexOfTest: ";
    bool test2 = sortedSequence->indexOf(2) == 0;
    check(test2);

    std::cout << "lastElemIndexOfTest: ";
    bool test3 = sortedSequence->indexOf(9) == sortedSequence->length() - 1;
    check(test3);

    return test1 && test2 && test3;
}

pair<int, int> Test::sortedSequenceTests() {
    pair<int, int> all_success;
    int all = 7;
    int success = 0;

    success += add_SortedSequenceTest();
    success += length_SortedSequenceTest();
    success += get_SortedSequenceTest();
    success += getFirst_SortedSequenceTest();
    success += getLast_SortedSequenceTest();
    success += indexOf_SortedSequenceTest();
    success += subseq_SortedSequenceTest();

    all_success.first = all;
    all_success.second = success;

    return all_success;
}

bool Test::subseq_SortedSequenceTest() {
    Sequence<int> *sequence = new LinkedListSequence<int>();
    sequence->prepend(5);
    sequence->prepend(7);
    sequence->prepend(2);
    sequence->prepend(9);
    sequence->prepend(3);
    sequence->prepend(4);
    SortedSequence<int> *sortedSequence = new SortedSequence<int>(sequence, Ordering::int_ascending); // 2 3 4 5 7 9

    std::cout << "usualSubseqTest: ";
    SortedSequence<int> *sub = sortedSequence->getSubsequence(1, 3);
    bool test1 = sub->get(0) == 3 && sub->get(1) == 4 && sub->get(2) == 5;
    check(test1);

    std::cout << "wrongRangesSubsequenceTest: ";
    bool test2 = false;
    try {
        sub = sortedSequence->getSubsequence(4, 2);
    } catch (...) {
        success();
        test2 = true;
    }
    space();

    return test1 && test2;
}

bool Test::add_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();

    std::cout << "addToEmptyTest: ";
    dictionary->add(2, "one");
    bool test1 = dictionary->get(2) == "one";
    check(test1);

    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "six");

    std::cout << "usualAddTest: ";
    dictionary->add(1, "seven");
    bool test2 = dictionary->get(1) == "seven";
    check(test2);

    return test1 && test2;
}

bool Test::get_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();

    std::cout << "getInEmptyDictionaryTest: ";
    bool test1 = false;
    try {
        string str = dictionary->get(4);
    } catch (...) {
        success();
        test1 = true;
    }
    space();

    std::cout << "usualGetTest: ";
    dictionary->add(2, "one");
    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "six");

    bool test2 = dictionary->get(5) == "two" && dictionary->get(0) == "six" && dictionary->get(4) == "five";
    check(test2);

    std::cout << "noElementGetTest: ";
    bool test3 = false;
    try {
        string str = dictionary->get(100);
    } catch (...) {
        success();
        test3 = true;
    }
    space();

    return test1 && test2 && test3;
}

bool Test::contains_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();
    dictionary->add(2, "one");
    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "six");

    std::cout << "usualContainsTest: ";
    bool test1 = dictionary->contains(5) && !dictionary->contains(11);
    check(test1);

    std::cout << "emptyDictionaryContainsTest: ";
    Dictionary<int, string> *emptyDictionary = new Dictionary<int, string>();
    bool test2 = !emptyDictionary->contains(2);
    check(test2);

    return test1 && test2;
}

bool Test::containsNullValue_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();
    dictionary->add(2, "one");
    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "");

    std::cout << "emptyDictionaryContainsNullTest: ";
    Dictionary<int, string> *empty = new Dictionary<int, string>();
    bool test1 = !empty->containsNullValue(strIsNull);
    check(test1);

    std::cout << "usualDictionaryContainsNullTest: ";
    bool test2 = dictionary->containsNullValue(strIsNull);
    check(test2);

    return test1 && test2;
}

bool Test::strIsNull(string str) {
    return str.empty();
}

bool Test::remove_DictionaryTest() {
    bool leafTest;
    bool oneChildTest;
    bool twoChildTest;
    bool rootTest;

    Dictionary<int, string> *dictionary = new Dictionary<int, string>();
    dictionary->add(2, "one");
    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "");

    std::cout << "allUsualRemoveTest: ";

    dictionary->remove(10);
    leafTest = !dictionary->contains(10);
    dictionary->remove(-3);
    oneChildTest = !dictionary->contains(-3);
    dictionary->add(11, "additional");
    dictionary->remove(5);
    twoChildTest = !dictionary->contains(5);
    dictionary->remove(2);
    rootTest = !dictionary->contains(2);

    bool test1 = leafTest && oneChildTest && twoChildTest && rootTest;
    check(test1);

    std::cout << "emptyDictionaryRemoveTest: ";
    Dictionary<int, string> *empty = new Dictionary<int, string>();
    bool test2 = false;
    try {
        empty->remove(4);
    } catch (...) {
        success();
        test2 = true;
    }
    space();

    return test1 && test2;
}

void Test::check(bool expression) {
    if (expression) {
        success();
    } else {
        error();
    }
    space();
}

bool Test::getCount_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();
    dictionary->add(2, "one");
    dictionary->add(5, "two");
    dictionary->add(-3, "three");
    dictionary->add(10, "four");
    dictionary->add(4, "five");
    dictionary->add(0, "");

    std::cout << "usualGetCountTest: ";
    bool test1 = dictionary->getCount() == 6;
    check(test1);

    std::cout << "emptyDictionaryGetCountTest: ";
    Dictionary<int, string> *empty = new Dictionary<int, string>();
    bool test2 = empty->getCount() == 0;
    check(test2);

    return test1 && test2;
}

bool Test::concat_DictionaryTest() {
    Dictionary<int, string> *dictionary1 = new Dictionary<int, string>();
    dictionary1->add(1, "one");
    dictionary1->add(2, "two");
    dictionary1->add(3, "three");
    dictionary1->add(4, "four");
    dictionary1->add(5, "five");
    dictionary1->add(6, "six");

    Dictionary<int, string> *dictionary2 = new Dictionary<int, string>();
    dictionary1->add(-3, "seven");
    dictionary1->add(-2, "eight");
    dictionary1->add(-1, "nine");
    dictionary1->add(0, "ten");

    std::cout << "concatenatingDictionariesTest: ";
    Dictionary<int, string> *concat = dictionary1->concat(dictionary2);

    bool testPassed = true;
    for (int key = -3; key < 7; key++) {
        if (!concat->contains(key)) {
            testPassed = false;
            break;
        }
    }
    check(testPassed);

    return testPassed;
}

bool Test::updateValue_DictionaryTest() {
    Dictionary<int, string> *dictionary = new Dictionary<int, string>();
    dictionary->add(1, "one");
    dictionary->add(2, "two");
    dictionary->add(3, "three");
    dictionary->add(4, "four");
    dictionary->add(5, "five");
    dictionary->add(6, "six");

    std::cout << "updateValueEmptyTest: ";
    Dictionary<int, string> *empty = new Dictionary<int, string>();
    bool test1 = false;
    try {
        empty->updateValue(4, "something");
    } catch (...) {
        success();
        test1 = true;
    }
    space();

    std::cout << "usualUpdateValueTest: ";
    bool wasFour = dictionary->get(4) == "four";
    dictionary->updateValue(4, "ten");
    bool becomeTen = dictionary->get(4) == "ten";
    bool test2 = wasFour && becomeTen;
    check(test2);

    return test1 && test2;
}

pair<int, int> Test::dictionaryTests() {
    pair<int, int> all_success;
    int all = 8;
    int success = 0;

    success += add_DictionaryTest();
    success += get_DictionaryTest();
    success += contains_DictionaryTest();
    success += containsNullValue_DictionaryTest();
    success += remove_DictionaryTest();
    success += getCount_DictionaryTest();
    success += concat_DictionaryTest();
    success += updateValue_DictionaryTest();

    all_success.first = all;
    all_success.second = success;

    return all_success;
}

void printTestsInfo(pair<int, int> info) {
    std::cout << "# Tests results: " << info.first << " tests all,  " << info.second << " succeeded\n\n";
}

void Test::launchAllTests() {
    std::cout << "*** SORTED SEQUENCE TESTING ***\n\n";
    pair<int, int> sequenceTestsInfo = sortedSequenceTests();
    printTestsInfo(sequenceTestsInfo);
    std::cout << "\n*** DICTIONARY TESTING ***\n\n";
    pair<int, int> dictionaryTestsInfo = dictionaryTests();
    printTestsInfo(dictionaryTestsInfo);
}


