#include <gtest/gtest.h>
#include "specificBehavior.hpp"
#include <fstream>

struct specificBehaviorTests : public ::testing::Test
{
    const std::string helpMessage {"This is program for score bowling \nenter ./Bowling nameDirectoryToread to print result to screen \nor ./Bowling nameDirectoryToread nameFileToSave\n"};
    const std::string expectMessage {"### Lane 1: game in progress ###\nHenryk 24\n### Lane 2: game in progress ###\nKevin 16\nSandra 16\n### Lane 3: no game ###\n"};
};

TEST_F(specificBehaviorTests, given_dash_h_expect_info_help_message)
{
    //GIVEN
    char* input[] = {(char*)"./Bowling", (char*)"-h"};
    //WHEN
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(helpMessage, output);
}

TEST_F(specificBehaviorTests, given_dash_dash_help_expect_info_help_message)
{
    //GIVEN
    char* input[] = {(char*)"./Bowling", (char*)"--help"};
    //WHEN
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(helpMessage, output);
}

TEST_F(specificBehaviorTests, given_path_to_directory_expect_information_about_games)
{
    //GIVEN
    char* input[] = {(char*)"./Bowling", (char*)"../tests/data_tests"};
    //WHEN
    testing::internal::CaptureStdout();
    specificBehavior(2, input);
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(expectMessage, output);
}

TEST_F(specificBehaviorTests, given_path_to_directory_and_name_of_file_expect_save_information_about_game_in_to_the_file)
{
    //GIVEN
    char* input[] = {(char*)"./Bowling", (char*)"../tests/data_tests", (char*)"results.txt"};
    //WHEN
    specificBehavior(3, input);
    std::ifstream file;
    file.open ("results.txt");
    std::string dataLine;
    std::string output;
    while (std::getline(file, dataLine))
    {
        output += dataLine + "\n";
    }
    //THEN
    ASSERT_EQ(expectMessage, output);
}
