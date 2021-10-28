// Copyright (c) 2021 Mikayla Barthelette All rights reserved
//
// Created by: Mikayla Barthelette
// Created on: Oct 2021
// This program finds the average of a list of marks

#include <iostream>
#include <list>
#include <string>

float averageOfMarks(std::list<int> marks) {
    // this function finds the average of the marks

    int theSum = 0;
    float theAverage = 0.0;

    theSum = 0;
    for (int aSingleMark : marks) {
        theSum = theSum + aSingleMark;
    }

    theAverage = theSum / marks.size();

    return theAverage;
}

main() {
    // this function calls other functions

    std::list<int> marks;
    int loopCounter = 0;
    std::string userInput;
    int tempMark;
    float average;

    // input
    std::cout << "Please enter 1 mark at a time. Enter -1 to end." << std::endl;
    std::cout << std::endl;

    // process
    while (true) {
        std::cout << "What is your mark? (as %): ";
        std::cin >> userInput;
        loopCounter = loopCounter + 1;
        try {
            tempMark = std::stoi(userInput);
            if (tempMark == -1) {
                break;
            } else if (tempMark < 0 || tempMark > 100) {
                std::cout << "\nPlease enter a mark between 0 - 100."
                << std::endl;
                std::cout << "\nDone." << std::endl;
                throw;
            } else {
                marks.push_back(tempMark);
            }
        } catch (std::invalid_argument) {
            std::cout << "\nInvalid input." << std::endl;
            std::cout << "\nDone." << std::endl;
            throw;
        }
    }

    average = averageOfMarks(marks);

    // output
    std::cout << "\nThe average is " << average << "%" << std::endl;
    std::cout << "\nDone." << std::endl;
}
