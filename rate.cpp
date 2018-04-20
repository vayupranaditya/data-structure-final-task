#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

using namespace std;

RatePointer CreateNewRate(int point, CustomerPointer customer, ProductPointer product){
  RatePointer rate=new RateElement;
  INFO(rate).point=point;
  NEXT(rate)=NULL;
  CUSTOMER(rate)=customer;
  PRODUCT(rate)=product;
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
      PREVIOUS(FIRST(list))=LAST(list);
    }else{
      NEXT(rate)=FIRST(list);
      PREVIOUS(rate)=LAST(list);
      PREVIOUS(NEXT(rate))=rate;
      NEXT(PREVIOUS(rate))=rate;
      FIRST(list)=rate;
    }
  }
}

RatePointer DeleteFirstRate(RateList &list){
  if(FIRST(list)!=NULL){
    RatePointer p=FIRST(list);
    if(FIRST(list)==LAST(list)){
      FIRST(list)=NULL;
      LAST(list)=NULL;
    }else{
      FIRST(list)=NEXT(FIRST(list));
      PREVIOUS(FIRST(list))=LAST(list);
      NEXT(LAST(list))=FIRST(list);
    }
    NEXT(p)=NULL;
    PREVIOUS(p)=NULL;
    return p;
  }else{
    return NULL;
  }
}

RatePointer DeleteLastRate(RateList &list){
  if(FIRST(list)!=NULL){
    if(FIRST(list)==LAST(list)){
      return DeleteFirstRate(list);
    }else{
      RatePointer p=LAST(list);
      LAST(list)=PREVIOUS(LAST(list));
      NEXT(LAST(list))=FIRST(list);
      PREVIOUS(FIRST(list))=LAST(list);
      NEXT(p)=NULL;
      PREVIOUS(p)=NULL;
      return p;
    }
  }else{
    return NULL;
  }
}

RatePointer DeleteAfterRate(RatePointer &precedent, RateList &list){
  if(precedent!=NULL){
    RatePointer p=NEXT(precedent);
    NEXT(precedent)=NEXT(p);
    PREVIOUS(NEXT(precedent))=precedent;
    NEXT(p)=NULL;
    PREVIOUS(p)=NULL;
    return p;
  }else{
    return NULL;
  }
}

void DeletePointer(RatePointer &rate, RateList &list){
  if(rate!=NULL){
    if(rate==FIRST(list)){
      rate=DeleteFirstRate(list);
    }else if(rate==LAST(list)){
      rate=DeleteLastRate(list);
    }else{
      rate=DeleteAfterRate(PREVIOUS(rate),list);
    }
  }
}

void ViewRateByCustomer(CustomerPointer customer, RateList list){
  if(FIRST(list)==NULL){
    cout<<"End of search.";
  }else{
    RatePointer p=FIRST(list);
    while(p!=LAST(list)){
      if(CUSTOMER(rate)==customer){
        cout<<INFO(PRODUCT(p)).product_name<<": ";
        cout<<INFO(p).point<<endl;
        p = NEXT(p);
      }
    }
    cout<<INFO(PRODUCT(p)).product_name<<": ";
    cout<<INFO(p).point;
  }
  cout<<endl;
}

void ViewRateByProduct(ProductPointer product, RateList list){
  if(FIRST(list)==NULL){
    cout<<"End of search.";
  }else{
    RatePointer p=FIRST(list);
    while(p!=LAST(list)){
      if(product(rate)==product){
        cout<<INFO(PRODUCT(p)).product_name<<": ";
        cout<<INFO(p).point<<endl;
        p = NEXT(p);
      }
    }
    cout<<INFO(CUSTOMER(p)).customer_name<<": ";
    cout<<INFO(p).point;
  }
  cout<<endl;
}

void ViewAllRate(RateList list){
  RatePointer p = FIRST(list);
  if (FIRST(list) == NULL){
    cout<<"No one rates at this time.";
  }else{
    while(p!=LAST(list)){
      cout<<INFO(PRODUCT(p)).product_name<<": ";
      cout<<INFO(p).point<<" by ";
      cout<<INFO(CUSTOMER(p)).customer_id<<"-";
      cout<<INFO(CUSTOMER(p)).customer_name<<endl;
      p = NEXT(p);
    }
    cout<<INFO(PRODUCT(p)).product_name<<": ";
    cout<<INFO(p).point<<" by ";
    cout<<INFO(CUSTOMER(p)).customer_id<<"-";
    cout<<INFO(CUSTOMER(p)).customer_name;
  }
  cout<<endl;
}
