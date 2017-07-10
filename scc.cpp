#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v;
        list<int> *adj;
        void printSCCUtil(int i, stack<int> &mystk, bool visited[]);
        void dfs(int v, bool visited[]);
    public:
        Graph(int v);
        void printSCC();
        void addEdge(int src, int dest);
        Graph transpose();
};

Graph :: Graph(int v){
    this->v = v;
    adj = new list<int> [v];
}

void Graph :: addEdge(int src, int dest){
    adj[src].push_back(dest);
}

Graph Graph :: transpose(){
    Graph g(v);
    list<int> :: iterator it;
    for(int i = 0; i<v; i++){
        for(it = adj[i].begin(); it!=adj[i].end(); it++){
            g.adj[*it].push_back(i);
        }
    }
    return g;
}

void Graph :: dfs(int i, bool visited[]){
    visited[i] = true;
    cout<<i<<" ";
    list<int> :: iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++){
        if(!visited[*it])
            dfs(*it,visited);
    }
}

void Graph :: printSCCUtil(int i, stack<int> &mystck, bool visited[]){
    visited[i] = true;
    list<int> :: iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++){
        if(!visited[*it])
            printSCCUtil(*it,mystck,visited);
    }
    mystck.push(i);
}

void Graph :: printSCC(){
    bool *visited = new bool[v];
    stack<int> mystck;
    memset(visited,false,v);
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            printSCCUtil(i,mystck,visited);
        }
    }
    Graph tr = transpose();
    memset(visited,false,v);
    while(!mystck.empty()){
        int i = mystck.top();
        mystck.pop();
        if(!visited[i]){
            tr.dfs(i,visited);
            cout<<endl;
        }
    }
    return;
}

int myint(string s){
    int num;
    stringstream ss;
    ss>>num;
    return num;
}

int main(){
    ifstream myfile;
    myfile.open("scc.txt");
    string input;
    istringstream s(input);
    int n;
    s>>n;
    Graph g(n);
    while(getline(myfile,input)){
        istringstream ss(input);
        int src, dest;
        ss>>src;
        ss>>dest;
        g.addEdge(src,dest);
    }
 
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCC();
 
    return 0;
}
