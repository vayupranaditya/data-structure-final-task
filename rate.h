//rate uses double circular linked list with first and last

#ifndef RATING_H_INCLUDED
#define RATING_H_INCLUDED

#include <iostream>

#define CUSTOMER(Element) Element->customer
#define PRODUCT(Element) ELement->product

typedef struct RateElement* RatePointer;

using namespace std;

struct RateInfotype{
  int point;
};

struct RateElement{
  RateInfotype info;
  RatePointer next;
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
RatePointer DeleteAfterRate(RatePointer &precedent RateList &list);
void ViewAllRate(RateList list);
void ViewRateByCustomer(CustomerPointer customer, RateList list);
void ViewRateByProduct(ProductPointer product, RateList list);

#endif //RATING_H_INCLUDED