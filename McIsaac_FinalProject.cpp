// Filename: McIsaac_FinalProject
// Description: Final Project for COSC-A212; This program is a very basic language translator, translating between English and Spanish
// Author: Erin M. McIsaac
// Date Last Modified: 12/12/2023

// When running this file, please remember to only run in OpenGL !!! Otherwise, it won't run!

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_WORDS = 20000;

struct Translation {
    string english;
    string spanish;
};

void readTranslations(Translation translations[], int& size) {
    ifstream inFile("Translations.txt");
    if (!inFile) {
        cout << "Error opening Translations.txt" << endl;
        exit(1);
    }

    size = 0;
    while (inFile >> translations[size].english >> translations[size].spanish) {
        size++;
    }

    inFile.close();
}

void writeTranslations(const Translation translations[], int size) {
    ofstream outFile("Translations.txt");
    if (!outFile) {
        cout << "Error opening Translations.txt for writing" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        outFile << translations[i].english << " " << translations[i].spanish << endl;
    }

    outFile.close();
}

void addWord(Translation translations[], int& size) {
    if (size < MAX_WORDS) {
        cout << "Enter English Word: ";
        cin >> translations[size].english;
        cout << "Enter Spanish Translation: ";
        cin >> translations[size].spanish;

        size++;
        cout << "Thank you for adding a new word to our dictionary!" << endl;
    } else {
        cout << "Dictionary is full. Cannot add more words." << endl;
    }
}

string translate(const string& word, const Translation translations[], int size) {
    for (int i = 0; i < size; ++i) {
        if (translations[i].english == word) {
            return translations[i].spanish;
        } else if (translations[i].spanish == word) {
            return translations[i].english;
        }
    }

    return word; // Return the original word if translation not found
}

void exitTranslator() {
    cout << "Thank you for using the translator! Have a nice day." << endl;
}

int main() {
    cout << "Welcome to the Language Translator! Press Enter to start." << endl;
    cout << "---------------------------------------------------------" << endl;
    cin.get(); // Wait for a key press

    Translation translationDictionary[MAX_WORDS];
    int dictionarySize = 0;
    readTranslations(translationDictionary, dictionarySize);

    bool continueTranslation = true;

    while (continueTranslation) {
        cin.ignore(); // Clear newline from previous input
        string input;
        cout << "Enter a sentence for translation: ";
        getline(cin, input);

        istringstream iss(input);
        string word;

        while (iss >> word) {
            string translation = translate(word, translationDictionary, dictionarySize);
            cout << translation << " ";
            if (translation == word) {
                cout << "Word not recognized!" << endl;
                cout << "\nWould you like to add a new word to the dictionary? Press 1 for yes, 2 for no: ";
                char choice;
                cin >> choice;
                if (choice == '1') {
                    addWord(translationDictionary, dictionarySize);
                    writeTranslations(translationDictionary, dictionarySize);
                } else if (choice == '2') {
                    exitTranslator();
                    continueTranslation = false;
                    break; // Exit the loop
                }
            }
        }

        cout << endl;

        if (continueTranslation) {
            cout << "Would you like to translate another sentence?" << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cout << "Enter your choice: ";
            int menuChoice;
            cin >> menuChoice;

            switch (menuChoice) {
                case 1:
                    break; // Continue translation (no action needed)
                case 2:
                    exitTranslator();
                    continueTranslation = false;
                    break; // Exit the loop
            }
        }
    }

    return 0;
}
