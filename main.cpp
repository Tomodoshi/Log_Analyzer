#include "startup.cpp"
#include <fstream>

int main()
{
    std::ofstream outputFile("out.txt");

    std::streambuf* originalCoutStreamBuffer = std::cout.rdbuf();
    std::cout.rdbuf(outputFile.rdbuf());
    
    HashTable table(3557);
    setUp(table);
    table.print();
    return 0;
}