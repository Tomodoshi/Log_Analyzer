#pragma once
#include <iostream>
#define MAXNAMELEN 50

struct fileNode
{
    int count;
    std::string fileName;
};


typedef struct fileNode fileNode;

class HashTable
{
private:
    int size;
    int length;
    char **arr;
    int * statusArr;
public:
    HashTable(int size);
    void insert(int hashIndex, fileNode& item);
    void del(fileNode item);
    fileNode search(fileNode item);
    ~HashTable();
};


