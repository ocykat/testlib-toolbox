#include "testlib.h"

#include <climits>
#include <iostream>
#include <random>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    auto truly_random_seed = []() {
        std::random_device rd;
        std::mt19937 engine(rd());
        std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
        return dis(engine);
    };

    rnd.setSeed(truly_random_seed());

    // With testlib, strings can be generated using a simple version of
    // regular expressions

    // all-lowercase string with length ranged from 1 to 10
    cout << rnd.next("[a-z]{1, 10}") << '\n'; 

    // mix-case string with length ranged from 1 to 10
    cout << rnd.next("[a-zA-Z]{1, 10}") << '\n'; 

    // tokens containing letters and digits with length ranged from 1 to 10
    cout << rnd.next("[a-zA-Z0-9]{1, 10}") << '\n'; 

    return 0;
}
