#include<iostream>
#include"Sale.h"
using namespace std;
void telltime();
struct s{
    char *ISBN;
    int num;
    char* Title;
    double Retail;
};
void Sale::ShowSale(BookDate *book)
{
  
    s p[100] = {};
    AddSale(book,p);
    int i = 0;
    cout << "           前台销售版面" << endl;
    telltime();
    cout << "数量" << "	ISBN号" << "	书名" << "	单价" << "	金额" << endl;
    while (p[i].num != 0) {
        cout << " " << p[i].num<< "		" << p[i].ISBN << "			" << p[i].Title<< "		" << p[i].Retail << "	" << p[i].num * p[i].Retail << endl;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "总计：" << total << endl;
    cout << "税：" << tax << endl;
    cout << "应付金额：" << total + tax << endl;
    
}

void Sale::AddSale(BookDate *book,s *p)
{
    int i = 0;
    char choice;
    do {
        cout << "请输入ISBN号：";
        char ISBN[50];
        cin >> ISBN;
        BookDate* temp = book;
        while (strcmp(temp->getISBN(), ISBN) != 0)
        {
            temp = temp->next;
        }
        p[i].ISBN=new char[strlen(temp->getISBN())+1];
		p[i].Title = new char[strlen(temp->getTitle()) + 1];
        p[i].Retail = temp->getRetail();
        cout << "请输入数量：";
        int num;
        cin >> num;
        total += num * temp->getRetail();
        tax = total * 0.06;
        p[i].num=num;
        cout << "是否继续购买？" << endl;
        cin >> choice;
        i++;
    } while (choice == 'Y' || choice == 'y');

}
