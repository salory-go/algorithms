#include<cstdio>
#include<iostream>
// 分配内存用这个头文件
using namespace std;

#define max 100
//define the struct
typedef struct Stock{
    int Data[max];
    int ltop;
    int rtop;
    // 在这里赋值是没有用的
}Stock;

// 还是得有个初始化
Stock* creat(){
    Stock *stock;
    stock = (Stock*)malloc(sizeof(Stock));
    stock->ltop = -1;
    stock->rtop = max;
    for(int i=0;i<max;i++){
        stock->Data[i] = 0;
    }
    return stock;
}

void push_Stock(Stock* stock,int tag,int data){
    if(tag==0){
        stock->Data[++(stock->ltop)] = data; 
        // 指针始终指向栈顶
    }
    else{
        stock->Data[--(stock->rtop)] = data; 
    }
}

int pop_stock(Stock* stock,int tag){
    int data=-1;
    if(stock->ltop==-1||stock->rtop==max){
        return -1;
    }
    else{
        if(tag==0){
            data = stock->Data[(stock->ltop)];
            stock->Data[(stock->ltop)] =0;
            stock->ltop--;
        }
        else{
            data = stock->Data[(stock->rtop)];
            stock->Data[(stock->rtop)] =0;
            stock->rtop--;
        }
    }
    return data;
}

void printStock(Stock* stock){
    for(int i=0;i<max;i++){
        cout<<stock->Data[i]<<endl;
    }
}
