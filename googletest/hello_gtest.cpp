#include <gtest/gtest.h>
#include <bits/stdc++.h>

// This is a simple test case to demonstrate the use of Google Test framework.

/*  ### Work in Progress  */

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(1 + 1, 2);
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}