#include <iostream>
#include <climits>

#define V 6

// Find the vertex with the minimum key value from the set of vertices not yet included in MST
int findMinKey(int key[], bool mstSet[])
{
    int minKey = INT_MAX, minIndex;

    int v = 0;
    while (v < V)
    {
        if (mstSet[v] == false && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
        v++;
    }

    return minIndex;
}

// Print the Minimum Spanning Tree
void printMST(int parent[], int graph[V][V])
{
    std::cout << "Edge \tWeight\n";
    int i = 1;
    while (i < V)
    {
        if (parent[i] < i)
            std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        else
            std::cout << i << " - " << parent[i] << " \t" << graph[i][parent[i]] << " \n";
        i++;
    }
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    int i = 0;
    while (i < V)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        i++;
    }

    key[0] = 0;      // Start with the first vertex
    parent[0] = -1;  // First node is always the root of MST

    int count = 0;
    while (count < V - 1)
    {
        int selectedVertex = findMinKey(key, mstSet); // Select the vertex with the minimum key value
        mstSet[selectedVertex] = true;                // Include the selected vertex in MST

        int adjacentVertex = 0;
        while (adjacentVertex < V)
        {
            if (graph[selectedVertex][adjacentVertex] && mstSet[adjacentVertex] == false && graph[selectedVertex][adjacentVertex] < key[adjacentVertex])
            {
                parent[adjacentVertex] = selectedVertex; // Update parent of the adjacent vertex
                key[adjacentVertex] = graph[selectedVertex][adjacentVertex]; // Update the key value of the adjacent vertex
            }
            adjacentVertex++;
        }

        count++;
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 1},
                       {3, 0, 2, 1, 10, 0},
                       {0, 2, 0, 3, 0, 5},
                       {0, 1, 3, 0, 5, 0},
                       {0, 10, 0, 5, 0, 4},
                       {1, 0, 5, 0, 4, 0}};

    primMST(graph);

    return 0;
}
