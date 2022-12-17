#include<cstdio>
#include<iostream>
using namespace std;

typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    int Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

QNode* init(){
    QNode* Q;
    Q = (QNode*)malloc(sizeof(QNode));
    Q->Front = Q->Rear = NULL;
    Q->MaxSize = 0;
    return Q;
}

int IsEmpty( Queue Q )
{
    if(Q->Rear ==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void QNode_add(QNode* quene,int data){
    Node* node;
    node = (Node*)malloc(sizeof(node));
    node->Data = data;
    node->Next = NULL;
    if(IsEmpty(quene)){
        quene->Front = node;
        quene->Rear = node;
    }
    else{
        quene->Rear->Next = node;
        quene->Rear = node;
    }
    quene->MaxSize++;
}

int DeleteQ( Queue Q )
{
    Position FrontCell; 
    int FrontElem;
    
    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return 0;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}

int main(){
    QNode* quene;
    quene = init();
    QNode_add(quene,10);
    QNode_add(quene,20);
    QNode_add(quene,30);
    cout<<DeleteQ(quene)<<endl;
    
}