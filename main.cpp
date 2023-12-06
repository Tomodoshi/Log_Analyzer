#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
        std::istringstream iss(line);
        std::string temp;
        iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
        if (line.length() > 11)
        {
            cout<< line << endl;
        }
    }

    infile.close();
    return 0;
}