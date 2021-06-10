#include <iostream>
#include <fstream>
using namespace std;

struct edge {
    long u, v, weight;
};

void swap(edge &a, edge &b) {
    edge tmp = a;
    a = b;
    b = tmp;
}

void quickSort(edge a[], long l, long r) {
    if (l >= r) return;
    long pivot = a[(l + r) / 2].weight;

    int i = l, j = r;

    while (i <= j)
    {
        while (a[i].weight < pivot) i++;
        while (pivot < a[j].weight) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }

    quickSort(a, l, j);
    quickSort(a, i, r);
}

//init Disjoin Set Union
long parent[45009], rankVertex[45009] = { 0 };

long findParent(long vertex) {
    if (parent[vertex] != vertex) parent[vertex] = findParent(parent[vertex]);
    return parent[vertex];
}

bool joinable(long u, long v) {
    long parent_u, parent_v;

    parent_u = findParent(u);
    parent_v = findParent(v);

    if (parent_u == parent_v) return false;

    if (rankVertex[parent_u] == rankVertex[parent_v]) rankVertex[parent_u]++;
    
    if (rankVertex[parent_u] > rankVertex[parent_v]) parent[parent_v] = parent_u;
    else parent[parent_u] = parent_v;

    return true;
}

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Kruskal MST\\input.txt");

    long n, m;
    edge *edges = new edge[45009];
    long long weight_sum = 0;

    read >> n >> m;

    //init parent array
    for (long i = 1; i <= n; i++)
        parent[i] = i;

    for (long i = 0; i < m; i++) {
        read >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    quickSort(edges, 0, m - 1);

    for (int i = 0; i < m; i++) {
        if (joinable(edges[i].u, edges[i].v))
            weight_sum += edges[i].weight;
    }

    cout << weight_sum << endl;

    system("pause");
    return 0;
}
