#pragma once

#include <queue>
#include "Logger.hpp"
#include "Submission.hpp"

class JUDGING_LIST
{
private:
    std::queue<int> JudgingList;

public:
    void Init();
    RESULT Add(SUBMISSION &Submission);
};

extern JUDGING_LIST JudgingList;
