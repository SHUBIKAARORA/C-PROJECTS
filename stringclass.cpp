#include<iostream>
#include<cstring>
using namespace std;
class String{
	char *str;
	public:
	String(){
		str=new char[1];
		str[0]='\0';
	}
	String(char* val);
	String(const String& obj);
	int strlength();
	void replace(const char temp[]);
	void reverse();
	void casechange();
	void display(){
		cout<<this->str;
	}
    String operator +(const String& rhs);
    String operator *(int n);
	~String(){delete str;}
	
};
String::String(char* val){
	str=new char[strlen(val)+1];
	strcpy(str,val);
	str[strlen(val)]='\0';
}
String::String(const String& obj){
	str=new char[strlen(obj.str)+1];
	strcpy(str,obj.str);
	str[strlen(obj.str)]='\0';
}
int String::strlength(){
	return strlen(str);
}
void String::replace(const char temp[]){
	strcpy(this->str,temp);
}
void String::reverse(){
	int length=strlen(this->str);
	int m=length-1;
	char* temp=this->str;
	char* temp2=new char[length+1];
	for(int i=0;i<length;i++){
		temp2[i]=temp[m];
		m--;
	}
	temp2[length+1]='\0';
	strcpy(this->str,temp2);
}
void String::casechange(){
	int length=strlen(this->str);
	char* temp=this->str;
	for(int i=0;i<length;i++){
		if(int(temp[i])>=97||int(temp[i])<=122){
			temp[i]=char(int(temp[i])-32);
		}
		else{
			temp[i]=char(int(temp[i])+32);
		}
	}
	strcpy(this->str,temp);
}
String String::operator +(const String& rhs){
	int length=strlen(this->str)+strlen(rhs.str);
	char* temp=new char[length+1];
	strcpy(temp,this->str);
	strcat(temp,rhs.str);
	temp[length]='\0';
	String constring(temp);
	delete[] temp;
	return constring;
}
String String::operator *(int n){
	int length=strlen(this->str);
	int m=(length*n)+1;
	char* temp=new char[m];
	for(int i=0;i<n;i++){
		strcat(temp,this->str);
	}
	temp[m]='\0';
	String s3(temp);
	return s3;
}
int main(){
	char temp[]="shubika";
	String string(temp);
	char temp2[]="arora";
	String string1(temp2);
	cout<<"The length of string is:";
	int m=string.strlength();
	cout<<m<<endl;
	String string3;
	string3=string+string1;
	string3.display();
	cout<<endl;
	String string2;
	string2=string*5;
	string2.display();
	cout<<endl;
	string3.replace(temp);
	string3.display();
	cout<<endl;
	string3.reverse();
	string3.display();
	cout<<endl;
	char ad[]="Shubika";
	String s3(ad);
	s3.casechange();
	s3.display();
}
