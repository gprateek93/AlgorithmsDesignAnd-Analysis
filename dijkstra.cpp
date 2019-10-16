#include <bits/stdc++.h>
using namespace std;
#define ntc 1000000
typedef pair<int,int> ipair;

class Graph{
    private:
        int v;
        list<ipair> *adj;
    public:
        Graph(int v);
        void addEdge(int src, int dest, int w);
        vector<int> runDijkstra(int src);
};

Graph :: Graph(int v){
    this->v = v;
    adj = new list<ipair> [v];
}

void Graph :: addEdge(int src, int dest, int w){
    adj[src-1].push_back(make_pair(dest-1,w));
}

vector<int> Graph :: runDijkstra(int src){
    priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
    vector<int> d(v,ntc);
    pq.push(make_pair(0,src));
    d[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        list<ipair> :: iterator it;
        for(it = adj[u].begin(); it!=adj[u].end(); it++){
            int dest = (*it).first;
            int w = (*it).second;
            if(d[dest]>d[u]+w){
                d[dest] = d[u]+w;
                pq.push(make_pair(d[dest],dest));
            }
        }
    }
    return d;
}

int main(){
    Graph g(200);
    ifstream myfile;
    myfile.open("dijkstraData.txt");
    string input;
    while(getline(myfile,input)){
        istringstream ss(input);
        int src,dest;
        ss>>src;
        while(ss>>dest){
            char p;
            ss>>p;
            int weight;
            ss>>weight;
            g.addEdge(src,dest,weight);
        }
    }
    
    vector<int> d = g.runDijkstra(0);
    cout<<d[7-1]<<","<<d[37-1]<<","<<d[59-1]<<","<<d[82-1]<<","<<d[99-1]<<","<<d[115-1]<<","<<d[133-1]<<","<<d[165-1]<<","<<d[188-1]<<","<<d[197-1]<<endl;
    return 0;
}
