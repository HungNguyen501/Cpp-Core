#include "iostream"
#include "fstream"
#include "vector"
#include "map"
#include "queue"
#include "set"
using namespace std;

class DFS {
public:
    DFS() {
        // Default constructor
    }

    static void dfs(map <int, vector<int> > graph, int startingNode, set <int> &visited) {
        cout << startingNode << " -> ";
        visited.insert(startingNode);
        for (int i = 0; i < graph[startingNode].size(); i++) {
            if (visited.find(graph[startingNode][i]) == visited.end()) {
                dfs(graph, graph[startingNode][i], visited);
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

9 - 3
|   |
0 - 2
| /
1

     --2 ←-
    ↓  ↓   |
    3  0 → 1
    ↑  ↓
     --9

*/

int main() {
    ifstream read;
    read.open("DFS/input.txt");
    map <int, vector<int> > graph;
    static set <int> visited;
    int n, startingNode;
    read >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        read >> a >> b;
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }
    read >> startingNode;
    DFS::dfs(graph, startingNode, visited);
    cout << "end" << "\n";

    return 0;
}
