#include "ItemTracker.h"

// Function to read input from a file and update item frequencies
void ItemTracker::readInputFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Function to search for the frequency of a specific item
int ItemTracker::searchItemFrequency(const string& item) {
    return itemFrequency[item];
}

// Function to print the list of items with their frequencies
void ItemTracker::printItemFrequencies() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to print a histogram representation of item frequencies
void ItemTracker::printHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to back up item frequencies to a data file
void ItemTracker::backupItemFrequencies(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create backup file " << filename << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}
