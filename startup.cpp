#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashTable.cpp"


using namespace std;
void setUp(HashTable &table)
{
    std::ifstream infile("access_log");

    if (!infile.is_open())
    {
        cerr << "Unable to open" << endl;
    }

    fileNode htmlNode;
    htmlNode.fileName = "index.html";
    htmlNode.count = 0;

    string line;
    while (getline(infile, line))
    {
        if (line.find("index.html") != -1)
            htmlNode.count++;
        else
        {
            istringstream iss(line);
            fileNode node;

            std::string temp;
            iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
            node.fileName = line;
            table.insert(node);
        }
    }
    table.insert(htmlNode);
    infile.close();
}

void setUpMap(unordered_map<std::string, fileNode> &map)
{
    ifstream infile("access_log");

    if (!infile.is_open())
    {
        cerr << "Unable to open" << endl;
    }

    fileNode htmlNode;
    htmlNode.fileName = "index.html";
    htmlNode.count = 0;

    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        fileNode node;

        if (line.find("index.html") != -1)
            htmlNode.count++;
        else
        {

            std::string temp;
            iss >> temp >> temp >> temp >> temp >> temp >> temp >> line;
            node.fileName = line;
            if (map.find(line) != map.end())
                map[line].count++;
            else
                map[line] = node;
        }
    }
    map["index.html"] = htmlNode;
}

bool compareFileNode(const std::pair<std::string, fileNode> &a, const std::pair<std::string, fileNode> &b)
{
    return a.second.count > b.second.count;
}

void printMap(unordered_map<std::string, fileNode> &map)
{
    std::vector<std::pair<std::string, fileNode>> vec(map.begin(), map.end());
    std::sort(vec.begin(), vec.end(), compareFileNode);

    int count = 0;
    for (const auto &record : vec)
    {
        std::cout << record.first << ": " << record.second.count << '\n';
        count++;
        if (count >= 10)
            break;
    }
}
