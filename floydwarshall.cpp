#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        int e;
        long long **adj;
    public:
        Graph(int v, int e);
        void addEdge(int src,int dest,long long dist);
        bool detectNegativeCycle(vector<vector<long long> > &dist);
        void floydWarshall();
};

Graph :: Graph(int v, int e){
    this->v = v;
    this->e = e;
    adj = new long long*[v];
    for(int i = 0; i<v; i++){
        adj[i] = new long long[v];
    }
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            adj[i][j] = INT_MAX;
        }
    }
}

void Graph :: addEdge(int src,int dest,long long d){
    adj[src-1][dest-1] = d;
}

bool Graph :: detectNegativeCycle(vector<vector<long long> > &dist){
    for(int i = 0; i<v; i++){
        if(dist[i][i] < 0)
            return true;
    }
    return false;
}

void Graph :: floydWarshall(){
    vector<vector<long long> > dist(v,vector<long long> (v,0));
    for(int i = 0; i<v; i++){
        for(int j = 0; j< v; j++){
            dist[i][j] = adj[i][j];
        }
    }
    for(int k = 0; k<v; k++){
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if(detectNegativeCycle(dist))
        cout<<"Null";
    else{
        long long res = INT_MAX;
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(res>dist[i][j])
                    res = dist[i][j];
            }
        }
        cout<<res;
    }
}

int main(){
    ifstream myfile;
    myfile.open("g1.txt");//Use g2.txt and g3.txt to compare
    int v,e;
    string input;
    getline(myfile,input);
    istringstream ss(input);
    ss>>v;
    ss>>e;
    Graph g(v,e);
    while(getline(myfile,input)){
        int src,dest;
        long long w;
        istringstream s(input);
        s>>src;
        s>>dest;
        s>>w;
        g.addEdge(src,dest,w);
    }
    g.floydWarshall();
    return 0;
}
