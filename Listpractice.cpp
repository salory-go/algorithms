#include<cstdio>
#include<iostream>
using namespace std;
//the writing of typedef
// 此代码的头结点是存储了数据的，正常应该不存储
typedef struct listNode
{
    int Data;
    listNode *next=NULL;
}listNode;
typedef struct List
{
    listNode* head;
}List;

listNode* new_listNode(int data){
    listNode* node;
    node = (listNode*)malloc(sizeof(listNode));
    node->Data = data;
    node->next = NULL;
    return node;
}

List* creatNewList(int n){
    List* list ;
    list = (List*)malloc(sizeof(List));
    listNode *normal;

    normal = new_listNode(0);
    list->head = normal;
    //这里之前头指针赋值反了a=b写错为b=a,所以导致的无限输出
    //并且上面两句话不能写反，因为normal = new_listNode(0)地址又发生了改变
    for(int i=1;i<n;i++){
        listNode* node;
        node = new_listNode(i*i);
        normal->next = node;
        normal = normal->next;
        // 思维是先创建点，再拼接
        // 并且指针要往下指
    }
    // cout<<list->head->next->next<<endl;
    return list;
}

int getIndexofList(int data,List* list){
    listNode* p;
    p = list->head;
    int i=0;
    while(p!=NULL&&p->Data!=data){//因为头节点存储了数据，所以条件不能写p=p.next
        i++;
        p = p->next;
    }
    return i;
}

List* insertList(int data,int i,List* list){
    if(i==0){
        listNode* node;
        node = new_listNode(data);
        node->next = list->head;
        list->head = node;
    }
    else {
        listNode* p;
        p = list->head;
        for(int j=0;j<i-1;j++){
            p = p->next;
        }
        listNode* node;
        node = new_listNode(data);
        node->next = p->next;
        p->next = node;
    }
    return list;
}

List* change_NodewithData(int data,int change_data,List* list){
    listNode* p;
    p = list->head;
    while(p!=NULL&&p->Data!=data){
        p = p->next;
    }
    p->Data = change_data;
    return list;
}

List* change_NodewithIndex(int i,int change_data,List* list){
    listNode* p;
    p = list->head;
    int j =0;
    while(p!=NULL&&j!=i){
        p = p->next;
        j++;
    }
    p->Data = change_data;
    return list;
}

int List_isempty(List* list){
    if(list->head->next ==NULL){
        return -1;
    }
    else{
        return 0;
    }
}

int delete_List(int i,List* list){
    if(List_isempty(list)){
        return -1;
    }
    else{
        if(i==0){
            list->head->Data = list->head->next->Data;
            listNode* p = list->head->next;
            list->head->next = list->head->next->next;
            free(p);
        }
        else {
            listNode* p,*q;
            p = list->head;
            for(int j=0;j<i-1;j++){
                p = p->next;
            }
            q = p->next;
            p->next = p->next->next;
            free(q);
        }   
    }
    return 1;
}

void print(List* list){
    listNode* p;
    p = list->head;
    while(p!=NULL){
        cout<<p->Data<<endl;
        p = p->next;
    }
}

int main(){
    List* list;
    list = creatNewList(10);
    // print(list);
    // cout<<getIndexofList(4,list)<<endl;
    list = insertList(100,3,list);
    print(list);
    cout<<endl;
    delete_List(1,list);
    print(list);
}