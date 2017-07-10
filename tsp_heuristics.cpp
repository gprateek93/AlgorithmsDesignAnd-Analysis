#include <bits/stdc++.h>
using namespace std;
#define INF_WEIGHT 99999999

double euclideanDistance(int i,int j,vector<pair<double,double> > &index){
    double x = (index[i].first-index[j].first)*(index[i].first-index[j].first);
    double y = (index[i].second-index[j].second)*(index[i].second-index[j].second);
    double res = x+y;
    return res;
}
	
double runTSPNN(int src,int n,vector<pair<double,double> > &index,int visited[],double minC){
	visited[src] = 1;
    pair<double,int> nearest = make_pair(INF_WEIGHT,-1);
    for(int i = 0; i<n; i++){
    	if(visited[i]==0){
    		double cost = euclideanDistance(i,src,index); 
    		if(cost<nearest.first){
            	nearest.first = cost;
            	nearest.second = i;
        	}
    	}
    }
    if(nearest.first == INF_WEIGHT){
        minC+=sqrt(euclideanDistance(src,0,index));
        return minC;
    }
    minC+=sqrt(nearest.first);
    cout<<minC<<endl;
    return runTSPNN(nearest.second,n,index,visited,minC);
}

int main(){
    ifstream myfile;
    myfile.open("nn.txt");
    string input;
    getline(myfile,input);
    istringstream ss(input);
    int n;
    ss>>n;
    int visited[n];
    memset(visited,0,n);
    vector<pair<double,double> > index;
    while(getline(myfile,input)){
        istringstream s(input);
        int j;
		double x,y;
		s>>j;
        s>>x;
        s>>y;
        index.push_back(make_pair(x,y));
    }
    double minC = 0.0;
    double res = runTSPNN(0,n,index,visited,minC);
    cout<<std::fixed<<res;
    return 0;
}
