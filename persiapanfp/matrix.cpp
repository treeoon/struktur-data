#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjMatrix;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showMatrix();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
  adjMatrix[src].push_back(dest);
  adjMatrix[src].sort();
}

void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    cout << currVertex << " ";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<int>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      int temp = *it;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  Graph grph(21);

    grph.addEdge(1, 2);
    grph.addEdge(1, 3);
    grph.addEdge(4, 3);
    grph.addEdge(3, 16);
    grph.addEdge(16, 17);
    grph.addEdge(17, 18);
    grph.addEdge(18, 20);
    grph.addEdge(19, 18);
    grph.addEdge(2, 6);
    grph.addEdge(6, 7);
    grph.addEdge(15, 18);
    
    grph.addEdge(2, 8);
    grph.addEdge(8, 9);
    grph.addEdge(9, 12);
    grph.addEdge(5, 4);
    grph.addEdge(6, 5);
    grph.addEdge(7, 12);
    grph.addEdge(7, 10);
    grph.addEdge(10, 11);
    grph.addEdge(10, 13);
    grph.addEdge(13, 14);
    grph.addEdge(14, 15);

    grph.showMatrix();
    grph.BFS(1, 15);

  return 0;
}