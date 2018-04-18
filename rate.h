//rate uses double circular linked list with first and last

#ifndef RATING_H_INCLUDED
#define RATING_H_INCLUDED

#include <iostream>
#include "app.h"

#define CUSTOMER(Element) Element->customer
#define PRODUCT(Element) ELement->product

typedef struct RateElement* RatePointer;

using namespace std;

struct RateInfotype{
  int point;
};

struct RateElement{
  RateInfotype info;
  RatePointer next,prev;
  CustomerPointer customer;
  ProductPointer product;
};

struct RateList{
  RatePointer first,last;
};

RatePointer CreateNewRate(int point);
void CreateRateList(RateList &list);
void InsertRate(RatePointer &rate, RateList &list);   //insert first
RatePointer DeleteFirstRate(RateList &list);
RatePointer DeleteLastRate(RateList &list);
RatePointer DeleteAfterRate(RatePointer &precedent, RateList &list);
void DeletePointer(RatePointer &rate, RateList &list);    //automatically call delete first/after/last
RatePointer FindRateByCustomer(CustomerPointer customer, RateList list);
RatePointer FindRateByProduct(ProductPointer product, RateList list);
//RatePointer FindRate()
void ViewAllRate(RateList list);
void ViewRateByCustomer(CustomerPointer customer, RateList list);
void ViewRateByProduct(ProductPointer product, RateList list);

#endif //RATING_H_INCLUDED