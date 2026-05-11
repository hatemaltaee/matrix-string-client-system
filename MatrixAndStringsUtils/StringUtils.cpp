/*
 * ============================================================
 *  File        : StringUtils.cpp
 *  Description : String utilities implementation module
 *  Author      : Hatem Altaee Altaee
 *  Course      : C++ Level 7 - Algorithms & Problem Solving
 *                (with Mohammed Abu Hadhoud)
 * ============================================================
 */

#include "StringUtils.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// ============================================================
//  SECTION: Problem Header
// ============================================================

void PrintProblemHeader(int number, const string& title) {
    cout << "\n" << string(55, '=') << endl;
    cout << "  Problem " << setw(2) << number << " : " << title << endl;
    cout << string(55, '=') << endl;
}

// ============================================================
//  SECTION: Input Utilities
// ============================================================

string ReadString(string message) {
    string text;
    cout << "\n  " << message << " : ";
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, text);
    return text;
}

int ReadInt(string message) {
    int number;

    while (true) {
        cout << "\n  " << message << " : ";
        cin >> number;

        if (cin.fail()) {
            cout << "  [!] Invalid input. Enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return number;
        }
    }
}

double ReadDouble(string message) {
    string input;
    double number;

    while (true) {
        cout << "\n  " << message << " : ";

        if (cin.peek() == '\n')
            cin.ignore();

        getline(cin, input);

        try {
            number = stod(input);
            return number;
        }
        catch (...) {
            cout << "  [!] Invalid input. Enter a valid number.\n";
        }
    }
}

char ReadChar(string message) {
    char Letter;
    cout << "\n  " << message << " : ";
    cin >> Letter;
    return Letter;
}

// ============================================================
//  SECTION: String Operations
// ============================================================

string GetLettersOfString(string& text) {
    string letters = "";
    letters += text[0];

    for (int i = 0; i < (int)text.length() - 1; i++)
        if (text[i] == ' ')
            letters += text[i + 1];

    return letters;
}

void PrintCharOfString(const string& text) {
    for (int i = 0; i < (int)text.length(); i++)
        cout << "  [" << i + 1 << "] = " << text[i] << endl;
}

string UpperFirstLetterOfEachWord(string& text) {
    text[0] = toupper(text[0]);

    for (int i = 0; i < (int)text.length() - 1; i++)
        if (text[i] == ' ')
            text[i + 1] = toupper(text[i + 1]);

    return text;
}

string LowerFirstLetterOfEachWord(string& text) {
    text[0] = tolower(text[0]);

    for (int i = 0; i < (int)text.length() - 1; i++)
        if (text[i] == ' ')
            text[i + 1] = tolower(text[i + 1]);

    return text;
}

string ToUpperAllString(string text) {
    for (int i = 0; i < (int)text.length(); i++)
        text[i] = toupper(text[i]);

    return text;
}

string ToLowerAllString(string text) {
    for (int i = 0; i < (int)text.length(); i++)
        text[i] = tolower(text[i]);

    return text;
}

char InvertCharacterCase(char& Char) {
    return isupper(Char) ? tolower(Char) : toupper(Char);
}

string InvertAllCharCase(string& text) {
    for (int i = 0; i < (int)text.length(); i++)
        text[i] = InvertCharacterCase(text[i]);

    return text;
}

// ============================================================
//  SECTION: Character Analysis
// ============================================================

int CountCapitalLetterInString(string& text) {
    int count = 0;

    for (char c : text)
        if (isupper(c)) count++;

    return count;
}

int CountSmallLetterInString(string& text) {
    int count = 0;

    for (char c : text)
        if (islower(c)) count++;

    return count;
}

int CountChar(string& text, char& Char) {
    int count = 0;

    for (char c : text)
        if (c == Char) count++;

    return count;
}

int CountCharTwoCases(string& text, char& Char) {
    int count = CountChar(text, Char);
    Char = InvertCharacterCase(Char);
    count += CountChar(text, Char);

    return count;
}

// ============================================================
//  SECTION: Vowels & Punctuation
// ============================================================

bool IsVowel(char Char) {
    string vowels = "aeiouAEIOU";

    for (char v : vowels)
        if (Char == v) return true;

    return false;
}

bool IsPunctuation(char Char) {
    string punctuations = ".,!?;:\"'()[]{}-_/\\";

    for (char p : punctuations)
        if (Char == p) return true;

    return false;
}

int CountVowel(string& text) {
    int count = 0;

    for (char c : text)
        if (IsVowel(c)) count++;

    return count;
}

string AllVowelInString(string& text) {
    string vowels = "";

    for (char c : text)
        if (IsVowel(c)) {
            vowels += c;
            vowels += ' ';
        }

    return vowels;
}

// ============================================================
//  SECTION: Split & Join
// ============================================================

vector<string> vSplitString(const string& text, char Char) {
    vector<string> tokens;
    string word = "";

    for (char c : text) {
        if (c != Char)
            word += c;
        else {
            tokens.push_back(word);
            word = "";
        }
    }

    tokens.push_back(word);
    return tokens;
}

vector<string> vSplitString(const string& text, string Separeater) {
    vector<string> tokens;
    string word = "";

    for (int i = 0; i < (int)text.length(); i++) {
        int j = 0;

        while (j < (int)Separeater.length()
            && i + j < (int)text.length()
            && Separeater[j] == text[i + j])
            j++;

        if (j == (int)Separeater.length()) {
            tokens.push_back(word);
            word = "";
            i += (int)Separeater.length() - 1;
        }
        else {
            word += text[i];
        }
    }

    tokens.push_back(word);
    return tokens;
}

// ============================================================
//  SECTION: Trimming
// ============================================================

string TrimLeft(string text) {
    for (int i = 0; i < (int)text.length(); i++)
        if (!isspace(text[i]))
            return text.substr(i);

    return "";
}

string TrimRight(string text) {
    while (!text.empty() && isspace(text.back()))
        text.pop_back();

    return text;
}

string Trim(string text) {
    return TrimRight(TrimLeft(text));
}

// ============================================================
//  SECTION: Joining Strings
// ============================================================

string JoinedString(const vector<string>& vString, char Char) {
    string joined = "";

    for (int i = 0; i < (int)vString.size(); i++) {
        joined += vString[i];

        if (i != (int)vString.size() - 1)
            joined += Char;
    }

    return joined;
}

string JoinedString(const string arrString[], int length, char Char) {
    string joined = "";

    for (int i = 0; i < length; i++) {
        joined += arrString[i];

        if (i != length - 1)
            joined += Char;
    }

    return joined;
}

// ============================================================
//  SECTION: Word Operations
// ============================================================

vector<string> vReversWord(vector<string>& vString) {
    vector<string> reversed;

    for (int i = 0; i < (int)vString.size(); i++)
        reversed.push_back(vString[vString.size() - 1 - i]);

    return reversed;
}

vector<string> vReplaceWord(vector<string>& text,
    string& oldWord, string& newWord, bool matchCase) {

    for (string& w : text) {
        if (!matchCase) {
            if (ToLowerAllString(w) == ToLowerAllString(oldWord))
                w = newWord;
        }
        else {
            if (w == oldWord)
                w = newWord;
        }
    }

    return text;
}

string RemovePunctuation(const string& text) {
    string result = "";

    for (char c : text)
        if (!IsPunctuation(c))
            result += c;

    return result;
}