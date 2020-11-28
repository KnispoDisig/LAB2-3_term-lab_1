//
// Created by fell2 on 20.10.2020.
//

#include "AlphabetPointer.h"

Sequence<string> *AlphabetPointer::split(const string &str) {
    string word;
    Sequence<string> *result = new LinkedListSequence<string>();

    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] == ' ' && word.empty())) {
            if (str[i] != ' ') {
                word.push_back(str[i]);
                if (i == str.length() - 1) {
                    result->prepend(word);
                }
            } else {
                result->prepend(word);
                word = "";
            }
        }
    }

    return result;
}

Sequence<Sequence<string> *> *AlphabetPointer::divideIntoPages(Sequence<string> *seq, int pageSize, bool inChars) {
    int firstPageSize = pageSize / 2;
    int tenthPageSize = (pageSize * 3) / 4;
    int pageNumber = pageCount(seq, pageSize, inChars);

    Sequence<string> *copySeq = new LinkedListSequence<string>();
    for (int i = 0; i < seq->getLength(); i++) {
        copySeq->prepend(seq->get(i));
    }

    Sequence<Sequence<string> *> *result = new LinkedListSequence<Sequence<string> *>();

    if (!inChars) {
        for (int num = 0; num < pageNumber; num++) {
            if (num == pageNumber - 1) {
                result->prepend(copySeq);
            } else if (num == 0) {
                Sequence<string> *temp = copySeq->getSubsequence(0, firstPageSize - 1);
                result->prepend(temp);
                copySeq = copySeq->getSubsequence(firstPageSize, copySeq->getLength() - 1);
            } else if (num % 10 == 0) {
                Sequence<string> *temp = copySeq->getSubsequence(0, tenthPageSize - 1);
                result->prepend(temp);
                copySeq = copySeq->getSubsequence(tenthPageSize, copySeq->getLength() - 1);
            } else {
                Sequence<string> *temp = copySeq->getSubsequence(0, pageSize - 1);
                result->prepend(temp);
                copySeq = copySeq->getSubsequence(pageSize, copySeq->getLength() - 1);
            }
        }
    }

    return result;
}

int AlphabetPointer::pageCount(Sequence<string> *seq, int pageSize, bool inChars) {
    int firstPageSize = pageSize / 2;
    int tenthPageSize = (pageSize * 3) / 4;
    int pageNumber = 0;

    if (!inChars) {
        int seqLength = seq->getLength();
        while (seqLength > 0) {
            if (pageNumber == 0) {
                seqLength -= firstPageSize;
            } else if (pageNumber % 10 == 0) {
                seqLength -= tenthPageSize;
            } else {
                seqLength -= pageSize;
            }
            pageNumber++;
        }
    } else {
        int seqLengthInChars = 0;
        for (int i = 0; i < seq->getLength(); i++) {
            seqLengthInChars += seq->get(i).length();
        }

        string text;
        for (int i = 0; i < seq->getLength(); i++) {
            text += seq->get(i);
            if (i != seq->getLength() - 1) {
                text += " ";
            }
        }

        while (seqLengthInChars > 0) {
            string buffer;
            if (pageNumber == 0) {
                if (text[firstPageSize - 1] != ' ') {
                    int nearestSpace = firstPageSize - 1;            // нашли пробел
                    while (text[nearestSpace] != ' ') {
                        nearestSpace--;
                    }
                    seqLengthInChars -= nearestSpace + 1;      // уменьшили количество символов
                    text = text.substr(nearestSpace + 1);  // обрубили первую страницу из общего текста
                } else {
                    seqLengthInChars -= firstPageSize;
                    text = text.substr(firstPageSize);
                }
                pageNumber++;
            } else if (pageNumber % 10 == 0) {

            } else {

            }
        }

    }

    return pageNumber;
}

Dictionary<string, Sequence<int> *> *AlphabetPointer::makeDictionary(Sequence<Sequence<string> *> *dividedSeq) {
    Dictionary<string, Sequence<int> *> *result = new Dictionary<string, Sequence<int> *>();

    for (int i = 0; i < dividedSeq->getLength(); i++) {                     // идем по страницам
        for (int j = 0; j < dividedSeq->get(i)->getLength(); j++) {         // идем по словам в страницах
            string currentString = dividedSeq->get(i)->get(j);

            if (result->contains(currentString)) {                          // если уже есть такое слово
                Sequence<int> *temp = result->get(currentString);
                if (!temp->contains(i)) {                                   // только если слово не встречалось уже на этой странице
                    temp->prepend(i);
                    result->updateValue(currentString, temp);
                }

            } else {
                int elem[] = { i };
                Sequence<int> *temp = new LinkedListSequence<int>(elem, 1);
                result->add(currentString, temp);
            }
        }
    }

    return result;
}

AlphabetPointer::AlphabetPointer(const string& str, int pageSize, bool inChars) {
    storage = makeDictionary(divideIntoPages(split(str), pageSize, inChars));
}

void AlphabetPointer::print() {
    Sequence<std::pair<string, Sequence<int>*>> *valuesSequence = storage->listOfPairs();

    for (int i = 0; i < valuesSequence->getLength(); i++) {
        string word = valuesSequence->get(i).first;
        Sequence<int> *pages = valuesSequence->get(i).second;

        std::cout << i << ") " << word << " --> ( ";
        for (int j = 0; j < pages->getLength(); j++) {
            std::cout << pages->get(j);
            if (j != pages->getLength() - 1) {
                std::cout << ", ";
            } else {
                std::cout << " )\n";
            }
        }
    }
}
