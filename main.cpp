#include "startup.cpp"
#include <fstream>

using namespace std;

int main()
{

    HashTable table(19997);
    //setUp(table);

    setUp(table);

    // ofstream outFile("hash_table_output.txt");
    // streambuf* originalCoutStreamBuffer = cout.rdbuf();
    // cout.rdbuf(outFile.rdbuf());

    table.print();

    // ofstream uMapOutputFile("uMap_output.txt");
    // for (const auto& entry : table.uMap)
    // {
    //     fileNode record = entry.second;
    //     uMapOutputFile << record.fileName << ":\t" << record.count << '\n';
    // }
   
    // uMapOutputFile.close();
    // outFile.close();

    // cout.rdbuf(originalCoutStreamBuffer);

    return 0;
}
