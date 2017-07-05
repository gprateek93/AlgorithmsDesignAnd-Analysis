#include <bits/stdc++.h>
using namespace std;
#define ntc INT_MAX
typedef pair<int,int> ipair;

class Graph{
    private:
        int v;
        list<ipair> *adj;
    public:
        Graph(int v);
        void addEdge(int src, int dest, int w);
        long long runPrim(int src);
};

Graph :: Graph(int v){
    this->v = v;
    adj = new list<ipair> [v];
}

void Graph :: addEdge(int src, int dest, int w){
    adj[src-1].push_back(make_pair(dest-1,w));
    adj[dest-1].push_back(make_pair(src-1,w));
}

long long Graph :: runPrim(int src){
    priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
    vector<int> d(v,ntc);
    vector<int> par(v,-1);
    vector<bool> inMST(v,false);
    pq.push(make_pair(0,src));
    d[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        list<ipair> :: iterator it;
        for(it = adj[u].begin(); it!=adj[u].end(); it++){
            int dest = (*it).first;
            int w = (*it).second;
            if(!inMST[dest]&&d[dest]>w){
                d[dest] = w;
                pq.push(make_pair(d[dest],dest));
                par[v] = u;
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i<v; i++){
        if(inMST[i])
            sum+=d[i];
    }
    return sum;
}

int main(){
    ifstream myfile;
    myfile.open("edges.txt");
    string input;
    getline(myfile,input);
    int v,e;
    istringstream ss(input);
    ss>>v;
    ss>>e;
    Graph g(v);
    while(getline(myfile,input)){
        istringstream s(input);
        int src,dest,weight;
        s>>src;
        s>>dest;
        s>>weight;
        g.addEdge(src,dest,weight);
    }
    cout<<g.runPrim(0);
    return 0;
}
