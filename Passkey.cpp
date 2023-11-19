#include "Passkey.hpp"
#include "Database.hpp"
#include "Utilities.hpp"

std::string PASSKEY::CreateChallenge(int UID)
{
    std::string Challenge = UTILITIES::RandomToken();
    DATABASE::INSERT("PasskeyChallenges")
        .Insert("UID", UID)
        .Insert("Challenge", Challenge)
        .Execute();
    return Challenge;
}
void PASSKEY::AddPasskey(std::string Challenge, int UID, std::string Credential, std::string PublicKey)
{
    DATABASE::SELECT("PasskeyChallenges")
        .Select("UID")
        .Select("CreateTime")
        .Where("Challenge", Challenge)
        .Execute(
            [UID, Challenge](auto Data)
            {
                if (Data.size() != 1)
                    throw EXCEPTION("Invalid challenge");
                DATABASE::DELETE("PasskeyChallenges")
                    .Where("Challenge", Challenge)
                    .Execute();
                if (std::stoi(Data[0]["UID"]) != UID)
                    throw EXCEPTION("Invalid challenge");
                if (UTILITIES::StringToTime(Data[0]["CreateTime"]) + 60 < time(NULL))
                    throw EXCEPTION("Challenge expired");
            });
    DATABASE::INSERT("Passkeys")
        .Insert("UID", UID)
        .Insert("Credential", Credential)
        .Insert("PublicKey", PublicKey)
        .Execute();
}