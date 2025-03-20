#include "Graph.h"

Graph::Graph(const std::string &filename) {
    if (!loadFromFile(filename)) {
        throw std::runtime_error("Failed to load graph from file");
    }
}

bool Graph::loadFromFile(const std::string &filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return false;
    }

    // Дальше предполагаем, что данные в файле указаны верно
    int m;
    fin >> numVertices >> m;

    adjList.resize(numVertices);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    fin >> startVertex;
    fin.close();
    return true;
}

//BFS
std::vector<int> Graph::findShortestDistance() const {
    std::vector<int> dist(numVertices, -1);
    std::queue<int> q;

    dist[startVertex] = 0;
    q.push(startVertex);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adjList[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist;
}

void Graph::printDistance() const {
    std::vector<int> dist = findShortestDistance();
    for (int i = 0; i < numVertices; i++) {
        if (i != startVertex) {
            std::cout << dist[i] << std::endl;
        }
    }
    std::cout << dist[startVertex] << std::endl;
}
