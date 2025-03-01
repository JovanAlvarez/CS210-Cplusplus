#include "ItemTracker.h"

int main() {
    ItemTracker tracker;
    tracker.readInputFromFile("CS210_Project_Three_Input_File.txt");

    int choice;
    string item;
    do {
        cout << "Menu Options:\n";
        cout << "1. Search for the frequency of a specific item\n";
        cout << "2. Print the list of items with their frequencies\n";
        cout << "3. Print a histogram representation of item frequencies\n";
        cout << "4. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue; // Continue to the next iteration of the loop
        }

        switch (choice) {
        case 1:
            cout << "Enter the item you wish to search for: ";
            cin >> item;
            cout << "Frequency of " << item << ": " << tracker.searchItemFrequency(item) << endl;
            break;
        case 2:
            tracker.printItemFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            tracker.backupItemFrequencies("frequency.dat");
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}