#include <iostream>
#include "app.h"
#include "customer.h"

using namespace std;

int TestCustomerList(){
  string customer_id="cust_id001";
  string customer_name="cust_name001";
  CustomerPointer p=CreateNewCustomer(customer_id,customer_name);

  return 0;
}