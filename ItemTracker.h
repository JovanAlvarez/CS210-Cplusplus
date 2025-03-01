#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;

public:
    void readInputFromFile(const string& filename);
    int searchItemFrequency(const string& item);
    void printItemFrequencies();
    void printHistogram();
    void backupItemFrequencies(const string& filename);
};
