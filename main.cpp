#include <iostream>
#include "Sequence/Sequence.h"
#include "Sequence/ArraySequence/ArraySequence.cpp"
#include "Sequence/LinkedListSequence/LinkedListSequence.cpp"
#include "Sparse/SparseSeq.cpp"


bool intIsNull(int i) {
    return i == 0;
}

int main() {
    int arr[] = {0, 0, 0, 0, 5, 0, 2, 0, 11, 0, 1, 0, 0, 0, 0, -1};
    Sequence<int> *sequence = new ArraySequence<int>(arr, 16);

    SparseSeq<int> *sparseSeq = new SparseSeq<int>(sequence, intIsNull, true);
    sparseSeq->print();


}
