#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "main.h"
#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

using namespace std;

string GetOsName(){
  #ifdef _WIN32
  return "Windows 32-bit";
  #elif _WIN64
  return "Windows 64-bit";
  #elif __unix || __unix__
  return "Unix";
  #elif __APPLE__ || __MACH__
  return "macOS";
  #elif __linux__
  return "Linux";
  #elif __FreeBSD__
  return "FreeBSD";
  #else
  return "Other";
  #endif
}

void ClearScreen(){
  string os=GetOsName();
  if((os=="Windows 32-bit") || (os=="Windows 64-bit")){
    system("cls");
  }else if(os!="macOS"){
    system("clear");
  }
}

string StrToLower(string str){
  for(int i=0; i<str.length(); i++){
    str[i]=tolower(str[i]);
  }
  return str;
}

vector <string> GetCommandInput(){
  string input;
  vector <string> commands {};
  cout<<"> ";
  getline(cin,input);
  input=StrToLower(input);
  unsigned int i,j;
  i=0;
  j=0;
  while(i<input.length()){
    if(input[i]==' '){
      commands.push_back(input.substr(j,i-j));
      j=i+1;
    }
    i++;
  }
  commands.push_back(input.substr(j,i-j));
  return commands;
}

void HomePage(CustomerList &customer_list, 
              ProductList &product_list, 
              RateList &rate_list){
  cout<<"Rate the Product v1.0\n";
  cout<<"By I Gusti Bagus Vayupranaditya Putraadinatha (1301174029) and\n";
  cout<<"I Gusti Bagus Agung Bayu Pramana Yudha (130117****).\n\n";
  cout<<"Type 'help' to see command list.\n\n";
  vector <string> command {};
  while(command.size() == 0){
    command=GetCommandInput();
    if(command[0]=="see"){
      //see top / all
      if(command.size()>1){
        if(command[1]=="-all"){
          //see all
        }else if(command[1]=="-top"){
          //see top
        }else{
          cout<<"Usage: see filter [-all | -top]\n";
          cout<<"Type 'help -see' for more info\n";
          command.clear();
        }
      }else{
        cout<<"Usage: see filter [-all | -top]\n";
        cout<<"Type 'help -see' for more info\n";
        command.clear();
      }
    }else if(command[0]=="signin"){
      //signin
      CustomerPointer customer=SignIn(customer_list, product_list, rate_list, NULL);
      if(customer!=NULL){
        Menu(customer, customer_list, product_list, rate_list);
      }
      break;
    }else if(command[0]=="signup"){
      //sign up
      CustomerPointer customer=SignUp(customer_list, product_list, rate_list);
      if(customer!=NULL){
        Menu(customer, customer_list, product_list, rate_list);
      }
      break;
    }else if(command[0]=="clear"){
      ClearScreen();
    }else if(command[0]=="help"){
      //help
      if(command.size()==1){
        cout<<"clear\n";  
        cout<<"  clear the screen.\n";
        cout<<"exit\n";
        cout<<"  exit of the program.\n";
        cout<<"help\n";
        cout<<"  see command list and description.\n";
        cout<<"see object [-all | -top]\n";
        cout<<"  -all: see all products.\n";
        cout<<"  -top: see maximum 10 products with highest rate.\n";
        cout<<"signin\n";
        cout<<"  sign into an account.\n";
        cout<<"signup\n";
        cout<<"  sign up an account.\n";
      }else{
        if(command[1]=="-see"){
          cout<<"see object [-all | -top]\n";
          cout<<"  -all: see all products.\n";
          cout<<"  -top: see maximum 10 products with highest rate.\n";
        }else{
          cout<<"Command not found. Type 'help' to see command list.\n";
        }
      }
    }else if(command[0]=="exit"){
      //exit
      cout<<"See you\n";
      break;
    }else{
      //reset
      cout<<"Command not found. Type 'help' to see command list.\n";
    }
    if(command[0]!="exit"){
      command.clear();
    }
  }
}

CustomerPointer SignUp(CustomerList &customer_list,
              ProductList &product_list,
              RateList &rate_list){
  cout<<"Sign Up\n";
  cout<<"Please type your credential below\n";
  cout<<"Or enter '!cancel' to cancel.\n";
  cout<<"User ID: ";
  string user_id, user_name;
  while(user_id==""){
    getline(cin,user_id);
    if(StrToLower(user_id)=="!cancel"){
      cout<<"Sign up canceled.\n\n";
      HomePage(customer_list, product_list, rate_list);
      return NULL;
    }
    if(FindCustomerId(user_id, customer_list)!=NULL){
      cout<<"User ID has been taken. Please choose a different user ID\n";
      user_id="";
    }
  }
  cout<<"User name: ";
  getline(cin, user_name);
  if(StrToLower(user_name)=="!cancel"){
    cout<<"Sign up canceled.\n\n";
    HomePage(customer_list, product_list, rate_list);
    return NULL;
  }
  CustomerPointer customer=CreateNewCustomer(user_id, user_name);
  InsertCustomer(customer, customer_list);

  cout<<"Sign up as "<<INFO(customer).customer_name<<" success!\n";

  //auto login
  customer=SignIn(customer_list, product_list, rate_list, customer);
  return customer;
}

CustomerPointer SignIn(CustomerList customer_list, 
                      ProductList &product_list, 
                      RateList &rate_list, 
                      CustomerPointer customer){
  if(customer==NULL){
    string user_id="";
    cout<<"Sign In\n";
    cout<<"Please enter your credential below\n";
    cout<<"Or enter '!cancel' to cancel.\n";
    while(user_id==""){
      cout<<"User ID: ";
      getline(cin, user_id);
      if(StrToLower(user_id)=="!cancel"){
        cout<<"Sign in canceled.\n\n";
        HomePage(customer_list, product_list, rate_list);
        return NULL;
      }
      customer=FindCustomerId(user_id,customer_list);
      if(customer==NULL){
        cout<<"User ID not found. Please try again.\n";
        user_id="";
      }
    }
  }else{
    customer=FindCustomerId(INFO(customer).customer_id, customer_list);
  }

  cout<<"Signed in as "<<INFO(customer).customer_name<<"!\n\n";
  return customer;
}

void Menu(CustomerPointer user, 
          CustomerList &customer_list, 
          ProductList &product_list, 
          RateList &rate_list){
  vector <string> command {};
  cout<<"Hi, "<<INFO(user).customer_name<<"!\n";
  if(INFO(user).customer_id=="admin"){
    //admin list
    while(command.size()==0){
      command=GetCommandInput();
      if(command[0]=="help"){
        //help
        cout<<"add\n";
        cout<<"clear\n";
        cout<<"delete\n";
        cout<<"exit\n";
        cout<<"help\n";
        cout<<"see\n";
        cout<<"signout\n";
      }else if(command[0]=="see"){
        //see
        if(command.size()>1){
          if(command[1]=="-customers"){
            //see customers
            ViewCustomer(customer_list);
          }else if(command[1]=="-products"){
            //see products
            ViewProduct(product_list);
          }else if(command[1]=="-rates"){
            //see rates
            if(command.size()>2){
              //see rates by
              if(command[2]=="-customer"){
                //see rates by customer X
              }else if(command[2]=="-product"){
                //see rates by product X
              }else{
                //wrong input
                cout<<"Usage: see -rates filter [-customer | -product]\n";
                cout<<"Type 'help -see' for more info\n";
              }
            }else{
              ViewAllRate(rate_list);
            }
          }else{
            //wrong input
            cout<<"Usage: see object [-customers | -products | -rates] filter [-customer | -product]\n";
            cout<<"Type 'help -see' for more info\n";
          }
        }else{
          cout<<"Usage: see object [-customers | -products | -rates] filter [-customer | -product]\n";
          cout<<"Type 'help -see' for more info\n";
        }
      }else if(command[0]=="add"){
        //add product
        AdminAddProduct(product_list);
      }else if(command[0]=="delete"){
        //delete
        if(command.size()>1){
          if(command[1]=="-customer"){
            //delete customer
            AdminDeleteCustomer(customer_list,rate_list);
          }else if(command[1]=="-product"){
            //delete product
            AdminDeleteProduct(product_list,rate_list);
          }else{
            //wrong input
            cout<<"Usage: delete object [-customer | -product]\n";
            cout<<"Type 'help -delete' for more info\n";
          }
        }else{
          //wrong input
          cout<<"Usage: delete object [-customer | -product]\n";
          cout<<"Type 'help -delete' for more info\n";
        }
      }else if(command[0]=="clear"){
        ClearScreen();
      }else if(command[0]=="signout"){
        //sign out
        HomePage(customer_list,product_list,rate_list);
        break;
      }else if(command[0]=="exit"){
        //exit
        cout<<"See you\n";
        break;
      }else{
        cout<<"Command not found. Type 'help' to see command list.\n";
      }
      command.clear();
    }
  }else{
    //customer list
    while(command.size()==0){
      command=GetCommandInput();
      if(command[0]=="help"){
        //help
        cout<<"clear\n";
        cout<<"delete\n";
        cout<<"exit\n";
        cout<<"help\n";
        cout<<"rate\n";
        cout<<"see\n";
        cout<<"signout\n";
        cout<<"udate\n";
      }else if(command[0]=="rate"){
        //input rate
        UserInputRate(user,product_list,rate_list);
      }else if(command[0]=="delete"){
        //delete rate
        cout<<"delete\n";
      }else if(command[0]=="see"){
        //view
        if(command.size()==2){
          if(command[1]=="-products"){
            //see products
            ViewProduct(product_list);
          }else if(command[1]=="-rates"){
            //see my rates
            ViewRateByCustomer(user,rate_list);
          }else{
            cout<<"Usage: see object [-products | -rates]\n";
            cout<<"Type 'help -see' for more info\n";
          }
        }else{
          cout<<"Usage: see object [-products | -rates]\n";
          cout<<"Type 'help -see' for more info\n";
        }
      }else if(command[0]=="update"){
        //update account
        cout<<"update\n";
      }else if(command[0]=="clear"){
        ClearScreen();
      }else if(command[0]=="signout"){
        //signout
        HomePage(customer_list,product_list,rate_list);
        break;
      }else if(command[0]=="exit"){
        cout<<"See you\n";
        break;
      }else{
        if(command[0]!=""){
          cout<<"Command not found. Type 'help' to see command list.\n";
        }
      }
      command.clear();
    }
  }
}

void AdminAddProduct(ProductList &product_list){
  string product_name;
  ProductPointer product;
  do{
    cout<<"Enter new product name (or type '!cancel' to cancel): ";
    getline(cin,product_name);
    if(product_name=="!cancel"){
      cout<<"Add product canceled.\n";
      break;
    }
    product=FindProduct(product_name, product_list);
    if(product!=NULL){
      cout<<"Product has already registered. Please try a new one.\n";
    }
  }while(product!=NULL);
  if(product_name!="!cancel"){
    product=CreateNewProduct(product_name);
    InsertProduct(product,product_list);
    cout<<"You have successfully added "<<product_name<<endl;
  }
}

void AdminDeleteCustomer(CustomerList &customer_list,
                         RateList &rate_list){
  string customer_id;
  CustomerPointer customer;
  ViewCustomer(customer_list);
  do{
    cout<<"Enter customer ID (or type '!cancel' to cancel): ";
    getline(cin,customer_id);
    if(customer_id=="!cancel"){
      cout<<"Delete customer canceled.\n";
      break;
    }
    customer=FindCustomerId(customer_id,customer_list);
    if(customer==NULL){
      cout<<"Customer ID not found.\n";
    }
  }while(customer==NULL);
  if(customer_id!="!cancel"){
    DeleteCustomer(customer,customer_list);
    DeleteRateByCustomer(customer,rate_list);
    cout<<INFO(customer).customer_name<<" ("<<INFO(customer).customer_id<<") has been deleted.\n";
  }
}

void AdminDeleteProduct(ProductList &product_list,
                        RateList &rate_list){
  string product_name;
  ProductPointer product;
  ViewProduct(product_list);
  do{
    cout<<"Enter product name (or type '!cancel' to cancel): ";
    getline(cin,product_name);
    if(product_name=="!cancel"){
      cout<<"Delete product canceled.\n";
      break;
    }
    product=FindProduct(product_name,product_list);
    if(product==NULL){
      cout<<"Product not found.\n";
    }
  }while(product==NULL);
  if(product_name!="!cancel"){
    DeleteProduct(product,product_list);
    DeleteRateByProduct(product,rate_list);
    cout<<INFO(product).product_name<<" has been deleted.\n";
  }
}

void UserInputRate(CustomerPointer user, 
                   ProductList product_list, 
                   RateList &rate_list){
  if(!IsProductListEmpty(product_list)){
    string product_name,point_string;
    int point;
    ProductPointer product;
    RatePointer rate;
    ViewProduct(product_list);
    do{
      cout<<"Enter product name (or type '!cancel' to cancel): ";
      getline(cin,product_name);
      if(product_name=="!cancel"){
        cout<<"Rate canceled.\n";
        break;
      }
      product=FindProduct(product_name, product_list);
      if(product==NULL){
        cout<<"Product not found. Please try again.\n";
      }
    }while(product==NULL);
    if(product_name!="!cancel"){
      do{
        cout<<"Score for "<<product_name<<"(1-5): ";
        getline(cin,point_string);
        if((point_string.length()!=1) || (point_string[0]<49) || (point_string[0]>53)){
          cout<<"Score range is 1-5. Please try again.\n";
        }
      }while((point_string.length()!=1) || (point_string[0]<49) || (point_string[0]>53));
      point=stoi(point_string);
      rate=CreateNewRate(point,user,product);
      InsertRate(rate,rate_list);
      cout<<"You have successfully rated "<<product_name<<endl;\
    }
  }else{
    cout<<"There is no product at this time.\n";
  }
}

