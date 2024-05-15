#include<iostream>
using namespace std;
char stack[100];
int top=-1;
void push(char c){
	top++;
	stack[top]=c;                                            
}
char pop(){
	char c=stack[top];
	top--;
	return c;
	
}
void checkparanthesis(string a){
	for(int i=0;i<a.length();i++){
		if (top==-1){
			push(a[i]);
		}
		else{
			char ch=pop();
			if((a[i]==')'&& ch=='(')||(a[i]=='}'&& ch=='{')||(a[i]==']'&& ch=='[')){
			}
			else{
				push(ch);
				push(a[i]);
			}
		}
	}
	if (top==-1){
		cout<<"ALL PARANTHESIS ARE BALANCED!!";
	}
	else{
		cout<<"PARANTHESIS ARE NOT BALANCED";
	}
}
int main(){
	cout<<"PARANTHESIS CHECKER!!\n";
	string chr;
	cout<<"Enter string of paranthesis:\t";
	cin>>chr;
	checkparanthesis(chr);
	return 0;
}
