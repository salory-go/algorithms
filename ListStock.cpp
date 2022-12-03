#include<cstdio>
#include<iostream>
// 分配内存用这个头文件
using namespace std;

typedef struct listNode
{
    char Data;
    listNode *next;
}listNode;
//define the struct
typedef struct Stock{
    listNode* head;
    // 在这里赋值是没有用的
}Stock;

listNode* new_listNode(char data){
    listNode* node;
    node = (listNode*)malloc(sizeof(listNode));
    node->Data = data;
    node->next = NULL;
    return node;
}

Stock* creatNewStock(){
    Stock *stock;
    stock = (Stock*)malloc(sizeof(Stock));
    stock->head = new_listNode('+');
    return stock;
}

int Stock_isEmpty(Stock* stock){
    if(stock->head->next==NULL){
        return 1;
    }
    return 0;
}

int push_stock(Stock* stock,int data){
    // 忘记判断堆栈是否为空了
    if (Stock_isEmpty(stock)){
        listNode* node ;
        node = new_listNode(data);
        stock->head->next = node;
    }
    else{
        listNode* node ;
        node = new_listNode(data);
        node->next = stock->head->next;
        stock->head->next = node;
    }
    return 1;
}

string pop_stock(Stock* stock){
    string data;
    if(Stock_isEmpty(stock)){
        return NULL;
    }
    else{
        data = stock->head->next->Data;
        listNode *p;
        p = stock->head->next;
        stock->head->next = stock->head->next->next;
        free(p);
        return data;
    }
}

void printStock(Stock* stock){
    listNode* p;
    p = stock->head;
    while((p=p->next)!=NULL){
        cout<<p->Data<<endl;
    }
}

int main(){
    Stock* stock;
    stock = creatNewStock();
    push_stock(stock,'2');
    push_stock(stock,'1');
    printStock(stock);
    pop_stock(stock);
    printStock(stock);
}





