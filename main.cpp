#include "Graph.h"

int main() {
    try {
        Graph graph("graph.txt");
        graph.printDistance();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
