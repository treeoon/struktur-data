#include <iostream>
#include <list>
#include <iterator>
#include <queue>
using namespace std;

class Graph
{
protected:
    int vertex;
    list<int> adj[100];

public:
    Graph(int v) {
        vertex = v;
    }

    void addVertex(int v1, int v2) {
        adj[v1].push_back(v2);
    }

    void showVertex() {
        for (int i = 1; i <= vertex; i++) {
            cout << i << " --> ";
            list<int>::iterator list;
            for (list = adj[i].begin(); list != adj[i].end(); list++) {
                cout << *list << " ";
            }
            cout << endl;
        }
    }

    void BFS(int s) {
        vector<bool> visited;
        visited.resize(vertex,false);
    
        list<int> queue;
    
        visited[s] = true;
        queue.push_back(s);
    
        while(!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto adjecent: adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
    }
};

int main()
{
    Graph grph(20);

    grph.addVertex(1, 2);
    grph.addVertex(1, 3);
    grph.addVertex(4, 3);
    grph.addVertex(3, 16);
    grph.addVertex(16, 17);
    grph.addVertex(17, 18);
    grph.addVertex(18, 20);
    grph.addVertex(19, 18);
    grph.addVertex(2, 6);
    grph.addVertex(6, 7);
    grph.addVertex(15, 18);
    
    grph.addVertex(2, 8);
    grph.addVertex(8, 9);
    grph.addVertex(9, 12);
    grph.addVertex(5, 4);
    grph.addVertex(6, 5);
    grph.addVertex(7, 12);
    grph.addVertex(7, 10);
    grph.addVertex(10, 11);
    grph.addVertex(10, 13);
    grph.addVertex(13, 14);
    grph.addVertex(14, 15);

    grph.showVertex();
    grph.BFS(1);

    return 0;
}