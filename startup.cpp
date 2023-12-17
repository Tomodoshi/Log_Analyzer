#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashTable.cpp"

using namespace std;




void setUp(HashTable &table)
{
    HashTable myHashTable(10);
    ifstream infile("access_log");
    

    if(!infile.is_open()) {
        cerr << "Unable to open" << endl;
    }
    
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string temp;
        iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
        fileNode node;
        node.fileName = line;
        // myHashTable.uMap[hashFunc(line, table.getSize())] = line;

        table.uMap[node.fileName]++;
        table.insert(node);
    }    
    infile.close();
}