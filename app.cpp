#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "main.h"
#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

using namespace std;


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
      if(command[1]=="all"){
        //see all
      }else if(command[1]=="top"){
        //see top
      }else{
        //command.erase();
      }
    }else if(command[0]=="signin"){
      //signin
      CustomerPointer customer=SignIn(customer_list, product_list, rate_list, NULL);
      Menu(customer, customer_list, product_list, rate_list);
    }else if(command[0]=="signup"){
      //sign up
      CustomerPointer customer=SignUp(customer_list, product_list, rate_list);
      Menu(customer, customer_list, product_list, rate_list);
    }else{
      //reset
      command.clear();
    }
  }
}

CustomerPointer SignUp(CustomerList &customer_list,
              ProductList &product_list,
              RateList &rate_list){
  cout<<"Sign Up\n";
  cout<<"Please type your credential below\n";
  cout<<"User ID: ";
  string user_id, user_name;
  while(user_id==""){
    getline(cin,user_id);
    if(FindCustomerId(user_id, customer_list)!=NULL){
      cout<<"User ID has been taken. Please choose a different user ID\n";
      user_id="";
    }
  }
  cout<<"User name: ";
  getline(cin, user_name);
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
  CustomerPointer user;
  if(customer==NULL){
    string user_id="";
    cout<<"Sign In\n";
    cout<<"Please enter your credential below\n";
    cout<<"Or enter '!cancel' to cancel.\n";
    while(user_id==""){
      cout<<"User ID: ";
      getline(cin, user_id);
      if(StrToLower(user_id)=="!cancel"){
        cout<<"\n\n";
        HomePage(customer_list, product_list, rate_list);
        break;
      }
      if((user=FindCustomerId(user_id, customer_list))==NULL){
        cout<<"User ID not found. Please try again.\n";
        user_id="";
      }
    }
  }else{
    user=FindCustomerId(INFO(customer).customer_id, customer_list);
  }

  cout<<"Signed in as "<<INFO(customer).customer_name<<"!\n";
  return user;
}

void Menu(CustomerPointer user, 
          CustomerList &customer_list, 
          ProductList &product_list, 
          RateList &rate_list){
  vector <string> command {};
  cout<<"Hi, "<<INFO(user).customer_name<<"!\n";
  if(INFO(user).customer_name=="admin"){
    //admin list
    while(command.size()==0){
      command=GetCommandInput();
      if(command[0]=="help"){
        //help
        cout<<"help\n";
      }else if(command[0]=="see"){
        //see
        if(command.size>1){
          if(command[1]=="-customers"){
            //see customers
          }else if(command[1]=="-products"){
            //see products
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
              }
            }else{
              //wrong input
              cout<<"Usage: see -rates filter [-customer | -product]\n";
              cout<<"Type 'help -see' for more info\n";
            }
          }else{
            //wrong input
          }
        }else{
          cout<<"Usage: see object [-customers | -products | -rates] -filter [-customer | -product]\n";
          cout<<"Type 'help -see' for more info\n";
        }
      }else if(command[0]=="signout"){
        //sign out
      }else if(command[0]=="exit"){
        //exit
        break;
      }else{
        cout<<"Command not found. Type 'help' to see command list.\n";
      }
      command.clear()
    }
  }else{
    //customer list
    while(command.size()==0){
      command=GetCommandInput();
      if(command[0]=="help"){
        //help
        cout<<"help\n";
      }else if(command[0]=="rate"){
        //input rate
        cout<<"rate\n";
        UserInputRate(user,product_list,rate_list);
      }else if(command[0]=="delete"){
        //delete rate
        cout<<"delete\n";
      }else if(command[0]=="see"){
        //view
        cout<<"see ";
        if(command.size()==2){
          if(command[1]=="-products"){
            //see products
            cout<<"products\n";
          }else if(command[1]=="-rates"){
            //see my rates
            cout<<"rates\n";
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
      }else if(command[0]=="exit"){
        cout<<"exit\n";
        break;
      }else{
        cout<<"Command not found. Type 'help' to see command list.\n";
      }
      command.clear();
    }
  }
}

void UserInputRate(CustomerPointer user, 
                   ProductList product_list, 
                   RateList &rate_list){
  if(!IsProductListEmpty(product_list)){
    string product_name;
    int point;
    ProductPointer product;
    RatePointer rate;
    ViewProduct(product_list);
    do{
      cout<<"Enter your desired product name (or type '!cancel' to cancel): ";
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
        cin>>point;
        if(!((point>=1) && (point<=5))){
          cout<<"Score range is 1-5. Please try again.\n";
        }
      }while((point>=1) && (point<=5));
      rate=CreateNewRate(point,user,product);
      InsertRate(rate,rate_list);
    }
  }else{
    cout<<"There is no product at this time.\n";
  }
}

void UserDeleteRate(CustomerPointer user,
                    RateList &rate_list){
}