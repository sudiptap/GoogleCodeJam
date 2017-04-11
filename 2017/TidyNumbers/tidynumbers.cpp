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

bool isTidy(string str){
	for(int i=0; i< str.length()-1; i++){
		if(str[i]>str[i+1]){
			return false;
		}
	}
	return true;
}

string getLastestTidy2Mer(string str){
	if(isTidy(str)) return str;
	if(str=="10") return "09";
	string ret = to_string((str[0]-48)-1) + "9";	
	return ret;
}

string process(string inp){
	bool flag=false;
	string temp = inp;
	if(isTidy(temp)) return temp;
	for(int i=0; i< temp.length()-1; i++){
		string twomer = temp.substr(i,2);
		if(isTidy(twomer)){
			continue;
		}else{			
			if(flag){
				temp[i+1]= '9';
			}else{
				string latesttidy2mer = getLastestTidy2Mer(twomer);
				temp[i]=latesttidy2mer[0]; temp[i+1]=latesttidy2mer[1];
				flag=true;
			}
		}		
	}
	string out = "";
	bool zero_found=false;
	for(int j=temp.length()-1; j>=0; j--){
		if(zero_found){
			out+='9';
		}else{
			if(temp[j]=='0'){
				zero_found=true;				
			}else{
				out+=temp[j];
			}
		}
	}
	reverse(out.begin(), out.end());
	return out;
}

int main(int argc,  char **argv) {
	//cout<<process("111111111111111110")<<endl;
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
		string inp;
		iss1>>inp;
		//cout<<inp<<endl;
		//cout<<s<<" "<<k<<endl;		
		string output = process(inp);
		ofile<<"Case #"<<i<<": "<<output<<endl;		
	}
	infile.close(); ofile.close();
    return 0;
}
