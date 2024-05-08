#ifndef BOOKDATE_H
#define BOOKDATE_H
#include"TitleInfo.h"
#include<fstream>

class BookDate : public TitleInfo       //���м̳�
{
private:
	static int Book_count;
public:

	BookDate* next;//����ָ��

	BookDate();
	BookDate(char* ISBN, char* Title, char* Author, char* Pub, char* DateAdded, int Qty, double Wholesale, double Retail);
	~BookDate();
	BookDate(const BookDate& book);
	static unsigned getBook_count() { return Book_count; }
	void setTitle(char* Title);
	void setISBN(char* ISBN);
	void setAuthor(char* Author);
	void setPub(char* Pub);
	void setDateAdded(char* DateAdded);
	void setQty(int Qty);
	void setWholesale(double Wholesale);
	void setRetail(double Retail);
	bool isEmpty();
	void BookInfo();

	//��������ϵͳ�ã���Ԫ����
	friend int FindBook(char* str, BookDate* book);
	friend BookDate* AddBook(BookDate* book);
	friend void EditBook(BookDate* book);
	friend void DeleteBook(BookDate* book);

	//������ϵͳ�ã� ��Ԫ����
	friend void ListBook(BookDate* book);
	friend void ListWholesale(BookDate* book);
	friend void ListRetail(BookDate* book);
	friend void ListQty(BookDate* book);
	friend void ListTotalWholesale(BookDate* book);
	friend void ListDateAdded(BookDate* book);
	friend ofstream& operator<<(ofstream& os, BookDate* book);
	friend ifstream& operator>>(ifstream& is, BookDate* book);


	BookDate* Initialize_List();
};

#endif
