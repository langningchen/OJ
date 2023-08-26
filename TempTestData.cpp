#include "TempTestData.hpp"
#include "Database.hpp"
RESULT TEMP_TEST_DATA::Insert(TEST_GROUP TestGroup)
{
    configor::json::array_type TestCasesJSON;
    for (int i = 0; i < TestGroup.TestCases.size(); i++)
    {
        TestCasesJSON.push_back(configor::json({{"Output", TestGroup.TestCases[i].Output},
                                                {"StandardOutput", TestGroup.TestCases[i].StandardOutput},
                                                {"StandardError", TestGroup.TestCases[i].StandardError},
                                                {"Result", (int)TestGroup.TestCases[i].Result},
                                                {"Description", TestGroup.TestCases[i].Description},
                                                {"Time", TestGroup.TestCases[i].Time},
                                                {"Memory", TestGroup.TestCases[i].Memory},
                                                {"Score", TestGroup.TestCases[i].Score}}));
    }
    return DATABASE::INSERT("TempTestData")
        .Insert("Index", std::to_string(TestGroup.SID) + "-" + std::to_string(TestGroup.TGID))
        .Insert("Data",
                configor::json({{"Result", (int)TestGroup.Result},
                                {"Score", TestGroup.Score},
                                {"Time", TestGroup.Time},
                                {"TimeSum", TestGroup.TimeSum},
                                {"Memory", TestGroup.Memory},
                                {"TestCases", TestCasesJSON}})
                    .dump())
        .Execute();
}
RESULT TEMP_TEST_DATA::Update(TEST_GROUP TestGroup)
{
    configor::json::array_type TestCasesJSON;
    for (int i = 0; i < TestGroup.TestCases.size(); i++)
    {
        TestCasesJSON.push_back(configor::json({{"Output", TestGroup.TestCases[i].Output},
                                                {"StandardOutput", TestGroup.TestCases[i].StandardOutput},
                                                {"StandardError", TestGroup.TestCases[i].StandardError},
                                                {"Result", (int)TestGroup.TestCases[i].Result},
                                                {"Description", TestGroup.TestCases[i].Description},
                                                {"Time", TestGroup.TestCases[i].Time},
                                                {"Memory", TestGroup.TestCases[i].Memory},
                                                {"Score", TestGroup.TestCases[i].Score}}));
    }
    return DATABASE::UPDATE("TempTestData")
        .Set("Data",
             configor::json({{"Result", (int)TestGroup.Result},
                             {"Score", TestGroup.Score},
                             {"Time", TestGroup.Time},
                             {"TimeSum", TestGroup.TimeSum},
                             {"Memory", TestGroup.Memory},
                             {"TestCases", TestCasesJSON}})
                 .dump())
        .Where("Index", std::to_string(TestGroup.SID) + "-" + std::to_string(TestGroup.TGID))
        .Execute();
}
RESULT TEMP_TEST_DATA::Select(TEST_GROUP &TestGroup)
{
    return DATABASE::SELECT("TempTestData")
        .Select("Data")
        .Where("Index", std::to_string(TestGroup.SID) + "-" + std::to_string(TestGroup.TGID))
        .Execute(
            [&TestGroup](auto Data)
            {
                configor::json JSONData = configor::json::parse(Data[0]["Data"]);
                TestGroup.Result = (JUDGE_RESULT)JSONData["Result"].as_integer();
                TestGroup.Score = JSONData["Score"].as_integer();
                TestGroup.Time = JSONData["Time"].as_integer();
                TestGroup.TimeSum = JSONData["TimeSum"].as_integer();
                TestGroup.Memory = JSONData["Memory"].as_integer();
                for (int i = 0; i < JSONData["TestCases"].size(); i++)
                {
                    TestGroup.TestCases[i].Output = JSONData["TestCases"][i]["Output"].as_string();
                    TestGroup.TestCases[i].StandardOutput = JSONData["TestCases"][i]["StandardOutput"].as_string();
                    TestGroup.TestCases[i].StandardError = JSONData["TestCases"][i]["StandardError"].as_string();
                    TestGroup.TestCases[i].Result = (JUDGE_RESULT)JSONData["TestCases"][i]["Result"].as_integer();
                    TestGroup.TestCases[i].Description = JSONData["TestCases"][i]["Description"].as_string();
                    TestGroup.TestCases[i].Time = JSONData["TestCases"][i]["Time"].as_integer();
                    TestGroup.TestCases[i].Memory = JSONData["TestCases"][i]["Memory"].as_integer();
                    TestGroup.TestCases[i].Score = JSONData["TestCases"][i]["Score"].as_integer();
                }
                CREATE_RESULT(true, "Get temp test data succeeds");
            });
}
RESULT TEMP_TEST_DATA::Delete(TEST_GROUP TestGroup)
{
    return DATABASE::DELETE("TempTestData")
        .Where("Index", std::to_string(TestGroup.SID) + "-" + std::to_string(TestGroup.TGID))
        .Execute();
}

RESULT TEMP_TEST_DATA::Insert(TEST_CASE TestCase)
{
    return DATABASE::INSERT("TempTestData")
        .Insert("Index", std::to_string(TestCase.SID) + "-" + std::to_string(TestCase.TGID) + "-" + std::to_string(TestCase.TCID))
        .Insert("Data",
                configor::json({{"Output", TestCase.Output},
                                {"StandardOutput", TestCase.StandardOutput},
                                {"StandardError", TestCase.StandardError},
                                {"Result", (int)TestCase.Result},
                                {"Description", TestCase.Description},
                                {"Time", TestCase.Time},
                                {"Memory", TestCase.Memory},
                                {"Score", TestCase.Score}})
                    .dump())
        .Execute();
}
RESULT TEMP_TEST_DATA::Update(TEST_CASE TestCase)
{
    return DATABASE::UPDATE("TempTestData")
        .Set("Data",
             configor::json({{"Output", TestCase.Output},
                             {"StandardOutput", TestCase.StandardOutput},
                             {"StandardError", TestCase.StandardError},
                             {"Result", (int)TestCase.Result},
                             {"Description", TestCase.Description},
                             {"Time", TestCase.Time},
                             {"Memory", TestCase.Memory},
                             {"Score", TestCase.Score}})
                 .dump())
        .Where("Index", std::to_string(TestCase.SID) + "-" + std::to_string(TestCase.TGID) + "-" + std::to_string(TestCase.TCID))
        .Execute();
}
RESULT TEMP_TEST_DATA::Select(TEST_CASE &TestCase)
{
    return DATABASE::SELECT("TempTestData")
        .Select("Data")
        .Where("Index", std::to_string(TestCase.SID) + "-" + std::to_string(TestCase.TGID) + "-" + std::to_string(TestCase.TCID))
        .Execute(
            [&TestCase](auto Data)
            {
                configor::json JSONData = configor::json::parse(Data[0]["Data"]);
                TestCase.Output = JSONData["Output"].as_string();
                TestCase.StandardOutput = JSONData["StandardOutput"].as_string();
                TestCase.StandardError = JSONData["StandardError"].as_string();
                TestCase.Result = (JUDGE_RESULT)JSONData["Result"].as_integer();
                TestCase.Description = JSONData["Description"].as_string();
                TestCase.Time = JSONData["Time"].as_integer();
                TestCase.Memory = JSONData["Memory"].as_integer();
                TestCase.Score = JSONData["Score"].as_integer();
                CREATE_RESULT(true, "Get temp test data succeeds");
            });
}
RESULT TEMP_TEST_DATA::Delete(TEST_CASE TestCase)
{
    return DATABASE::DELETE("TempTestData")
        .Where("Index", std::to_string(TestCase.SID) + "-" + std::to_string(TestCase.TGID) + "-" + std::to_string(TestCase.TCID))
        .Execute();
}