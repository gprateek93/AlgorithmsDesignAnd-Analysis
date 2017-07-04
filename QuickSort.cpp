#include <bits/stdc++.h>
using namespace std;

int myint(string s){
	stringstream ss;
	ss.str(s);
	int res;
	ss>>res;
	return res;
}

int medianOfThree(int num[], int m, int n){
	int a = num[m];
	int b = num[n];
	int mid = m + (n-m)/2;
	int c = num[mid];
	vector<pair<int,int> > sample;
	sample.push_back(make_pair(a,m));
	sample.push_back(make_pair(b,n));
	sample.push_back(make_pair(c,mid));
	sort(sample.begin(),sample.end());
	return sample[1].second;
}

int makePartition(int num[], int m ,int n,int t,int &count){
	int i,j;
	if(t){
		i = m+1;
		j=m+1;
		while(j<=n){
			if(num[j]<=num[m]){
				int temp = num[j];
				num[j] = num[i];
				num[i] = temp;
				i++;
			}
			j++;
		}
		int temp = num[i-1];
		num[i-1] = num[m];
		num[m] = temp;
		count+=n-m;
		return i-1;
	}
}

int QuickSort(int num[],int m, int n, int t, int &count){
	if(m<n){
		int p;
		if(t==1){
			p = m;
		}
		else if(t==2){
			p = n;
		}
		else if(t==3){
			p = medianOfThree(num,m,n);
		}
		int temp = num[m];
		num[m]=num[p];
		num[p]=temp;
		int partition = makePartition(num,m,n,t,count);
		QuickSort(num,m,partition-1,t,count);
		QuickSort(num,partition + 1, n, t,count);
		return count;
	}
}

int main(){
	int num[10000];
	string input;
	ifstream integers;
	int i = 0;
	integers.open("QuickSort.txt");
	while(!integers.eof()){
		getline(integers,input);
		num[i++] = myint(input);
	}
	integers.close();
	int t;
	cout<<"Please enter the question number"<<endl;
	cin>>t;
	int count = 0;
	cout<<QuickSort(num,0,9999,t,count);
	return 0;
}
