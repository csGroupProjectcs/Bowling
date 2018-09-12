#include <gtest/gtest.h>
#include "specificBehavior.hpp"

struct specificBehaviorTests : public ::testing::Test
{
};

TEST_F(specificBehaviorTests, given_dash_h_expect_info_help_message)
{
    char* input[] = {(char*)"./Bowling", (char*)"-h"};
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("This is program for score bowling \nenter ./Bowling nameDirectoryToread to print result to screen \nor ./Bowling nameDirectoryToread nameFileToSave\n", output);
}

TEST_F(specificBehaviorTests, given_dash_dash_help_expect_info_help_message)
{
    char* input[] = {(char*)"./Bowling", (char*)"--help"};
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("This is program for score bowling \nenter ./Bowling nameDirectoryToread to print result to screen \nor ./Bowling nameDirectoryToread nameFileToSave\n", output);
}

TEST_F(specificBehaviorTests, given_path_todirectory_expect_information_about_games)
{
    char* input[] = {(char*)"./Bowling", (char*)"../tests/data_tests"};
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("### Lane 1: GAME STATUS ###\nHenryk 24\n### Lane 2: GAME STATUS ###\nKevin 16\nSandra 16\n### Lane 3: GAME STATUS ###\n", output);
}
