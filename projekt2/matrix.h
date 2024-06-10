#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <queue>
using namespace std;

#pragma once
class GraphMatrix {
protected:
    int V; // liczba wierzchołków
    vector<vector<int>> matrix; // macierz sąsiedztwa

    // Własna implementacja kopca priorytetowego
    class PriorityQueue {
    private:
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    public:
        void push(int priority, int value) {
            pq.push(make_pair(priority, value));
        }

        pair<int, int> pop() {
            pair<int, int> top = pq.top();
            pq.pop();
            return top;
        }

        bool empty() const {
            return pq.empty();
        }
    };

public:
    GraphMatrix(int vertices);
    void addEdge(int x, int y, int w);
    void show();
    void fillRandomEdges(int density, int max_weight);
    void dijkstra(int source, bool show_result);
    void dijkstra_two(int source, int destination, bool show_result);
};