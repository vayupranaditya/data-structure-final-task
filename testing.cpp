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

  cout<<"INSERT INTO customer_list VALUES ('cust_id001','cust_name001');"<<endl;
  cout<<"INSERT INTO customer_list VALUES ('cust_id002','cust_name002');"<<endl;
  cout<<"INSERT INTO customer_list VALUES ('cust_id003','cust_name003');"<<endl;
  cout<<"INSERT INTO customer_list VALUES ('cust_id004','cust_name004');"<<endl;
  cout<<"INSERT INTO customer_list VALUES ('cust_id005','cust_name005');"<<endl;
  ViewCustomer(customer_list);

  customer=FindCustomerId("cust_id001",customer_list);
  DeleteCustomer(customer,customer_list);
  customer=FindCustomerId("cust_id005",customer_list);
  DeleteCustomer(customer,customer_list);
  customer=FindCustomerId("cust_id003",customer_list);
  DeleteCustomer(customer,customer_list);

  cout<<"DELETE FROM customer_list WHERE customer_id='cust_id001';"<<endl;
  cout<<"DELETE FROM customer_list WHERE customer_id='cust_id005';"<<endl;
  cout<<"DELETE FROM customer_list WHERE customer_id='cust_id003';"<<endl;
  ViewCustomer(customer_list);

  customer_name="cust_name001";
  customer_id="";
  customer=FindCustomerId("cust_id004",customer_list);
  UpdateCustomer(customer,customer_id,customer_name,customer_list);

  cout<<"UPDATE customer_list SET customer_name='cust_name001' WHERE customer_id='cust_id004';"<<endl;
  ViewCustomer(customer_list);

  customer_name="cust_name001";
  customer_id="cust_id001";
  customer=FindCustomerId("cust_id004",customer_list);
  UpdateCustomer(customer,customer_id,customer_name,customer_list);
  
  cout<<"UPDATE customer_list SET customer_id='cust_name001' WHERE customer_id='cust_id004';"<<endl;
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

int TestRateList(){
  RateList rate_list;
  CreateRateList(rate_list);
  CustomerList customer_list;
  CreateCustomerList(customer_list);
  ProductList product_list;
  CreateProductList(product_list);

  string customer_id="cust_id001";
  string customer_name="cust_name001";
  CustomerPointer customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  customer_id="cust_id002";
  customer_name="cust_name002";
  customer=CreateNewCustomer(customer_id,customer_name);
  InsertCustomer(customer,customer_list);

  string product_name="prod_name001";
  ProductPointer product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  product_name="prod_name002";
  product=CreateNewProduct(product_name);
  InsertProduct(product,product_list);

  cout<<"> insert rate\n";

  int point=5;
  customer=FindCustomerId("cust_id001",customer_list);
  product=FindProduct("prod_name002",product_list);
  RatePointer rate=CreateNewRate(point,customer,product);
  InsertRate(rate,rate_list);

  point=4;
  customer=FindCustomerId("cust_id002",customer_list);
  product=FindProduct("prod_name001",product_list);
  rate=CreateNewRate(point,customer,product);
  InsertRate(rate,rate_list);

  point=3;
  customer=FindCustomerId("cust_id001",customer_list);
  product=FindProduct("prod_name001",product_list);
  rate=CreateNewRate(point,customer,product);
  InsertRate(rate,rate_list);

  point=2;
  customer=FindCustomerId("cust_id002",customer_list);
  product=FindProduct("prod_name002",product_list);
  rate=CreateNewRate(point,customer,product);
  InsertRate(rate,rate_list);

  //output insert rate: done.
  cout<<"done.\n\n";

  cout<<"> see rate by product\n";
  cout<<"prod_name001\n";
  ViewRateByProduct(FindProduct("prod_name001",product_list),rate_list);
  cout<<"prod_name002\n";
  ViewRateByProduct(FindProduct("prod_name002",product_list),rate_list);
  //output see rate by product: done.
  cout<<"done.\n\n";


  cout<<"> see rate by customer\n";
  cout<<"cust_id001\n";
  ViewRateByCustomer(FindCustomerId("cust_id001",customer_list),rate_list);
  cout<<"cust_id002\n";
  ViewRateByCustomer(FindCustomerId("cust_id002",customer_list),rate_list);
  //output see rate by customer: done.
  cout<<"done.\n\n";

  cout<<"> see customer\n";
  ViewCustomer(customer_list);
  //output see customer: done.
  cout<<"done.\n\n";
  cout<<"> see product\n";
  ViewProduct(product_list);
  //output see product: done.
  cout<<"done.\n\n";
  cout<<"> see rate\n";
  ViewAllRate(rate_list);
  //output see rate: done.
  cout<<"done.\n\n";

  cout<<"> delete rate\n";
  rate=FindRate(FindCustomerId("cust_id002",customer_list),
                FindProduct("prod_name001",product_list),
                rate_list);
  DeleteRate(rate,rate_list);
  rate=FindRate(FindCustomerId("cust_id002",customer_list),
                FindProduct("prod_name002",product_list),
                rate_list);
  DeleteRate(rate,rate_list);
  rate=FindRate(FindCustomerId("cust_id001",customer_list),
                FindProduct("prod_name002",product_list),
                rate_list);
  DeleteRate(rate,rate_list);
  cout<<"done.\n\n";

  cout<<"> see rate\n";
  ViewAllRate(rate_list);
  cout<<"done.\n\n";


  return 0;
}