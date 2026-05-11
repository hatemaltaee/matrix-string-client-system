#pragma once

/*
 * ================================
 * Matrix Utilities Module
 * ================================
 * Provides all matrix operations:
 * - Creation & generation
 * - Mathematical operations
 * - Analysis & validation
 * - Search & statistics
 * ================================
 */

#include <vector>

using namespace std;

/*
 * ================================
 * STRUCT: stMatrix
 * ================================
 * Stores matrix data and analysis results
 */
struct stMatrix {

    // Dimensions
    int row_random, col_random;
    int row_order, col_order;

    // Analysis
    int countNumberInMatrix;
    int number_for_search;
    int max_number, min_number;
    int number_fibonacci;

    // Matrices
    vector<vector<int>> randomMatrix;
    vector<vector<int>> orderMatrix;
    vector<vector<int>> transposeMatrix;
    vector<vector<int>> multiplyMatrix;

    // Aggregations
    vector<int> sumRows;
    vector<int> sumCols;
    vector<int> middleRow;
    vector<int> middleCol;

    vector<int> IntersectedNumberInMatrix;
    vector<int> vFibonacci;

    int totalSum = 0;

    // Flags
    bool isEqualTwoMatrix;
    bool isTypicalTwoMatrix;
    bool isIdentityMatrix;
    bool isScalarMatrix;
    bool isSparceMatrix;
    bool ExistsNumberInMatrix;
    bool vIsPalindrome;
    bool MatrixIsPalindrome;
};

/*
 * ================================
 * MATRIX FUNCTIONS
 * ================================
 */

 // Utility
int RandomNumber(int from, int to);

// Creation
vector<vector<int>> CreateRandomMatrix(int rows, int cols);
vector<vector<int>> CreateOrderedMatrix(int rows, int cols);
vector<vector<int>> TransposeMatrix(const vector<vector<int>>& matrix);
vector<vector<int>> MultiplyMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B);

// Analysis
vector<int> SumRows(const vector<vector<int>>& matrix);
vector<int> SumCols(const vector<vector<int>>& matrix);
vector<int> GetMiddleRow(const vector<vector<int>>& matrix);
vector<int> GetMiddleCol(const vector<vector<int>>& matrix);
int         TotalSum(const vector<vector<int>>& matrix);

// Display
void PrintMatrix(const vector<vector<int>>& matrix);
void PrintIntArray(const vector<int>& arr);

// Checks
bool IsEqualTwoMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B);
bool IsTypicalTwoMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B);
bool IsIdentityMatrix(const vector<vector<int>>& A);
bool IsScalarMatrix(const vector<vector<int>>& A);
bool IsSparceMatrix(const vector<vector<int>>& A);
bool ExistsNumberInMatrix(int number, const vector<vector<int>>& A);

// Search & Stats
vector<int> IntersectedNumberInMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B);

int  CountNumberInMatrix(const vector<vector<int>>& A, int& number);

void MaxAndMinNumberInMatrix(stMatrix& md,
    const vector<vector<int>>& A);

// Palindrome
bool vIsPalindrome(const vector<int>& A);
bool MatrixIsPalindrome(const vector<vector<int>>& A);

// Fibonacci
vector<int> vFibonacci(int& number);
void PrintFibonacciUsingRecurssion(int number, int privuos1, int privuos2);