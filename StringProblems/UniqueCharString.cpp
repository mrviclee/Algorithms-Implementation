#include <iostream>
#include <string>
bool UniqueCharString(const std::string& test)
{
    int checker = 0;
    for (int index = 0; index < test.length(); index++)
    {
        int asciiVal = test[index] - 'a';
        if ((checker & (1 << asciiVal)) > 0)
        {
            return false;
        }

        checker = checker | (1 << asciiVal);
    }

    return true;
}

int main()
{
    std::string testUnique = "abcdefg";
    std::string testDuplicated = "abbcdefg";

    if (UniqueCharString(testUnique))
    {
        std::cout << testUnique << " is a unique string" << std::endl;
    }
    else
    {
        std::cout << testUnique << " is NOT a unique string" << std::endl;
    }

    if (UniqueCharString(testDuplicated))
    {
        std::cout << testUnique << " is a unique string" << std::endl;
    }
    else
    {
        std::cout << testUnique << " is NOT a unique string" << std::endl;
    }
}