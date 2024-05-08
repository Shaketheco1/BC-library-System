#include"BookDate.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//缺省构造函数
BookDate::BookDate():TitleInfo()
{
	Book_count++;
	next = NULL;
}


//带参构造函数
BookDate::BookDate(char* ISBN, char* Title, char* Author, char* Pub, char* DateAdded, int Qty, double Wholesale, double Retail) :TitleInfo(ISBN, Title, Author, Pub, DateAdded, Qty, Wholesale, Retail)
{
	Book_count++;
	next = NULL;
}


//拷贝构造函数
BookDate::BookDate(const BookDate& book) :TitleInfo(book)
{

	Book_count++;
	next = NULL;
}


//析构函数
BookDate::~BookDate()
{
	//释放动态内存
	delete[]ISBN;
	delete[]Title;
	delete[]Author;
	delete[]Pub;
	delete[]DateAdded;
	Book_count--;
}


//设置书名
void BookDate::setTitle(char* Title)
{
    delete[] this->Title;
	//删除原来动态内存
	//再分配动态内存
	//可以节省空间
    this->Title = new char[strlen(Title) + 1];
    strcpy(this->Title, Title);
}


//设置ISBN号
void BookDate::setISBN(char* ISBN) {
    delete[] this->ISBN;
	//删除原来动态内存
	//再分配动态内存
	//可以节省空间
    this->ISBN = new char[strlen(ISBN) + 1];
	strcpy(this->ISBN, ISBN);

}


//设置作者
void BookDate::setAuthor(char* Author) {
	delete[]this->Author;
	//删除原来动态内存
	//再分配动态内存
	//可以节省空间
	this->Author = new char[strlen(Author) + 1];
	strcpy(this->Author, Author);

}


//设置出版商
void BookDate:: setPub(char* Pub)
{
	
	delete[]this->Pub;
	//删除原来动态内存
	//再分配动态内存
	//可以节省空间
	this->Pub = new char[strlen(Pub) + 1];
	strcpy(this->Pub, Pub);

}


//进书日期
void BookDate::setDateAdded(char* DateAdded)
{
	delete[]this->DateAdded;
	//删除原来动态内存
	//再分配动态内存
	//可以节省空间
	this->DateAdded = new char[strlen(DateAdded) + 1];
	strcpy(this->DateAdded, DateAdded);
}


//设置库存量
void BookDate::setQty(int Qty)
{
	this->Qty = Qty;

}


//设置批发价
void BookDate::setWholesale(double Wholesale)
{

	this->Wholesale = Wholesale;
}


//设置零售价
void BookDate::setRetail(double Retail)
{
	this->Retail = Retail;
}


//判断对象是否为空
bool BookDate::isEmpty()
{
	if (this== NULL)
	{
		return true;
	}
	else return false;
}


//打印书籍信息；
void BookDate::BookInfo()
{
	TitleInfo::print();
	cout << endl;
}


//外部函数作 友元函数::查找书
int  FindBook(char* str, BookDate* book)
{
	BookDate* temp ;
	temp = book;
	int count = 0;
	while (temp != NULL){
		//用strncmp实现模糊查找
		if (strncmp(temp->Title, str,strlen(str)) == 0)
		{
			count++;
			temp->BookInfo();
			cout << endl;
		}

		if (strncmp(temp->Pub, str, strlen(str)) == 0)
		{
			count++;
			temp->BookInfo();
			cout << endl;
		}

		if (strncmp(temp->Author, str, strlen(str)) == 0)
		{
			count++;
			temp->BookInfo();
			cout << endl;
		}

		temp = temp->next;

	}

	//分析找到书籍情况
	if (count == 0)
	{
		cout << "没有找到相关书籍"<<endl;
		return 0;
	}
	else if (count == 1)
	{
		cout << "找到书籍一本" << endl;
		return 1;
	}
	else
	{
		cout << "找到书籍多本" << endl;
		return 2;
	}
}


//外部函数作 友元函数:添加书
BookDate* AddBook(BookDate *book)
{
	BookDate* temp = book;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new BookDate;
	temp = temp->next;

	cout << "请输入书籍的ISBN号：";
	char ISBN[50];
	cin >> ISBN;
	temp->setISBN(ISBN);

	cout << "请输入书籍的书名：";
	char Title[50];
	cin >> Title;
	temp->setTitle(Title);

	cout << "请输入书籍的作者：";
	char Author[50];
	cin >> Author;
	temp->setAuthor(Author);

	cout << "请输入书籍的出版社：";
	char Pub[50];
	cin >> Pub;
	temp->setPub(Pub);

	cout << "请输入书籍的入库日期：";
	char DateAdded[50];
	cin >> DateAdded;
	temp->setDateAdded(DateAdded);

	cout << "请输入书籍的数量：";
	int Qty;
	cin >> Qty;
	temp->setQty(Qty);

	cout << "请输入书籍的批发价：";
	double Wholesale;
	cin >> Wholesale;
	temp->setWholesale(Wholesale);

	cout << "请输入书籍的零售价：";
	double Retail;
	cin >> Retail;
	temp->setRetail(Retail);

	return book;
}


//外部函数作 友元函数:修改书
void EditBook(BookDate* book)
{
	cout << "请输入要修改的书的书名：";
	char str[50];
	cin >> str;
	BookDate* temp = book;
	int sk = 0;

	//模糊搜索查找书籍并记录找到书籍种类
	while (temp != NULL)
	{
		if (strncmp(temp->Title, str, strlen(str)) == 0)
		{
			temp->BookInfo();
			sk++;
		}
		if (temp->next == NULL) {
			break;
		}
		temp = temp->next;
	}

	//根据书籍种类做出分析并执行不同操作
	if (sk == 0) {
		cout << "没有找到相关书籍" << endl;
		exit(0);
	}

	else if (sk == 1) {
		cout << "请问这是你要修改的书籍吗？(y/n):";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y');
		else {
			cout << "请再次输入要修改的书的书名：";
			char str1[50];
			cin >> str1;
			temp = book;
			while (temp != NULL) {
				if (strncmp(temp->ISBN, str1, strlen(str1) + 1) == 0)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL) {
				cout << "没有找到相关书籍" << endl;
				exit(0);
			}
		}
	}

	else {
		cout << "请确定要修改的书的全名：";
		char str1[50];
		cin >> str1;
		temp = book;
		while (temp != NULL)
		{
			if (strncmp(temp->Title, str1, strlen(str1) + 1) == 0)
			{
				break;
			}
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "没有找到相关书籍" << endl;	
			exit(0);
		}
	}
	//

	int choice;
	char ch;
	do {
		cout << "请输入要修改的信息："<<endl;
		cout << "1.书名" << endl;
		cout << "2.ISBN号" << endl;
		cout << "3.作者" << endl;
		cout << "4.出版社" << endl;
		cout << "5.入库日期" << endl;
		cout << "6.数量" << endl;
		cout << "7.批发价" << endl;
		cout << "8.零售价" << endl;
		cout << "9.退出" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "请输入新的书名：";
			char Title[50];
			cin >> Title;
			temp->setTitle(Title);
			break;
		case 2:
			cout << "请输入新的ISBN号：";
			char ISBN[50];
			cin >> ISBN;
			temp->setISBN(ISBN);
			break;
		case 3:
			cout << "请输入新的作者：";
			char Author[50];
			cin >> Author;
			temp->setAuthor(Author);
			break;
		case 4:
			cout << "请输入新的出版社：";
			char Pub[50];
			cin >> Pub;
			temp->setPub(Pub);
			break;
		case 5:
			cout << "请输入新的入库日期：";
			char DateAdded[50];
			cin >> DateAdded;
			temp->setDateAdded(DateAdded);
			break;
		case 6:
			cout << "请输入新的数量：";
			int Qty;
			cin >> Qty;
			temp->setQty(Qty);
			break;
		case 7:
			cout << "请输入新的批发价：";
			double Wholesale;
			cin >> Wholesale;
			temp->setWholesale(Wholesale);
			break;
		case 8:
			cout << "请输入新的零售价：";
			double Retail;
			cin >> Retail;
			temp->setRetail(Retail);
			break;
		case 9:
			exit(0);
		}
		cout << "是否继续修改？(y/n):";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return;
}


//外部函数作 友元函数 :删除书
void DeleteBook(BookDate* book)
{
	cout << "请输入要删除的书的ISBN号：";
	char ISBN[50];
	cin >> ISBN;
	BookDate* temp = book;
	BookDate* p = book;
	while (temp!=NULL)
	{
		if (strcmp(temp->ISBN,ISBN)==0)
		{
			temp->BookInfo();
			cout << "是否删除该书籍？(y/n):";
			char ch;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				p->next = temp->next;
				cout << "删除成功" << endl;
			}
			else 
			{
				cout << "取消删除" << endl;
			}
			break;
		}
		p = temp;
		temp = temp->next;
	}
	
}


//链表初始化
BookDate* BookDate::Initialize_List()
{
	BookDate* temp = this;
	BookDate* head = this;
	temp->next = NULL;
	return head;
}


//友元函数 
//书库列表
void ListBook(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		temp->BookInfo();
		temp = temp->next;
	}
}


//友元函数
//批发价列表
void ListWholesale(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		cout << "书名：" << temp->Title << "	 ";
		cout << "批发价：" << temp->Wholesale << "		";
		cout << "库存量：" << temp->Qty << "		";
		cout << "总批发价：" << temp->Wholesale * temp->Qty << endl;
		temp = temp->next;
	}
}


//友元函数
//零售价列表
void ListRetail(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		cout << "书名：" << temp->Title << "	 ";
		cout << "零售价：" << temp->Retail << "		";
		cout << "库存量：" << temp->Qty << "		";
		cout << "总零售价：" << temp->Retail * temp->Qty << endl;
		temp = temp->next;
	}
}	


//友元函数
//按书的数量列表
//通过链表的冒泡排序实现
void ListQty(BookDate* book)
{
	if (book == NULL || book->next == NULL) {
		return; 
	}

	BookDate* end = NULL; // 结束标记，已排序的部分
	bool swapped; // 标记是否发生了交换

	do {
		swapped = false;
		BookDate* current = book;
		BookDate* next = current->next;
		BookDate* prev = NULL;

		while (next != end) {
			if (current->Qty > next->Qty) {
				swapped = true;
				if (prev != NULL) {
					prev->next = next;
				}
				else { 
					book = next;
				}
				current->next = next->next;
				next->next = current;

				
				prev = next;
				next = current->next;
			}
			else { 
				prev = current;
				current = next;
				next = next->next;
			}
		}
		end = current; 
	} while (swapped); 
	while (book != NULL)
	{
		book->BookInfo();
		book = book->next;
	}

}


//友元函数
//按书的价值额列表
//通过链表的冒泡排序实现
void ListTotalWholesale(BookDate* book)
{
	if (book == NULL || book->next == NULL) {
		return; 
	}

	BookDate* end = NULL;
	bool swapped; 

	do {
		swapped = false;
		BookDate* current = book;
		BookDate* next = current->next;
		BookDate* prev = NULL;

		while (next != end) {
			if (current->Wholesale>next->Wholesale) { 
				swapped = true;
				if (prev != NULL) {
					prev->next = next;
				}
				else {
					book = next;
				}
				current->next = next->next;
				next->next = current;

				
				prev = next;
				next = current->next;
			}
			else { 
				prev = current;
				current = next;
				next = next->next;
			}
		}
		end = current;
	} while (swapped); 
	while (book != NULL)
	{
		book->BookInfo();
		book = book->next;
	}
}


//友元函数
//按书的进书日期列表
//通过链表的冒泡排序实现
void ListDateAdded(BookDate* book)
{
	if (book == NULL || book->next == NULL) {
		return;
	}
	//空指针不需要排序

	BookDate* end = NULL; //用来标记已排序部分
	bool swapped;

	do {
		swapped = false;
		BookDate* current = book;
		BookDate* next = current->next;
		BookDate* prev = NULL;

		while (next != end) {
			if (strcmp(current->DateAdded,next->DateAdded)>0) {
				swapped = true;
				if (prev != NULL) {
					prev->next = next;
				}
				else {
					book = next;
				}
				current->next = next->next;
				next->next = current;


				prev = next;
				next = current->next;
			}
			else {
				prev = current;
				current = next;
				next = next->next;
			}
		}
		end = current;
	} while (swapped);
	while (book != NULL)
	{
		book->BookInfo();
		book = book->next;
	}
}


//重载流操作符
ofstream& operator<<(ofstream& os, BookDate* book)
{
	BookDate* temp = book;
	while (temp->next != NULL)
	{
		os << temp->getISBN() <<" ";
		os << temp->getTitle() << " ";
		os << temp->getAuthor() << " ";
		os << temp->getPublisher() << " ";
		os << temp->getEntryDate() << " ";
		os << temp->getNumber() <<" ";
		os << temp->getWholesale() << " ";
		os << temp->getRetail() << " ";
		temp = temp->next;
	}
	return os;
}


ifstream& operator>>(ifstream& is, BookDate* book)
{
	ifstream file;
	file.open("book.txt", ios::in );
	if (!file)
	{
		cout << "文件打开失败" << endl;
		exit(0);
	}
	char *ISBN;
	ISBN = new char[50];
	char *Title;
	Title = new char[50];
	char *Author;
	Author = new char[50];
	char *Pub;
	Pub = new char[50];
	char *DateAdded;
	DateAdded = new char[50];
	int Qty;
	double Wholesale;
	double Retail;
	if (file.eof())
	{
		return is;
	}
	file >> ISBN;
	file >> Title;
	file >> Author;
	file >> Pub;
	file >> DateAdded;
	file >> Qty;
	file >> Wholesale;
	file >> Retail;
	book->setISBN(ISBN);
	book->setTitle(Title);
	book->setAuthor(Author);
	book->setPub(Pub);
	book->setDateAdded(DateAdded);
	book->setQty(Qty);
	book->setWholesale(Wholesale);
	book->setRetail(Retail);
	delete []ISBN;
	delete []Title;
	delete []Author;
	delete []Pub;
	delete []DateAdded;
	file.close();
	return is;
}

