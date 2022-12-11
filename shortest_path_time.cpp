#include "shortest_path.h"
#include <iostream>
#include <random>
#include <numeric>
#include <chrono>
#include <ctime>

const int N = 1e8;

Graph random_graph(int size) {
    Graph graph;
    int vertices = size - 1;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution_distance(10, 100);

    for (int i = 0; i < vertices; ++i) {
        graph.add_edge(i, i + 1, distribution_distance(generator) / 10.0);
    }

    int additional_edges = random_number(size); // количество дополнительных ребер (генерируется)

    for (int i = 0; i < additional_edges; ++i) {
        int vertex_1 = random_number(size);
        int vertex_2 = random_number(size);
        if (!(graph.has_edge(vertex_1, vertex_2) || vertex_1 == vertex_2)) {
            graph.add_edge(vertex_1, vertex_2, distribution_distance(generator) / 10.0);
        }
    }

    return graph;
}

int random_number(int size) {
    srand(time(NULL));

    return rand() % size;
}

void measure_time() {
    Graph graph = random_graph(N);
    int vertex_1 = random_number(N);
    int vertex_2 = random_number(N);

    std::cout << "shortest_path: " << "N = " << N << ", " << "time = " << shortest_path_time(graph, vertex_1, vertex_2) << std::endl;
}

double shortest_path_time(const Graph& graph, int start_vertex, int end_vertex) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> result = shortest_path(graph, start_vertex, end_vertex);
    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration<double>(t2 - t1).count();

    return time;
}
