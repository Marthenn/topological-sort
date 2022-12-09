#include <bits/stdc++.h>
using namespace std;

// Class yang Digunakan untuk Merepresentasikan Graph
class Graph {
    // Jumlah Simpul
    int V;

    // Pointer ke Array yang Berisi Adjacency List
    list<int>* adj;

    void topologicalSortRecursive(int v, bool visited[], stack<int>& Stack);

    public:
    //Constructor dari Class Graph
    Graph(int V);

    // Fungsi untuk Menambahkan Edge ke Graph
    void addEdge(int v, int w);

    // Fungsi untuk Melakukan Topological Sort
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortRecursive(int v, bool visited[], stack<int>& Stack){
    // Menandai Node yang Sedang Dikunjungi
    visited[v] = true;

    // Melakukan Iterasi pada Adjacency List
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortRecursive(*i, visited, Stack);

    // Memasukkan Node ke Stack
    Stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;

    //Tandai semua titik sebagai belum dikunjungi
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Memanggil fungsi rekursif untuk semua simpul yang belum dikunjungi
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortRecursive(i, visited, Stack);
    
    // Print isi Stack
    while (Stack.empty() == false){
        cout << Stack.top() << " ";
        Stack.pop();
    }

    delete [] visited;
}

// main program
int main(){
    // Buat Graph
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout<<"Topological Sort: \n";
    g.topologicalSort();
    return 0;
}