#pragma once

#include <vector>
#include "Logger.hpp"
#include "Result.hpp"

#define DEBUG_HERE                                                                                                    \
    {                                                                                                                 \
        Logger.Info(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " " + std::string(__PRETTY_FUNCTION__)); \
        std::cout << __FILE__ << ":" << __LINE__ << " " << __PRETTY_FUNCTION__ << std::endl;                          \
    }

class UTILITIES
{
private:
    static size_t UploadFunction(char *ptr, size_t size, size_t nmemb, void *userp);

public:
    static std::string StringReplaceAll(std::string Data, std::string Search, std::string Replace);
    static std::vector<std::string> StringSplit(std::string Data, std::string Delimiter);
    static std::string StringJoin(std::vector<std::string> Data, std::string Delimiter);
    static RESULT MakeDir(std::string Dir);
    static RESULT RemoveDir(std::string Dir);
    static RESULT CopyFile(std::string Source, std::string Destination);
    static RESULT CopyDir(std::string Source, std::string Destination);
    static RESULT LoadFile(std::string Filename, std::string &Output);
    static RESULT LoadFile(std::string Filename, int &Output);
    static RESULT SaveFile(std::string Filename, std::string Data);
    static RESULT SaveFile(std::string Filename, int Data);
    static std::string RemoveSpaces(std::string Input);
    static RESULT SendEmail(std::string To, std::string Subject, std::string Body);
    static time_t StringToTime(std::string String);
};
