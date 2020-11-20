#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <windows.h>
#include "Sparse/SparseSeq.cpp"
#include "Test.h"

using namespace std;

bool intIsNull(int i) {
    return i == 0;
}

int int_ascending(int n1, int n2) {
    if (n1 > n2) {
        return 1;
    } else if (n1 == n2) {
        return 0;
    } else {
        return -1;
    }
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

string get_text_from_file() {
    string text;
    ifstream myfile (R"(C:\Users\fell2\CLionProjects\proglab2\text.txt)");
    while (myfile.good()) {
        char c = myfile.get();
        text += c;
    }
    myfile.close();

    return text;
}

void print_art() {
    std::cout << R"(
  _           _       _  _  ___             _                  _ _   _
 | |         | |    _| || ||__ \      /\   | |                (_) | | |
 | |     __ _| |__ |_  __  _| ) |    /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  ___
 | |    / _` | '_ \ _| || |_ / /    / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
 | |___| (_| | |_) |_  __  _/ /_   / ____ \| | (_| | (_) | |  | | |_| | | | | | | | \__ \
 |______\__,_|_.__/  |_||_||____| /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
                                               __/ |
                                              |___/                                      )" << "\n\n";
}

string firstWord(string str) {
    std::string word;
    int i = 0;
    while (str[i] != ' ' && i != str.length()) {
        word += str[i];
        i++;
    }
    return word;
}

void removeFirstWord(string *str) {
    int i = 0;
    while ((*str)[i] != ' ' && i != (*str).length()) {
        i++;
    }
    if (i == (*str).length()) {
        (*str) = "";
    } else {
        (*str).erase(0, i + 1);
    }
}

void println(string str) {
    std::cout << str << "\n";
}

void print_info() {
    println("test  -  launch all tests");
    println("sparse (option) -  make sparse sequence (option == generate or option == custom)");
    println("alphabet (option) -  make alphabet pointer (option == file or option == custom)");

    println("exit  -  exit the program");
}

int main() {
    const int PROBABILITY_NOT_NULL = 15;
    const int COUNT_GENERATED = 500;
    string request;
    print_art();

    while (firstWord(request) != "exit") {
        print_info();
        getline(cin, request);
        string command = firstWord(request);

        if (command == "test") {
            Test::launchAllTests();
        } else if (command == "sparse") {
            string option;
            removeFirstWord(&request);
            try {
                option = firstWord(request);
            } catch (...) {
                println("Something went wrong. Enter proper value for option\n");
                continue;
            }
            if (option == "generate") {
                Sequence<int> *baseSequence = new LinkedListSequence<int>();
                println("** GENERATED SEQUENCE **");
                int count_not_null = 0;
                for (int i = 0; i < COUNT_GENERATED; i++) {
                    int n = generateInt(PROBABILITY_NOT_NULL);
                    count_not_null += n != 0;
                    baseSequence->prepend(n);
                    std::cout << n << " ";
                }
                std::cout << "\nElements count: " << COUNT_GENERATED << "; Not-null elements: " << count_not_null;
                std::cout << "\n" << 100 - ((count_not_null * 100) / (COUNT_GENERATED)) << "% is nulls";
                std::cout << "\n\n";

                println("** SPARSE SEQUENCE **");
                int usual_duration;
                unsigned int start_time = clock();
                SparseSeq<int> *sparseSeq = new SparseSeq<int>(baseSequence, 0, intIsNull);
                usual_duration = clock() - start_time;

                int mapReduce_duration;
                start_time = clock();
                SparseSeq<int> *sparseSeqMapReduce = new SparseSeq<int>(baseSequence, 0, intIsNull, true);
                mapReduce_duration = clock() - start_time;

                for (int i = 0; i < sparseSeq->getLength(); i++) {
                    int elem = sparseSeq->get(i);
                    if (elem != sparseSeq->getNull()) {
                        std::cout << i << " -> " << elem << "\n";
                    }
                }

                std::cout << "Usual processing time: " << usual_duration << " ms\n";
                std::cout << "MapReduce processing time: " << mapReduce_duration << " ms\n\n";

            } else if (option == "custom") {
                int elem_count = 0;

                bool read_count_ok = true;
                do {
                    println("Enter count of elements: \n");
                    string count;
                    getline(cin, count);
                    try {
                        elem_count = std::stoi(count);
                        read_count_ok = false;
                    } catch (...) {
                        println("Something went wrong, try again\n");
                    }
                } while (read_count_ok);

                Sequence<int> *sequence = new LinkedListSequence<int>();
                bool enter_seq_ok = true;
                do {

                    println("Enter your custom sequence of integers\nExample: 0 0 0 0 1 0 -3 0\n");
                    string str;
                    getline(cin, str);
                    try {
                        for (int i = 0; i < elem_count; i++) {
                            sequence->prepend(stoi(firstWord(str)));
                            removeFirstWord(&str);
                        }
                        enter_seq_ok = false;
                    } catch (...) {
                        sequence = new LinkedListSequence<int>();
                        println("Something went wrong, try again\n");
                    }
                } while (enter_seq_ok);

                println("** SPARSE SEQUENCE **");
                SparseSeq<int> *sparseSeq = new SparseSeq<int>(sequence, 0, intIsNull);
                for (int i = 0; i < sparseSeq->getLength(); i++) {
                    int elem = sparseSeq->get(i);
                    if (elem != sparseSeq->getNull()) {
                        std::cout << i << " -> " << elem << "\n";
                    }
                }
                std::cout << "\n";
            } else {
                println("Something went wrong. Enter proper value for option\n");
                continue;
            }
        } else if (command == "alphabet") {
            string option;
            removeFirstWord(&request);
            option = firstWord(request);

            if (option == "file") {
                string text = get_text_from_file();
                int page_size;

                bool page_size_read_ok = true;
                do {
                    println("Enter the size of one page:");
                    string input;
                    getline(cin, input);
                    try {
                        page_size = stoi(input);
                        page_size_read_ok = false;
                    } catch (...) {
                        println("Something went wrong, try again\n");
                    }
                } while (page_size_read_ok);

                cout << "Input text:\n" << text << "\n";

                AlphabetPointer *alphabetPointer = new AlphabetPointer(text, page_size);
                std::cout << "\nCreated alphabet pointer:\n";
                alphabetPointer->print();
                println("");

            } else if (option == "custom") {
                string custom_text;
                int page_size;

                std::cout << "Enter your text:\n";
                getline(cin, custom_text);

                bool page_size_read_ok = true;
                do {
                    println("Enter the size of one page:");
                    string input;
                    getline(cin, input);
                    try {
                        page_size = stoi(input);
                        page_size_read_ok = false;
                    } catch (...) {
                        println("Something went wrong, try again\n");
                    }
                } while (page_size_read_ok);

                AlphabetPointer *alphabetPointer = new AlphabetPointer(custom_text, page_size);
                std::cout << "\nCreated alphabet pointer:\n";
                alphabetPointer->print();
                println("");

            } else {
                println("Something went wrong. Enter proper value for option\n");
                continue;
            }
        }
    }

}
