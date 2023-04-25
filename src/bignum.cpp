#include "bignum.h"
#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::isalpha;
using std::strlen;
using alp::BigNumber;
int BigNumber::GetDec(char ch){
	if(isalpha(ch)) return ch-'A'+10;
	else return ch-'0';
}

char* BigNumber::GetTotal(char* a,char* b,int adv){
	const char* output="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int lena=strlen(a);
	const int lenb=strlen(b);
    int m[lena+1],n[lenb+1],tmpAns[lenb+1];
	int maxLen=(lena<lenb)?lenb:lena;
	for(int i=0;i<lena;i++) m[i]=GetDec(a[lena-i-1]);
	for(int i=0;i<lenb;i++) n[i]=GetDec(b[lenb-i-1]);
	for(int i=0;i<maxLen;i++){
		tmpAns[i]+=m[i]+n[i]; 
		tmpAns[i+1]=tmpAns[i]/adv;
		tmpAns[i]%=adv;
	}
	if(tmpAns[maxLen]) maxLen++;
    char* Ans =new char[maxLen];
	for(int i=maxLen-1;i>=0;i--){
		Ans[maxLen-i-1]=char(output[tmpAns[i]]);
	} 
    return Ans;
}

BigNumber::BigNumber(){
	number=new char[1];
	number[0]='0';
	adv=10;
}
BigNumber::BigNumber(char* num,int nadv=10){
	int numlen=strlen(num);
	number=new char[numlen];
	adv=nadv;
}

BigNumber BigNumber::Add(BigNumber num){
	return *this+num;
}
BigNumber BigNumber::Add(char* num,int nadv){

}
BigNumber BigNumber::Add(int num){

}
BigNumber BigNumber::operator+(const BigNumber num){
	BigNumber newBN(num.number,num.adv);
	char * numb=this->number;
	if(this->adv==num.adv)
		newBN.number=BigNumber::GetTotal(numb,newBN.number,num.adv);
	else{
		
	}
	return newBN;
}
