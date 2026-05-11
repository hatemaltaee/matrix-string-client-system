#pragma once

/*
 * ================================
 * String Utilities Module
 * ================================
 * Provides all string operations:
 * - Manipulation
 * - Parsing & splitting
 * - Case conversion
 * - Word operations
 * - Analysis functions
 * ================================
 */

#include <vector>
#include <string>

using namespace std;

/*
 * ================================
 * STRUCT: stString
 * ================================
 * Holds all string-related data
 */
struct stString {

    vector<string> vSplitString;
    vector<string> vReverseWord;
    vector<string> vReplaceWord;

    bool isVowel;
    bool IsPunctuation;

    string read_string;
    string letter_of_string;
    string to_upper_letter_of_each_word;
    string to_lower_letter_of_each_word;
    string to_upper_all_string;
    string to_lower_all_string;
    string all_vowel_in_string;
    string trim_left;
    string trim_right;
    string trim;
    string oldWord;
    string newWord;
    string invert_all_char_case;
    string join_string;
    string remove_paunctuation;

    char read_char;
    char invert_charcter_case;

    int count_capital_letter;
    int count_small_letter;
    int counter_char;
    int counter_char_two_cases;
    int counter_vowel;
    int count_words_in_string;
};

/*
 * ================================
 * STRING FUNCTIONS
 * ================================
 */

 // UI
void PrintProblemHeader(int number, const string& title);

// Input
string ReadString(string message);
int    ReadInt(string message);
double ReadDouble(string message);
char   ReadChar(string message);

// Manipulation
string GetLettersOfString(string& text);
void   PrintCharOfString(const string& text);
string UpperFirstLetterOfEachWord(string& text);
string LowerFirstLetterOfEachWord(string& text);
string ToUpperAllString(string  text);
string ToLowerAllString(string  text);
char   InvertCharacterCase(char& Char);
string InvertAllCharCase(string& text);

// Analysis
int  CountCapitalLetterInString(string& text);
int  CountSmallLetterInString(string& text);
int  CountChar(string& text, char& Char);
int  CountCharTwoCases(string& text, char& Char);
bool IsVowel(char Char);
bool IsPunctuation(char Char);
int  CountVowel(string& text);
string AllVowelInString(string& text);

// Split & Join
vector<string> vSplitString(const string& text, char Char);
vector<string> vSplitString(const string& text, string Separeater);
string TrimLeft(string text);
string TrimRight(string text);
string Trim(string text);
string JoinedString(const vector<string>& vString, char Char);
string JoinedString(const string arrString[], int length, char Char);

// Word Ops
vector<string> vReversWord(vector<string>& vString);
vector<string> vReplaceWord(vector<string>& text,
    string& oldWord, string& newWord, bool matchCase);

string RemovePunctuation(const string& text);

// Display
void PrintStringArray(const vector<string>& arr);