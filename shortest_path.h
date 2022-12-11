#pragma once
#include "graph.h"

#include <vector>
using namespace std;




std::vector<int> shortest_path(const Graph& graph, int start_vertex, int end_vertex);

void measure_time();
Graph random_graph(int size);
int random_number(int size);
double shortest_path_time(const Graph& graph, int start_vertex, int end_vertex);
