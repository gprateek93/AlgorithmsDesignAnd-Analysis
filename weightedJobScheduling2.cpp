#include <bits/stdc++.h>
using namespace std;
typedef pair<double,pair<int,int> > ipair;

bool mycomp(ipair a, ipair b){
    return a.first > b.first;
}

int main(){
    ifstream myfile;
    myfile.open("Jobs.txt");
    string input;
    getline(myfile,input);
    istringstream ss(input);
    int total;
    ss>>total;
    vector<ipair> numbers;
    while(getline(myfile,input)){
        istringstream s(input);
        int w,l;
        s>>w;
        s>>l;
        double ratio = 1.0*w/l;
        cout<<ratio<<endl;
        numbers.push_back(make_pair(ratio,make_pair(w,l)));
    }
    sort(numbers.begin(), numbers.end(),mycomp);
    long long cumLen = 0; 
    long long cumWt = 0;
    for(int i = 0; i<numbers.size(); i++){
        cumLen += numbers[i].second.second;
        cumWt += cumLen * numbers[i].second.first;
    }
    cout<<cumWt;
    return 0;
}
