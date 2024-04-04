#include <bits/stdc++.h>
using namespace std;
bool check(int a[], int key){
 for (int i=0; i<7; i++)
  if (a[i]==key) return true;
 return false;
}
struct lotto_record_t{
	int receipt_id;
	int receipt_price;
	char receipt_time[32];
	int lotto[5][7];
};
bool hasIntersection(const vector<int>& v1, const vector<int>& v2) {
    for (int val1 : v1) 
        for (int val2 : v2) 
            if (val1 == val2) return true;            
    return false;
}
lotto_record_t generate(int id, int n){
	srand(time(NULL));
	lotto_record_t rec;
	rec.receipt_id=id;
	rec.receipt_price=n*100;
	string ids=to_string(id);
    ids=string(5-ids.length(),'0')+ids;
	string s="lotto["+ids+"].txt";
	ofstream outFile(s);
    outFile<<"======== lotto649 =========="<<endl; 
    outFile<<"=======+ No."+ids+" +========="<<endl; 
    outFile<<"= ";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", ltm);
    outFile<<buffer<<" ="<<endl;
	strcpy(rec.receipt_time,buffer); 
	for(int i=0; i<5; i++)for(int j=0;j<7;j++)rec.lotto[i][j] = 0;   
    int temp;
    cout<<"已為您購買的 "<<n<<" 組樂透組合輸出至"<<s<<endl;    
    for (int i=1; i<=n; i++){
    	outFile<<"["<<i<<"]: ";
	    int a[7]={0};
	    for (int j=0; j<7; j++){
	    	bool rep=true;
	        while (rep){
		       temp=rand()%69+1;
		       rep=check(a,temp);
		       if (!rep) a[j]=temp;
		       rec.lotto[i-1][j]=temp;
	        }
		    if (a[j]<10)  outFile <<0<<a[j]<<" ";
		    else          outFile <<a[j]<<" ";
	 	 }
	 	 outFile <<endl;  
	 }
	 for(int i=n+1;i<=5;i++)outFile<<"["<<i<<"]: -- -- -- -- -- -- --\n"; 
	 outFile<<"======== csie@CGU =========="<<endl; 
	 outFile.close();
	 return rec;
}
int main() {
 	int id,n;
 	vector<lotto_record_t>record;
 	lotto_record_t rec;
 	record.clear();
 	string outfn,fn="record.bin";
  	fstream file(fn.c_str(),ios::binary|ios::in);
  	if (file){
    	while(file.read((char*)&rec, sizeof(lotto_record_t)))
			record.push_back(rec);    	
		id=record.size()+1;
	}
	else{id=1;} 
	file.close();	
 	cout<<"請問您要買幾組樂透彩：";
    cin>>n;    
    if (n<0) return 0;
    if (n>=1){
		rec=generate(id,n);  
		fstream file(fn.c_str(),ios::binary|ios::out|ios::app);
	    file.write((char*)&rec, sizeof(lotto_record_t));
    	file.close();      
    	return 0;
	}
	string s;	
    getline(cin, s);
	cout << "請輸入中獎號碼(最多三個): ";
	getline(cin, s);
    istringstream iss(s);
    vector<int> numbers;
    int number;
    while (iss >> number) numbers.push_back(number);
	cout << "輸入的中獎號碼為: ";
	for (int n:numbers){
		if (n<10) cout<<0;
		cout<<n<< " ";
	}
	cout<<endl;
	cout<<"以下為中獎彩卷:\n";
	
	for (int i=0; i<record.size(); i++){
		for (int ii=0; ii<5; ii++){
			vector<int> temp;
			temp.clear();
			for(int j=0;j<7;j++)temp.push_back(record[i].lotto[ii][j]);
  	    	if (hasIntersection(numbers, temp)){
			  	cout<<"彩卷 No. "<<record[i].receipt_id<<endl;
			  	cout<<"售出時間: "<<record[i].receipt_time<<endl;
			  	cout<<"號碼: ";
			  	for (int n:temp){if (n<10) cout<<0;	cout<<n<<" ";}
				cout<<endl;
			} 
		} 
	}
}
