#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <filesystem>



namespace fs = std::filesystem;

// Helper to read a file into a string
std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Helper to run the scheduler and capture output
std::string run_scheduler(const std::string& input_file) {
    std::string tmp_output = "tmp_test_output.txt";
    std::string cmd = "../lab4 < " + input_file + " > " + tmp_output;
    int ret = system(cmd.c_str());
    EXPECT_EQ(ret, 0) << "Failed to run scheduler";
    std::string output = read_file(tmp_output);
    std::remove(tmp_output.c_str());
    return output;
}

// Parameterized test
class SchedulerTest : public ::testing::TestWithParam<std::string> {};

TEST_P(SchedulerTest, OutputMatchesExpected) {
    std::string base = GetParam();
    std::string input_file = base + "_input.txt";
    std::string expected_file = base + "_output.txt";
    std::string actual_output = run_scheduler(input_file);
    std::string expected_output = read_file(expected_file);
    EXPECT_EQ(actual_output, expected_output);
}

// List your test cases here (without _input.txt/_output.txt)
INSTANTIATE_TEST_SUITE_P(
    SchedulerTests,
    SchedulerTest,
    ::testing::Values(
        "testcases/test1",
        "testcases/test2"
        // Add more test cases as needed
    )
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);}