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

//���������ļ�
void creatTestfile()
{
    fstream outfile;
    outfile.open("book.txt", ios::out|ios::app );
    if (!outfile)
    {
        cout << "�ļ���ʧ��" << endl;
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

    //�ر��ļ�
    outfile.close();
}


//���ۺ���
void ShowSale(BookDate* book)
{
    double total = 0;
    double tax = 0;
    s p[100] = {};
    //���������ݴ��ڽṹ���У�

    AddSale(book, p);

    int i = 0;
    cout << "           ǰ̨���۰���" << endl;
    telltime();
    cout << "����"
        << setw(20) << "ISBN��" 
        << setw(31) << "����"
        << setw(33) << "����" 
        << setw(15) << "���" 
        << endl;
    //�޶���������룻

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
    cout << "�ܼƣ�" << total << endl;
    cout << "˰��" << tax << endl;
    cout << "Ӧ����" << total + tax << endl;
    cout << endl;
}

//��ӹ���
void AddSale(BookDate* book, s* p)
{
    int i = 0;
    char choice;

    do {
        cout << "������ISBN�ţ�";
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
            cout << "û���ҵ�����" << endl;
            continue;
        }

        p[i].ISBN = new char[strlen(temp->getISBN()) + 1];
        strcpy(p[i].ISBN, temp->getISBN());
        p[i].Title = new char[strlen(temp->getTitle()) + 1];
        strcpy(p[i].Title, temp->getTitle());
        p[i].Retail = temp->getRetail();
        cout << "������������";
        int num;
        cin >> num;
        p[i].num = num;

        cout << "�Ƿ��������" << endl;
        cin >> choice;
        i++;
    } while (choice == 'Y' || choice == 'y');

}



//���˵�
void Mainmenu(BookDate* book)
{
    cout << "          xxxͼ�����ϵͳ" << endl;
    cout << "                     ���˵�" << endl;
    cout << "1.����ģ��" << endl;
    cout << "2.������ģ��" << endl;
    cout << "3.����ģ��" << endl;
    cout << "4.�˳�ϵͳ" << endl;
    cout << "   ����ѡ��1~4����";

    int choice;

    while (true) {
        cin >> choice; // �޸�����Ҫ��ȡ�û���ѡ��
        switch (choice)
        {
        case 1:
            Cashiermodule(book);
            break;
            //����ģ�飻
        case 2:
            librarymanagement(book);
            break;
            //������ģ�飻            
        case 3:
            Report_List(book);
            break;
            //����ģ�飻
        case 4:
            exit(0);
            //exit(0);
        }
    }
}


//����ϵͳ�˵�
void Cashiermodule(BookDate* book)
{
    //չʾ���ﵥ
    ShowSale(book);
    //�������˵�
    exit(0);
    //Mainmenu(book);
}


//������ϵͳ�˵�
void librarymanagement(BookDate* book)
{
    cout << "          xxxͼ�����ϵͳ" << endl;
    cout << "                     ���˵�" << endl;
    cout << "1.����ĳ�������Ϣ" << endl;
    cout << "2.������" << endl;
    cout << "3.�޸������Ϣ" << endl;
    cout << "4.ɾ����" << endl;
    cout << "5.�������˵�" << endl;
    cout << "   ����ѡ��1~5����";

    int choice2 = 0;
    cin >> choice2;
    while (true) {
        switch (choice2) {

        case 1:
            char* str;
            str = new char[50];
            cout << "��������Ҫ���ҵ��������Ϣ��";
            cin >> str;
            char ch;

            do {
                FindBook(str, book);//����ĳ�������Ϣ
                cout << "�Ƿ�������ң�(y/n)��";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');

            librarymanagement(book);//���ز˵���ֹ��ѭ��
            break;


        case 2:
            AddBook(book);
            save_file(book);
            //���޸Ĵ����ļ���
            librarymanagement(book);
            break;
            //������

        case 3:
            EditBook(book);
            save_file(book);                            //���޸Ĵ����ļ���
            librarymanagement(book);
            break;
            //�޸������Ϣ��

        case 4:
            DeleteBook(book);                           //ɾ���飻

            save_file(book);                                         //���޸Ĵ����ļ���
            librarymanagement(book);
            break;

        case 5:
            Mainmenu(book);
            break;
            //return  Mainmenu��
        }
    }
}


//ʱ�亯��
void telltime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    cout << "���ڣ�" << (now->tm_year + 1900) << "��"
        << (now->tm_mon + 1) << "��"
        << now->tm_mday << "��" << endl;
}

//���ļ��ж�ȡ���ݵ�����������
//��ʼ��һ����������
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
        //�����ļ��Ƿ�ĩβ��
        //��ֹ������������Ԫ�أ�
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

        //�ͷŶ�̬�ڴ�
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
    cout << "          xxxͼ�����ϵͳ" << endl;
    cout << "                     ���˵�" << endl;
    cout << "1.����б�" << endl;
    cout << "2.�������б�" << endl;
    cout << "3.���ۼ��б�" << endl;
    cout << "4.��������б�" << endl;
    cout << "5.��ļ�ֵ���б�" << endl;
    cout << "6.���������б�" << endl;
    cout << "7.�������˵�" << endl;
    cout << "   ����ѡ��1~7����";
    while (true) {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ListBook(book);
            break;                                  //����б�
        case 2:
            ListWholesale(book);
            break;                                      //�������б�
        case 3:
            ListRetail(book);
            break;                                  //���ۼ��б�
        case 4:
            ListQty(book);
            break;                              //��������б�
        case 5:
            ListTotalWholesale(book);
            break;                                      //��ļ�ֵ���б�
        case 6:
            ListDateAdded(book);
            break;                                  //���������б�
        case 7:
            Mainmenu(book);                     //���˵�
        }
    }
}

               



//��������������ļ���
//�����ļ�
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

