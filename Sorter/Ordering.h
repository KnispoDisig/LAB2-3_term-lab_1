//
// Created by fell2 on 15.11.2020.
//

#ifndef PROGLAB2_ORDERING_H
#define PROGLAB2_ORDERING_H

class Ordering {
public:
    static int int_ascending(int n1, int n2) {
        if (n1 > n2) {
            return 1;
        } else if (n1 == n2) {
            return 0;
        } else {
            return -1;
        }
    }

    static int int_descending(int n1, int n2) {
        if (n1 < n2) {
            return 1;
        } else if (n1 == n2) {
            return 0;
        } else {
            return -1;
        }
    }

    static int double_ascending(double n1, double n2) {
        if (n1 > n2) {
            return 1;
        } else if (n1 == n2) {
            return 0;
        } else {
            return -1;
        }
    }

    static int double_descending(double n1, double n2) {
        if (n1 < n2) {
            return 1;
        } else if (n1 == n2) {
            return 0;
        } else {
            return -1;
        }
    }
};

#endif //PROGLAB2_ORDERING_H
