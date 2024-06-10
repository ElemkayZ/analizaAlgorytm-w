#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <queue>
#include "matrix.h"
using namespace std;


GraphMatrix::GraphMatrix(int vertices) {
    V = vertices;
    matrix.resize(V, vector<int>(V, 0));
}

void GraphMatrix::addEdge(int x, int y, int w) {
    matrix[x][y] = w;
    matrix[y][x] = w;
}

void GraphMatrix::show() {
    cout << "Macierz:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void GraphMatrix::fillRandomEdges(int density, int max_weight) {
    srand(time(nullptr));
    int x, y, w;
    int threshold = (V * (V - 1) / 2) * density / 100;
    int edgesCount = 0;
    while (edgesCount < threshold) {
        x = rand() % V;
        y = rand() % V;
        w = rand() % max_weight + 1;
        if (matrix[x][y] == 0 && x != y) {
            addEdge(x, y, w);
            edgesCount++;
        }
    }
}

void GraphMatrix::dijkstra(int source, bool show_result) {
    if (source == -1) {
        srand(time(nullptr));
        source = rand() % V;
    }
    vector<int> distance(V, numeric_limits<int>::max()); // Tablica tras
    vector<bool> visited(V, false); // Tablica odwiedzonych

    distance[source] = 0;

    PriorityQueue pq;
    pq.push(0, source); // Dodaj w do kopca

    while (!pq.empty()) {
        int u = pq.pop().second;
        if (visited[u]) continue;
        visited[u] = true; // Oznacz w jako odwiedzony

        // Aktualizacja tras do sąsiadów wierzchołka u
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && matrix[u][v] != 0) {
                // Sprawdzenie czy istnieje krawędź
                if (distance[u] != numeric_limits<int>::max() && distance[u] + matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + matrix[u][v];
                    pq.push(distance[v], v); // Dodaj v do kopca
                }
            }
        }
    }

    if (show_result) {
        cout << "Najkrotsze sciezki z wierzcholka " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Do wierzcholka " << i << ": " << distance[i] << "\n";
        }
    }
}

void GraphMatrix::dijkstra_two(int source, int destination, bool show_result) {
    if (source == -1) {
        srand(time(nullptr));
        source = rand() % V;
        destination = rand() % V;
    }
    int path = -1;
    vector<int> distance(V, numeric_limits<int>::max()); // Tablica tras
    vector<bool> visited(V, false); // Tablica odwiedzonych

    distance[source] = 0;

    PriorityQueue pq;
    pq.push(0, source); // Dodaj w do kopca

    while (!pq.empty()) {
        int u = pq.pop().second; // Wybierz w o najniższym koszcie
        if (u == destination) {
            path = distance[u];
            break;
        }

        if (visited[u]) continue;
        visited[u] = true; // Oznacz w jako odwiedzony

        // Aktualizacja kosztów dotarcia do sąsiadów wierzchołka u
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && matrix[u][v] != 0) {
                // Sprawdzenie czy krawędź istnieje
                if (distance[u] != numeric_limits<int>::max() && distance[u] + matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + matrix[u][v];
                    pq.push(distance[v], v); // Dodaj v do kopca
                }
            }
        }
    }

    if (show_result) {
        if (path == -1) {
            cout << "source: " << source << " destination: "<< destination << " -> Not exists" << endl;
        } else {
            cout << "source: " << source << " destination: "<< destination << " -> " << " path " << path << endl;
        }
    }
}
