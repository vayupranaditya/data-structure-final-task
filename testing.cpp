#include <iostream>
#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

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

int TestProductList(){
  ProductList product_list;
  CreateProductList(product_list);

  string product_name="prod_name001";
  ProductPointer product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name003";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name002";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name003";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name004";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name005";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  ViewProduct(product_list);

  cout<<"delete 005"<<endl;
  DeleteProduct(product,product_list);

  ViewProduct(product_list);

  cout<<"delete 001"<<endl;
  product=FindProduct("prod_name001",product_list);
  DeleteProduct(product,product_list);

  ViewProduct(product_list);

  cout<<"delete 002"<<endl;
  product=FindProduct("prod_name002",product_list);
  DeleteProduct(product,product_list);

  ViewProduct(product_list);

  cout<<"update 003 > 001"<<endl;
  product=FindProduct("prod_name003",product_list);
  UpdateProduct(product,"prod_name001");

  ViewProduct(product_list);

  cout<<"update 004 > 002"<<endl;
  product=FindProduct("prod_name004",product_list);
  UpdateProduct(product,"prod_name002");
  
  ViewProduct(product_list);

  cout<<"update !NULL > 003"<<endl;
  product=FindProduct("auuu",product_list);
  UpdateProduct(product,"prod_name003");

  ViewProduct(product_list);

  return 0;

}