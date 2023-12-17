#pragma once
#include <iostream>
#include <unordered_map>

#define MAXNAMELEN 50
typedef struct fileNode fileNode;

struct fileNode
{
    uint16_t count = 1;
    std::string fileName;
};


uint16_t hashFunc(const std::string& s, int size);

class HashTable
{
private:
    int size;
    int length;
    fileNode *arr;
    fileNode *maxNodes;
    int * statusArr;
public:
    HashTable(int size);
    void insert(fileNode& item);
    void search(fileNode item, bool &found );
    void print();
    int getSize();
    ~HashTable();
    // std::unordered_map<uint16_t, std::string> uMap;

    std::unordered_map<std::string, int> uMap;
};


