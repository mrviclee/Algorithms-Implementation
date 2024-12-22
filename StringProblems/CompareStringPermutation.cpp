#include <iostream>
#include <unordered_map>
#include <string>

bool IsPermutation(const std::string& target, const std::string& comparison)
{
    if (target.length() != comparison.length())
    {
        return false;
    }

    std::unordered_map<char, unsigned int> charCount;
    for (const auto& character : target)
    {
        if (charCount.find(character) == charCount.end())
        {
            charCount.insert({ character, 1 });
        }
        else
        {
            charCount[character]++;
        }
    }

    for (const auto& character : comparison)
    {
        if (charCount.find(character) == charCount.end())
        {
            return false;
        }

        if (charCount[character] < 0)
        {
            return false;
        }

        charCount[character]--;
    }

    return true;
}

int main()
{
    std::string testTarget = "abcdefg";
    std::string testComparisionPass = "cdabfge";
    std::string testComparisonFail = "asdfads";

    if (IsPermutation(testTarget, testComparisionPass))
    {
        std::cout << "Test Passed| " << testTarget << " & " << testComparisionPass << " are permutations" << std::endl;
    }
    else
    {
        std::cout << "Test Failed| " << testTarget << " & " << testComparisionPass << " are NOT permutations" << std::endl;
    }

    if (!IsPermutation(testTarget, testComparisonFail))
    {
        std::cout << "Test Passed| " << testTarget << " & " << testComparisionPass << " are NOT permutations" << std::endl;
    }
    else
    {
        std::cout << "Test Failed| " << testTarget << " & " << testComparisionPass << " are permutations" << std::endl;
    }
}