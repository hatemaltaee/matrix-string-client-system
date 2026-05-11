/*
 * ================================
 * Client Data Module Implementation
 * ================================
 * Handles all client-related operations:
 * - Data input/output
 * - File storage & retrieval
 * - Search, update, delete operations
 * ================================
 */

#include "ClientData.h"
#include "StringUtils.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
 * ================================
 * CLIENT DATA OPERATIONS
 * ================================
 */

 // Reads client data from user input
void ReadClientData(stClient& Client) {
    cout << "\n" << string(45, '=') << endl;
    cout << "  Enter Client Data" << endl;
    cout << string(45, '=') << endl;

    Client.account_number = ReadString("Account Number");
    Client.pin_code = ReadString("PIN Code      ");
    Client.name = ReadString("Full Name     ");
    Client.phone = ReadString("Phone Number  ");
    Client.account_balance = ReadDouble("Balance       ");
}

// Converts client object into a single formatted line for file storage
string ConvertRecordToLine(stClient& Client) {
    return Client.account_number + Client.SEPAREATER
        + Client.pin_code + Client.SEPAREATER
        + Client.name + Client.SEPAREATER
        + Client.phone + Client.SEPAREATER
        + to_string(Client.account_balance);
}

// Displays a single client record
void PrintClientRecord(vector<string>& vClientRecord) {
    cout << "\n" << string(45, '-') << endl;
    cout << "  Account Number  : " << vClientRecord[0] << endl;
    cout << "  PIN Code        : " << vClientRecord[1] << endl;
    cout << "  Name            : " << vClientRecord[2] << endl;
    cout << "  Phone           : " << vClientRecord[3] << endl;
    cout << "  Account Balance : " << vClientRecord[4] << endl;
    cout << string(45, '-') << endl;
}

// Appends a record line to file
void AddClientDataToFile(string& text, const string& name_file) {
    fstream client_file;
    client_file.open(name_file, ios::out | ios::app);

    if (client_file.is_open()) {
        client_file << text << endl;
        client_file.close();
    }
}

// Adds multiple clients until user stops
void AddNewClientToFile(stClient& Client) {
    int addMore;

    do {
        system("cls");

        ReadClientData(Client);
        Client.record_client = ConvertRecordToLine(Client);

        AddClientDataToFile(Client.record_client, Client.ClientFile);

        addMore = ReadInt("Client saved! Add another? Yes[any number] / No[0]");

    } while (addMore);
}

/*
 * ================================
 * FILE PARSING
 * ================================
 */

 // Converts a file line into a client object
stClient ConvertClientDataLineToRecord(string text) {
    stClient Client;
    vector<string> parts = vSplitString(text, Client.SEPAREATER);

    Client.account_number = parts[0];
    Client.pin_code = parts[1];
    Client.name = parts[2];
    Client.phone = parts[3];
    Client.account_balance = stod(parts[4]);

    return Client;
}

// Reads all lines from file
vector<string> vGetLineClientDataFromFile(const string& name_file) {
    vector<string> lines;
    ifstream file;
    string line;

    file.open(name_file, ios::in);

    if (file.is_open()) {
        while (getline(file, line))
            lines.push_back(line);

        file.close();
    }

    return lines;
}

// Converts file lines into client objects
vector<stClient> vClientDataFromFile(vector<string> vLineClientData) {
    vector<stClient> clients;

    for (int i = 0; i < (int)vLineClientData.size(); i++)
        clients.push_back(ConvertClientDataLineToRecord(vLineClientData[i]));

    return clients;
}

/*
 * ================================
 * CLIENT DISPLAY
 * ================================
 */

 // Displays all clients in formatted table
void PrintVectorClientData(vector<stClient> vClientData, string message, bool clear_screen) {
    if (clear_screen)
        system("cls");

    cout << "\n" << string(90, '=') << endl;
    cout << "  " << message << endl;
    cout << string(90, '=') << endl;

    cout << left
        << setw(4) << "No."
        << setw(18) << "| Account Number"
        << setw(12) << "| PIN Code"
        << setw(35) << "| Name"
        << setw(17) << "| Phone"
        << "| Balance"
        << endl;

    cout << string(90, '-') << endl;

    for (int i = 0; i < (int)vClientData.size(); i++) {
        cout << left
            << setw(4) << i + 1
            << "| " << setw(16) << vClientData[i].account_number
            << "| " << setw(10) << vClientData[i].pin_code
            << "| " << setw(35) << vClientData[i].name
            << "| " << setw(15) << vClientData[i].phone
            << "| " << vClientData[i].account_balance
            << endl;
    }

    cout << string(90, '=') << endl;
}

// Displays clients based on encoded positions
void PrintVectorClientDataByPosition(vector<stClient> vClientData,
    string message,
    const string& position) {

    cout << "\n" << string(90, '=') << endl;
    cout << "  " << message << endl;
    cout << string(90, '=') << endl;

    cout << left
        << setw(4) << "No."
        << setw(18) << "| Account Number"
        << setw(12) << "| PIN Code"
        << setw(35) << "| Name"
        << setw(17) << "| Phone"
        << "| Balance"
        << endl;

    cout << string(90, '-') << endl;

    for (int i = 0; i < (int)position.length(); i++) {
        int idx = (unsigned char)position[i];

        cout << left
            << setw(4) << i + 1
            << "| " << setw(16) << vClientData[idx].account_number
            << "| " << setw(10) << vClientData[idx].pin_code
            << "| " << setw(35) << vClientData[idx].name
            << "| " << setw(15) << vClientData[idx].phone
            << "| " << vClientData[idx].account_balance
            << endl;
    }

    cout << string(90, '=') << endl;
}

/*
 * ================================
 * SEARCH & DELETE OPERATIONS
 * ================================
 */

 // Finds positions of clients by account number
string FindPosClientDataByAccountNumber(const vector<stClient>& vClientData,
    const string& account_number) {

    string position = "";

    for (int i = 0; i < (int)vClientData.size(); i++)
        if (vClientData[i].account_number == account_number)
            position += (char)i;

    return position;
}

// Removes clients from vector using encoded positions
void RemoveClientDataByAccountNumber(vector<stClient>& vClientData,
    const string& position) {

    for (int i = (int)position.length() - 1; i >= 0; i--)
        vClientData.erase(vClientData.begin() + (unsigned char)position[i]);
}

/*
 * ================================
 * FILE SAVE & UPDATE
 * ================================
 */

 // Saves all clients back to file
void SaveVectorClientDataForFile(vector<stClient>& vClientData, string& name_file) {
    ofstream client_file;

    client_file.open(name_file, ios::out);

    if (client_file.is_open()) {
        for (int i = 0; i < (int)vClientData.size(); i++)
            client_file << ConvertRecordToLine(vClientData[i]) << endl;

        client_file.close();
    }
}

// Updates client data by position
void UpdateClientDataByAccountNumber(vector<stClient>& vClientData,
    const string& position) {

    for (int i = 0; i < (int)position.length(); i++) {

        cout << "\nEdit Client " << i + 1 << " : " << endl;

        vClientData[i].account_number = ReadString("Account Number");
        vClientData[i].pin_code = ReadString("PIN Code      ");
        vClientData[i].name = ReadString("Full Name     ");
        vClientData[i].phone = ReadString("Phone Number  ");
        vClientData[i].account_balance = ReadDouble("Balance       ");
    }
}