#include <bits/stdc++.h>
using namespace std;


void addNumber(int num, priority_queue<int,vector<int>,greater<int> > &minHeap, priority_queue<int,vector<int>,less<int> > &maxHeap){
    if(minHeap.size() == maxHeap.size()){
        if(!minHeap.empty()&&num>minHeap.top()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
    }
    else{
        if(num>maxHeap.top()){
            minHeap.push(num);
        }
        else{
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(num);
        }
    }
}

long long getMedian(priority_queue<int,vector<int>,greater<int> > minHeap, priority_queue<int,vector<int>,less<int> > maxHeap){
    if(maxHeap.empty())
        return 0;
    else
        return maxHeap.top();
}

int main(){
    int res=0;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    priority_queue<int,vector<int>,less<int> > maxHeap;
    ifstream myfile;
    myfile.open("Median.txt");
    string input;
    while(getline(myfile,input)){
        istringstream ss(input);
        int n;
        ss>>n;
        addNumber(n,minHeap,maxHeap);
        res += (getMedian(minHeap,maxHeap)%10000);
    }
    cout<<res%10000;
    return 0;
}
