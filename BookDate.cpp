#include"BookDate.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//ȱʡ���캯��
BookDate::BookDate():TitleInfo()
{
	Book_count++;
	next = NULL;
}


//���ι��캯��
BookDate::BookDate(char* ISBN, char* Title, char* Author, char* Pub, char* DateAdded, int Qty, double Wholesale, double Retail) :TitleInfo(ISBN, Title, Author, Pub, DateAdded, Qty, Wholesale, Retail)
{
	Book_count++;
	next = NULL;
}


//�������캯��
BookDate::BookDate(const BookDate& book) :TitleInfo(book)
{

	Book_count++;
	next = NULL;
}


//��������
BookDate::~BookDate()
{
	//�ͷŶ�̬�ڴ�
	delete[]ISBN;
	delete[]Title;
	delete[]Author;
	delete[]Pub;
	delete[]DateAdded;
	Book_count--;
}


//��������
void BookDate::setTitle(char* Title)
{
    delete[] this->Title;
	//ɾ��ԭ����̬�ڴ�
	//�ٷ��䶯̬�ڴ�
	//���Խ�ʡ�ռ�
    this->Title = new char[strlen(Title) + 1];
    strcpy(this->Title, Title);
}


//����ISBN��
void BookDate::setISBN(char* ISBN) {
    delete[] this->ISBN;
	//ɾ��ԭ����̬�ڴ�
	//�ٷ��䶯̬�ڴ�
	//���Խ�ʡ�ռ�
    this->ISBN = new char[strlen(ISBN) + 1];
	strcpy(this->ISBN, ISBN);

}


//��������
void BookDate::setAuthor(char* Author) {
	delete[]this->Author;
	//ɾ��ԭ����̬�ڴ�
	//�ٷ��䶯̬�ڴ�
	//���Խ�ʡ�ռ�
	this->Author = new char[strlen(Author) + 1];
	strcpy(this->Author, Author);

}


//���ó�����
void BookDate:: setPub(char* Pub)
{
	
	delete[]this->Pub;
	//ɾ��ԭ����̬�ڴ�
	//�ٷ��䶯̬�ڴ�
	//���Խ�ʡ�ռ�
	this->Pub = new char[strlen(Pub) + 1];
	strcpy(this->Pub, Pub);

}


//��������
void BookDate::setDateAdded(char* DateAdded)
{
	delete[]this->DateAdded;
	//ɾ��ԭ����̬�ڴ�
	//�ٷ��䶯̬�ڴ�
	//���Խ�ʡ�ռ�
	this->DateAdded = new char[strlen(DateAdded) + 1];
	strcpy(this->DateAdded, DateAdded);
}


//���ÿ����
void BookDate::setQty(int Qty)
{
	this->Qty = Qty;

}


//����������
void BookDate::setWholesale(double Wholesale)
{

	this->Wholesale = Wholesale;
}


//�������ۼ�
void BookDate::setRetail(double Retail)
{
	this->Retail = Retail;
}


//�ж϶����Ƿ�Ϊ��
bool BookDate::isEmpty()
{
	if (this== NULL)
	{
		return true;
	}
	else return false;
}


//��ӡ�鼮��Ϣ��
void BookDate::BookInfo()
{
	TitleInfo::print();
	cout << endl;
}


//�ⲿ������ ��Ԫ����::������
int  FindBook(char* str, BookDate* book)
{
	BookDate* temp ;
	temp = book;
	int count = 0;
	while (temp != NULL){
		//��strncmpʵ��ģ������
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

	//�����ҵ��鼮���
	if (count == 0)
	{
		cout << "û���ҵ�����鼮"<<endl;
		return 0;
	}
	else if (count == 1)
	{
		cout << "�ҵ��鼮һ��" << endl;
		return 1;
	}
	else
	{
		cout << "�ҵ��鼮�౾" << endl;
		return 2;
	}
}


//�ⲿ������ ��Ԫ����:�����
BookDate* AddBook(BookDate *book)
{
	BookDate* temp = book;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new BookDate;
	temp = temp->next;

	cout << "�������鼮��ISBN�ţ�";
	char ISBN[50];
	cin >> ISBN;
	temp->setISBN(ISBN);

	cout << "�������鼮��������";
	char Title[50];
	cin >> Title;
	temp->setTitle(Title);

	cout << "�������鼮�����ߣ�";
	char Author[50];
	cin >> Author;
	temp->setAuthor(Author);

	cout << "�������鼮�ĳ����磺";
	char Pub[50];
	cin >> Pub;
	temp->setPub(Pub);

	cout << "�������鼮��������ڣ�";
	char DateAdded[50];
	cin >> DateAdded;
	temp->setDateAdded(DateAdded);

	cout << "�������鼮��������";
	int Qty;
	cin >> Qty;
	temp->setQty(Qty);

	cout << "�������鼮�������ۣ�";
	double Wholesale;
	cin >> Wholesale;
	temp->setWholesale(Wholesale);

	cout << "�������鼮�����ۼۣ�";
	double Retail;
	cin >> Retail;
	temp->setRetail(Retail);

	return book;
}


//�ⲿ������ ��Ԫ����:�޸���
void EditBook(BookDate* book)
{
	cout << "������Ҫ�޸ĵ����������";
	char str[50];
	cin >> str;
	BookDate* temp = book;
	int sk = 0;

	//ģ�����������鼮����¼�ҵ��鼮����
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

	//�����鼮��������������ִ�в�ͬ����
	if (sk == 0) {
		cout << "û���ҵ�����鼮" << endl;
		exit(0);
	}

	else if (sk == 1) {
		cout << "����������Ҫ�޸ĵ��鼮��(y/n):";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y');
		else {
			cout << "���ٴ�����Ҫ�޸ĵ����������";
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
				cout << "û���ҵ�����鼮" << endl;
				exit(0);
			}
		}
	}

	else {
		cout << "��ȷ��Ҫ�޸ĵ����ȫ����";
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
			cout << "û���ҵ�����鼮" << endl;	
			exit(0);
		}
	}
	//

	int choice;
	char ch;
	do {
		cout << "������Ҫ�޸ĵ���Ϣ��"<<endl;
		cout << "1.����" << endl;
		cout << "2.ISBN��" << endl;
		cout << "3.����" << endl;
		cout << "4.������" << endl;
		cout << "5.�������" << endl;
		cout << "6.����" << endl;
		cout << "7.������" << endl;
		cout << "8.���ۼ�" << endl;
		cout << "9.�˳�" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "�������µ�������";
			char Title[50];
			cin >> Title;
			temp->setTitle(Title);
			break;
		case 2:
			cout << "�������µ�ISBN�ţ�";
			char ISBN[50];
			cin >> ISBN;
			temp->setISBN(ISBN);
			break;
		case 3:
			cout << "�������µ����ߣ�";
			char Author[50];
			cin >> Author;
			temp->setAuthor(Author);
			break;
		case 4:
			cout << "�������µĳ����磺";
			char Pub[50];
			cin >> Pub;
			temp->setPub(Pub);
			break;
		case 5:
			cout << "�������µ�������ڣ�";
			char DateAdded[50];
			cin >> DateAdded;
			temp->setDateAdded(DateAdded);
			break;
		case 6:
			cout << "�������µ�������";
			int Qty;
			cin >> Qty;
			temp->setQty(Qty);
			break;
		case 7:
			cout << "�������µ������ۣ�";
			double Wholesale;
			cin >> Wholesale;
			temp->setWholesale(Wholesale);
			break;
		case 8:
			cout << "�������µ����ۼۣ�";
			double Retail;
			cin >> Retail;
			temp->setRetail(Retail);
			break;
		case 9:
			exit(0);
		}
		cout << "�Ƿ�����޸ģ�(y/n):";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return;
}


//�ⲿ������ ��Ԫ���� :ɾ����
void DeleteBook(BookDate* book)
{
	cout << "������Ҫɾ�������ISBN�ţ�";
	char ISBN[50];
	cin >> ISBN;
	BookDate* temp = book;
	BookDate* p = book;
	while (temp!=NULL)
	{
		if (strcmp(temp->ISBN,ISBN)==0)
		{
			temp->BookInfo();
			cout << "�Ƿ�ɾ�����鼮��(y/n):";
			char ch;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				p->next = temp->next;
				cout << "ɾ���ɹ�" << endl;
			}
			else 
			{
				cout << "ȡ��ɾ��" << endl;
			}
			break;
		}
		p = temp;
		temp = temp->next;
	}
	
}


//�����ʼ��
BookDate* BookDate::Initialize_List()
{
	BookDate* temp = this;
	BookDate* head = this;
	temp->next = NULL;
	return head;
}


//��Ԫ���� 
//����б�
void ListBook(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		temp->BookInfo();
		temp = temp->next;
	}
}


//��Ԫ����
//�������б�
void ListWholesale(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		cout << "������" << temp->Title << "	 ";
		cout << "�����ۣ�" << temp->Wholesale << "		";
		cout << "�������" << temp->Qty << "		";
		cout << "�������ۣ�" << temp->Wholesale * temp->Qty << endl;
		temp = temp->next;
	}
}


//��Ԫ����
//���ۼ��б�
void ListRetail(BookDate* book)
{
	BookDate* temp = book;
	while (temp != NULL)
	{
		cout << "������" << temp->Title << "	 ";
		cout << "���ۼۣ�" << temp->Retail << "		";
		cout << "�������" << temp->Qty << "		";
		cout << "�����ۼۣ�" << temp->Retail * temp->Qty << endl;
		temp = temp->next;
	}
}	


//��Ԫ����
//����������б�
//ͨ�������ð������ʵ��
void ListQty(BookDate* book)
{
	if (book == NULL || book->next == NULL) {
		return; 
	}

	BookDate* end = NULL; // ������ǣ�������Ĳ���
	bool swapped; // ����Ƿ����˽���

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


//��Ԫ����
//����ļ�ֵ���б�
//ͨ�������ð������ʵ��
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


//��Ԫ����
//����Ľ��������б�
//ͨ�������ð������ʵ��
void ListDateAdded(BookDate* book)
{
	if (book == NULL || book->next == NULL) {
		return;
	}
	//��ָ�벻��Ҫ����

	BookDate* end = NULL; //������������򲿷�
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


//������������
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
		cout << "�ļ���ʧ��" << endl;
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

