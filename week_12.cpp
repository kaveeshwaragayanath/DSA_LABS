#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int numCities = 6;  // Number of cities in the graph

// Find the vertex with the minimum distance value
int findMinDistance(const vector<int>& distances, const vector<bool>& visited) {
    int minDistance = numeric_limits<int>::max();
    int minIndex = -1;

    int v = 0;
    while (v < numCities) {
        if (!visited[v] && distances[v] <= minDistance) {
            minDistance = distances[v];
            minIndex = v;
        }
        v++;
    }

    return minIndex;
}

// Print the shortest path distances from the source city to all other cities
void printSolution(const vector<int>& distances, int sourceCity) {
    int i = 0;
    while (i < numCities) {
        cout << "Time taken from city " << sourceCity << " to city " << i << " = " << distances[i] << endl;
        i++;
    }
}

// Dijkstra's algorithm to find the shortest path from the source city to all other cities
void dijkstra(const vector<vector<int>>& graph, int sourceCity) {
    vector<int> distances(numCities, numeric_limits<int>::max());  // Shortest path distances
    vector<bool> visited(numCities, false);  // Visited cities

    distances[sourceCity] = 0;

    int count = 0;
    while (count < numCities - 1) {
        int u = findMinDistance(distances, visited);
        visited[u] = true;

        int v = 0;
        while (v < numCities) {
            if (!visited[v] && graph[u][v] && distances[u] != numeric_limits<int>::max() &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
            v++;
        }

        count++;
    }

    printSolution(distances, sourceCity);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
