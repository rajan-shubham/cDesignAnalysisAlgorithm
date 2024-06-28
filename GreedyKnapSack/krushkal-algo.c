#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort edges by weight
int comparator(const void *p1, const void *p2)
{
    const int(*edge1)[3] = p1;
    const int(*edge2)[3] = p2;
    return (*edge1)[2] - (*edge2)[2];
}

// Initialize parent and rank arrays
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the parent of a node with path compression
int findParent(int parent[], int node)
{
    if (parent[node] != node)
    {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

// Unite two sets by rank
void unionSets(int u, int v, int parent[], int rank[], int n)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalAlgorithm(int numEdges, int edges[][3], int numVertices)
{
    // Sort edges by weight
    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    int parent[numVertices];
    int rank[numVertices];

    // Initialize parent and rank arrays
    makeSet(parent, rank, numVertices);

    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < numEdges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        // If u and v are in different sets, include this edge in the MST
        if (rootU != rootV)
        {
            unionSets(rootU, rootV, parent, rank, numVertices);
            minCost += weight;
            printf("%d ---- %d == %d\n", u, v, weight);
        }
    }

    printf("Minimum Cost of Spanning Tree is : %d\n", minCost);
}

// Main function
int main()
{
    // user input as runtime
    int edges[5][3] = {
        {0, 1, 8},
        {0, 2, 11},
        {0, 3, 4},
        {1, 3, 10},
        {2, 3, 2}};
    int numVertices = 4;
    int numEdges = 5;

    kruskalAlgorithm(numEdges, edges, numVertices);

    return 0;
}