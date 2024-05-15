#include<iostream>
#include<cstdlib>
using namespace std;
int user_choice(){
	cout<<"Enter your choice";
	cout<<"1.ROCK--r\n2.PAPER--p\n3.SCISSORS--s\n";
	char ch;
	cin>>ch;
	int userchoice;
	switch(ch){
		case 'r':
			userchoice=1;
			cout<<"YOU CHOSE ROCK\n";
			break;
		case 'p':
		    userchoice=2;
			cout<<"YOU CHOSE PAPER\n";
			break;
		case 's':
			userchoice=3;
			cout<<"YOU CHOSE SCISSORS\n";
			break;
	}
	return userchoice;
}
int comp_choice(){
	int answer=rand()%3+1;
	switch(answer){
		case 1:
			cout<<"COMPUTER CHOSE ROCK\n";
			break;
		case 2:
			cout<<"COMPUTER CHOSE PAPER\n";
			break;
		case 3:
			cout<<"COMPUTER CHOSE SCISSORS\n";
			break;
	}
	return answer;
}
int result(int u,int c){
	int answer;
	if(u==1){
		if (c==2){
			answer=-1;
		}
		else if (c==3){
			answer=1;
		}
		else{
			answer=0;
		}
	}
	else if (u==2){
		if(c==1){
			answer=1;
		}
		else if(c==3){
			answer=-1;
		}
		else{
			answer=0;
		}
	}
	else{
		if (c==1){
			answer=-1;
		}
		else if (c==2){
			answer=1;
		}
		else{
			answer=0;
		}
	}
	return answer;
}
int main(){
	int userchoice=user_choice();
	int computerchoice=comp_choice();
	int final=result(userchoice,computerchoice);
	switch(final){
		case 0:
			cout<<"IT IS A TIE\n";
			break;
		case 1:
			cout<<"YOU WON!!\n";
			break;
		case -1:
			cout<<"COMPUTER WON\n";
			break;
	}
	return 0;
}
