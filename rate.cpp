#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

using namespace std;

RatePointer CreateNewRate(int point){
  RatePointer rate=new RateElement;
  INFO(rate)=point;
  NEXT(rate)=NULL;
  CUSTOMER(rate)=NULL;
  PRODUCT(rate)=NULL;
  return rate;
}

void CreateRateList(RateList &list){
  FIRST(list)=NULL;
  LAST(list)=NULL;
}

void InsertRate(RatePointer &rate, RateList &list){
  if(rate!=NULL){
    if(FIRST(list)==NULL){
      FIRST(list)=rate;
      LAST(list)=rate;
      NEXT(LAST(list))=FIRST(list);
      PREV(FIRST(list))=LAST(list);
    }else{
      NEXT(LAST(list))=rate;
      PREV(rate)=LAST(list);
      NEXT(rate)=FIRST(list);
      PREV(FIRST(list))=rate;
      LAST(list)=rate;
    }
  }
}
/*
RatePointer DeleteFirstRate(RateList &list){
  if(FIRST(list)!=NULL){
    RatePointer p=FIRST(list);
    if(NEXT(p)!=FIRST(list)){
      FIRST(list)=NEXT(p);
      NEXT(p)=NULL;
    }else{
      FIRST(list)=NULL;
    }
    return p;
  }else{
    return NULL;
  }
}

/*
 *INGET BOY
 *INI PUNYA FIRST AMA LAST
 

RatePointer DeleteLastRate(RateList &list){
  if(FIRST(list)!=NULL){
    if(FIRST(list)!=LAST(list)){
      //deletefirst
    }
  }
}

RatePointer DeleteAfterRate(RatePointer &precedent, RateList &list){
  if(precedent!=NULL){
    RatePointer p=NEXT(precedent);
    NEXT(precedent)=
  }
}
void DeletePointer(RatePointer &rate, RateList &list);    //automatically call delete first/after/last
void ViewRateByCustomer(CustomerPointer customer, RateList list);
void ViewRateByProduct(ProductPointer product, RateList list);
*/
void ViewAllRate(RateList list);