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

void HomePage(){
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
    }else if(command[0]=="login"){
      //login
    }else if(command[0]=="signup"){
      //sign up
    }
  }
}

void SignUp(){}
void Login(){}
void Menu(){}