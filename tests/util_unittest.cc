


#include "../src/util.h"
#include "gtest/gtest.h"
#include <string>

namespace {
    
TEST(ConvertToNumberTest, positiveIntegerNumber) {

    std::string str1 = "1234";
    std::string str2 = "98123421";
    EXPECT_EQ(1234, util::convertToNumber(str1));
    EXPECT_EQ(98123421, util::convertToNumber(str2));

}

}
