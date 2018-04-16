#include <iostream>
#include "app.h"
#include "customer.h"

using namespace std;

int TestCustomerList(){
  CustomerList customer_list;
  CreateCustomerList(customer_list);

  string customer_id="cust_id001";
  string customer_name="cust_name001";
  CustomerPointer customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  customer_id="cust_id002";
  customer_name="cust_name002";
  customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  customer_id="cust_id004";
  customer_name="cust_name004";
  customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);
  
  customer_id="cust_id003";
  customer_name="cust_name003";
  customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  customer_id="cust_id005";
  customer_name="cust_name005";
  customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  ViewCustomer(customer_list);

  customer=FindCustomerId("cust_id001",customer_list);
  DeleteCustomer(customer,customer_list);
  customer=FindCustomerId("cust_id005",customer_list);
  DeleteCustomer(customer,customer_list);
  customer=FindCustomerId("cust_id003",customer_list);
  DeleteCustomer(customer,customer_list);

  ViewCustomer(customer_list);

  customer_name="cust_name001";
  customer_id="";
  customer=FindCustomerId("cust_id004",customer_list);
  UpdateCustomer(customer,customer_id,customer_name,customer_list);

  ViewCustomer(customer_list);

  customer_name="cust_name001";
  customer_id="cust_id001";
  customer=FindCustomerId("cust_id004",customer_list);
  UpdateCustomer(customer,customer_id,customer_name,customer_list);
  
  ViewCustomer(customer_list);

  return 0;
}