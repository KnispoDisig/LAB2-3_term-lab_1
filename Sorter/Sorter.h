//
// Created by fell2 on 15.11.2020.
//
#include "../Sequence/LinkedListSequence/LinkedListSequence.h"
#include "../Sequence/ArraySequence/ArraySequence.h"
#include <chrono>
#include <utility>
#include "Ordering.h"
using namespace std;

#ifndef PROGLAB2_SORTER_H
#define PROGLAB2_SORTER_H

template<class T>
class Sorter {
private:
    virtual int compare(T item1, T item2) = 0;
public:
    virtual void sort(Sequence<T> *list) = 0;              // main sorting func; returns the duration of sorting
    // and count of comparisons
};

template<class T>
class BubbleSorter : public Sorter<T> {
private:
    int (*comparison)(T, T);

    int compare(T item1, T item2) {
        return (*comparison)(item1, item2);
    }

    pair<int, int> sort_info;
public:
    BubbleSorter() {
        comparison = Ordering::int_ascending;
    }

    explicit BubbleSorter(int (*comparisonFunction)(T, T)) {
        comparison = comparisonFunction;
    }

    pair<int, int> get_sort_info() {
        return sort_info;
    }

    void sort(Sequence<T> *list) {
        pair<int, int> pair;
        int countOfComparisons = 0;
        int start_time = clock();

        for (int i = 0; i < list->getLength() - 1; i++) {
            for (int j = i + 1; j < list->getLength(); j++) {
                if (compare(list->get(i), list->get(j)) == 1) {
                    T temp = list->get(i);
                    list->set(i, list->get(j));
                    list->set(j, temp);
                    countOfComparisons++;
                }
            }
        }

        int end_time = clock();

        sort_info.first = end_time - start_time;
        sort_info.second = countOfComparisons;
    }
};

template<class T>
class MergeSorter : public Sorter<T> {
private:
    int (*comparison)(T, T);

    pair<int, int> sort_info;

    int compare(T item1, T item2) {
        return (*comparison)(item1, item2);
    }

    int merge(Sequence<T> *seq, int low, int high, int mid) {       //returns count of comparisons
        int i, k, j, countOfComparisons;
        T tempArr[seq->getLength()];
        i = low;
        k = low;
        j = mid + 1;
        countOfComparisons = 0;

        while (i <= mid && j <= high) {
            if (compare(seq->get(i), seq->get(j)) != 1) {
                tempArr[k] = seq->get(i);
                k++;
                i++;
            } else {
                tempArr[k] = seq->get(j);
                k++;
                j++;
            }
            countOfComparisons++;
        }

        while (i <= mid) {
            tempArr[k] = seq->get(i);
            k++;
            i++;
        }

        while (j <= high) {
            tempArr[k] = seq->get(j);
            k++;
            j++;
        }

        for (i = low; i < k; i++) {
            seq->set(i, tempArr[i]);
        }

        return countOfComparisons;
    }

    int sortHelper(Sequence<T> *sequence, int low, int high) {          //returns count of comparisons
        int countOfComparisons = 0;

        if (low < high) {
            int mid = (low + high) / 2;

            countOfComparisons += sortHelper(sequence, low, mid);
            countOfComparisons += sortHelper(sequence, mid + 1, high);

            countOfComparisons += merge(sequence, low, high, mid);
        }

        return countOfComparisons;
    }

public:
    MergeSorter() {
        comparison = Ordering::int_ascending;
    }

    explicit MergeSorter(int (*comparisonFunction)(T, T)) {
        comparison = comparisonFunction;
    }

    pair<int, int> get_sort_info() {
        return sort_info;
    }

    void sort(Sequence<T> *sequence) {
        int start_time = clock();

        sort_info.second = sortHelper(sequence, 0, sequence->getLength() - 1);

        int end_time = clock();

        sort_info.first = end_time - start_time;
    }
};

template<class T>
class QuickSorter : public Sorter<T> {
private:
    int (*comparison)(T, T);

    pair<int, int> sort_info;

    int compare(T item1, T item2) {
        return (*comparison)(item1, item2);
    }

    int sortHelper(Sequence<T> *sequence, int left, int right) {
        int countOfComparisons = 0;
        int i = left;
        int j = right;
        T pivot = sequence->get((left + right) / 2);

        while (i <= j) {
            while (compare(sequence->get(i), pivot) == -1) {
                countOfComparisons++;
                i++;
            }

            while (compare(sequence->get(i), pivot) == 1) {
                countOfComparisons++;
                i++;
            }

            if (i <= j) {
                int temp = sequence->get(i);
                sequence->set(i, sequence->get(j));
                sequence->set(j, temp);
                i++;
                j--;
            }
        }

        if (j > left) {
            countOfComparisons += sortHelper(sequence, left, j);
        }

        if (i < right) {
            countOfComparisons += sortHelper(sequence, i, right);
        }

        return countOfComparisons;
    }

public:
    QuickSorter() {
        comparison = Ordering::int_ascending;
    }

    explicit QuickSorter(int (*comparisonFunction)(T, T)) {
        comparison = comparisonFunction;
    }

    pair<int, int> get_sort_info() {
        return sort_info;
    }

    void sort(Sequence<T> *sequence) {
        if (sequence->getLength() != 0) {
            int start_time = clock();

            sort_info.second = sortHelper(sequence, 0, sequence->getLength() - 1);

            int end_time = clock();

            sort_info.first = end_time - start_time;
        } else {
            sort_info.first = 0;
            sort_info.second = 0;
        }
    }
};

#endif //PROGLAB2_SORTER_H
