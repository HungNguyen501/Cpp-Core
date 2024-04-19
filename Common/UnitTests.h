#ifndef _UnitTests_
#define _UnitTests_

#include <vector>
#include <tuple>

#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define ESCAPE "\033[0m"

template<typename T>
void runTest(T actual, T expected) {
    std::cout << BOLD;
    if ( actual != expected) {
        std::cout << RED << "[Failed] ";
    } else {
        std::cout << GREEN << "[Passed] ";
    }
    std::cout << "expected=" << expected << " vs "
        << "actual=" << actual << "\n";
    std::cout << ESCAPE;
}


#endif