#pragma once

/*
 * ================================
 * Client Data Module
 * ================================
 * Handles all client-related operations:
 * - Data storage
 * - File handling
 * - CRUD operations
 * - Search & update logic
 * ================================
 */

#include <vector>
#include <string>

using namespace std;

/*
 * ================================
 * STRUCT: stClient
 * ================================
 * Represents a client record and
 * related file handling data
 */
struct stClient {

    string ClientFile = "ClientData.txt";
    string SEPAREATER = "#//#";

    string account_number;
    string name;
    string record_client = "";
    string position_data;
    string read_account_number;
    string phone;
    string pin_code;

    double account_balance;

    vector<string>   vSplitString;
    vector<string>   vClientDataLine;
    vector<stClient> vClientData;
};

/*
 * ================================
 * CLIENT OPERATIONS
 * ================================
 */

 // Data Processing
void    ReadClientData(stClient& Client);
string  ConvertRecordToLine(stClient& Client);
void    PrintClientRecord(vector<string>& vClientRecord);
void    AddClientDataToFile(string& text, const string& name_file);
void    AddNewClientToFile(stClient& Client);
stClient ConvertClientDataLineToRecord(string text);
vector<string>   vGetLineClientDataFromFile(const string& name_file);
vector<stClient> vClientDataFromFile(vector<string> vLineClientData);

// Display
void PrintVectorClientData(vector<stClient> vClientData, string message, bool clear_screen);
void PrintVectorClientDataByPosition(vector<stClient> vClientData,
    string message,
    const string& position);

// Search & Delete
string FindPosClientDataByAccountNumber(const vector<stClient>& vClientData,
    const string& account_number);

void RemoveClientDataByAccountNumber(vector<stClient>& vClientData,
    const string& position);

// File Save
void SaveVectorClientDataForFile(vector <stClient>& vClientData, string& name_file);

// Update
void UpdateClientDataByAccountNumber(vector <stClient>& vClientData,
    const string& position);