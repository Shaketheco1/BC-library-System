#include<iostream>
#include<cstring>
#include<iomanip>
#include<ctime>
#include<fstream>
#include"TitleInfo.h"
#include"BookDate.h"

using namespace std;

struct s {
    char* ISBN;
    int num;
    char* Title;
    double Retail;
};

void Mainmenu(BookDate* book);
void telltime();
void Cashiermodule(BookDate* book);
void librarymanagement(BookDate* book);
BookDate* read_file();
void Report_List(BookDate* book);
void AddSale(BookDate* book, s* p);
void save_file(BookDate* book);
void ShowSale(BookDate* book);

//创建测试文件
void creatTestfile()
{
    fstream outfile;
    outfile.open("book.txt", ios::out|ios::app );
    if (!outfile)
    {
        cout << "文件打开失败" << endl;
        exit(0);
    }
    BookDate* book;
    book = new BookDate;
    book->setISBN("123456");
    book->setTitle("C++");
    book->setAuthor("Tom");
    book->setPub("Tsinghua");
    book->setDateAdded("2020-12-12");
    book->setQty(10);
    book->setWholesale(10.0);
    book->setRetail(20.0);
    outfile << book->getISBN() 
        << " " << book->getTitle() 
        << " " << book->getAuthor() 
        << " " << book->getPublisher() 
        << " " << book->getEntryDate()
        << " " << book->getNumber()
        << " " << book->getWholesale() 
        << " " << book->getRetail() 
        << endl;
    BookDate* book1;
    book1 = new BookDate;
    book1->setISBN("234567");
    book1->setTitle("Java");
    book1->setAuthor("Alice");
    book1->setPub("Oxford");
    book1->setDateAdded("2021-01-01");
    book1->setQty(5);
    book1->setWholesale(15.0);
    book1->setRetail(25.0);
    outfile << book1->getISBN()
        << " " << book1->getTitle() 
        << " " << book1->getAuthor()
        << " " << book1->getPublisher() 
        << " "  << book1->getEntryDate() 
        << " " << book1->getNumber()
        << " " << book1->getWholesale() 
        << " " << book1->getRetail()
        << endl;

    BookDate* book2;
    book2 = new BookDate;
    book2->setISBN("345678");
    book2->setTitle("Python");
    book2->setAuthor("Bob");
    book2->setPub("MIT");
    book2->setDateAdded("2021-02-02");
    book2->setQty(8);
    book2->setWholesale(12.0);
    book2->setRetail(22.0);
    outfile << book2->getISBN() 
        << " " << book2->getTitle() 
        << " " << book2->getAuthor() 
        << " " << book2->getPublisher() 
        << " " << book2->getEntryDate() 
        << " " << book2->getNumber()
        << " " << book2->getWholesale() 
        << " " << book2->getRetail() << endl;

    //关闭文件
    outfile.close();
}


//销售函数
void ShowSale(BookDate* book)
{
    double total = 0;
    double tax = 0;
    s p[100] = {};
    //将购物数据存在结构体中；

    AddSale(book, p);

    int i = 0;
    cout << "           前台销售版面" << endl;
    telltime();
    cout << "数量"
        << setw(20) << "ISBN号" 
        << setw(31) << "书名"
        << setw(33) << "单价" 
        << setw(15) << "金额" 
        << endl;
    //限定域宽保持整齐；

    while (p[i].num != 0) {
        cout << setw(3) << p[i].num 
            << setw(20) << p[i].ISBN 
            << setw(30) << p[i].Title 
            << setw(34) << p[i].Retail 
            << setw(15) << p[i].num * p[i].Retail
            << endl;

        total += p[i].num * p[i].Retail;
        i++;
    }

    tax = 0.06 * total;

    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "总计：" << total << endl;
    cout << "税：" << tax << endl;
    cout << "应付金额：" << total + tax << endl;
    cout << endl;
}

//添加购书
void AddSale(BookDate* book, s* p)
{
    int i = 0;
    char choice;

    do {
        cout << "请输入ISBN号：";
        char ISBN[50];
        cin >> ISBN;
        BookDate* temp;
        temp = book;

        while (strcmp(temp->getISBN(), ISBN) != 0)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "没有找到该书" << endl;
            continue;
        }

        p[i].ISBN = new char[strlen(temp->getISBN()) + 1];
        strcpy(p[i].ISBN, temp->getISBN());
        p[i].Title = new char[strlen(temp->getTitle()) + 1];
        strcpy(p[i].Title, temp->getTitle());
        p[i].Retail = temp->getRetail();
        cout << "请输入数量：";
        int num;
        cin >> num;
        p[i].num = num;

        cout << "是否继续购买？" << endl;
        cin >> choice;
        i++;
    } while (choice == 'Y' || choice == 'y');

}



//主菜单
void Mainmenu(BookDate* book)
{
    cout << "          xxx图书管理系统" << endl;
    cout << "                     主菜单" << endl;
    cout << "1.收银模块" << endl;
    cout << "2.书库管理模块" << endl;
    cout << "3.报表模块" << endl;
    cout << "4.退出系统" << endl;
    cout << "   输入选择（1~4）：";

    int choice;

    while (true) {
        cin >> choice; // 修复：需要读取用户的选择
        switch (choice)
        {
        case 1:
            Cashiermodule(book);
            break;
            //收银模块；
        case 2:
            librarymanagement(book);
            break;
            //书库管理模块；            
        case 3:
            Report_List(book);
            break;
            //报表模块；
        case 4:
            exit(0);
            //exit(0);
        }
    }
}


//收银系统菜单
void Cashiermodule(BookDate* book)
{
    //展示购物单
    ShowSale(book);
    //返回主菜单
    exit(0);
    //Mainmenu(book);
}


//书库管理系统菜单
void librarymanagement(BookDate* book)
{
    cout << "          xxx图书管理系统" << endl;
    cout << "                     主菜单" << endl;
    cout << "1.查找某本书的信息" << endl;
    cout << "2.增加书" << endl;
    cout << "3.修改书的信息" << endl;
    cout << "4.删除书" << endl;
    cout << "5.返回主菜单" << endl;
    cout << "   输入选择（1~5）：";

    int choice2 = 0;
    cin >> choice2;
    while (true) {
        switch (choice2) {

        case 1:
            char* str;
            str = new char[50];
            cout << "请输入你要查找的书相关信息：";
            cin >> str;
            char ch;

            do {
                FindBook(str, book);//查找某本书的信息
                cout << "是否继续查找？(y/n)：";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');

            librarymanagement(book);//返回菜单防止死循环
            break;


        case 2:
            AddBook(book);
            save_file(book);
            //将修改存入文件中
            librarymanagement(book);
            break;
            //增加书

        case 3:
            EditBook(book);
            save_file(book);                            //将修改存入文件中
            librarymanagement(book);
            break;
            //修改书的信息；

        case 4:
            DeleteBook(book);                           //删除书；

            save_file(book);                                         //将修改存入文件中
            librarymanagement(book);
            break;

        case 5:
            Mainmenu(book);
            break;
            //return  Mainmenu；
        }
    }
}


//时间函数
void telltime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    cout << "日期：" << (now->tm_year + 1900) << "年"
        << (now->tm_mon + 1) << "月"
        << now->tm_mday << "日" << endl;
}

//从文件中读取数据到对象链表中
//初始化一个对象链表；
BookDate* read_file()
{
    BookDate* head = NULL;
    BookDate* temp = NULL;
    ifstream infile;
    infile.open("book.txt", ios::in);
    while (!infile.eof()) {

        char* ISBN;
        ISBN = new char[50];
        char* Title;
        Title = new char[50];
        char* Author;
        Author = new char[50];
        char* Pub;
        Pub = new char[50];
        char* DateAdded;
        DateAdded = new char[50];
        int Qty;
        double Wholesale;
        double Retail;

        infile >> ISBN;
        //检验文件是否到末尾；
        //防止建立多余链表元素；
        if (infile.eof())
            break;
        infile >> Title;
        if (infile.eof())
            break;
        infile >> Author;
        if (infile.eof())
            break;
        infile >> Pub;
        if (infile.eof())
            break;
        infile >> DateAdded;
        if (infile.eof())
            break;
        infile >> Qty;
        if (infile.eof())
            break;
        infile >> Wholesale;
        if (infile.eof())
            break;
        infile >> Retail;
        if (infile.eof())
            break;

        BookDate* newbook = new BookDate;
        newbook->setISBN(ISBN);
        newbook->setTitle(Title);
        newbook->setAuthor(Author);
        newbook->setPub(Pub);
        newbook->setDateAdded(DateAdded);
        newbook->setQty(Qty);
        newbook->setWholesale(Wholesale);
        newbook->setRetail(Retail);

        if (head == NULL) {
            head = newbook;
            infile >> head;
            temp = head;
        }
        else {
            temp->next = newbook;
            temp = temp->next;
        }

        //释放动态内存
        delete[]ISBN;
        delete[]Title;
        delete[]Author;
        delete[]Pub;
        delete[]DateAdded;
    }
    infile.close();
    return head;
}


void Report_List(BookDate* book)
{
    cout << "          xxx图书管理系统" << endl;
    cout << "                     主菜单" << endl;
    cout << "1.书库列表" << endl;
    cout << "2.批发价列表" << endl;
    cout << "3.零售价列表" << endl;
    cout << "4.书的数量列表" << endl;
    cout << "5.书的价值额列表" << endl;
    cout << "6.进书日期列表" << endl;
    cout << "7.返回主菜单" << endl;
    cout << "   输入选择（1~7）：";
    while (true) {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ListBook(book);
            break;                                  //书库列表
        case 2:
            ListWholesale(book);
            break;                                      //批发价列表
        case 3:
            ListRetail(book);
            break;                                  //零售价列表
        case 4:
            ListQty(book);
            break;                              //书的数量列表
        case 5:
            ListTotalWholesale(book);
            break;                                      //书的价值额列表
        case 6:
            ListDateAdded(book);
            break;                                  //进书日期列表
        case 7:
            Mainmenu(book);                     //主菜单
        }
    }
}

               



//将对象链表存入文件中
//更新文件
void save_file(BookDate* book)
{
    ofstream outfile;
    outfile.open("book.txt", ios::out);
    BookDate* temp = book;

    while (temp != NULL)
    {
        outfile << temp->getISBN()
            << " " << temp->getTitle()
            << " " << temp->getAuthor()
            << " " << temp->getPublisher()
            << " " << temp->getEntryDate()
            << " " << temp->getNumber()
            << " " << temp->getWholesale()
            << " " << temp->getRetail() << endl;
        temp = temp->next;
    }

    outfile.close();
}

