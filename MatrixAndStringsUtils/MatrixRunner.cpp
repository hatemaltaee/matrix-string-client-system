/*
 * ============================================================
 *  File        : MatrixRunner.cpp
 *  Description : Runs all matrix problem modules.
 *  Author      : Hatem Altaee Altaee
 *  Course      : C++ Level 7 - Algorithms & Problem Solving
 *                (with Mohammed Abu Hadhoud)
 * ============================================================
 */

#include <iostream>
#include "MatrixOperator.h"
#include "StringUtils.h"

using namespace std;

// ============================================================
//  MATRIX PROBLEMS EXECUTION
// ============================================================

void RunMatrixProblems() {

    stMatrix Matrix;

    // ========================================================
    //  MATRIX SETUP
    // ========================================================
    cout << "\n" << string(55, '=') << endl;
    cout << "  Matrix Setup" << endl;
    cout << string(55, '=') << endl;

    cout << "\n  Enter rows and cols for the RANDOM matrix  : ";
    cin >> Matrix.row_random >> Matrix.col_random;

    cout << "  Enter rows and cols for the ORDERED matrix : ";
    cin >> Matrix.row_order >> Matrix.col_order;

    // ========================================================
    //  PROBLEM 1 : Create Random Matrix
    // ========================================================
    PrintProblemHeader(1, "Create Random Matrix");

    Matrix.randomMatrix =
        CreateRandomMatrix(Matrix.row_random, Matrix.col_random);

    PrintMatrix(Matrix.randomMatrix);

    // ========================================================
    //  PROBLEM 2-3 : Row Sum
    // ========================================================
    PrintProblemHeader(2, "Sum of Each Row");

    Matrix.sumRows = SumRows(Matrix.randomMatrix);
    PrintIntArray(Matrix.sumRows);

    // ========================================================
    //  PROBLEM 4-5 : Column Sum
    // ========================================================
    PrintProblemHeader(4, "Sum of Each Column");

    Matrix.sumCols = SumCols(Matrix.randomMatrix);
    PrintIntArray(Matrix.sumCols);

    // ========================================================
    //  PROBLEM 6 : Ordered Matrix
    // ========================================================
    PrintProblemHeader(6, "Create Ordered Matrix");

    Matrix.orderMatrix =
        CreateOrderedMatrix(Matrix.row_order, Matrix.col_order);

    PrintMatrix(Matrix.orderMatrix);

    // ========================================================
    //  PROBLEM 7 : Transpose Matrix
    // ========================================================
    PrintProblemHeader(7, "Transpose Matrix");

    Matrix.transposeMatrix =
        TransposeMatrix(Matrix.orderMatrix);

    PrintMatrix(Matrix.transposeMatrix);

    // ========================================================
    //  PROBLEM 8 : Element-wise Multiplication
    // ========================================================
    PrintProblemHeader(8, "Element-wise Multiply Matrix");

    Matrix.multiplyMatrix =
        MultiplyMatrix(Matrix.orderMatrix, Matrix.orderMatrix);

    PrintMatrix(Matrix.multiplyMatrix);

    // ========================================================
    //  PROBLEM 9 : Middle Row & Column
    // ========================================================
    PrintProblemHeader(9, "Middle Row and Middle Column");

    Matrix.middleRow = GetMiddleRow(Matrix.randomMatrix);
    Matrix.middleCol = GetMiddleCol(Matrix.randomMatrix);

    cout << "\n  Middle Row:\n";
    PrintIntArray(Matrix.middleRow);

    cout << "\n  Middle Column:\n";
    PrintIntArray(Matrix.middleCol);

    // ========================================================
    //  PROBLEM 10 : Total Sum
    // ========================================================
    PrintProblemHeader(10, "Total Sum of Matrix");

    Matrix.totalSum = TotalSum(Matrix.randomMatrix);

    cout << "\n  Total Sum = " << Matrix.totalSum << endl;

    // ========================================================
    //  PROBLEM 11 : Matrix Equality (by sum)
    // ========================================================
    PrintProblemHeader(11, "Are Two Matrices Equal (by total sum)?");

    Matrix.isEqualTwoMatrix =
        IsEqualTwoMatrix(Matrix.orderMatrix, Matrix.randomMatrix);

    cout << "\n  Result: "
        << (Matrix.isEqualTwoMatrix ?
            "Yes - Matrices are EQUAL" :
            "No - Matrices are NOT equal")
        << endl;

    // ========================================================
    //  PROBLEM 12 : Matrix Identity Check
    // ========================================================
    PrintProblemHeader(12, "Are Two Matrices Identical (same values)?");

    Matrix.isTypicalTwoMatrix =
        IsTypicalTwoMatrix(Matrix.orderMatrix, Matrix.orderMatrix);

    cout << "\n  Result: "
        << (Matrix.isTypicalTwoMatrix ?
            "Yes - Matrices are IDENTICAL" :
            "No - Matrices are DIFFERENT")
        << endl;

    // ========================================================
    //  PROBLEM 13 : Identity Matrix
    // ========================================================
    PrintProblemHeader(13, "Is Identity Matrix?");

    Matrix.isIdentityMatrix =
        IsIdentityMatrix(Matrix.orderMatrix);

    cout << "\n  Result: "
        << (Matrix.isIdentityMatrix ?
            "Yes - Identity Matrix" :
            "No - Not an Identity Matrix")
        << endl;

    // ========================================================
    //  PROBLEM 14 : Scalar Matrix
    // ========================================================
    PrintProblemHeader(14, "Is Scalar Matrix?");

    Matrix.isScalarMatrix =
        IsScalarMatrix(Matrix.orderMatrix);

    cout << "\n  Result: "
        << (Matrix.isScalarMatrix ?
            "Yes - Scalar Matrix" :
            "No - Not a Scalar Matrix")
        << endl;

    // ========================================================
    //  PROBLEM 15 : Count Number Occurrences
    // ========================================================
    PrintProblemHeader(15, "Count Occurrences of a Number in Matrix");

    cout << "\n  Enter number to count : ";
    int searchNum;
    cin >> searchNum;

    Matrix.countNumberInMatrix =
        CountNumberInMatrix(Matrix.multiplyMatrix, searchNum);

    cout << "\n  Number [" << searchNum << "] appears "
        << Matrix.countNumberInMatrix << " time(s).\n";

    // ========================================================
    //  PROBLEM 16 : Sparse Matrix Check
    // ========================================================
    PrintProblemHeader(16, "Is Sparse Matrix?");

    Matrix.isSparceMatrix =
        IsSparceMatrix(Matrix.multiplyMatrix);

    cout << "\n  Result: "
        << (Matrix.isSparceMatrix ?
            "Yes - Sparse Matrix" :
            "No - Not a Sparse Matrix")
        << endl;

    // ========================================================
    //  PROBLEM 17 : Number Existence
    // ========================================================
    PrintProblemHeader(17, "Does a Number Exist in the Matrix?");

    cout << "\n  Enter number to search : ";
    cin >> Matrix.number_for_search;

    Matrix.ExistsNumberInMatrix =
        ExistsNumberInMatrix(Matrix.number_for_search, Matrix.randomMatrix);

    cout << "\n  Result: Number [" << Matrix.number_for_search << "] is "
        << (Matrix.ExistsNumberInMatrix ? "FOUND" : "NOT FOUND")
        << endl;

    // ========================================================
    //  PROBLEM 18 : Intersection Between Matrices
    // ========================================================
    PrintProblemHeader(18, "Intersected Numbers Between Two Matrices");

    Matrix.IntersectedNumberInMatrix =
        IntersectedNumberInMatrix(Matrix.randomMatrix, Matrix.orderMatrix);

    cout << "\n  Common numbers:\n";
    PrintIntArray(Matrix.IntersectedNumberInMatrix);

    // ========================================================
    //  PROBLEM 19 : Min & Max
    // ========================================================
    PrintProblemHeader(19, "Maximum and Minimum Numbers in Matrix");

    MaxAndMinNumberInMatrix(Matrix, Matrix.randomMatrix);

    cout << "\n  Maximum = " << Matrix.max_number << endl;
    cout << "  Minimum = " << Matrix.min_number << endl;

    // ========================================================
    //  PROBLEM 20 : Palindrome Matrix
    // ========================================================
    PrintProblemHeader(20, "Is the Matrix a Palindrome?");

    Matrix.MatrixIsPalindrome =
        MatrixIsPalindrome(Matrix.randomMatrix);

    cout << "\n  Result: "
        << (Matrix.MatrixIsPalindrome ?
            "Yes - Matrix IS a palindrome" :
            "No - Matrix is NOT a palindrome")
        << endl;

    // ========================================================
    //  PROBLEM 21 : Fibonacci Vector
    // ========================================================
    PrintProblemHeader(21, "Fibonacci Sequence (Vector)");

    cout << "\n  How many Fibonacci numbers? : ";
    cin >> Matrix.number_fibonacci;

    Matrix.vFibonacci =
        vFibonacci(Matrix.number_fibonacci);

    PrintIntArray(Matrix.vFibonacci);

    // ========================================================
    //  PROBLEM 22 : Fibonacci Recursion
    // ========================================================
    PrintProblemHeader(22, "Fibonacci Sequence (Recursion)");

    cout << "\n  Fibonacci (recursive): ";
    PrintFibonacciUsingRecurssion(Matrix.number_fibonacci, 0, 1);
    cout << endl;
}