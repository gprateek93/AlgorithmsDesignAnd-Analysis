#include <bits/stdc++.h>
using namespace std;

long long myint(string s){
	stringstream ss;
	ss.str(s);
	long long ans ;
	ss>>ans;
	return ans;
}

void makeEqualSizes(string &a, string &b){
	if(a.size()!=b.size()){
		string c = "";
		if(a.size()>b.size()){
			int diff = a.size()-b.size();
			while(diff--){
				c+="0";
			}
			b = c+b;
		}
		else{
			int diff = b.size()-a.size();
			while(diff--){
				c+="0";
			}
			a = c+a;	
		}
		return;
	}
	else
		return;
}

string to_string(long long num){
	stringstream ss;
	ss<<num;
	return ss.str();
}
string multiply(string a, string b){
	makeEqualSizes(a,b);
	if(a.size()==1){
		stringstream ss;
		long long x = myint(a), y = myint(b);
		long long prod = x*y;
		return to_string(prod);
	}
	else{
		string p,q,r,s; 
		if(a.size()%2==0){
			p= a.substr(0,a.size()/2);
			q = a.substr(a.size()/2,a.size()/2);
		}
		else if(a.size()!=1){
			p= a.substr(0,a.size()/2+1);
			q = a.substr(a.size()/2+1,a.size()/2);
		}
		if(b.size()%2==0){
			r = b.substr(0,b.size()/2);
			s = b.substr(b.size()/2,b.size()/2);
		}
		else if(b.size()!=1){
			r = b.substr(0,b.size()/2+1);
			s = b.substr(b.size()/2+1,b.size()/2);
		}
		string pr = multiply(p,r);
		string qs = multiply(q,s);
		long long p1 = myint(p), q1 = myint(q), r1 = myint(r), s1 = myint(s) ,pr1 = myint(pr), qs1 = myint(qs);
		string aux = multiply(to_string(p1+q1),to_string(r1+s1));
		long long aux1 = myint(aux);
		long long temp = aux1 - pr1 - qs1;
		int m = a.size() - a.size()%2;
		long long ans = pr1 * pow(10,m) + temp * pow(10,m/2) + qs1;
		return to_string(ans);
	}
}

int main() {
	string a,b;
	cout<<"Enter the strings"<<endl;
	cin>>a>>b;
	cout<<multiply(a,b);
	return 0;
}
