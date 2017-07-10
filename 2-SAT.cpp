#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        long long  v;
        list<long long> *adj;
        void printSCCUtil(long long  i, stack<long long > &mystk, bool visited[]);
        void dfs(long long  v, bool visited[],vector<long long> &component, long long count);
    public:
        Graph(long long v);
        void printSCC(vector<long long> &component);
        void addEdge(long long  src, long long  dest);
        Graph transpose();
};

Graph :: Graph(long long v){
    this->v = v;
    adj = new list<long long > [v];
}

void Graph :: addEdge(long long  src, long long  dest){
    adj[src-1].push_back(dest-1);
}

Graph Graph :: transpose(){
    Graph g(v);
    list<long long > :: iterator it;
    for(long long  i = 0; i<v; i++){
        for(it = adj[i].begin(); it!=adj[i].end(); it++){
            g.adj[*it].push_back(i);
        }
    }
    return g;
}

void Graph :: dfs(long long  i, bool visited[],vector<long long> &component, long long count){
    visited[i] = true;
    component[i] = count;
    list<long long > :: iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++){
        if(!visited[*it])
            dfs(*it,visited,component,count);
    }
}

void Graph :: printSCCUtil(long long  i, stack<long long > &mystck, bool visited[]){
    visited[i] = true;
    list<long long > :: iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++){
        if(!visited[*it])
            printSCCUtil(*it,mystck,visited);
    }
    mystck.push(i);
}

void Graph :: printSCC(vector<long long> &component){
    bool *visited = new bool[v];
    stack<long long > mystck;
    memset(visited,false,v);
    for(long long  i = 0; i<v; i++){
        if(!visited[i]){
            printSCCUtil(i,mystck,visited);
        }
    }
    Graph tr = transpose();
    memset(visited,false,v);
    long long count = 0;
    while(!mystck.empty()){
        long long  i = mystck.top();
        mystck.pop();
        if(!visited[i]){
            count++;
            tr.dfs(i,visited,component,count);
        }
    }
    return;
}

long long mynode(long long v, long long n){
    if(v<0){
        return -v+n;
    }
    else
        return v;
}

int main(){
    ifstream myfile;
    myfile.open("2SAT2.txt");
    string input;
    getline(myfile,input);
    istringstream s(input);
    long long n;
    s>>n;
    Graph g(2*n);
    while(getline(myfile,input)){
        istringstream ss(input);
        long long src, dest;
        ss>>src;
        ss>>dest;
        g.addEdge(mynode(-src,n),mynode(dest,n));
        g.addEdge(mynode(-dest,n),mynode(src,n));
    }
    vector<long long> component(2*n,0);
    g.printSCC(component);
    for(int i = 0; i<n; i++){
        if(component[i] == component[n+i]){
            cout<<"0"<<endl;
            return 0;
        }
    }
    cout<<"1"<<endl;
    return 0;
}
