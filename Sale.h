#ifndef SALE_H
#define SALE_H
#include "BookDate.h"
struct s;
class Sale :public BookDate
{
protected:
    double total;
    double tax;

public:
    Sale()
    {
        total = 0;
        tax = 0;
    }
    void ShowSale(BookDate* book);
    void AddSale(BookDate* book,s *p);
};

#endif