#include<iostream>
#include<cstring>
#include<iomanip>
#include<ctime>
#include<fstream>


#include"TitleInfo.h"
#include"BookDate.h"

using namespace std;

//�洢�����¼��
struct s {
    char* ISBN;
    int num;
    char* Title;
    double Retail;
};


//����������
//�洢��file.cpp��

void Mainmenu(BookDate* book);
void telltime();
void Cashiermodule(BookDate* book);
void librarymanagement(BookDate* book);
BookDate* read_file();
void Report_List(BookDate* book);
void AddSale(BookDate* book, s* p);
void save_file(BookDate* book);
void ShowSale(BookDate* book);

int  BookDate::Book_count = 0;   //��ʼ����̬��Ա

int main()
{
    BookDate* book;
    book = read_file();//��ʼ������

    Mainmenu(book);                               //�������˵�
    return 0;
}
