#include<bits/stdc++.h>
using namespace std;
char encrypt(int key,char letter)
{
	int temp;
	char a;
	key=key%26;
	if(letter>=65&&letter<=90)
	{
		temp=(letter + key)%91;
		if(key>=0)
		{
			if(temp<65)
			{
				temp+=65;
			}
		}
		else
		{
			if(temp<65)
			{
				temp+=26;
			}
		}
	}
	else if(letter>=97&&letter<=122)
	{
		temp=(letter + key)%123;
		if(key>=0)
		{
			if(temp<97)
			{
				temp+=97;
			}		
		}
		else
		{
			if(temp<97)
			{
				temp+=26;
			}
		}
	}
	else
	{
		return letter;
	}
	a=temp;
	return a;
}
char decrypt(int key,char letter)
{
	int temp;
	char a;
	key=-key;
	key=key%26;
	if(letter>=65&&letter<=90)
	{
		temp=(letter + key)%91;
		if(key>=0)
		{
			if(temp<65)
			{
				temp+=65;
			}
		}
		else
		{
			if(temp<65)
			{
				temp+=26;
			}
		}
	}
	else if(letter>=97&&letter<=122)
	{
		temp=(letter + key)%123;
		if(key>=0)
		{
			if(temp<97)
			{
				temp+=97;
			}		
		}
		else
		{
			if(temp<97)
			{
				temp+=26;
			}
		}
	}
	else
	{
		return letter;
	}
	a=temp;
	return a;
}
int main()
{
	char a[100];
	char b[100];
	int i=0,j=0,key,size;
	a[0]=':';
	cout<<"Enter the size of the string to be encrypted: "<<"\n";
	cin>>size;
	cout<<"Enter the string to encrpyted: "<<"\n";
    for(int l=0;l<size;l++)
    {
    	cin>>a[l];
	}
	cout<<"Enter the key to encrpyt the information: "<<"\n";
	cin>>key;
	i=size;
	while(i>0)
	{
		b[j]=encrypt(key,a[j]);
		j++;
		i--;
	}
	cout<<"The encrypted informaton is : "<<"\n";
	cout<<b<<"\n";
	cout<<"the decrypted info is: "<<"\n";
	i=size;
	j=0;
	while(i>0)
	{
		b[j]=decrypt(key,b[j]);
		j++;
		i--;
	}
	cout<<b<<"\n";
}
