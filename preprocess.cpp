// Nhan Nguyen
// 11 September 2021
// CS-124-01
// Professor Chenhansa
#include "preprocess.h"
#include <iostream>
/*
    Process each word for punctuation
    @param Name of the text file.
*/
void Preprocess::process(std::string filename, std::string outputname){
    std::string temp; // Store word from text in a temp variable.
    std::ifstream in; // Declarations for input and output filestream.
    std::ofstream out;
    in.open(filename); // Open the text file.
    out.open(outputname); // Open an output for processed words.
    
    while (in >> temp){ // While loop to take in words.
        if (temp.find("’")){
            int pos = temp.find("’");
            if (pos != -1){
                temp.replace(pos, 3, "\'");
            }
        }
        if (temp.find(std::to_string('‘'))){
            int pos = temp.find("‘");
            if (temp == "‘"){
                temp = " ";
            }
            else if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        if (temp.find(std::to_string('“'))){
            int pos = temp.find("“");
            if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        if (temp.find(std::to_string('”'))){
            int pos = temp.find("”");
            if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        if (temp.find(std::to_string('—'))){
            int pos = temp.find("—");
            if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        if (temp.find(std::to_string('-'))){
            int pos = temp.find("-");
            if (pos != -1){
                temp.replace(pos, 1, " ");
            }
        }
        if (temp.find(std::to_string('–'))){
            int pos = temp.find("–");
            if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        if (temp.find(std::to_string('…'))){
            int pos = temp.find("…");
            if (pos != -1){
                temp.replace(pos, 3, " ");
            }
        }
        for (int i = 0; i < temp.size(); i++){
            int j = i; // For loop to scan the string.
            if (ispunct(temp[i])){ // If-else to check for punctuation.
                if (temp[i] == '\''){ // if equal to ', don't do anything
                    if (temp.size() == 1){ // If first character.
                        temp[i] = ' ';
                    }
                    else if (i == 0){
                        temp[i] = ' ';
                    }
                    else if (temp[i-1] == ' '){
                        temp[i] = ' ';
                    }
                }
                else if (temp[i] == ','){ // If a comma, remove it.
                    temp[i] = ' '; // If in a number, scan the number and
                    if (isdigit(temp[i+1])){ // remove it.
                        while (j < temp.size()){
                            temp[j] = temp[j+1];
                            j++;
                        }
                        temp[j-1] = ' ';
                    }
                }
                else if (temp[i] == '.'){ // If a period, remove it.
                    if (!isalpha(temp[i+1]) && !isdigit(temp[i+1])){ 
                        temp[i] = ' ';
                    }// However, if a digit and character, don't remove it.
                    if (temp[i-1] == ' '){
                        temp[i] = ' ';
                    }
                }
                else if (temp[i] == '/'){ // If a slash, if used in a date,
                    if (!(isalpha(temp[i+1]) || isdigit(temp[i+1]))){
                        temp[i] = ' '; // Remove it.
                    }
                }
                else{
                    temp[i] = ' ';
                }
            }
        } // Send processed word to processed.txt
        out << temp << " ";
    }
}