//
//  main.cpp
//  passwordphilosophy
//
//  Created by Divya Ramamoorthy on 12/19/20.
//  Copyright © 2020 Divya Ramamoorthy. All rights reserved.
//

#include <iostream>
#include "xcode_redirect.hpp"

using namespace std;

// part1
size_t password1() {
    size_t lower_limit;
    size_t upper_limit;
    char letter;
    char trash;
    string pass;
    size_t temp_count = 0;
    size_t count = 0;
    for (size_t i = 0; i < 1000; ++i) { // just to read in from file
        cin >> lower_limit >> trash >> upper_limit >> letter >> trash >> pass;
        for (size_t j = 0; j < pass.length(); ++j) {
            if (pass[j] == letter) {
                temp_count++;
            }
        }
        if (temp_count >= lower_limit and temp_count <= upper_limit) {
            count++;
        }
        temp_count = 0;
    }
    cout << count << '\n';
    return count;
}

// part2
size_t password2() {
    size_t index1;
    size_t index2;
    char letter;
    char trash;
    string pass;
    size_t count = 0;
    for (size_t i = 0; i < 1000; ++i) {
        cin >> index1 >> trash >> index2 >> letter >> trash >> pass;
        if (pass[index1 - 1] != pass[index2 - 1] and ((pass[index1 - 1] == letter) or (pass[index2 - 1] == letter))) {
            count++;
        }
    }
    cout << count << '\n';
    return count;
}

int main(int argc, char * argv[]) {
    xcode_redirect(argc, argv);
    // comment out one to run the other
    password1();
    password2();
}
