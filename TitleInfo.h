#ifndef TITLEINFO_H
#define TITLEINFO_H

#include<cstring>
#include<iostream>
using namespace std;


class TitleInfo{        //����

protected:
	char* ISBN;
	char* Title;
	char* Author;
	char *Pub;
	char*DateAdded;
	int Qty;
	double Wholesale;
	double Retail;
public:

	TitleInfo() 
	{
		ISBN=new char[50];
		Title = new char[50];
		Author = new char[50];
		Pub = new char[50];
		DateAdded = new char[50];
		Qty=0;
		Wholesale=0;
		Retail=0;
	}

	TitleInfo(const TitleInfo& book);
	TitleInfo(char* ISBN, char* Title, char* Author, char *Pub, char*DateAdded, int Qty, double Wholesale, double Retail);
	~TitleInfo();

	char * getISBN(){ return ISBN; }
	char* getTitle() { return Title; }
	char* getAuthor(){ return Author; }
	char* getPublisher(){ return Pub; }
	char* getEntryDate(){ return DateAdded; }
	int getNumber(){ return Qty;}
	double getWholesale(){ return Wholesale;}
	double getRetail(){ return Retail; }
	void setISBN(char * ISBN);
	void setTitle(char* Title);
	void setAuthor(char* Author);
	void setPub(char* Pub);
	void setEntryDate(char* DateAdded);
	void setNumber(int Qty);
	void setWholesale(double Wholesale);
	void setRetail(double Retail); 


	void print()
	{
		cout<<"ISBN��: "<<ISBN<<endl;
		cout<<"����: "<<Title<<endl;
		cout<<"����: "<<Author<<endl;
		cout<<"������: "<<Pub<<endl;
		cout<<"��������: "<<DateAdded<<endl;
		cout<<"�������: "<<Qty<<endl;
		cout<<"������: "<<Wholesale<<endl;
		cout<<"���ۼ�: "<<Retail<<endl;
	}
};
#endif  
