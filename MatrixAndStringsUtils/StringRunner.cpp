/*
 * ============================================================
 *  File        : StringRunner.cpp
 *  Description : Runs all string problem modules.
 *  Author      : Hatem Altaee Altaee
 *  Course      : C++ Level 7 - Algorithms & Problem Solving
 *                (with Mohammed Abu Hadhoud)
 * ============================================================
 */

#include <iostream>
#include "StringUtils.h"

using namespace std;

// ============================================================
//  STRING PROBLEMS EXECUTION
// ============================================================

void RunStringProblems() {

    stString String;

    // ========================================================
    //  PROBLEM 23 : First Letter of Each Word
    // ========================================================
    PrintProblemHeader(23, "First Letter of Each Word");

    String.read_string = ReadString("Enter your string");
    String.letter_of_string =
        GetLettersOfString(String.read_string);

    cout << "\n  First letters:\n";
    PrintCharOfString(String.letter_of_string);

    // ========================================================
    //  PROBLEM 24 : Upper First Letter of Each Word
    // ========================================================
    PrintProblemHeader(24, "Capitalise First Letter of Each Word");

    String.read_string = ReadString("Enter your string");
    String.to_upper_letter_of_each_word =
        UpperFirstLetterOfEachWord(String.read_string);

    cout << "\n  Result : "
        << String.to_upper_letter_of_each_word << endl;

    // ========================================================
    //  PROBLEM 25 : Lower First Letter of Each Word
    // ========================================================
    PrintProblemHeader(25, "Lowercase First Letter of Each Word");

    String.read_string = ReadString("Enter your string");
    String.to_lower_letter_of_each_word =
        LowerFirstLetterOfEachWord(String.read_string);

    cout << "\n  Result : "
        << String.to_lower_letter_of_each_word << endl;

    // ========================================================
    //  PROBLEM 26 : Convert String Case
    // ========================================================
    PrintProblemHeader(26, "Convert Entire String to Upper / Lower");

    String.read_string = ReadString("Enter your string");

    String.to_upper_all_string =
        ToUpperAllString(String.read_string);

    String.to_lower_all_string =
        ToLowerAllString(String.read_string);

    cout << "\n  UPPERCASE : "
        << String.to_upper_all_string << endl;

    cout << "  lowercase : "
        << String.to_lower_all_string << endl;

    // ========================================================
    //  PROBLEM 27 : Invert Single Character Case
    // ========================================================
    PrintProblemHeader(27, "Invert a Single Character's Case");

    String.read_char = ReadChar("Enter a character");
    String.invert_charcter_case =
        InvertCharacterCase(String.read_char);

    cout << "\n  Original : '" << String.read_char << "'"
        << "\n  Inverted : '" << String.invert_charcter_case << "'"
        << endl;

    // ========================================================
    //  PROBLEM 28 : Invert String Case
    // ========================================================
    PrintProblemHeader(28, "Invert Case of All Characters");

    String.read_string = ReadString("Enter a string");

    String.invert_all_char_case =
        InvertAllCharCase(String.read_string);

    cout << "\n  Result : "
        << String.invert_all_char_case << endl;

    // ========================================================
    //  PROBLEM 29 : Count Letters
    // ========================================================
    PrintProblemHeader(29, "Count Capital and Small Letters");

    String.read_string = ReadString("Enter a string");

    String.count_capital_letter =
        CountCapitalLetterInString(String.read_string);

    String.count_small_letter =
        CountSmallLetterInString(String.read_string);

    cout << "\n  String Length   : "
        << String.read_string.length() << endl;

    cout << "  Capital Letters : "
        << String.count_capital_letter << endl;

    cout << "  Small Letters   : "
        << String.count_small_letter << endl;

    // ========================================================
    //  PROBLEM 30 : Count Character (Case Sensitive)
    // ========================================================
    PrintProblemHeader(30, "Count a Specific Character");

    String.read_string = ReadString("Enter a string");
    String.read_char = ReadChar("Enter character to count");

    String.counter_char =
        CountChar(String.read_string, String.read_char);

    cout << "\n  Character '" << String.read_char
        << "' appears " << String.counter_char << " time(s).\n";

    // ========================================================
    //  PROBLEM 31 : Count Character (Both Cases)
    // ========================================================
    PrintProblemHeader(31, "Count Character (Both Cases)");

    String.read_string = ReadString("Enter a string");
    String.read_char = ReadChar("Enter character to count");

    String.counter_char_two_cases =
        CountCharTwoCases(String.read_string, String.read_char);

    String.invert_charcter_case =
        InvertCharacterCase(String.read_char);

    cout << "\n  '" << String.read_char << "' or '"
        << String.invert_charcter_case << "' appears "
        << String.counter_char_two_cases << " time(s).\n";

    // ========================================================
    //  PROBLEM 32 : Vowel Check
    // ========================================================
    PrintProblemHeader(32, "Is the Character a Vowel?");

    String.read_char = ReadChar("Enter a character");
    String.isVowel = IsVowel(String.read_char);

    cout << "\n  '" << String.read_char << "' is "
        << (String.isVowel ? "a VOWEL" : "NOT a vowel")
        << endl;

    // ========================================================
    //  PROBLEM 33 : Count Vowels
    // ========================================================
    PrintProblemHeader(33, "Count Vowels in String");

    String.read_string = ReadString("Enter a string");

    String.counter_vowel =
        CountVowel(String.read_string);

    cout << "\n  Number of vowels : "
        << String.counter_vowel << endl;

    // ========================================================
    //  PROBLEM 34 : Extract Vowels
    // ========================================================
    PrintProblemHeader(34, "Print All Vowels in String");

    String.read_string = ReadString("Enter a string");

    String.all_vowel_in_string =
        AllVowelInString(String.read_string);

    cout << "\n  Vowels found : "
        << String.all_vowel_in_string << endl;

    // ========================================================
    //  PROBLEM 35 : Split String
    // ========================================================
    PrintProblemHeader(35, "Split String into Words");

    String.read_string = ReadString("Enter a sentence");

    String.vSplitString =
        vSplitString(String.read_string, ' ');

    PrintStringArray(String.vSplitString);

    // ========================================================
    //  PROBLEM 36 : Word Count
    // ========================================================
    PrintProblemHeader(36, "Count Words in String");

    String.read_string = ReadString("Enter a sentence");

    String.vSplitString =
        vSplitString(String.read_string, ' ');

    String.count_words_in_string =
        (int)String.vSplitString.size() - 1;

    cout << "\n  Word count : "
        << String.count_words_in_string << endl;

    // ========================================================
    //  PROBLEM 38 : Trim Strings
    // ========================================================
    PrintProblemHeader(38, "Trim Whitespace");

    String.read_string =
        ReadString("Enter a string with spaces");

    String.trim_left = TrimLeft(String.read_string);
    String.trim_right = TrimRight(String.read_string);
    String.trim = Trim(String.read_string);

    cout << "\n  Trim Left  : [" << String.trim_left << "]" << endl;
    cout << "  Trim Right : [" << String.trim_right << "]" << endl;
    cout << "  Trim Both  : [" << String.trim << "]" << endl;

    // ========================================================
    //  PROBLEM 39 : Join Vector Strings
    // ========================================================
    PrintProblemHeader(39, "Join a Vector of Strings");

    String.read_string =
        ReadString("Enter a string to split then re-join");

    String.vSplitString =
        vSplitString(String.read_string, ' ');

    PrintStringArray(String.vSplitString);

    String.join_string =
        JoinedString(String.vSplitString, ',');

    cout << "\n  Joined with comma : "
        << String.join_string << endl;

    // ========================================================
    //  PROBLEM 40 : Join C-Array
    // ========================================================
    PrintProblemHeader(40, "Join a C-Array of Strings");

    string arrString[] =
    { "hatem", "ahmad", "mahmoud", "mohammed" };

    int length =
        sizeof(arrString) / sizeof(arrString[0]);

    String.join_string =
        JoinedString(arrString, length, ',');

    cout << "\n  Joined array : "
        << String.join_string << endl;

    // ========================================================
    //  PROBLEM 41 : Reverse Words
    // ========================================================
    PrintProblemHeader(41, "Reverse Words in Vector");

    String.read_string =
        ReadString("Enter words separated by commas");

    String.vSplitString =
        vSplitString(String.read_string, ',');

    cout << "\n  Original order:\n";
    PrintStringArray(String.vSplitString);

    String.vReverseWord =
        vReversWord(String.vSplitString);

    cout << "\n  Reversed order:\n";
    PrintStringArray(String.vReverseWord);

    // ========================================================
    //  PROBLEM 42-43 : Replace Word
    // ========================================================
    PrintProblemHeader(42, "Replace Word in String");

    String.read_string = ReadString("Enter a string");
    String.vSplitString = vSplitString(String.read_string, ' ');

    String.oldWord = ReadString("Word to replace");
    String.newWord = ReadString("Replacement word");

    String.vReplaceWord =
        vReplaceWord(String.vSplitString,
            String.oldWord,
            String.newWord,
            false);

    String.join_string =
        JoinedString(String.vReplaceWord, ' ');

    cout << "\n  Original : " << String.read_string << endl;
    cout << "  Result   : " << String.join_string << endl;

    // ========================================================
    //  PROBLEM 44 : Remove Punctuation
    // ========================================================
    PrintProblemHeader(44, "Remove Punctuation");

    String.read_string = ReadString("Enter a string");

    String.remove_paunctuation =
        RemovePunctuation(String.read_string);

    cout << "\n  Original : " << String.read_string << endl;
    cout << "  Cleaned  : " << String.remove_paunctuation << endl;
}