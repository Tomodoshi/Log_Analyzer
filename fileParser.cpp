#include <iostream>
#include <fstream>

void parse(int &arr)
{
    std::ifstream infile("access_log");

    
    
    std ::string line;
    while (std::getline(infile, line)) {
        std::string temp;
        std::string filename;
        infile >> temp >> temp >> temp >> temp >> temp >> filename;

        std::cout << filename << '\n';
    }

}


struct fileNode
{
    int count;
    std::string fileName;
};


