#include <bits/stdc++.h>                                                                                                                                                                
using namespace std;

class myString {
	private:
		string m_str;
	public:
		myString(string s){
			m_str=s;
		}
}; 

class ReadClass{
	ifstream in;
	string line;
	in.open("main.cpp");
	if (in.fail()){
		cout <<"Error opening a file"<<endl;
		in.close();
	}
	while (getline(in,line)){
		cout <<line<<endl;
	}
	                                                                                                                                                                                                                                                                                        
	
};

int main (){
	
	ReadClass rfile;
	rfile.showClass();
	return 0;
}
                                                                                                       
