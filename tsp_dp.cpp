#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

double mymap[30][30];
double dp[(1<<25)-1][30];

double euclideanDistance(int i, int j , vector<pair<double,double> > &index){
    double x = pow((index[i].first-index[j].first),2);
    double y = pow((index[i].second-index[j].second),2);
    return x+y;
} 

void generatePaths(vector<pair<double,double> > &index, int n){
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++){
            mymap[i][j] = sqrt(euclideanDistance(i,j,index));
        }
    } 
}

void computeSol(){
  memset(dp,-1,sizeof(dp));
  dp[1][0]=0;
    for (i=1; i<(1<<n); i++) { 
        for (j=0; j<n; j++) {
            if (dp[i][j]==-1) 
                continue;
            for (k=1; k<n; k++) {
                if ((i & (1<<k))!=0)
                    continue;
                p=(i | (1<<k));
                if (dp[p][k]==-1)
                    dp[p][k]=dp[i][j]+mymap[j][k]; 
                dp[p][k]=min(dp[p][k],dp[i][j]+mymap[j][k]);
            }
        }
    }
}

int main() {
    ifstream myfile;
    myfile.open("tsp.txt");
    string input;
    long long i,j,n,k,p;
    double ans;
    getline(myfile,input);
    istringstream ss(input);
    ss>>n;
    vector<pair<double,double> > index;
    while(getline(myfile,input)){
        istringstream s(input);
        double x,y;
        s>>x;
        s>>y;
        index.push_back(make_pair(x,y));
    } 
    generatePaths(index,n);
    computeSol();
    ans=INF;
    for (i=1; i<n; i++) {
        if (dp[(1<<n)-1][i]>0)
            ans=min(ans,dp[(1<<n)-1][i]+mymap[i][0]);
    }
    cout<<ans<<endl;
    return 0;
}
