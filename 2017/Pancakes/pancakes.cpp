#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include <tuple>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool is_happy(string s){
	for(int i=0; i< s.length(); i++){
		if(s[i]=='-') return false;
	}
	return true;
}

string make_flip(string s, int loc, int k){
	for(int i=0; i<k; i++){
		s[loc+i]=(s[loc+i]=='+')?'-':'+';
	}
	return s;
}

bool impotent(string s){
	bool b=true; bool flag=false;
	for(int i=0; i< s.length()-1; i++){
		if(s[i]!=s[i+1]){
			if(flag){
				return true;
			}
			flag=true;
		}
	}	
	return false;
}

bool noFlip(string s){
	bool b=false;
	for(int i=0; i< s.length(); i++){
		if(s[i]!='+'){
			return false;
		}
	}
	return true;
}

int process(string inp, int k){
	//records a string, position from where I should start lookup and level I am in
	queue<tuple<string,int,int>> q;
	q.push(make_tuple(inp, -1, 0));
	while(!q.empty()){
		string temp = get<0>(q.front()); //cout<<"processing "<<temp<<endl;
		int pos = get<1>(q.front());
		int level = get<2>(q.front());		
		q.pop();
		if(is_happy(temp)) {/*cout<<"I am happy"<<endl;*/return level;}
		for(int loc=pos+1; loc< temp.length()-k+1; loc+=k){
			
			/*if(impotent(temp.substr(loc,k))){
				cout<<temp.substr(loc,k)<<"  "<<"impotent"<<endl;
			}else{
				cout<<temp.substr(loc,k)<<"  "<<"potent"<<endl;
			}*/
			if(noFlip(temp.substr(loc,k))) continue;		
			if(impotent(temp.substr(loc,k))) continue;
			string updated_string = make_flip(temp, loc, k);	//cout<<"processing "<<updated_string<<endl;
			if(is_happy(updated_string)) {/*cout<<"I am happy"<<endl;*/return level+1;}
			q.push(make_tuple(updated_string, pos+1, level+1));
		}
	}
	return -1;
}


int main() {
	string inp = "++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-++-"; int k=3;
    int output = process(inp, k);
	if(output>=0) cout<<output<<endl;
	else cout<<"IMPOSSIBLE"<<endl;	
    return 0;
}

/*
int main() {	
    int num_test_cases;
    cin>>num_test_cases;
	for(int i=0; i< num_test_cases; i++){
		string inp;
		int k;
		cin>>inp;
		cin>>k;
		//cout<<inp<<"--->"<<k;
		if(k>inp.length()){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		int output = process(inp, k);
		if(output>=0) cout<<"Case #"<<i+1<<": "<<output<<endl;
		else cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;	
	}
    return 0;
}*/

/*
int main(int argc,  char **argv) {
	cout<<argv[1]<<endl;
	cout<<argv[2]<<endl;
	ifstream infile(argv[1]);
	std::string line;
	int num_test_cases;
	getline(infile, line);
	istringstream iss(line);
    iss>>num_test_cases;
	ofstream ofile(argv[2]);
	int i=0;
	while (std::getline(infile, line))
	{
		i++;
		istringstream iss1(line);
		string inp; int k;
		iss1>>inp>>k;
		//cout<<s<<" "<<k<<endl;
		if(k>inp.length()){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<inp<<endl;
		int output = process(inp, k);		
		cout<<"Case "<<i<<" Completed"<<endl;
		if(output>=0) ofile<<"Case #"<<i<<": "<<output<<endl;
		else ofile<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;	
	}
	infile.close(); ofile.close();	
    return 0;
}*/
