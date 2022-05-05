// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa

#include <iostream>
#include <chrono>
#include <iomanip>
#include "selectionsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "linearsearch.h"
#include "binarysearch.h"
#include "preprocess.h"
using namespace std::chrono;

void printTime(double avgTimeSort[], int &timeIndex, int &avgTimeIndex, std::string choice, std::string sort){
    std::cout << std::setw(26) << std::left << sort << std::setw(6) << choice << avgTimeSort[avgTimeIndex] << std::endl;
    avgTimeIndex++;
}

void toLowerCase(std::string &input){
    for (int i = 0; i < input.size(); i++){
        input[i] = tolower(input[i]);
    } // Convert user choice to lower case for less cases to check.
}

void loadVector(std::vector<std::string> &v1, std::vector<std::string> &v2, std::string processed){
    std::fstream in;
    std::string temp;
    in.open(processed);
    while (in >> temp){
        if (temp != "a" && temp != "A" && temp != "the" 
            && temp != "The" && temp != "and" && temp != "And"){
            v2.push_back(temp);
            for (int i = 0; i < temp.size(); i++){
                temp[i] = tolower(temp[i]);
            } // Sets word to all lower case for sort vector.
            v1.push_back(temp); // Pushes back word to vector.
        }
    }
    in.close();
}

void takeTimeSelect(double timeKeep[], SelectionSort select, 
  std::vector<std::string> &v1, std::vector<std::string> &v2, 
  std::string choice, std::string sort, int j){
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    std::cout << "Doing " << sort << choice << std::endl;
    timePoint1 = high_resolution_clock::now();
    select.sort(v1, v2);
    timePoint2 = high_resolution_clock::now();
    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
    timeKeep[j] = timeSpan.count();
}

void takeTimeBubble(double timeKeep[], BubbleSort bubble, 
  std::vector<std::string> &v1, std::vector<std::string> &v2, 
  std::string choice, std::string sort, int j){
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    std::cout << "Doing " << sort << choice << std::endl;
    timePoint1 = high_resolution_clock::now();
    bubble.sort(v1, v2);
    timePoint2 = high_resolution_clock::now();
    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
    timeKeep[j] = timeSpan.count();
}

void takeTimeInsertion(double timeKeep[], InsertionSort insertion, 
  std::vector<std::string> &v1, std::vector<std::string> &v2, 
  std::string choice, std::string sort, int j){
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    std::cout << "Doing " << sort << choice << std::endl;
    timePoint1 = high_resolution_clock::now();
    insertion.sort(v1, v2);
    timePoint2 = high_resolution_clock::now();
    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
    timeKeep[j] = timeSpan.count();
}

void takeTimeMerge(double timeKeep[], MergeSort merge, 
  std::vector<std::string> &v1, std::vector<std::string> &v2, 
  std::string choice, std::string sort, int j){
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    std::cout << "Doing " << sort << choice << std::endl;
    timePoint1 = high_resolution_clock::now();
    merge.sort(v1, v2, 0, v1.size() - 1);
    timePoint2 = high_resolution_clock::now();
    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
    timeKeep[j] = timeSpan.count();
}

void takeTimeQuick(double timeKeep[], QuickSort quick, 
  std::vector<std::string> &v1, std::vector<std::string> &v2, 
  std::string choice, std::string sort, int j){
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    std::cout << "Doing " << sort << choice << std::endl;
    timePoint1 = high_resolution_clock::now();
    quick.sort(v1, v2, 0, v1.size() - 1);
    timePoint2 = high_resolution_clock::now();
    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
    timeKeep[j] = timeSpan.count();
}

int main(){
    Preprocess pre;
    SelectionSort select;
    BubbleSort bubble;
    InsertionSort insertion;
    MergeSort merge;
    QuickSort quick;
    LinearSearch linear;
    BinarySearch binary;
    std::ifstream in;
    std::ofstream out;
    std::vector<std::string> vectOutput;
    std::vector<std::string> vectSort;
    std::vector<double> vectTime;
    std::string input, choice1, choice2, temp;
    std::string fileA = "a.txt";
    std::string fileB = "b.txt", fileC = "c.txt";
    std::string processed1 = "processed1.txt";
    std::string processed2 = "processed2.txt";
    std::string sorted1 = "sorted1.txt";
    std::string sorted2 = "sorted2.txt";
    high_resolution_clock::time_point timePoint1;
    high_resolution_clock::time_point timePoint2;
    duration<double> timeSpan;
    int timeIndex = 0;
    int avgTimeIndex = 0;   
    double average = 0;
    double binarySortTime;
    double timeKeep[5];
    double avgTimeSort[20];
    double avgTimeSearch[2];
    std::string sorts[10] = {"Selection Sort (Unsorted) ", "Selection Sort (Sorted) ", 
      "Bubble Sort (Unsorted) ", "Bubble Sort (Sorted) ", "Insertion Sort (Unsorted) ", 
      "Insertion Sort (Sorted) ", "Merge Sort (Unsorted) ", "Merge Sort (Sorted) ", 
      "Quick Sort (Unsorted) ", "Quick Sort (Sorted) "};
    
    std::cout << "Welcome to the sort comparison program!" << std::endl;
    std::cout << "The program will involve two files that you will choose "
     << "and will compare 5 sorts against each other"
     << "Would you like to run or quit? (run/quit): ";
    std::cin >> input; // Get user input.

    toLowerCase(input);

    while (input != "quit"){ // If user fails input, ask for valid input.
        if (input != "run" && input != "quit"){
            while (input != "run" && input != "quit"){
                std::cout << "Please enter a valid choice (run/quit): ";
                std::cin >> input;
            }
        } // if else statement to check for user request to run or quit.
        else{
            std::cout << "Please select the 1st file." << std::endl;
            std::cout << "A: 5,000 Words" << std::endl;
            std::cout << "B: 10,000 Words" << std::endl;
            std::cout << "C: 20,000 Words" << std::endl;
            std::cout << "Select an option: ";
            std::cin >> choice1;

            for (int i = 0; i < choice1.size(); i++){
                choice1[i] = tolower(choice1[i]);
            } // Convert user choice to lower case for less cases to check.

            while (choice1 != "a" && choice1 != "b" && choice1 != "c"){
                std::cout << "Please enter a valid choice (A/B/C): ";
                std::cin >> choice1;
            }

            std::cout << "Please select the 2nd file." << std::endl;
            if (choice1 == "a"){
                std::cout << "B: 10,000 Words" << std::endl;
                std::cout << "C: 20,000 Words" << std::endl;
            }
            else if (choice1 == "b"){
                std::cout << "A: 5,000 Words" << std::endl;
                std::cout << "C: 20,000 Words" << std::endl;
            }
            else{
                std::cout << "A: 5,000 Words" << std::endl;
                std::cout << "B: 10,000 Words" << std::endl;
            }
            std::cout << "Select an option: ";
            std::cin >> choice2;

            for (int i = 0; i < choice2.size(); i++){
                choice2[i] = tolower(choice2[i]);
            } // Convert user choice to lower case for less cases to check.

            while (choice2 != "a" && choice2 != "b" && choice2 != "c"){
                if (choice1 == "a"){
                    std::cout << "Please enter a valid choice (B/C): ";
                    std::cin >> choice2;
                }
                else if (choice1 == "b"){
                    std::cout << "Please enter a valid choice (A/C): ";
                    std::cin >> choice2;
                }
                else{
                    std::cout << "Please enter a valid choice (A/B): ";
                    std::cin >> choice2;
                }
                for (int i = 0; i < choice2.size(); i++){
                    choice2[i] = tolower(choice2[i]);
                }// Convert user choice to lower case for less cases to check.
            }

            while (choice1 == choice2){
                std::cout << "Not valid, please choose a different 2nd file ";
                if (choice1 == "a"){
                    std::cout << "(B/C): ";
                    std::cin >> choice2;
                }
                else if (choice1 == "b"){
                    std::cout << "(A/C): ";
                    std::cin >> choice2;
                }
                else{
                    std::cout << "(A/B): ";
                    std::cin >> choice2;
                }
                for (int i = 0; i < choice2.size(); i++){
                    choice2[i] = tolower(choice2[i]);
                }// Convert user choice to lower case for less cases to check.
                if (choice2 != "a" && choice2 != "b" && choice2 != "c"){
                    choice2 = choice1;
                }
            }

            if (choice1 == "a" && choice2 == "b"){
                pre.process(fileA, processed1);
                pre.process(fileB, processed2);
            }
            else if (choice1 == "b" && choice2 == "a"){
                pre.process(fileB, processed1);
                pre.process(fileA, processed2);
            }
            else if (choice1 == "b" && choice2 == "c"){
                pre.process(fileB, processed1);
                pre.process(fileC, processed2);
            }
            else if (choice1 == "c" && choice2 == "b"){
                pre.process(fileC, processed1);
                pre.process(fileB, processed2);
            }
            else if (choice1 == "a" && choice2 == "c"){
                pre.process(fileA, processed1);
                pre.process(fileC, processed2);
            }
            else{
                pre.process(fileC, processed1);
                pre.process(fileA, processed2);
            }


            for (int i = 0; i < 20; i++){
                for (int j = 0; j < 5; j++){
                    switch (i){
                        case 0:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed1);
                            takeTimeSelect(timeKeep, select, vectSort, 
                              vectOutput, choice1, sorts[0], j);
                            break;
                        case 1:
                            takeTimeSelect(timeKeep, select, vectSort, 
                              vectOutput, choice1, sorts[1], j);
                            break;
                        case 2:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed2);
                            takeTimeSelect(timeKeep, select, vectSort, 
                              vectOutput, choice2, sorts[0], j);
                            break;
                        case 3:
                            takeTimeSelect(timeKeep, select, vectSort, 
                              vectOutput, choice2, sorts[1], j);
                            break;
                        case 4:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed1);
                            takeTimeBubble(timeKeep, bubble, vectSort, 
                              vectOutput, choice1, sorts[2], j);
                            break;
                        case 5:
                            takeTimeBubble(timeKeep, bubble, vectSort, 
                              vectOutput, choice1, sorts[3], j);
                            break;
                        case 6:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed2);
                            takeTimeBubble(timeKeep, bubble, vectSort, 
                              vectOutput, choice2, sorts[2], j);
                            break;
                        case 7:
                            takeTimeBubble(timeKeep, bubble, vectSort, 
                              vectOutput, choice2, sorts[3], j);
                            break;
                        case 8:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed1);
                            takeTimeInsertion(timeKeep, insertion, vectSort, 
                              vectOutput, choice1, sorts[4], j);
                            break;
                        case 9:
                            takeTimeInsertion(timeKeep, insertion, vectSort, 
                              vectOutput, choice1, sorts[5], j);
                            break;
                        case 10:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed2);
                            takeTimeInsertion(timeKeep, insertion, vectSort, 
                              vectOutput, choice2, sorts[4], j);
                            break;
                        case 11:
                            takeTimeInsertion(timeKeep, insertion, vectSort, 
                              vectOutput, choice2, sorts[5], j);
                            break;
                        case 12:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed1);
                            takeTimeMerge(timeKeep, merge, vectSort, 
                              vectOutput, choice1, sorts[6], j);
                            break;
                        case 13:
                            takeTimeMerge(timeKeep, merge, vectSort, 
                              vectOutput, choice1, sorts[7], j);
                            break;
                        case 14:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed2);
                            takeTimeMerge(timeKeep, merge, vectSort, 
                              vectOutput, choice2, sorts[6], j);
                            break;
                        case 15:
                            takeTimeMerge(timeKeep, merge, vectSort, 
                              vectOutput, choice2, sorts[7], j);
                            break;
                        case 16:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed1);
                            takeTimeQuick(timeKeep, quick, vectSort, 
                              vectOutput, choice1, sorts[8], j);
                            break;
                        case 17:
                            takeTimeQuick(timeKeep, quick, vectSort, 
                              vectOutput, choice1, sorts[9], j);
                            break;
                        case 18:
                            vectSort.clear();
                            vectOutput.clear();
                            loadVector(vectSort, vectOutput, processed2);
                            takeTimeQuick(timeKeep, quick, vectSort, 
                              vectOutput, choice2, sorts[8], j);
                            break;
                        case 19:
                            takeTimeQuick(timeKeep, quick, vectSort, 
                              vectOutput, choice2, sorts[9], j);
                            break;
                        default:
                            break;
                    }
                }
                average = 0;
                for (int j = 0; j < 5; j++){
                    average += timeKeep[j];
                    vectTime.push_back(timeKeep[j]);
                }
                average /= 5;
                avgTimeSort[i] = average;
            }
            std::cin.ignore();
            std::cout << std::setprecision(6) << std::fixed;
            std::cout << std::endl << "Sorts"  << std::setw(34) << "Average" << std::endl;
            std::cout << "********************************************" << std::endl;
            for (int j = 0; j < 10; j+=2){
                printTime(avgTimeSort, timeIndex, avgTimeIndex, choice1, sorts[j]);
                printTime(avgTimeSort, timeIndex, avgTimeIndex, choice1, sorts[j+1]);
                printTime(avgTimeSort, timeIndex, avgTimeIndex, choice2, sorts[j]);
                printTime(avgTimeSort, timeIndex, avgTimeIndex, choice2, sorts[j+1]);
                std::cout << "********************************************" << std::endl;
            }

            std::cout << "Would you like to search for a word? (Yes/No): ";
            std::cin >> input;

            for (int i = 0; i < input.size(); i++){
                input[i] = tolower(input[i]);
            } // Convert user choice to lower case for less cases to check.
            while (input != "yes" && input != "no"){
                std::cout << "Please enter a valid choice (yes/no): ";
                std::cin >> input;
            }
            while (input == "yes"){
                vectSort.clear();
                vectOutput.clear();
                loadVector(vectSort, vectOutput, processed1);
                std::cout << "What word do you want to search for?: ";
                std::cin >> input;
                for (int i = 0; i < 2; i++){
                    for (int j = 0; j < 5; j++){
                        switch (i){
                            case 0:
                                std::cout << "Doing Linear Search" << std::endl;
                                timePoint1 = high_resolution_clock::now();
                                linear.search(vectOutput, input);
                                timePoint2 = high_resolution_clock::now();
                                timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
                                timeKeep[j] = timeSpan.count();
                                break;
                            case 1:
                                if (j == 0){
                                    timePoint1 = high_resolution_clock::now();
                                    quick.sort(vectSort, vectOutput, 0, vectSort.size() - 1);
                                    timePoint2 = high_resolution_clock::now();
                                    timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
                                    binarySortTime = timeSpan.count();
                                }
                                std::cout << "Doing Binary Search" << std::endl;
                                timePoint1 = high_resolution_clock::now();
                                binary.search(vectOutput, 0, vectOutput.size() - 1, input);
                                timePoint2 = high_resolution_clock::now();
                                timeSpan = duration_cast<duration<double> >(timePoint2 - timePoint1);
                                timeKeep[j] = timeSpan.count();
                                break;
                            default:
                                break;
                        }
                    }
                    average = 0;
                    for (int j = 0; j < 5; j++){
                        average += timeKeep[j];
                    }
                    if (i == 1){
                        average += binarySortTime;
                    }
                    average /= 5;
                    avgTimeSearch[i] = average;
                }
                int found = linear.search(vectOutput, input);
                std::cin.ignore();
                std::cout << "Linear Search versus Binary Search" << std::endl;
                std::cout << "**********************************" << std::endl;
                std::cout << "Linear Average" << std::endl;
                std::cout << avgTimeSearch[0] << std::endl;
                std::cout << "Binary Average" << std::endl;
                std::cout << avgTimeSearch[1] << std::endl;
                if (found != -1){
                    std::cout << input << " found at: " << found << std::endl;
                }
                else{
                    std::cout << input << " was not found.." << std::endl;
                }
                std::cout << "Please press return to continue" << std::endl;
                std::cin.get();
            }

            std::cout << "Would you like to output the first or last 50 words? (First/Last): ";
            std::cin >> input;
            toLowerCase(input);

            while (input != "first" && input != "last"){
                std::cout << "Please enter a valid choice (First/Last): ";
                std::cin >> input;
                toLowerCase(input);
            }

            if (input == "first"){
                for (int i = 0; i < 50; i++){
                    std::cout << vectOutput[i] << " ";
                }
            }
            else{
                for (int i = vectOutput.size() - 51; i < vectOutput.size(); i++){
                    std::cout << vectOutput[i] << " ";
                }
            }

            std::cout << std::endl << std::endl << "Would you like to run again or quit? (Run/Quit): ";
            std::cin >> input; // Ask for user input to restart or quit.
            toLowerCase(input);
            vectSort.clear();
            vectOutput.clear();
            loadVector(vectSort, vectOutput, processed1);
            merge.sort(vectSort, vectOutput, 0, vectSort.size()-1);
            out.open(sorted1);
            for (int i = 0; i < vectOutput.size(); i++){
                out << vectOutput[i] << " ";
            }
            out.close(); // Close output filestream.
            vectOutput.clear();
            vectSort.clear();
            loadVector(vectSort, vectOutput, processed2);
            merge.sort(vectSort, vectOutput, 0, vectSort.size()-1);
            out.open(sorted2);
            for (int i = 0; i < vectOutput.size(); i++){
                out << vectOutput[i] << " ";
            }
            out.close(); // Close output filestream.

            avgTimeIndex = 0;
            timeIndex = 0;
            vectTime.clear();
            vectOutput.clear();
            vectSort.clear();
        }
        
    }

    return 0;
} 