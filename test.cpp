#include <iostream>

int main() {
#if __cplusplus >= 202002L
    std::cout << "C++20 enabled\n";
#else
    std::cout << "Not using C++20\n";
#endif
}