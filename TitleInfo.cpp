#include"TitleInfo.h"

TitleInfo::TitleInfo(char* ISBN,char* Title, char* Author, char* Pub, char* DateAdded, int Qty, double Wholesale, double Retail)
{
	this->ISBN = new char[strlen(ISBN)+1];
	this->Title = new char[strlen(Title)+1];
	this->Author = new char[strlen(Author)+1];
	this->Pub = new char[strlen(Pub)+1];
	this->DateAdded = new char[strlen(DateAdded)+1];
	strcpy(this->ISBN, ISBN);
	strcpy(this->Title, Title);
	strcpy(this->Author, Author);
	strcpy(this->Pub, Pub);
	strcpy(this->DateAdded, DateAdded);
	this->Qty = Qty;
	this->Wholesale = Wholesale;
	this->Retail = Retail;
}
//设置ISBN号
TitleInfo::TitleInfo(const TitleInfo& book)
{
	this->ISBN = new char[strlen(book.ISBN) + 1];
	this->Title = new char[strlen(book.Title) + 1];
	this->Author = new char[strlen(book.Author) + 1];
	this->Pub = new char[strlen(book.Pub) + 1];
	this->DateAdded = new char[strlen(book.DateAdded) + 1];
	strcpy(this->ISBN, book.ISBN);
	strcpy(this->Title, book.Title);
	strcpy(this->Author, book.Author);
	strcpy(this->Pub, book.Pub);
	strcpy(this->DateAdded, book.DateAdded);
	this->Qty = book.Qty;
	this->Wholesale = book.Wholesale;
	this->Retail = book.Retail;
}
void TitleInfo::setISBN(char* ISBN) 
{
	delete[]ISBN;
	this->ISBN = new char[strlen(ISBN) + 1];
	strcpy(this->ISBN, ISBN);
}
//设置书名
void TitleInfo::setTitle(char* Title)
{
	delete[]this->Title;
	this->Title = new char[strlen(Title) + 1];
	strcpy(this->Title, Title);
}
//设置作者
void TitleInfo::setAuthor(char* Author)
{
	delete[]this->Author;
	this->Author = new char[strlen(Author) + 1];
	strcpy(this->Author, Author);
}
//设置出版商
void TitleInfo::setPub(char* Pub)
{
	delete[]this->Pub;
	this->Pub = new char[strlen(Pub) + 1];
	strcpy(this->Pub, Pub);
}
//设置进书日期
void TitleInfo::setEntryDate(char* DateAdded)
{
	delete[]this->DateAdded;
	this->DateAdded = new char[strlen(DateAdded) + 1];
	strcpy(this->DateAdded, DateAdded);
}
//设置数量
void TitleInfo::setNumber(int Qty)
{
	this->Qty = Qty;
}
//设置批发价
void TitleInfo::setWholesale(double Wholesale)
{
	this->Wholesale = Wholesale;
}
//设置零售价
void TitleInfo::setRetail(double Retail)
{
	this->Retail = Retail;
}



TitleInfo::~TitleInfo()
{
	delete[]ISBN;
	delete[]Title;
	delete[]Author;
	delete[]Pub;
	delete[]DateAdded;
}