#include "coder.h"


std::string coder(const std::string &input) {
    std::string result;
    std::vector<uint8_t> inputData;

    for (int i = 0; i < input.size(); i++) {
        inputData.push_back(static_cast<uint8_t>(input[i]));
    }

    const int groupSize = 4;

    for (int i = 0; i < inputData.size(); i += groupSize) {
        uint32_t number = 0;
        int bytesInGroup = 0;

        for (int j = 0; j < groupSize; ++j) {
            if (i + j < inputData.size()) {
                number = (number << 8) | inputData[i + j];
                bytesInGroup++;
            } else {
                number <<= 8;
            }
        }

        char digits[5];
        for (int k = 4; k >= 0; --k) {
            digits[k] = '!' + (number % 85);
            number /= 85;
        }

        result.append(digits, bytesInGroup + 1);
    }

    return result;
}
