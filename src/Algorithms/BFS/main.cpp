#include "iostream"
#include "fstream"
#include "vector"
#include "map"
#include "queue"
#include "set"
using namespace std;

class BFS {
public:
    BFS() {
        // Default constructor
    }

    static void bfs(map <int, vector<int> > graph, int startingNode) {
        set <int> visited;
        queue <int> traversal;
        traversal.push(startingNode);
        visited.insert(startingNode);

        while (!traversal.empty()) {
            int item = traversal.front();
            cout << item << " -> ";
            for (int i = 0; i < graph[item].size(); i++) {
                int nextVertex = graph[item][i];
                if (visited.find(nextVertex) == visited.end()) {
                    traversal.push(nextVertex);
                    visited.insert(nextVertex);
                }
            }
            traversal.pop();
        }
        cout << "end" << "\n";
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

*/

int main() {
    ifstream read;
    read.open("BFS/input.txt");
    map <int, vector<int> > graph;
    int n, startingNode;
    read >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        read >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    read >> startingNode;
    BFS::bfs(graph, startingNode);

    return 0;
}
