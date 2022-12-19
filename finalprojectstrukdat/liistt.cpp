#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int v;
        string nama[100];
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;
    public:
        Graph(int v) {
            this->v = v;
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void addName(int i, string nama){
			this->nama[i]=nama;
			vector<int>arr;
			arr.push_back(i);
			sort(arr.begin(), arr.end());
		}
        void addEdge(int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
        }
		void showList(){
			cout << "Adjacency List" <<endl;
            list<int>::iterator it;
            for(int i=1; i < v; i++){
                cout << "V"<< i <<"-" << nama[i] ;
                for(it=adj[i].begin(); it != adj[i].end(); ++it){
                    cout << " -> V" << *it << "-" << nama[*it] <<"[" <<  weight[make_pair(i, *it)] << "]";
                }                                                                 
                cout << endl;
        	}
        	cout << endl;        	
		}
        void BFS(int start, int end){
            cout << endl;
            cout << "BFS" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty()) {
                int curr = q.front();
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++){
                    if(weight[make_pair(curr, *it)] + dist[curr] < dist[*it]){
                        dist[*it] = weight[make_pair(curr, *it)] + dist[curr];
                        domain[*it] = curr;
                        q.push(*it);
                    }
                } // nyari vertex terdekat dari qfront, if untuk menentukan weight dari vertex yang terkecil dari tiap vertex terus dipush
                q.pop();
                // for(int i=1; i <= v; i++){
                //     if(dist[i] >= 9999)
                //         cout << ". ";
                //     else 
                //         cout << dist[i] << " ";

                // }
                // cout << endl;
            }
            // for(int i=1; i <= v; i++)
            //     cout << domain[i] << " ";

            vector<int> result;
            int i = end;
            // ngepush ke vector result
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }
            // cout
            for (int i = result.size()-1; i >= 0; i--){
                cout << "V" <<  result[i] << "-" << nama[result[i]] << ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }
        
        void DFS(int start, int end){
            cout << endl;
            cout << "DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited(v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++){
                cout <<"V" << dfsResult[i] << "-" << nama[dfsResult[i]] << ", ";
            }
            cout << endl << "Weight = " << dfsWeight << endl;
        }
        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            // base case ketika ke titik end bakalan nyari weight terkecil, dan nyimpan path/weight
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                // cout << dfsWeight << endl;
                // for(int i=0; i < path.size(); i++)
                //     cout << path[i] << " ";
                // cout << endl;
            }   
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            //looping masing-masing vertex dan diproses pada function rekursif dfs
            for ( it = adj[start].begin(); it != adj[start].end(); it++){
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }
        // mencari vertex dengan distance terkecil
        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            int flag = 0;
            for (int i = 1; i <= v; i++) {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                    flag = 1;
                }
            }
                if ( flag == 1 ) 
                    return min_index;
                else 
                    return -1;
        }

        void dijkstra(int start, int end){
            cout << endl << "Dijkstra" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);

            dist[start] = 0;

            for (int itv = 1; itv <= v ; itv++)
            {
                int min = minDist(dist, vis);
                if (min == -1 ) break;
                // cout << min << endl;
                vis[min] = true;
                list<int>::iterator it;
                // membandingkan weight untuk mendapatkan weight terkecil dari masing-masing vertex
                for(it = adj[min].begin(); it != adj[min].end(); ++it){
                    if (
                        weight[make_pair(min, *it)] &&
                        !vis[*it] && 
                        dist[min] + weight[make_pair(min, *it)]  < dist[*it]
                    )
                    {
                        dist[*it] = dist[min] + weight[make_pair(min, *it)]; 
                        res[*it] = min;
                    }
                }
                // for(int i=1; i <= v; i++){
                //     if(dist[i] >= 9999)
                //         cout << ". ";
                //     else 
                //         cout << dist[i] << " ";

                // }
                // cout << endl;
            }
            int i = res[end];
            vector<int> r;
            r.push_back(end);
            //looping dan cout hasil
            while (true){
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            reverse(r.begin(), r.end());
            for (int i = 0; i <  r.size(); i++){
                cout <<"V" <<  r[i] << "-" << nama[r[i]] << ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }
};

int main(){
    Graph graph(20);

    graph.addName(1, "Rumah");
    graph.addName(2, "RentalMobil");
    graph.addName(3, "Apotek");
    graph.addName(4, "Pertama");
    graph.addName(5, "HotelPremier"); 
    graph.addName(6, "Soto"); 
    graph.addName(7, "MangEngking"); 
    graph.addName(8, "Pasar"); 
    graph.addName(9, "Sekolah"); 
    graph.addName(10, "Resto"); 
    graph.addName(11, "Grosir"); 
    graph.addName(12, "Halte"); 
    graph.addName(13, "MCDWaru"); 
    graph.addName(14, "RSMitra"); 
    graph.addName(15, "Mayasi"); 
    graph.addName(16, "Kantor"); 
    graph.addName(17, "HotelKemuning"); 
    graph.addName(18, "RSSheila"); 
    graph.addName(19, "MieGacoan"); 
    graph.addName(20, "MCDPabean"); 

	graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(4, 3, 4);
    graph.addEdge(3, 16, 3);
    graph.addEdge(16, 17, 4);
    graph.addEdge(17, 18, 5);
    graph.addEdge(18, 20, 6);
    graph.addEdge(19, 18, 6);
    graph.addEdge(2, 6, 3);
    graph.addEdge(6, 7, 2);
    graph.addEdge(15, 18, 15);
    graph.addEdge(2, 8, 3);
    graph.addEdge(8, 9, 7);
    graph.addEdge(9, 12, 5);
    graph.addEdge(5, 4, 3);
    graph.addEdge(6, 5, 1);
    graph.addEdge(7, 12, 12);
    graph.addEdge(7, 10, 14);
    graph.addEdge(10, 11, 4);
    graph.addEdge(10, 13, 7);
    graph.addEdge(13, 14, 2);
    graph.addEdge(14, 15, 11);	
  
    graph.showList();

	int start, end;
	cout << "start : ";
	cin >> start;
	cout << "end : ";
	cin >> end;

	graph.BFS(start, end);
    graph.DFS(start, end);
    graph.dijkstra(start, end);

    return 0;
}