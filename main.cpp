#include <iostream>
#include "coder.h"
#include "decoder.h"


int main () {

    std::string input;
    std::getline(std::cin, input);


    std::cout << coder(input) << std::endl;
    std::string output = coder(input);

    std::cout << decoder(output) << std::endl;

    return 0;
}
