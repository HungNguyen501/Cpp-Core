#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    public:
        map <int, vector<int>> graph;
        map <int, bool> visited;

        Graph() {
            // Default constructor
        }

        // add edge to list vertex
        void addEdge(int v, int w) {
            graph[v].push_back(w);
        }

        void DFS(int v) {
            visited[v] = true; // marked as traversed this vertex
            cout << v << " ";

            for (int i = 0; i < graph[v].size(); i++) {
                int child = graph[v][i];
                if (!visited[child]) {
                    DFS(child);
                }
            }
        }

        void BFS(int starting_node) {
            queue <int> reached_nodes;
            reached_nodes.push(starting_node);
            visited[starting_node] = true;

            while (!reached_nodes.empty())
            {
                int u = reached_nodes.front();
                cout << u << " ";
                reached_nodes.pop();

                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];
                    if (!visited[v]) {
                        reached_nodes.push(v);
                        visited[v] = true;
                    }
                }
            }
            
        }
};

/*
↑↓→←

0 1
0 9
1 2
2 0
2 3
9 3

     --2 ←-
    ↓  ↓   |
    3  0 → 1
    ↑  ↓
     --9    

==> Score: 2 0 1 9 3

*/

int main()
{
    ifstream input;
    input.open("CPP\\Data Structure and Algorithms\\DFS\\input.txt");

    Graph g;
    int n;
    input >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        input >> a >> b;
        g.addEdge(a, b);
    }
    
    int starting_node = 2;
    cout << "Starting from vertex " << starting_node <<": " << endl;

    cout << "DFS: ";
    g.DFS(starting_node);
    cout << endl;

    system("pause");
    return 0;
}