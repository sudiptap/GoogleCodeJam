#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include <tuple>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

struct compare  
 {  
   bool operator()(const tuple<int, int, int>& l, const tuple<int, int, int>& r)  
   {  
       return get<2>(l)<get<2>(r);
   }  
 }; 


pair<int, int> process(int n, int k){
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, compare> pq;
	tuple<int,int,int> t; t = make_tuple(1,n,n-1+1);
	pq.push(t); pair<int, int> output; 
	for(int i=0; i< k; i++){
		tuple<int,int,int> maxt = pq.top();
		
		//cout<<get<0>(maxt)<<",";
		//cout<<get<1>(maxt)<<",";
		//cout<<get<2>(maxt)<<endl<<endl;
		
		int room_occupy = floor((get<0>(maxt)+get<1>(maxt))/2);
		pq.pop();
		
		pq.push(make_tuple(get<0>(maxt),room_occupy-1,room_occupy-get<0>(maxt)));
		pq.push(make_tuple(room_occupy+1,get<1>(maxt),get<1>(maxt)-(room_occupy)));
		int rs = get<1>(maxt)-room_occupy;
		int ls = room_occupy-get<0>(maxt);
		output = make_pair(max(ls,rs),min(ls,rs));
	}
	return output;
}

/*
int main() {	
    pair<int, int> output = process(1000, 1);	
	cout<<output.first<<" "<<output.second<<endl;	
    return 0;
}*/


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
		int n; int k;
		iss1>>n>>k;
		
		//cout<<n<<" "<<k<<endl;
		pair<int, int> output = process(n, k);		
		//cout<<"Case "<<i<<" Completed"<<endl;
		//cout<<output.first<<" "<<output.second<<endl;
		ofile<<"Case #"<<i<<": "<<output.first<<" "<<output.second<<endl;
	}
	infile.close(); ofile.close();	
    return 0;
}
