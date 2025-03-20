#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    int startVertex;
public:
    Graph(const std::string &filename);
    bool loadFromFile(const std::string &filename);
    std::vector<int> findShortestDistance() const;
    void printDistance() const;
};

#endif //GRAPH_H
