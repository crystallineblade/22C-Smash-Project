#include<iostream>
#include"HashTable.h"
using namespace std;
const int T_S = 200;
HashMapTable::HashMapTable() {
	Htable = new HashTableEntry[T_S];
	collisions=0;
}
int HashMapTable::HashFunc(string bd) {
	int sum=0;
	for(int i=0;i<bd.length();i++)
	{
		if(bd[i]>='0' && bd[i]<='9')
		{
			int num=bd[i]-'0';
			sum=sum+num;
		}
	}
	int index=0;
	while(sum!=0)
	{
		index=index+(sum%10);
		sum=sum/10;
	}
	return index;
}
void HashMapTable::Insert(string name,string bd) {
	
	int h = HashFunc(bd);
	int j=0;
	if(Htable[h].birthday==""&&Htable[h].name=="")
	{
		Htable[h].birthday=bd;
		Htable[h].name=name;
		Htable[h].key=h;
	}
	else if(Htable[h].birthday!=""&&Htable[h].name!="")
	{
		while(Htable[h].birthday!=""&&Htable[h].name!=""&&h<T_S)
		{
			collisions++;
			j++;
			h=(h+j)%T_S;
		}
		if(h<T_S)
		{
		Htable[h].birthday=bd;
		Htable[h].name=name;
		Htable[h].key=h;
		}
	}
}
int HashMapTable::SearchKey(string bd) {
	int h = HashFunc(bd);
	int j=0;
	if(Htable[h].birthday==bd)
	{
		cout<<"Name:"<<Htable[h].name<<endl;
		cout<<"Birthday:"<<Htable[h].birthday<<endl;
	}
	else
	{
		while(Htable[h].birthday!=bd&&j<T_S)
		{
			j++;
			h=(h+j)%T_S;
		}
		if(j<T_S&&Htable[h].birthday==bd)
		{
			cout<<"Name:"<<Htable[h].name<<endl;
		cout<<"Birthday:"<<Htable[h].birthday<<endl;
		}
		else
		{
			cout<<"Invalid Data"<<endl;
		}
	}
	return 0;
}
HashMapTable::~HashMapTable() {
	Htable=nullptr;
}
int HashMapTable::getCollisions()
{
	return collisions;
}