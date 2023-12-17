#include "startup.cpp"
#include <fstream>

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
    // Output file for HashTable::print() function
    std::ofstream hashTableOutputFile("hash_table_output.txt");

    // Save the original cout stream buffer
    std::streambuf* originalCoutStreamBuffer = std::cout.rdbuf();

    // Redirect cout to the hashTableOutputFile
    std::cout.rdbuf(hashTableOutputFile.rdbuf());


    HashTable table(3557);
    setUp(table);

    std::ofstream uMapOutputFile("uMap_output.txt");
    for (const auto& entry : table.uMap)
    {
        uMapOutputFile << entry.first << " : " << entry.second << std::endl;
    };
    uMapOutputFile.close();

    table.print();

    hashTableOutputFile.close();


    std::cout.rdbuf(originalCoutStreamBuffer);

    return 0;
}