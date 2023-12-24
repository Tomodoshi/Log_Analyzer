#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "HashTable.cpp"

using namespace std;

string split(string&, char);


void setUp(HashTable &table)
{
    // HashTable myHashTable(10);
    ifstream infile("access_log");
    

    if(!infile.is_open()) {
        cerr << "Unable to open" << endl;
    }
    
    fileNode htmlNode;
    htmlNode.fileName = "index.html";
    htmlNode.count = 0;

    string line;
    while (getline(infile, line)) {
        if(line.find("index.html")!=-1)htmlNode.count++; 

        else
        {
        istringstream iss(line);
        fileNode node;

        std::string temp;
        iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
        node.fileName = line;
        table.insert(node);
        }
    }    
    table.insert(htmlNode);
    infile.close();
}
