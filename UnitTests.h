#ifndef _UnitTests_
#define _UnitTests_

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

template<typename T>
void runTest(T actual, T expected) {
    std::cout << BOLD_ON;
    if ( actual != expected) {
        std::cout << "<Failed> ";
    } else {
        std::cout << "<Passed> ";
    }
    std::cout << BOLD_OFF;
    std::cout << "expected=" << expected << " vs "
        << "actual=" << actual << "\n";
}


#endif