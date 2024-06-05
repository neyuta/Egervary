#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Инициализация графа
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = false;
}

// Добавление ребер
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// Алгоритм поиска в глубину
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    cout << "Enter the number of vertices (from 3 to 10):" << endl;
    int countOfVertices;
    cin >> countOfVertices;
    while ((countOfVertices > 10) || (countOfVertices < 3)) {
        cout << "Enter the number of vertices from 3 to 10:" << endl;
        cin >> countOfVertices;
    }

    Graph g(countOfVertices);

    for (int i = 0; i < countOfVertices; i++) {
        int first, second;
        cout << "Enter the first coordinate of the edge:" << endl;
        cin >> first;
        cout << "Enter the second coordinate of the edge:" << endl;
        cin >> second;
        g.addEdge(first, second);
    }

    cout << "From which peak should I start a deep search?" << endl;
    cout << "Enter a number from 0 to" << countOfVertices - 1 << endl;
    int startVertex;
    cin >> startVertex;
    g.DFS(startVertex);

    return 0;
}