#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <queue>
#include <utility>
#pragma once

using namespace std;

class GraphList {
public:
    GraphList(int vertices);
    void addEdge(int x, int y, int w);
    void show();
    void fillRandomEdges(int density, int maxWeight);
    bool hasEdge(int x, int y);
    void addRandomEdge(int x, int y, int maxWeight);
    void dijkstra(int source, bool showResult);
    void dijkstra_two(int source, int destination, bool showResult);

private:
    int V;
    vector<vector<pair<int, int>>> List;

    // porównywanie w priority q
    struct Compare {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        }
    };
};
