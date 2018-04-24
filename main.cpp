#include <iostream>

#include "main.h"
#include "customer.h"
#include "product.h"
#include "rate.h"
#include "app.h"

#include "testing.h"

using namespace std;

int main(){

  //code here

  //testing
  /*
   cout<<"\n\nTest Customer \n";
   TestCustomerList();
   cout<<"\n\nTest Product \n";
   TestProductList();
   cout<<"\n\nTest Rate\n";
   TestRateList();
   */

  CustomerList customer_list;
  ProductList product_list;
  RateList rate_list;

  CreateCustomerList(customer_list);
  CreateProductList(product_list);
  CreateRateList(rate_list);

  HomePage(customer_list, product_list, rate_list);

  return 0;
}