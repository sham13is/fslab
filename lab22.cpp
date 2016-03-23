/*
 * lab22.cpp
 *
 *  Created on: 15-Feb-2016
 *      Author: 1CR13IS086
 */
#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<stdlib.h>
#define MAX 100
using namespace std;
class student{
	string name;
	string usn;
	string branch;
	string sem;
	public: void pack();
        void unpack();
        void modify();
        void search();
   void read();
    void write();
   void del();
   void insert();
   string BUFFER;
   fstream f1;
};

void student::read()
{
	cout<<"enter the name"<<endl;
	cin>>name;
	cout<<"enter the usn"<<endl;
    cin>>usn;
    cout<<"enter the branch"<<endl;
    cin>>branch;
    cout<<"enter the sem"<<endl;
    cin>>sem;
};
void student:: pack()
{
	string i;
	fstream f1;
    BUFFER=name+'|'+usn+'|'+branch+'|'+sem;
    BUFFER.resize(100,'$');
	f1.open("data1.txt",ios::out|ios::app);
     f1<<BUFFER<<endl;
	f1.close();
};
/*void student :: write()
{
	fstream f1,f2;
	{
	f1.open("data.txt",ios::out|ios::app);
	f1<<temp;
	f1.close();
    };*/
void student::unpack()
{
	int  i=0;
    usn.erase();
	while(BUFFER[i]!='|')
		name+=BUFFER[i++];
	i++;
	while(BUFFER[i]!='|')
			usn+=BUFFER[i++];
}

void student::insert()
{
	 read();
	 pack();
/*	 write();*/
};
void student::search()

	{
	string key;
	int flag;
	cout<<"enter key ";
	cin>>key;
	 f1.open("data1.txt",ios::in);
	 while(!f1.eof())
	 {
	 getline(f1,BUFFER);

	 unpack();

	 if(usn==key)
	 {
	 flag=1;
	 cout<<"found the record"<<endl;
	 int pos=f1.tellp();
	 cout<<BUFFER<<"found at position\t"<<pos<<endl;
	 break;
	 }
	  else
	  {
		  flag=0;
	  }
	 }
	 f1.close();
	 if(flag==0)
		 cout<<"not found"<<endl;
	}
int main()
{
	int choice;
	string key;
	student s;
	while(1)
		{
		cout<<"1.insert 2.search 3.modify 4.delete 5.exit";
		cin>>choice;

		switch(choice)
		{
		case 1:s.insert();
		        break;
		case 2:
	         s.search();
		       break;
		/*case 3:s.modify();
		       break;*/
		case 4:exit(0);

		      break;
		case 5:return 0;
		}
 }
	return 0;
}



