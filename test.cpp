#include <gtest/gtest.h>
#include "coder.h"
#include "decoder.h"


TEST(ascii85, encodeCheck) {
    std::string input = "Hello";
    std::string encoded = coder(input);
    EXPECT_EQ(encoded, "87cURDZ");
}


TEST(ascii85, decodeCheck) {
    std::string input = "87cURDZ";
    std::string decoded = decoder(input);
    EXPECT_EQ(decoded, "Hello");
}


TEST(ascii85, checkEmpty) {
    std::string input;
    std::string encoded = coder(input);
    EXPECT_TRUE(encoded.empty());
    std::string decoded = decoder(encoded);
    EXPECT_TRUE(decoded.empty());
}


TEST(ascii85, encodeAndDecode) {
    std::string input = "test to encode/decode";
    std::string encoded = coder(input);
    std::string decoded = decoder(encoded);
    EXPECT_EQ(input, decoded);
}


TEST(ascii85, checkToWorkWithSpaces) {
    std::string input = "Hello World";
    std::string encoded = coder(input);
    std::string decoded = decoder(encoded);
    EXPECT_EQ(input, decoded);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}