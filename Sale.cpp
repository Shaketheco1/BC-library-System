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
    cout << "           ǰ̨���۰���" << endl;
    telltime();
    cout << "����" << "	ISBN��" << "	����" << "	����" << "	���" << endl;
    while (p[i].num != 0) {
        cout << " " << p[i].num<< "		" << p[i].ISBN << "			" << p[i].Title<< "		" << p[i].Retail << "	" << p[i].num * p[i].Retail << endl;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "�ܼƣ�" << total << endl;
    cout << "˰��" << tax << endl;
    cout << "Ӧ����" << total + tax << endl;
    
}

void Sale::AddSale(BookDate *book,s *p)
{
    int i = 0;
    char choice;
    do {
        cout << "������ISBN�ţ�";
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
        cout << "������������";
        int num;
        cin >> num;
        total += num * temp->getRetail();
        tax = total * 0.06;
        p[i].num=num;
        cout << "�Ƿ��������" << endl;
        cin >> choice;
        i++;
    } while (choice == 'Y' || choice == 'y');

}
