#include <iostream>
#include <fstream>
#include <map>
#include <limits.h>
using namespace std;

int minIndex(int list_dist[], bool list_node[] ,int n) {
    int min = INT16_MAX;
    int min_index = 0;
    for (int i = 1; i <= n; i++) {
        if (!list_node[i] && list_dist[i] < min) {
            min = list_dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[100][100], int n, int start) {
    bool list_node[100] = {false};
    int list_dist[100];

    for (int i = 1; i <= n; i++) {
        list_dist[i] = INT16_MAX;
    }

    list_dist[start] = 0;

    for (int i = 1; i < n; i++) {
        int u = minIndex(list_dist, list_node, n);
        list_node[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!list_node[v] && graph[u][v] && list_dist[u] != INT16_MAX && list_dist[u] + graph[u][v] < list_dist[v]) {
                list_dist[v] = list_dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (list_dist[i] == INT16_MAX) cout << i << ": -1" << endl;
        else cout << i << ": " << list_dist[i] << endl;
    }

}


int main() {
    ifstream input;
    input.open("D:\\Projects\\CPP\\__test__\\input.txt");

    int graph[100][100];
    int start;
    int n, m;
    input >> n >> m;

    // clean matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, distance;
        input >> u >> v >> distance;
        graph[u][v] = distance;
        graph[v][u] = distance;
    }

    input >> start;

    dijkstra(graph, n, start);

    system("pause");
    return 0;
}