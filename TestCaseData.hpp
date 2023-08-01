#pragma once

#include <string>

class TEST_CASE_DATA
{
private:
    int TCID = 0;
    std::string Input;
    std::string Answer;
    int TimeLimit;
    int MemoryLimit;
    int Score;

    friend class PROBLEMS;
    friend class SUBMISSIONS;
    friend class TEST_CASE;
    friend class API_PROCEED;
    friend class TEST_GROUP_DATA;
};
