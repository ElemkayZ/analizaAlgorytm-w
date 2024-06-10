#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <queue>
#include <utility>
#include "list.h"
using namespace std;

// Constructor 
GraphList::GraphList(int vertices) : V(vertices), List(vertices) {}

// funkcja dodania w
void GraphList::addEdge(int x, int y, int w) {
    List[x].emplace_back(y, w);
    List[y].emplace_back(x, w);
}

// fun print listy
void GraphList::show() {
    cout << "Lista:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << " -> ";
        for (const auto& edge : List[i]) {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << endl;
    }
}

// Fun gen random graf
void GraphList::fillRandomEdges(int density, int maxWeight) {
    srand(static_cast<unsigned>(time(nullptr)));
    int threshold = (V * (V - 1) / 2) * density / 100;
    int edgesCount = 0;
    while (edgesCount < threshold) {
        int x = rand() % V;
        int y = rand() % V;
        if (!hasEdge(x, y) && x != y) {
            addRandomEdge(x, y, maxWeight);
            edgesCount++;
        }
    }
}

// sprawdz czy jest krawedz
bool GraphList::hasEdge(int x, int y) {
    for (const auto& edge : List[x]) {
        if (edge.first == y) {
            return true;
        }
    }
    return false;
}

// Fun random krawedz
void GraphList::addRandomEdge(int x, int y, int maxWeight) {
    int weight = rand() % maxWeight + 1;
    addEdge(x, y, weight);
}

// Fun dijkstra wszystkie w
void GraphList::dijkstra(int source, bool showResult) {
    if (source == -1) {
        srand(static_cast<unsigned>(time(nullptr)));
        source = rand() % V;
    }

    vector<int> distance(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& edge : List[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    if (showResult) {
        cout << "Najkrotsze sciezki z wierzcholka " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Do wierzcholka " << i << ": " << distance[i] << "\n";
        }
    }
}
// Fun dijkstra w1 i w2
void GraphList::dijkstra_two(int source, int destination, bool showResult) {
    if (source == -1 || destination == -1) {
        srand(static_cast<unsigned>(time(nullptr)));
        source = rand() % V;
        destination = rand() % V;
    }

    int path = -1;
    vector<int> distance(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);

    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == destination) {
            path = distance[u];
            break;
        }

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : List[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    if (showResult) {
        if (path == -1) {
            cout << "source: " << source << " destination: "<< destination << " -> Not exists" << endl;
        } else {
            cout << "source: " << source << " destination: "<< destination << " -> " << " path " << path << endl;
        }
    }
}
