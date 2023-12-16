#pragma once
#include <iostream>

#define MAXNAMELEN 50
typedef struct fileNode fileNode;

struct fileNode
{
    uint16_t count = 1;
    std::string fileName;
};



uint16_t hashFunc(const std::string& s, int size)
{
    uint16_t hashValue = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        // Multiply the ASCII value of the character by its position and add to the hash
        hashValue += static_cast<unsigned long long>(s[i]) * (i + 1);
    }

    return hashValue % size;
}

class HashTable
{
private:
    int size;
    int length;
    fileNode *arr;
    std::unordered_map<uint16_t, std::string> uMap;
    fileNode *maxNodes;
    int * statusArr;
public:
    HashTable(int size);
    void insert(fileNode& item);
    void del(fileNode item);
    void search(fileNode item, bool &found );
    void print();
    int getSize();
    ~HashTable();
};


