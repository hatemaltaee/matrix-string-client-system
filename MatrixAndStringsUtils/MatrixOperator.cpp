/*
 * ================================
 * Matrix Operator Module
 * ================================
 * Implements all matrix operations:
 * - Creation
 * - Transformation
 * - Analysis
 * - Validation
 * - Statistics
 * - Algorithms (Fibonacci, Palindrome)
 * ================================
 */

#include "MatrixOperator.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * ================================
 * UTILITY FUNCTIONS
 * ================================
 */

 // Generates a random number in a range
int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

/*
 * ================================
 * MATRIX CREATION
 * ================================
 */

 // Creates matrix with random values
vector<vector<int>> CreateRandomMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = RandomNumber(1, 100);

    return matrix;
}

// Creates ordered sequential matrix
vector<vector<int>> CreateOrderedMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    int counter = 1;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = counter++;

    return matrix;
}

// Transposes matrix
vector<vector<int>> TransposeMatrix(const vector<vector<int>>& matrix) {
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];

    return result;
}

// Element-wise multiplication
vector<vector<int>> MultiplyMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {

    int rows = (int)A.size();
    int cols = (int)A[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] * B[i][j];

    return result;
}

/*
 * ================================
 * MATRIX ANALYSIS
 * ================================
 */

 // Row sums
vector<int> SumRows(const vector<vector<int>>& matrix) {
    vector<int> sums;

    for (const auto& row : matrix) {
        int sum = 0;
        for (int val : row) sum += val;
        sums.push_back(sum);
    }

    return sums;
}

// Column sums
vector<int> SumCols(const vector<vector<int>>& matrix) {
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();

    vector<int> sums(cols, 0);

    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            sums[j] += matrix[i][j];

    return sums;
}

// Middle row
vector<int> GetMiddleRow(const vector<vector<int>>& matrix) {
    return matrix[matrix.size() / 2];
}

// Middle column
vector<int> GetMiddleCol(const vector<vector<int>>& matrix) {
    vector<int> col;
    int mid = (int)matrix[0].size() / 2;

    for (int i = 0; i < (int)matrix.size(); i++)
        col.push_back(matrix[i][mid]);

    return col;
}

// Total sum of matrix
int TotalSum(const vector<vector<int>>& matrix) {
    int sum = 0;

    for (const auto& row : matrix)
        for (int val : row)
            sum += val;

    return sum;
}

/*
 * ================================
 * MATRIX DISPLAY
 * ================================
 */

 // Prints matrix
void PrintMatrix(const vector<vector<int>>& matrix) {
    cout << string(45, '-') << endl;

    for (int i = 0; i < (int)matrix.size(); i++) {
        cout << "  Row " << setw(2) << i + 1 << " | ";

        for (int j = 0; j < (int)matrix[i].size(); j++)
            cout << setw(5) << matrix[i][j];

        cout << endl;
    }

    cout << string(45, '-') << endl;
}

// Prints integer array
void PrintIntArray(const vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++)
        cout << "  [" << setw(2) << i + 1 << "] = " << arr[i] << endl;
}

// Prints string array
void PrintStringArray(const vector<string>& arr) {
    for (int i = 0; i < (int)arr.size(); i++)
        cout << "  [" << setw(2) << i + 1 << "] = " << arr[i] << endl;
}

/*
 * ================================
 * MATRIX VALIDATION
 * ================================
 */

 // Compare total sum
bool IsEqualTwoMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    return (TotalSum(A) == TotalSum(B));
}

// Exact equality check
bool IsTypicalTwoMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {

    int rowA = (int)A.size(), rowB = (int)B.size();
    int colA = (int)A[0].size(), colB = (int)B[0].size();

    if (rowA != rowB || colA != colB) return false;

    for (int i = 0; i < rowA; i++)
        for (int j = 0; j < colA; j++)
            if (A[i][j] != B[i][j]) return false;

    return true;
}

// Identity matrix check
bool IsIdentityMatrix(const vector<vector<int>>& A) {
    int row = (int)A.size();
    int col = (int)A[0].size();

    if (row != col) return false;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            if (i == j && A[i][j] != 1) return false;
            if (i != j && A[i][j] != 0) return false;
        }

    return true;
}

// Scalar matrix check
bool IsScalarMatrix(const vector<vector<int>>& A) {
    int row = (int)A.size();
    int col = (int)A[0].size();

    if (row != col) return false;

    int scalar = A[0][0];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            if (i == j && A[i][j] != scalar) return false;
            if (i != j && A[i][j] != 0) return false;
        }

    return true;
}

// Sparse matrix check
bool IsSparceMatrix(const vector<vector<int>>& A) {
    int row = (int)A.size();
    int col = (int)A[0].size();
    int total = row * col;
    int zeros = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (A[i][j] == 0) zeros++;

    return (zeros > total / 2);
}

// Search number
bool ExistsNumberInMatrix(int number, const vector<vector<int>>& A) {
    for (const auto& row : A)
        for (int val : row)
            if (val == number) return true;

    return false;
}

/*
 * ================================
 * MATRIX STATISTICS
 * ================================
 */

 // Intersection
vector<int> IntersectedNumberInMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {

    vector<int> vIntersected;

    for (const auto& row : A)
        for (int val : row)
            if (ExistsNumberInMatrix(val, B))
                vIntersected.push_back(val);

    return vIntersected;
}

// Count occurrences
int CountNumberInMatrix(const vector<vector<int>>& A, int& number) {
    int counter = 0;

    for (const auto& row : A)
        for (int val : row)
            if (val == number) counter++;

    return counter;
}

// Min & Max
void MaxAndMinNumberInMatrix(stMatrix& md,
    const vector<vector<int>>& A) {

    int row = (int)A.size();
    int col = (int)A[0].size();

    md.max_number = A[0][0];
    md.min_number = A[0][0];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            if (A[i][j] > md.max_number) md.max_number = A[i][j];
            if (A[i][j] < md.min_number) md.min_number = A[i][j];
        }
}

/*
 * ================================
 * PALINDROME
 * ================================
 */

 // Vector palindrome
bool vIsPalindrome(const vector<int>& A) {
    int col = (int)A.size();

    for (int i = 0; i < col / 2; i++)
        if (A[i] != A[col - i - 1]) return false;

    return true;
}

// Matrix palindrome
bool MatrixIsPalindrome(const vector<vector<int>>& A) {
    for (const auto& row : A)
        if (!vIsPalindrome(row)) return false;

    return true;
}

/*
 * ================================
 * FIBONACCI
 * ================================
 */

 // Generate Fibonacci
vector<int> vFibonacci(int& number) {
    vector<int> fib;

    fib.push_back(1);
    if (number == 1) return fib;

    fib.push_back(1);

    for (int i = 2; i < number; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    return fib;
}

// Recursive print
void PrintFibonacciUsingRecurssion(int number, int privuos1, int privuos2) {
    if (number > 0) {
        int fibonacci = privuos1 + privuos2;
        cout << fibonacci << "  ";
        PrintFibonacciUsingRecurssion(number - 1, fibonacci, privuos1);
    }
}