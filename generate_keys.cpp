/* Algorithm Challenge & Problem Solving
 * 21 - Generate Random Security Keys
 *
 * This program generates a user-defined number of random security keys.
 * Each key is composed of multiple randomly generated segments that may
 * include uppercase letters, digits, or special characters.
 *
 * The program demonstrates:
 *   - Using enums to categorize character types
 *   - Generating random characters within ASCII ranges
 *   - Building random words of specific lengths
 *   - Constructing complete formatted security keys
 *   - Validating user input before processing
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enum representing available character categories
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

// Returns a random number in range [From, To]
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Returns a random character based on a chosen character type
char GetRandomCharacter(enCharType type)
{
    switch (type)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122)); // a–z
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90)); // A–Z
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47)); // Special symbols
    case enCharType::Digit:
        return char(RandomNumber(48, 57)); // 0–9
    default:
        return '?';
    }
}

// Reads a positive integer from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

// Generates a random word of a specific type and length
string GenerateWord(enCharType charType, short Length)
{
    string Word = "";

    for (int i = 1; i <= Length; i++)
        Word += GetRandomCharacter(charType);

    return Word;
}

// Generates a formatted multi-segment security key
string GenerateKey()
{
    string Key = "";

    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::Digit, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += "#"; // Optional custom marker
    Key += GenerateWord(enCharType::Digit, 4);

    return Key;
}

// Prints the required number of generated keys
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "]: ";
        cout << GenerateKey() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate:\n"));

    return 0;
}
