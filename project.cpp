#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class a{
	string id,name,author;
	fstream file;
	public:
	void addBook();
	void showAll();
	void extractBook();
	
};
int main() {
 char choice;
 cout<<"................................";
 cout<<"1-Show All Books";
 cout<<"2-Extract Book";
 cout<<"3-Add Books(ADMIN)";
 cout<<"4-Exit";
 cout<<"..............................";
 cout<<"Enter Your Choice::";
 cin>>choice;
  
  switch(choice){
  	case '1':
  	cin.ignore();
  	obj.showAll();
  	break;
  	case '2':
  	cin.ignore();
  	obj.extractBook();
  	break;
  	case '3':
  	cin.ignore();
  	obj.addbook();
  	break;
  	case '4':
  	return 0;
  	break;
  	default:
  	cout<<"Invalid choice...!";
  }
	return 0;
}
void a :: addBook(){
	cout<<"\nEnter Book ID :: ";
	getline(cin,id);
	cout<<"Enter Book Name :: ";
	getline(cin,name);
	cout<<"Enter Books Author name::";
	getline(cin,author);
	
	file.open("bookData.txt",ios::out|ios::app);
	file<<id<<"*"<<name<<"*"<<author<<endl;
	file.close();
}
void a::showAll(){
	file.open("bookData.txt",ios::in);
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	cout<<endl<<endl;
	cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
	while(!file.eof()){
		cout<<"\t\t "<<id<<" \t\t\t "<<name<<"\t\t\t "<<author<<endl;
	
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	}
	file.close();
}
void a::extractBook(){
	showAll();
	cout<<"Enter Book Id :: ";
	getline(cin,search);
	file.open("bookData.txt",ios::in);
	getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	cout<<endl<<endl;
	cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
	while(!file.eof()){
		if(search==id){
		cout<<"\t\t "<<id<<" \t\t\t "<<name<<"\t\t\t "<<author<<endl;
		cout<<"Book Extracted Succeefully....!";
		}
		getline(file,id,'*');
	getline(file,name,'*');
	getline(file,author,'\n');
	}
	file.close();
}

