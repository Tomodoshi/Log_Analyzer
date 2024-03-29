#ifndef HASHTABLE
#define HASHTABLE

#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#define MAXNAMELEN 50
typedef struct fileNode fileNode;

struct fileNode
{
    uint32_t count = 1;
    std::string fileName;
};

uint16_t hashFunc(const std::string &s, int size);

class HashTable
{
private:
    int size;
    int length;
    fileNode *arr;
    int *statusArr;

public:
    HashTable(int size);
    void insert(fileNode &item);
    void print();
    int getSize();
    static bool compareFileNode(fileNode &a, fileNode &b);
    ~HashTable();
};

#endif //HASHTABLE