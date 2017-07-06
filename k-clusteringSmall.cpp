#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int> > ipair;

class Graph{
    private:
        int v;
        int e;
        vector<ipair> edge;
    public:
        Graph(int v);
        void addEdge(int src, int dest, int wt);
        int runKClustering(int k);
};

class DisjointSet{
    private:
        int n;
        vector<int> par;
        vector<int> rank;
    public: 
        DisjointSet(int n);
        int find(int u);
        void _union(int x, int y);
};

DisjointSet :: DisjointSet(int n){
    this->n = n;
    for(int i = 0; i<=n; i++){
        rank.push_back(0);
        par.push_back(i);
    }
}

int DisjointSet :: find(int u){
    if(u!=par[u])
        par[u] = find(par[u]);
    return par[u];
}
void DisjointSet :: _union(int x, int y){
    x = find(x);
    y = find(y);
    if(rank[x]>rank[y])
        par[y] = x;
    else
        par[x] = y;
    if(rank[x] == rank[y])
        rank[y]++;
}

Graph :: Graph(int v){
    this->v = v;
    e = 0;
}

void Graph :: addEdge(int src, int dest, int weight){
    edge.push_back(make_pair(weight,make_pair(src,dest)));
    e++;
}

int Graph :: runKClustering(int k){
    int res = 0;
    sort(edge.begin(),edge.end());
    DisjointSet s(v);
    int K = v;
    vector<ipair> :: iterator it;
    it = edge.begin();
    while(K!=k-1 && it!=edge.end()){
        int u = it->second.first;
        int v = it->second.second;
        
        int s_u = s.find(u);
        int s_v = s.find(v);
        
        if(s_u!=s_v){
            s._union(s_u,s_v);
            K--;
            if(K==k-1){
                res = it->first;
            }
        }
        it++;
    }
    return res;
}

int main(){
    ifstream myfile;
    myfile.open("clustering1.txt");
    string input;
    getline(myfile,input);
    istringstream ss(input);
    int v;
    ss>>v;
    Graph g(v);
    while(getline(myfile,input)){
        istringstream s(input);
        int src, dest,  wt;
        s>>src;
        s>>dest;
        s>>wt;
        g.addEdge(src,dest,wt);
    }
    int k = 4;
    cout<<g.runKClustering(4);
    return 0;
}
