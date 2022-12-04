#include<cstdio>
#include <map> 
#include<iostream>
#include "ListStock.cpp"
#include<string>
 #include<math.h>
#define max 100

using namespace std;
typedef map<char,int> OPERATOR;

string push_operator(Stock* stock,char data,string number){
    OPERATOR caculator_char ;  
    caculator_char.insert(pair<char,int>('+',1));
    caculator_char.insert(pair<char,int>('-',1));
    caculator_char.insert(pair<char,int>('*',2));
    caculator_char.insert(pair<char,int>('/',2));
    if(Stock_isEmpty(stock)){
            push_stock(stock,data);
        }
    else{
        if(caculator_char[data]>caculator_char[stock->head->next->Data]){
            push_stock(stock,data);
            }
        else{
            string a = pop_stock(stock);
            number.insert(number.length(),a);
            // cout<<a<<endl;
            // cout<<data<<endl;
            number = push_operator(stock,data,number);
            }
        }
    return number;
}
string turn_back(string s){
    string number;
    Stock* stock;
    stock = creatNewStock();
    
    for(int i=0;i<s.length();i++){
        // 2+8/2-2  282/+2-
        char data = s[i];
        string datd = string (1,data);
        if(data<='9'&&data>='0'){
            number.insert(number.length(),datd);
        }
        else{
            // cout<<data<<endl;
            number = push_operator(stock,data,number);
        }
    }
    number = push_operator(stock,s[s.length()-1],number);
    return number;
}

char cacluate(Stock* stock,char data){
    int a=0,b=0;
    b = atoi(pop_stock(stock).c_str());
    a = atoi(pop_stock(stock).c_str());
    
    float c =0;
    switch (data)
    {
    case '*':c=a*b;
        break;
    case '/':c=a/b;
        break;
    case '+':c=a+b;
        break;
    case '-':c=a-b;
        break;
    default:return 0;
    }
    return (char)c;
}

string eval(string s){
    char data ;
    Stock* stock;
    stock = creatNewStock();
    for(int i=0;i<s.length();i++){
        data = s[i];
        if(data<='9'&&data>='0'){
            push_stock(stock,data);
        }
        else{
            int c=0;
            c =cacluate(stock,data);
            data = c+'0';
            push_stock(stock,data);
        }
    }
    cout<<pop_stock(stock)<<endl;
    return "1";
}

int main(){
    eval(turn_back("2/2+8/4-2*1"));
}