#include "startup.cpp"
#include <fstream>

using namespace std;

// int main()
// {
//     std::ofstream outputFile("out.txt");

//     std::streambuf* originalCoutStreamBuffer = std::cout.rdbuf();
//     std::cout.rdbuf(outputFile.rdbuf());
    
//     HashTable table(3557);
//     setUp(table);
//     table.print();
//     return 0;
// }

int main()
{
    ofstream outFile("hash_table_output.txt");
    streambuf* originalCoutStreamBuffer = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    HashTable table(3557);
    setUp(table);

    ofstream uMapOutputFile("uMap_output.txt");
    // for (const auto& entry : table.getMap())
    // {
    //     uMapOutputFile << entry.first << " : " << entry.second << '\n';
    // };

    for (int i = 0; i < table.getMap().size(); i++)
    {
       uMapOutputFile << table.getMap()[i].fileName << "\t:\t" << table.getMap()[i].count << '\n';
    }
    

    uMapOutputFile.close();
    table.print();
    outFile.close();

    cout.rdbuf(originalCoutStreamBuffer);

    return 0;
}
