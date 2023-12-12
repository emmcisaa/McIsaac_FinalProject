// Filename: McIsaac_FinalProject
// Description: Final Project for COSC-A212; This program is a very basic language translator, translating between English and Spanish
// Author: Erin M. McIsaac
// Date Last Modified: 12/12/2023

#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ifstream inFile;
    ofstream outFile;
    char inName[200];
    char outName[] = "out.txt";  // Output file name is fixed
    char input;
    int direction;

    // Enter the input file
    cout << "Enter the input file name (i.e., English.txt): ";
    cin >> inName;
    inFile.open(inName);


    // Enter the output file
    cout << "Output will be written to: " << outName << endl;
    outFile.open(outName);

    // Testing inFile (for failure)
    if (!inFile) 
    {
        cout << "Error opening " << inName << endl;
        return 2;
    }

    // Testing outFile (for failure)
    if (!outFile) 
    {
        cout << "Error opening " << outName << endl;
        return 6;
    }

    cout << "Enter 1 to translate to Spanish. Enter 2 to translate to English." << endl;
    cin >> direction;

    while (inFile.get(input)) 
    {
        if (direction == 1) 
        {
            // Translate to Spanish (example: shift characters by 1 positions)
            input += 1;
        } 
        else 
        {
            // Translate to English (example: shift characters back by 1 positions)
            input -= 1;
        }
        outFile.put(input);
    }

    cout << "The file " << outName << " has been processed." << endl;
    inFile.close();
    outFile.close();

    return 0;
}