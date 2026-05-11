/*
 * ============================================================
 *  File        : AppRunner.cpp
 *  Description : Runs all application problem modules.
 *  Author      : Hatem Altaee Altaee
 *  Course      : C++ Level 7 - Algorithms & Problem Solving
 *                (with Mohammed Abu Hadhoud)
 * ============================================================
 */

#include <iostream>
#include "ClientData.h"
#include "StringUtils.h"

using namespace std;

// ============================================================
//  CLIENT MODULE EXECUTION
// ============================================================

void RunClientProblems() {

    stClient Client;

    // ========================================================
    //  PROBLEM 45 : Record Client Data
    // ========================================================
    PrintProblemHeader(45, "Record Client Data as a Delimited Line");

    ReadClientData(Client);
    Client.record_client = ConvertRecordToLine(Client);

    cout << "\n  Saved record:\n  " << Client.record_client << endl;

    // ========================================================
    //  PROBLEM 46 : Parse Client Record From Line
    // ========================================================
    PrintProblemHeader(46, "Parse Client Record from Delimited Line");

    cout << "\n  Parsing: " << Client.record_client << endl;

    Client.vSplitString =
        vSplitString(Client.record_client, Client.SEPAREATER);

    PrintClientRecord(Client.vSplitString);

    // ========================================================
    //  PROBLEM 47 : Add Client To File
    // ========================================================
    PrintProblemHeader(47, "Add Client To File");

    AddNewClientToFile(Client);

    // ========================================================
    //  PROBLEM 48 : Read Client Data From File
    // ========================================================
    PrintProblemHeader(48, "Read Client Data From File");

    Client.vClientDataLine =
        vGetLineClientDataFromFile(Client.ClientFile);

    Client.vClientData =
        vClientDataFromFile(Client.vClientDataLine);

    PrintVectorClientData(Client.vClientData,
        "All Client Records", true);

    // ========================================================
    //  PROBLEM 49 : Find Client By Account Number
    // ========================================================
    PrintProblemHeader(49, "Find Client By Account Number");

    Client.read_account_number =
        ReadString("Enter account number to search");

    Client.position_data =
        FindPosClientDataByAccountNumber(
            Client.vClientData,
            Client.read_account_number);

    if (!Client.position_data.empty()) {

        system("cls");

        PrintVectorClientDataByPosition(
            Client.vClientData,
            "Search Results",
            Client.position_data);
    }
    else {
        cout << "\n  [!] No client found with that account number.\n";
    }

    // ========================================================
    //  PROBLEM 50 : Remove Client By Account Number
    // ========================================================
    PrintProblemHeader(50, "Remove Client By Account Number");

    PrintVectorClientData(Client.vClientData,
        "Current Client List", false);

    Client.read_account_number =
        ReadString("Enter account number to remove");

    Client.position_data =
        FindPosClientDataByAccountNumber(
            Client.vClientData,
            Client.read_account_number);

    if (!Client.position_data.empty()) {

        RemoveClientDataByAccountNumber(
            Client.vClientData,
            Client.position_data);

        SaveVectorClientDataForFile(
            Client.vClientData,
            Client.ClientFile);

        PrintVectorClientData(
            Client.vClientData,
            "Client List After Removal",
            true);
    }
    else {
        cout << "\n  [!] No client found to remove.\n";
    }

    // ========================================================
    //  PROBLEM 51 : Update Client By Account Number
    // ========================================================
    PrintProblemHeader(51, "Update Client By Account Number");

    PrintVectorClientData(Client.vClientData,
        "Current Client List", true);

    Client.read_account_number =
        ReadString("Enter account number to Update");

    Client.position_data =
        FindPosClientDataByAccountNumber(
            Client.vClientData,
            Client.read_account_number);

    if (!Client.position_data.empty()) {

        PrintVectorClientDataByPosition(
            Client.vClientData,
            "Results For Update",
            Client.position_data);

        UpdateClientDataByAccountNumber(
            Client.vClientData,
            Client.position_data);

        SaveVectorClientDataForFile(
            Client.vClientData,
            Client.ClientFile);

        PrintVectorClientData(
            Client.vClientData,
            "Current Client List",
            true);
    }
    else {
        cout << "\n  [!] No client found to update.\n";
    }

    // ========================================================
    //  END OF MODULE
    // ========================================================
    cout << "\n" << string(55, '=') << endl;
    cout << "  All problems completed successfully!" << endl;
    cout << string(55, '=') << endl;
}