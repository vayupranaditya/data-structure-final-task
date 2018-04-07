//customer uses single linear linked list with first

#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>

using namespace std;

struct CustomerInfotype{
  string customer_id, customer_name;
};

struct CustomerElement{
  CustomerInfotype info;
  CustomerPointer next;
};

struct CustomerList{
  CustomerPointer first;
};

CustomerPointer CreateNewCustomer(string customer_id, string customer_name);
void CreateCustomerList(CustomerList &list);
CustomerPointer FindCustomerId(string customer_id, CustomerList list);
void InsertFirstCustomer(CustomerPointer &customer, CustomerList &list);
void InsertLastCustomer(CustomerPointer &customer, CustomerList &list);
void InsertAfterCustomer(CustomerPointer &customer, CustomerPointer &precedent, CustomerList &list);
CustomerPointer DeleteFirstCustomer(CustomerList &list);
CustomerPointer DeleteLastCustomer(CustomerList &list);
CustomerPointer DeleteAfterCustomer(CustomerPointer &precedent CustomerList &list);
void UpdateCustomer(CustomerPointer &customer, string customer_id, string customer_name, CustomerList &list);
void ViewCustomer(CustomerList list);

#endif //CUSTOMER_H_INCLUDED