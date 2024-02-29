#include <stdio.h>
//using namespace std;
void print_sp(int rows,int n){
for (int sp=0;sp<rows-n;sp++){
		printf(" ");
}}
void print_num(int n){
	for (int i=0;i<n;i++){
	    printf("%d",n);
	    printf(" ");
	
	}
}
int main (){
	int rows=6;
	for (int n=0;n<=rows;n++){
		print_sp(rows,n);
		print_num(n);
		printf("\n");
	}
}
