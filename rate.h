//rate uses double circular linked list with first and last

#ifndef RATING_H_INCLUDED
#define RATING_H_INCLUDED

#include <iostream>
#include "app.h"

#define CUSTOMER(Element) Element->customer
#define PRODUCT(Element) Element->product

typedef struct RateElement* RatePointer;

using namespace std;

struct RateInfotype{
  int point;
};

struct RateElement{
  RateInfotype info;
  RatePointer next,previous;
  CustomerPointer customer;
  ProductPointer product;
};

struct RateList{
  RatePointer first,last;
};

RatePointer CreateNewRate(int point, CustomerPointer customer, ProductPointer product);
void CreateRateList(RateList &list);
void InsertRate(RatePointer &rate, RateList &list);   //insert first
RatePointer DeleteFirstRate(RateList &list);
RatePointer DeleteLastRate(RateList &list);
RatePointer DeleteAfterRate(RatePointer &precedent, RateList &list);
void DeleteRate(RatePointer &rate, RateList &list);    //automatically call delete first/after/last
RatePointer FindRate(CustomerPointer customer, ProductPointer product, RateList list);
void ViewAllRate(RateList list);
void ViewRateByCustomer(CustomerPointer customer, RateList list);
void ViewRateByProduct(ProductPointer product, RateList list);

//testing
void CountRate(RateList list);

#endif //RATING_H_INCLUDED
