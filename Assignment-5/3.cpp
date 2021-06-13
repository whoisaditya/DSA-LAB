// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the adj

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // Number of vertex
    int v;

    // Number of edges
    int e;

    // Adjacency matrix
    int **adj;

    // To create the initial adjacency matrix
    Graph(int v, int e);

    // Function to insert a new edge
    void addEdge(int start, int e, int i);

    int minDistance(int dist[], bool sptSet[]);

    void printSolution(int dist[]);

    void dijkstra(int src);
};

// Function to fill the empty adjacency matrix
Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int *[v];
    for (int row = 0; row < v; row++)
    {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++)
        {
            adj[row][column] = 0;
        }
    }
}

// Function to add an edge to the adj
void Graph::addEdge(int start, int e, int i)
{

    // Considering a bidirectional edge
    adj[start][e] = i;
    adj[e][start] = i;
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Graph::minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int i = 0; i < v; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

// A utility function to print the constructed distance array
void Graph::printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a adj represented using adjacency matrix representation
void Graph::dijkstra(int src)
{
    int dist[v]; // The output array. dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[v]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < v - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. k is always equal to src in the first iteration.
        int k = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[k] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int j = 0; j < v; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // k to v, and total weight of path from src to v through k is
            // smaller than current value of dist[v]
            if (!sptSet[v] && adj[k][j] && dist[k] != INT_MAX && dist[k] + adj[k][j] < dist[j])
                dist[j] = dist[j] + adj[k][j];
    }

    // print the constructed distance array
    printSolution(dist);
}



// Driver code
int main()
{
    int v = 0, e = 0, ch;

    while (true)
    {
        cout << "\nMenu\n1. Create your own graph\n2. Use the sample graph\n3. Exit\nYour choice: ";
        cin >> ch;
        cout << "\n";

        switch (ch)
        {
        case 1:
        {
            cout << "Enter the no. of vertices and edges : ";
            cin >> v >> e;

            // Create the graph
            Graph G(v, e);

            cout << "Enter the starting and end point of the edges and weight" << endl;
            for (int j = 0; j < e; j++)
            {
                int x, y, z;
                cin >> x >> y >> z;
                G.addEdge(x, y, z);
            }

            cout << "Adjadency matrix" << endl;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    cout << G.adj[i][j] << " ";
                }
                cout << endl;
            }

            cout << "Shortest Path Using Dijkstra Traversal :";
            // Perform DFS
            G.dijkstra(0);
            break;
        }

        case 2:
        {
            v=4;
            e=6;

            Graph G(v, e);

            G.addEdge(0, 1, 1);
            G.addEdge(1, 2, 2);
            G.addEdge(2, 3, 3);
            G.addEdge(3, 0, 4);
            G.addEdge(0, 2, 5);
            G.addEdge(1, 3, 6);

            cout << "Adjadency matrix" << endl;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    cout << G.adj[i][j] << " ";
                }
                cout << endl;
            }

            cout << "\nShortest Path Using Dijkstra Traversal : ";
            // Perform DFS
            G.dijkstra(0);

            break;
        }

        case 3:
        {
            exit(0);
            break;
        }

        default:
        {
            cout << "Invalid Input";
        }
        }
    }
}
