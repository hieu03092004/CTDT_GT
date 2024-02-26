#include<bits/stdc++.h>
using namespace std;
int pre(string x){
	if(x=="*" || x=="/")
		return 2;
	if(x=="+" || x=="-")
		return 1;
	return 0;
}
void solve1(vector<string>v){
	stack<long long>st;
	for(string x:v){
		if(x!="+" && x!="-" && x!="*")
			st.push(stoll(x));
		else{
			long long a=st.top();
			st.pop();
			long long b=st.top();
			st.pop();
			if(x=="+") st.push(b+a);
			if(x=="-") st.push(b-a);
			if(x=="*") st.push(b*a);
		}
	}
	cout<<st.top();
}
void solve(vector<pair<string,char>>v){
	stack<string>st;
	vector<string>k;
	for(auto it:v){
		string x=it.first;
		// cout<<x<<endl;
		if(it.second=='B')
			st.push(x);
		else if(it.second=='C'){
			while(!st.empty() && st.top()!="("){
				k.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else if(it.second=='D')
			k.push_back(x);
		else{
			while(!st.empty() && pre(st.top())>=pre(x)){
				k.push_back(st.top());
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()){
		k.push_back(st.top());
		st.pop();
	}
	solve1(k);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;
	getline(cin,s);
	if(s[s.size()-1]!=')')
	 	s+="#";
	vector<pair<string,char>>v;
	bool check=false;
	for(int i=0;i<s.size();i++){
		if(!isdigit(s[i])){
			check=true;
			break;
		}
	}
	if(check){
		for(int i=0;i<s.size();i++){
			int j;
			if(s[s.size()-1]!=')'&& j==s.size()-1)
				break;
		char x=s[i];
		if(x=='+' || x=='-' || x=='*'){
			string res="";
			res+=x;
			v.push_back({res,'A'});
			//toan hang la ki tu B
		}
		else if(x=='('){
			string res="";
			res+=x;
			v.push_back({res,'B'});
		}
		else if(x==')'){
			string res="";
			res+=x;
			v.push_back({res,'C'});
			//toan hang la ki tu B
		}
		else{
			int cnt=0;
			for( j=i;j<s.size();j++){
				if(!isdigit(s[j])){
					v.push_back({s.substr(j-cnt,cnt),'D'});
					break;
				}
				else
				cnt++;
			}
		}	
	}
	// for(auto it:v)
	// 	cout<<it.first<<" "<<it.second<<endl;
	solve(v);
	return 0;
	}
	cout<<s;
}
