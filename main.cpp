#include<iostream>
#include<cstring>
#include<iomanip>
#include<ctime>
#include<fstream>


#include"TitleInfo.h"
#include"BookDate.h"

using namespace std;

//存储购书记录；
struct s {
    char* ISBN;
    int num;
    char* Title;
    double Retail;
};


//函数声明；
//存储在file.cpp中

void Mainmenu(BookDate* book);
void telltime();
void Cashiermodule(BookDate* book);
void librarymanagement(BookDate* book);
BookDate* read_file();
void Report_List(BookDate* book);
void AddSale(BookDate* book, s* p);
void save_file(BookDate* book);
void ShowSale(BookDate* book);

int  BookDate::Book_count = 0;   //初始化静态成员

int main()
{
    BookDate* book;
    book = read_file();//初始化链表

    Mainmenu(book);                               //进入主菜单
    return 0;
}
