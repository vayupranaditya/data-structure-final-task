#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "main.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

string GetOsName();
void ClearScreen();
string StrToLower(string str);
vector <string> GetCommandInput();
void HomePage(CustomerList &customer_list, 
              ProductList &product_list, 
              RateList &rate_list);
CustomerPointer SignUp(CustomerList &customer_list,
              ProductList &product_list,
              RateList &rate_list);
CustomerPointer SignIn(CustomerList customer_list, 
                      ProductList &product_list, 
                      RateList &rate_list, 
                      CustomerPointer customer);
void Menu(CustomerPointer user, 
          CustomerList &customer_list, 
          ProductList &product_list, 
          RateList &rate_list);
void TopTenProduct(ProductList product_list);
void AdminAddProduct(ProductList &product_list);
void AdminDeleteCustomer(CustomerList &customer_list,
                         RateList &rate_list);
void AdminDeleteProduct(ProductList &product_list,
                        RateList &rate_list);
void AdminSeeRateByCustomer(CustomerList customer_list,
                            RateList rate_list);
void AdminSeeRateByProduct(ProductList product_list,
                           RateList rate_list);
void AdminUpdateProduct(ProductList product_list);
void UserInputRate(CustomerPointer user, 
                   ProductList product_list, 
                   RateList &rate_list);
void UserDeleteRate(CustomerPointer user,
                    RateList &rate_list);

#endif //APP_H_INCLUDED