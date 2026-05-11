/*
 * ================================
 * Program Entry Point
 * ================================
 */

#include <iostream>
#include <ctime>
#include "AppRunner.h"

using namespace std;

int main() {

    /*
     * ================================
     * Program Information
     * ================================
     * Student : Hatem Altaee
     * Course  : Algorithms & Problem Solving
     * Level   : 7
     * Instructor : Mohammed Abu Hadhoud
     */

     /*
      * ================================
      * Random Seed Initialization
      * ================================
      */
    srand((unsigned)time(nullptr));

    /*
     * ================================
     * Run All Problem Modules
     * ================================
     */
    RunMatrixProblems();
    RunStringProblems();
    RunClientProblems();

    return 0;
}