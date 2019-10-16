#include <bits/stdc++.h>
using namespace std;

struct subset{
	int parent;
	int rank;
};

int find(struct subset s[], int i){
	if(s[i].parent!=i)
		return find(s,s[i].parent);
	return i;
}

void Union(struct subset s[], int x, int y){
	int xr = find(s,x);
	int yr = find(s,y);
	if(s[xr].rank<s[yr].rank){
		s[xr].parent = yr;
	}
	else if(s[yr].rank<s[xr].rank){
		s[yr].parent = xr;
	}
	else{
		s[xr].parent = yr;
		s[yr].rank++;
	}
}

struct Edge{
	int src,dest;
};

class Graph{
	private:
		int v;
		int e;
		struct Edge *edge;
	public:
		Graph(int v);
		void addEdge(int src, int dest, int i);
		int minCut();
};

Graph::Graph(int v){
	this->v = v;
	e=5034;
	edge = new Edge[e];
}

void Graph::addEdge(int s, int d, int i){
	edge[i].src = s;
	edge[i].dest = d;
}

int Graph::minCut(){
	int mincut = INT_MAX;
	int m =1; // Change the value of m to get more fine results.
	while(m--){
		srand(time(NULL));
		int cut = 0;
		int vertices = v;
		int edges = e;
		struct Edge *adj = edge;
		struct subset *s = new subset[v];
		for(int i = 0; i< v; i++){
			s[i].parent = i;
			s[i].rank = 0;
		}	
		while(vertices>2){
			int i = rand() % edges;
			int s1 = find(s,adj[i].src);
			int s2 = find(s,adj[i].dest);
			if(s1!=s2){
				vertices--;
				Union(s,s1,s2);
			}
		}
		for(int k = 0; k<edges; k++){
			int s1 = find(s,adj[k].src);
			int s2 = find(s,adj[k].dest);
			if(s1!=s2)
				cut++;
		}
		if(cut<mincut){
			mincut = cut;
		}
	}
	return mincut;
}

int main(){
	Graph g(200);
	ifstream myfile;
	myfile.open("KargerMinCut.txt");
	string input;
	int i = 0;
	while(getline(myfile,input)){
		istringstream iss(input);
		int source;
		iss>>source;
		int dest;
		while(iss>>dest){
			g.addEdge(source,dest,i);
			i++;
		}
	}
	cout<<g.minCut();
	return 0;
}
