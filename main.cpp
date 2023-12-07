#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "hashTable.cpp"

using namespace std;

int main()
{
    ifstream infile("access_log");

    if(!infile.is_open()) {
        cerr << "Unable to open" << endl;
        return 1;
    }
    
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string temp;
        iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
        unsigned long long result = hashFunc(line);
    }
    
    infile.close();
    return 0;
}