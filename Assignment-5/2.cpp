// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

class Graph
{

    // Number of vertex
    int v;

    // Number of edges
    int e;

public:
    // Adjacency matrix
    int **adj;


    // To create the initial adjacency matrix
    Graph(int v, int e);

    // Function to insert a new edge
    void addEdge(int start, int e);

    // Function to display the DFS traversal
    void DFS(int start, vector<bool> &visited);
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

// Function to add an edge to the graph
void Graph::addEdge(int start, int e)
{

    // Considering a bidirectional edge
    adj[start][e] = 1;
    adj[e][start] = 1;
}

// Function to perform DFS on the graph
void Graph::DFS(int start, vector<bool> &visited)
{

    // Print the current node
    cout << start << " ";

    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    for (int i = 0; i < v; i++)
    {

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i]))
        {
            DFS(i, visited);
        }
    }
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

            cout << "Enter the starting and end point of the edges" << endl;
            for (int j = 0; j < e; j++)
            {
                int x, y;
                cin >> x >> y;
                G.addEdge(x, y);
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

            // Visited vector to so that
            // a vertex is not visited more than once
            // Initializing the vector to false as no
            // vertex is visited at the beginning
            vector<bool> visited(v, false);

            cout << "DFS Traversal : ";
            // Perform DFS
            G.DFS(0, visited);

            break;
        }

        case 2:
        {
            v = 5, e = 4;

            Graph G(v, e);

            // Visited vector to so that
            // a vertex is not visited more than once
            // Initializing the vector to false as no
            // vertex is visited at the beginning
            vector<bool> visited(v, false);

            G.addEdge(0, 1);
            G.addEdge(0, 2);
            G.addEdge(0, 3);
            G.addEdge(0, 4);

            cout << "Adjadency matrix" << endl;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    cout << G.adj[i][j] << " ";
                }
                cout << endl;
            }


            cout << "\nDFS Traversal : ";
            // Perform DFS
            G.DFS(0, visited);

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
