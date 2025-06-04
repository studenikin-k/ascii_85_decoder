#include "decoder.h"
#include <string>
#include <vector>
#include <cstdint>

std::string decoder(const std::string &input) {
    std::string result;
    std::vector<uint8_t> VecToDecode;


    for (int i = 0; i < input.size(); ++i) {
        if (input[i] < '!' || input[i] > 'u') {
            std::cerr << "Ошибка, неизвестный символ: " << input[i] << std::endl;
            std::exit(1);
        }
        VecToDecode.push_back(static_cast<uint8_t>(input[i]));
    }

    const int groupSize = 5;


    for (int i = 0; i < VecToDecode.size(); i += groupSize) {
        uint32_t number = 0;
        int charsInGroup = 0;

        for (int j = 0; j < groupSize; ++j) {
            if (i + j < VecToDecode.size()) {
                number = number * 85 + (VecToDecode[i + j] - static_cast<uint8_t>('!'));
                charsInGroup++;
            } else {
                number = number * 85 + 84;
            }
        }


        for (int k = 3; k >= 0; --k) {
            char byte = static_cast<char>((number >> (k * 8)) & 0xFF);
            result += byte;
        }
    }


    int totalChars = VecToDecode.size();
    int fullGroups = totalChars / 5;
    int leftover = totalChars % 5;

    int expectedBytes = fullGroups * 4;
    if (leftover > 0) {
        expectedBytes += leftover - 1;
    }


    std::string finalResult;
    for (int i = 0; i < expectedBytes && i < result.size(); ++i) {
        finalResult += result[i];
    }

    return finalResult;
}
