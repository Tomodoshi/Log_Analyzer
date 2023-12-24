#include <iostream>
#include "HashTable.h"
#include <string.h>
#include "sortingAlg.cpp"

uint16_t hashFunc(const std::string &s, int size)
{
    uint16_t hashValue = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        hashValue += static_cast<unsigned long long>(s[i]) * (i + 1);
    }

    return hashValue % size;
}

HashTable::HashTable(int size)
{
    length = 0;
    this->size = size;
    arr = new fileNode[size];
    statusArr = new int[size];

    for (int i = 0; i < size; i++)
        statusArr[i] = 0;
}

HashTable::~HashTable()
{
    delete[] arr;
    delete[] statusArr;
}

void HashTable::insert(fileNode &item)
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
    {
        arr[hashIndex].count++;
    }
    else
    {
        std::cerr << "Error: The table is full. "
                  << "Unable to resolve the collision" << std::endl;
    }
}

int HashTable::getSize() { return size; }

void HashTable::print()
{
    std::vector<fileNode> sortedNodes(arr, arr + size);
    std::sort(sortedNodes.begin(), sortedNodes.end(), compareFileNode);

    int count = 0;
    for(const auto& record : sortedNodes){
        std::cout << record.fileName << "\t\t:\t" << record.count << '\n';
        count++;
        if(count >= 10) break;
    }
}

bool HashTable::compareFileNode(fileNode &a, fileNode &b) { return a.count > b.count; }