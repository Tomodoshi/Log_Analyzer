#include "startup.cpp"
#include <fstream>

using namespace std;

int main()
{

    HashTable table(19997);
    unordered_map<std::string, fileNode> map;

    ofstream outFile("hash_table_output.txt");
    streambuf *originalCoutStreamBuffer = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    setUpMap(map);
    printMap(map);

    ofstream uMapOutputFile("uMap_output.txt");

    uMapOutputFile.close();
    outFile.close();

    cout.rdbuf(originalCoutStreamBuffer);

    return 0;
}
