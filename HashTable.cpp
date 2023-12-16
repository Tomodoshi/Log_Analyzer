#include <iostream>
#include <string.h>
#include "HashTable.h"
#include <algorithm>
#include <vector>


uint16_t hashFunc(const std::string& s, int size)
{
    uint16_t hashValue = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        hashValue += static_cast<unsigned long long>(s[i]) * (i + 1);
    }

    return hashValue % size;
}

HashTable::HashTable(int size)
{
    length = 0;
    this-> size = size;
    arr = new fileNode[size];
    statusArr = new int[size];

    for (int i = 0; i < size; i++) statusArr[i] = 0;
    
}

HashTable::~HashTable()
{
    delete[] arr;
    delete[] statusArr;
}


void HashTable::insert(fileNode& item)
{
    int hashIndex = hashFunc(item.fileName, size);
    uint16_t pcount = 0;
    uint16_t inc = 1;

    while (statusArr[hashIndex] == 1 && arr[hashIndex].fileName != item.fileName && pcount < size / 2)
    {
        pcount++;
        hashIndex = (hashIndex + inc) % size;
        inc += 2;
    }

    if (statusArr[hashIndex] != 1)
    {
        arr[hashIndex] = item; 
        statusArr[hashIndex] = 1;
        length++;
    }
    else if (arr[hashIndex].fileName == item.fileName)
        arr[hashIndex].count++;
    else
        std::cerr << "Error: The table is full. " << "Unable to resolve the collision" << std::endl;
}

int HashTable::getSize()
{
    return size;
}

void HashTable::search(fileNode item, bool& found)
{
    int hashIndex = hashFunc(item.fileName, size);
    int pCount = 0;
    int inc = 1;

    while (statusArr[hashIndex] != 0 && arr[hashIndex].fileName != item.fileName && pCount < size / 2)
    {
        pCount++;
        hashIndex = (hashIndex + inc) % size;
        inc = inc + 2;
    }

    if (statusArr[hashIndex] == 1 && arr[hashIndex].fileName == item.fileName)
        found = true;
    else
        found = false;
}


void HashTable::print()
{

    std::vector<fileNode> nodeVector;


    for (int i = 0; i < size; i++)
    {
        if (statusArr[i])
        {
            nodeVector.push_back(arr[i]);
        }
    }

    std::sort(nodeVector.begin(), nodeVector.end(),
              [](const fileNode &a, const fileNode &b) {
                  return a.count > b.count;
              });


    int printCount = std::min(10, static_cast<int>(nodeVector.size()));
    for (int i = 0; i < printCount; i++)
    {
        std::cout << nodeVector[i].fileName << "\t : \t" << nodeVector[i].count << "\n";
    }
}




