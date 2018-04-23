#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "app.h"
#include "customer.h"
#include "product.h"
#include "rate.h"

using namespace std;

vector <string> GetCommandInput(){
  string input;
  vector <string> commands {};
  cout<<"> ";
  getline(cin,input);
  //transform(input.begin(), input.end(), input.begin(), tolower);
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

void HomePage(CustomerList &customer_list, ProductList &product_list, RateList &rate_list){
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
      CustomerPointer customer=SignIn();
    }else if(command[0]=="signup"){
      //sign up
    }else{
      //reset
    }
  }
}

CustomerPointer SignUp(CustomerList &customer_list){
  cout<<"Sign Up\n";
  cout<<"Please type your credential below\n";
  cout<<"User ID: ";
  string user_id, user_name;
  while(user_id==""){
    getline(cin,user_id);
    if(FindCustomerId(user_id, customer_list)!=NULL){
      cout<<"User ID has been taken. Please choose a different user ID\n"
      user_id="";
    }
  }
  cout<<"User name: ";
  getline(cin, user_name);
  CustomerPointer customer=CreateNewCustomer(user_id, user_name, customer_list);
  InsertCustomer(customer, customer_list);

  //auto login
  customer=SignIn(customer, customer_list);
  return customer;
}

CustomerPointer SignIn(CustomerPointer customer = NULL, CustomerList customer_list){
  CustomerPointer user;
  if(customer!=NULL){
    string user_id="";
    cout<<"Sign In\n";
    cout<<"Please enter your credential below\n";
    while(user_id==""){
      cout<<"User ID: ";
      getline(cin, user_id);
      if(user=FindCustomerId(user_id, customer_list)==NULL){
        cout<<"User ID not found. Please try again.\n"
        user_id="";
      }
    }
  }else{
    user=FindCustomerId(INFO(customer).user_id, customer_list);
  }
  return user;
}

void Menu(CustomerPointer user, CustomerList &customer_list, ProductList &product_list, RateList &rate_list){
  vector <string> command {};
  if(INFO(user).customer_name=="admin"){
    //admin list
  }else{
    //customer list
    while(command.size()==0){
      command=GetCommandInput();
      if(command[0]=="rate"){
        //input rate
      }else if(command[0]=="delete"){
        //delete rate
      }else if(command[0]=="see"){
        //view
        if(command.size()==2){
          if(command[1]=="products"){
            //see products
          }else if(command[1]=="rates"){
            //see my rates
          }
        }
      }else if(command[0]=="update"){
        //update account
      }else{
        //reset
      }
    }
  }
}