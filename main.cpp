#include "startup.cpp"
#include <fstream>
#include <chrono>

int main()
{

    HashTable table(30689);
    unordered_map<std::string, fileNode> map;

    auto start_time = std::chrono::high_resolution_clock::now();
    setUpMap(map);
    printMap(map);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << '\n' << duration.count();


    std::cout << "\n\n";

    start_time = std::chrono::high_resolution_clock::now();
    setUp(table);
    table.print();
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << '\n' << duration.count();

    return 0;
}
