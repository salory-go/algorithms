#include<cstdio>
#include<iostream>
using namespace std;

#define max 12

typedef struct TNode
{
    int Data=0;
    TNode* left;
    TNode* right;
}TNode;

TNode* initTree(TNode* node,int key){
    node = (TNode*)malloc(sizeof(TNode));
    node->Data = key;
    node->left =NULL;
    node->right=NULL;
    return node;
}

TNode* insertBinTree(TNode* tree,int data){
    if(!tree){
        tree = (TNode*)malloc(sizeof(TNode));
        tree->Data = data;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        if (tree->Data>data){
            tree->left = insertBinTree(tree->left,data);
        }
        else if (tree->Data<data){
            tree->right = insertBinTree(tree->right,data);
        }
        else;
    }
    return tree;
}

int BinTreeFindMax(TNode* tree){
    int Max = tree->Data;
    if(!tree->right){
        return tree->Data;
    }
    else{
        Max = BinTreeFindMax(tree->right);
    }
    return Max;
}
int BinTreeFindMin(TNode* tree){
    int Min = tree->Data;
    if(!tree->left){
        return tree->Data;
    }
    else{
        Min = BinTreeFindMax(tree->left);
    }
    return Min;
}
TNode* BinTreeFind(TNode* tree,int data){
    TNode* result;
    if(tree->Data == data){
        return tree;
    }
    else if(data<tree->Data){
        result = BinTreeFind(tree->left,data);
    }
    else if(data>tree->Data){
        result = BinTreeFind(tree->right,data);
    }
    return result;
}

TNode* BinTreeDelete(TNode* tree,int data){
    TNode* node;
    node = initTree(node,1);
    if(!tree){
        cout<<"not found"<<endl;
    }
    else{
        if(data<tree->Data){
            tree->left = BinTreeDelete(tree->left,data);
        }
        else if(data>tree->Data){
            tree->right = BinTreeDelete(tree->right,data);
        }
        else{
            if(tree->left&&tree->right){
                node->Data = BinTreeFindMin(tree->right);
                tree->Data = node->Data;
                tree->right = BinTreeDelete(tree->right,tree->Data);
            }
            else{
                node = tree;
                if(!tree->left){
                    tree = tree->right;
                }
                else{
                    tree = tree->left;
                }
                free(node);
            }
        }
    }
    return tree;
}

void printBinTreeLeft(TNode* node){
    if(node->left){
        printBinTreeLeft(node->left);
    }
    cout<<node->Data<<endl;
    if(node->right){
        printBinTreeLeft(node->right);
    }    
}
void printBinTreeMid(TNode* node){
    
    cout<<node->Data<<endl;
    if(node->left){
        printBinTreeMid(node->left);
    }
    if(node->right){
        printBinTreeMid(node->right);
    }    
}
void printBinTreeRight(TNode* node){
    if(node->right){
        printBinTreeRight(node->right);
    }   
    cout<<node->Data<<endl;
    if(node->left){
        printBinTreeRight(node->left);
    }
     
}

typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    TNode* Data;
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

void QNode_add(QNode* quene,TNode* data){
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

TNode* DeleteQ( Queue Q )
{
    Position FrontCell; 
    TNode* FrontElem;
    
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

void printBinTreeByQuene(TNode* node){
    if(!node)return;
    TNode* T; QNode* quene;
    quene = init();
    QNode_add(quene,node);
    while( !IsEmpty(quene)){
        T = DeleteQ(quene);
        cout<<T->Data<<endl;
        
        if(T->left) QNode_add(quene,T->left);
        if(T->right) QNode_add(quene,T->right);
    }
}

int main(){
    TNode* tree;
    tree =initTree(tree,2);
    
    tree = insertBinTree(tree,3);
    tree = insertBinTree(tree,4);
    tree = insertBinTree(tree,1);
    // cout<<tree->left->Data<<endl;
    BinTreeDelete(tree,3);
    printBinTreeByQuene(tree);
}
