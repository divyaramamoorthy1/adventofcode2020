//
//  main.cpp
//  day1
//
//  Created by Divya Ramamoorthy on 12/16/20.
//  Copyright © 2020 Divya Ramamoorthy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "xcode_redirect.hpp"


using namespace std;

//void expense_report() {
//    size_t x;
//    vector<size_t> list;
//    for (size_t i = 0; i < 200; ++i) {
//        cin >> x;
//        if (x < 2020) {
//            list.push_back(x);
//        }
//    }
//    for (size_t i = 0; i < list.size() - 2; ++i) {
//        for (size_t j = i + 1; j < list.size() - 1; ++j) {
//            for (size_t k = j  + 1; k < list.size(); ++k) {
//                if (i != j != k and list[i] + list[j] + list[k] == 2020) {
//                    cout << list[i] * list[j] * list[k];
//                    return;
//                }
//            }
//        }
//    }
//}

//part 2
void expense_report() {
    size_t x;
    vector<size_t> list;
    for (size_t i = 0; i < 200; ++i) {
        cin >> x;
        if (x < 2020) {
            list.push_back(x);
        }
    }
    for (size_t i = 0; i < list.size() - 2; ++i) {
        size_t current_sum = 2020 - list[i];
        for (size_t j = i + 1; j < list.size(); ++j) {
            auto it = find(list.begin(), list.end(), current_sum - list[j]);
            if (it != list.end()) {
                cout << list[i] * list[j] * (current_sum - list[j]) << '\n';
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    xcode_redirect(argc, argv);
    expense_report();
    return 0;
}
