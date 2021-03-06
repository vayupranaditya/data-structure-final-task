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
    RatePointer p=FindRate(CUSTOMER(rate),PRODUCT(rate),list);
    if(p==NULL){
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
      INFO(PRODUCT(rate)).point=INFO(PRODUCT(rate)).point+INFO(rate).point;
      INFO(PRODUCT(rate)).number++;
      INFO(PRODUCT(rate)).average_product=(float)INFO(PRODUCT(rate)).point/INFO(PRODUCT(rate)).number;
    }else{
      INFO(p)=INFO(rate);
      INFO(PRODUCT(rate)).point=INFO(PRODUCT(rate)).point+INFO(rate).point;
      INFO(PRODUCT(rate)).number++;
      INFO(PRODUCT(rate)).average_product=float(INFO(PRODUCT(rate)).point)/INFO(PRODUCT(rate)).number;
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

void DeleteRate(RatePointer &rate, RateList &list){
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

void DeleteRateByCustomer(CustomerPointer customer, RateList &rate_list){
  if((customer!=NULL) && (FIRST(rate_list)!=NULL)){
    RatePointer rate=FIRST(rate_list);
    while(NEXT(rate)!=FIRST(rate_list)){
      if(CUSTOMER(rate)==customer){
        DeleteRate(rate,rate_list);
      }
      rate=NEXT(rate);
    }
    if(CUSTOMER(rate)==customer){
      DeleteRate(rate,rate_list);
    }
  }
}

void DeleteRateByProduct(ProductPointer product, RateList &rate_list){
  if((product!=NULL) && (FIRST(rate_list)!=NULL)){
    RatePointer rate=FIRST(rate_list);
    while(NEXT(rate)!=FIRST(rate_list)){
      if(PRODUCT(rate)==product){
        DeleteRate(rate,rate_list);
      }
      rate=NEXT(rate);
    }
    if(PRODUCT(rate)==product){
      DeleteRate(rate,rate_list);
    }
  }
}

RatePointer FindRate(CustomerPointer customer, ProductPointer product, RateList list){
  RatePointer p=FIRST(list);
  if(p!=NULL){
    while((p!=LAST(list)) && ((CUSTOMER(p)!=customer) || (PRODUCT(p)!=product))){
      p=NEXT(p);
    }
    if((CUSTOMER(p)==customer) && (PRODUCT(p)==product)){
      return p;
    }else{
      return NULL;
    }
  }else{
    return NULL;
  }
}

void ViewAllRate(RateList list){
  RatePointer p = FIRST(list);
  if (p == NULL){
    cout<<"No one has rated at this time.\n";
  }else{
    while(p!=LAST(list)){
      cout<<INFO(PRODUCT(p)).product_name<<": ";
      cout<<INFO(p).point<<" by ";
      cout<<INFO(CUSTOMER(p)).customer_name<<" (";
      cout<<INFO(CUSTOMER(p)).customer_id<<")\n";
      p = NEXT(p);
    }
    cout<<INFO(PRODUCT(p)).product_name<<": ";
    cout<<INFO(p).point<<" by ";
    cout<<INFO(CUSTOMER(p)).customer_name<<" (";
    cout<<INFO(CUSTOMER(p)).customer_id<<")\n";
  }
}


void ViewRateByCustomer(CustomerPointer customer, RateList list){
  if(FIRST(list)==NULL){
    cout<<"No one has rated at this time.\n";
  }else{
    RatePointer p=FIRST(list);
    while(p!=LAST(list)){
      if(CUSTOMER(p)==customer){
        cout<<INFO(PRODUCT(p)).product_name<<": ";
        cout<<INFO(p).point<<endl;
      }
      p = NEXT(p);
    }
    if(CUSTOMER(p)==customer){
      cout<<INFO(PRODUCT(p)).product_name<<": ";
      cout<<INFO(p).point<<endl;
    }
  }
}

void ViewRateByProduct(ProductPointer product, RateList list){
  if(FIRST(list)==NULL){
    cout<<"No one has rated at this time.\n";
  }else{
    RatePointer p=FIRST(list);
    while(p!=LAST(list)){
      if(PRODUCT(p)==product){
        cout<<INFO(CUSTOMER(p)).customer_name<<" (";
        cout<<INFO(CUSTOMER(p)).customer_id<<"): ";
        cout<<INFO(p).point<<endl;
      }
      p = NEXT(p);
    }
    if(PRODUCT(p)==product){
      cout<<INFO(CUSTOMER(p)).customer_name<<" (";
      cout<<INFO(CUSTOMER(p)).customer_id<<"): ";
      cout<<INFO(p).point<<endl;
    }
  }
}

void ViewProductRate(ProductList product_list, RateList rate_list){
  int lots_of_data=0;
  int amount_of_data=0;
  int point;
  float average;
  ProductPointer product=FIRST(product_list);
  RatePointer rate;
  while(product!=NULL){
    amount_of_data=0;
    lots_of_data=0;
    if(FIRST(rate_list)!=NULL){
      rate=FIRST(rate_list);
      while(rate!=LAST(rate_list)){
        if(PRODUCT(rate)==product){
          amount_of_data=amount_of_data+INFO(rate).point;
          lots_of_data++;
        }
        rate=NEXT(rate);
      }
      if(PRODUCT(rate)==product){
        amount_of_data=amount_of_data+INFO(rate).point;
        lots_of_data++;
      }
      if((amount_of_data==0)&&(lots_of_data==0)){
        average=0;
      }else{
        average=float(amount_of_data)/lots_of_data;
      }
    }else{
      average=0;
    }
    cout<<INFO(product).product_name<<": "<<average<<endl;
    product=NEXT(product);
  }
}

void CountRate(RateList list){
  if(FIRST(list)!=NULL){
    RatePointer p=FIRST(list);
    int x=1;
    while(NEXT(p)!=FIRST(list)){
      p=NEXT(p);
      x++;
    }
    cout<<"num: "<<x<<endl;
  }else{
    cout<<"num: 0"<<endl;
  }
}
