#include <iostream>

#ifndef VERSION_PROJECT
#define VERSION_PROJECT "0"
#endif

int main(int, char**){
    std::cout << "Hello, World! Version 1.0." << VERSION_PROJECT << std::endl;
    std::cout << "test";
    return 0;
}