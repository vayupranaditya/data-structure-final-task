#include <iostream>
#include <string>

#include "app.h"
#include "customer.h"

using namespace std;

CustomerPointer CreateNewCustomer(string customer_id, string customer_name){
  CustomerPointer customer=new CustomerElement;
  INFO(customer).customer_id=customer_id;
  INFO(customer).customer_name=customer_name;
  return customer;
}

void CreateCustomerList(CustomerList &list){
  FIRST(list)=NULL;
}

CustomerPointer FindCustomerId(string customer_id, CustomerList list){
  CustomerPointer p=FIRST(list);
  if(p!=NULL){
    while((NEXT(p)!=NULL) && (INFO(p).customer_id!=customer_id)){
      p=NEXT(p);
    }
    if(INFO(p).customer_id==customer_id){
      return p;
    }else{
      return NULL;
    }
  }
}

void InsertFirstCustomer(CustomerPointer &customer, CustomerList &list){
  NEXT(customer)=FIRST(list);
  FIRST(list)=customer;
}

void InsertLastCustomer(CustomerPointer &customer, CustomerList &list){
  if(FIRST(list)==NULL){
    InsertFirstCustomer(customer,list);
  }else{
    CustomerPointer p=FIRST(list);
    while(NEXT(p)!=NULL){
      p=NEXT(p);
    }
    NEXT(p)=customer;
  }
}

void InsertAfterCustomer(CustomerPointer &customer, CustomerPointer &precedent, CustomerList &list){
  if(precedent!=NULL){
    NEXT(customer)=NEXT(precedent);
    NEXT(precedent)=customer;
  }
}

void InsertCustomer(CustomerPointer &customer, CustomerList &list){
  if(FindCustomerId(INFO(customer).customer_id,list)==NULL){
    if((FIRST(list)==NULL) || (INFO(FIRST(list)).customer_id.compare(INFO(customer).customer_id)>0)){
      InsertFirstCustomer(customer,list);
    }else{
      CustomerPointer p=FIRST(list);
      while((NEXT(p)!=NULL) && (INFO(NEXT(p)).customer_id.compare(INFO(customer).customer_id)<0)){
        p=NEXT(p);
      }
      if(NEXT(p)==NULL){
        InsertLastCustomer(customer,list);
      }else{
        InsertAfterCustomer(customer,p,list);
      }
    }
  }else{
    cout<<"Customer ID has been used."<<endl;
  }
}

CustomerPointer DeleteFirstCustomer(CustomerList &list){
  CustomerPointer p=FIRST(list);
  if(p!=NULL){
    FIRST(list)=NEXT(p);
    NEXT(p)=NULL;
  }
  return p;
}

CustomerPointer DeleteLastCustomer(CustomerList &list){
  CustomerPointer p=FIRST(list);
  if(p!=NULL){
    if(NEXT(p)!=NULL){
      while(NEXT(NEXT(p))!=NULL){
        p=NEXT(p);
      }
      CustomerPointer q=NEXT(p);
      NEXT(p)=NULL;
      return q;
    }else{
      DeleteFirstCustomer(list);
    }
  }
}

CustomerPointer DeleteAfterCustomer(CustomerPointer &precedent, CustomerList &list){
  if(precedent!=NULL){
    CustomerPointer p=NEXT(precedent);
    NEXT(precedent)=NEXT(p);
    NEXT(p)=NULL;
  }
}

void DeleteCustomer(CustomerPointer &customer, CustomerList &list){
  if(FIRST(list)!=NULL){
    if(customer==FIRST(list)){
      customer=DeleteFirstCustomer(list);
    }else if(NEXT(customer)==NULL){
      customer=DeleteLastCustomer(list);
    }else{
      CustomerPointer p=FIRST(list);
      while(NEXT(p)!=customer){
        p=NEXT(p);
      }
      customer=DeleteAfterCustomer(p,list);
    }
  }
}

void UpdateCustomer(CustomerPointer &customer, string customer_id, string customer_name, CustomerList &list){
  if(customer!=NULL){
    if((customer_name!="") && (INFO(customer).customer_name!=customer_name)){
      INFO(customer).customer_name=customer_name;
    }
    if((customer_id!="") && (INFO(customer).customer_id!=customer_id)){
      DeleteCustomer(customer,list);
      INFO(customer).customer_id=customer_id;
      InsertCustomer(customer,list);
    }
  }
}

void ViewCustomer(CustomerList list){
  if(FIRST(list)!=NULL){
    CustomerPointer p=FIRST(list);
    while(p!=NULL){
      cout<<INFO(p).customer_id<<": "<<INFO(p).customer_name<<endl;
      p=NEXT(p);
    }
  }else{
    cout<<"!empty"<<endl;
  }
}