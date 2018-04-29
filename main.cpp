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

  CustomerPointer user=CreateNewCustomer("admin","Administrator");
  InsertCustomer(user,customer_list);
  user=CreateNewCustomer("cust_001","Customer 001");
  InsertCustomer(user,customer_list);
  user=CreateNewCustomer("cust_002","Customer 002");
  InsertCustomer(user,customer_list);

  ProductPointer product=CreateNewProduct("Microsoft Windows 10");
  InsertProduct(product,product_list);
  product=CreateNewProduct("Ubuntu 18.04 Bionic Beaver");
  InsertProduct(product,product_list);
  product=CreateNewProduct("macOS 10.13 High Sierra");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 4");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 5");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 6");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 7");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 8");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 9");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 10");
  InsertProduct(product,product_list);
  product=CreateNewProduct("product 11");
  InsertProduct(product,product_list);
  

  HomePage(customer_list, product_list, rate_list);

  return 0;
}