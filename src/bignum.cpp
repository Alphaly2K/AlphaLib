#include "bignum.h"
#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::isalpha;
using std::strlen;
using std::endl;
using alp::BigNumber;
using alp::RadixNotEqualException;
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
	try{
		return *this+num;
	}catch(RadixNotEqualException& e){
		e.Print();
		return BigNumber(0,10);
	}

}
BigNumber BigNumber::Add(char* num,int nadv){
	BigNumber newBN(num,nadv);
	try{
		return *this+newBN;
	}catch(RadixNotEqualException& e){
		e.Print();
		return BigNumber(0,10);
	}
}
BigNumber BigNumber::Add(int num){
	//To-do
	return 0;
}
BigNumber BigNumber::operator+(const BigNumber num){
	BigNumber newBN(num.number,num.adv);
	if(this->adv==num.adv)
		newBN.number=BigNumber::GetTotal(this->number,newBN.number,num.adv);
	else{
		throw RadixNotEqualException(this->adv,num.adv);	//Use try-catch to detect RadixNotEqualException.
	}
	return newBN;
}
void RadixNotEqualException::Print() const{
	switch (m_flag)
	{
	case 1:
		cout<<"The radix of the value left is bigger than that of the right one."<<endl;
		break;
	case 2:
		cout<<"The radix of the value right is bigger than that of the left one."<<endl;
	default:
		cout<<"Unknown exception detected."<<endl;
		break;
	}
}
