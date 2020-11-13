#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <windows.h>
#include "Sparse/SparseSeq.cpp"
#include "AlphabetPointer/AlphabetPointer.h"

using namespace std;

bool intIsNull(int i) {
    return i == 0;
}

int generateInt(int probability) {
    int n = rand() % 101;

    if (n <= probability) {
        int result = rand() % 1000;
        return result;
    } else {
        return 0;
    }
}

string getText() {
    string text;
    ifstream myfile (R"(C:\Users\fell2\CLionProjects\proglab2\text.txt)");
    while (myfile.good()) {
        char c = myfile.get();
        text += c;
    }
    myfile.close();

    return text;
}

int main() {
//    DictionaryTree<int, int> *tree = new DictionaryTree<int, int>(10, 100);
//    tree->add(5, 10);
//    tree->add(7, 10);
//    tree->add(-6, 9);
//    tree->add(70, 12);
//    tree->add(100, 101);
//
//    DictionaryTree<int, int> *tree1 = new DictionaryTree<int, int>(-1, 1);
//    tree1->add(2, 1);
//    tree1->add(-3, 1);
//    tree1->add(10, 10);
//    tree1->add(150, 12);
//
//    Dictionary<int, int> *dictionary = new Dictionary<int, int>();
//    dictionary->add(5, 1);
//    dictionary->add(3, 2);
//    dictionary->add(1, 3);
//    dictionary->add(4, 4);
//    dictionary->add(2, 5);
//    dictionary->add(8, 6);
//    dictionary->add(10, 7);
//    dictionary->add(6, 8);
//
//    dictionary->remove(5);
//
//    dictionary->print("NLR");
    srand(time(NULL));
    Sequence<int> *sequence = new LinkedListSequence<int>();
    int countNoNull = 0;

    for (int i = 0; i < 1000; i++) {
        int j = generateInt(20);
        if (j != 0) {
            countNoNull++;
        }
        sequence->prepend(j);
    }



    unsigned int start_time = GetTickCount();
    SparseSeq<int> *sparseSeq1 = new SparseSeq<int>(sequence, intIsNull);
    unsigned int end_time =  GetTickCount();
    std::cout << end_time - start_time << "\n";

    start_time = GetTickCount();
    SparseSeq<int> *sparseSeq2 = new SparseSeq<int>(sequence, intIsNull, true);
    end_time = GetTickCount();
    std::cout << end_time - start_time << "\n";

    AlphabetPointer *alphabetPointer = new AlphabetPointer(getText(), 50);

    alphabetPointer->print();


}
