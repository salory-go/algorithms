#include<cstdio>
#include<iostream>
using namespace std;

typedef struct TNode
{
    int Data;
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

int main(){
    TNode* tree;
    tree =initTree(tree,2);
    
    tree = insertBinTree(tree,3);
    tree = insertBinTree(tree,4);
    tree = insertBinTree(tree,1);
    // cout<<tree->left->Data<<endl;
    
    printBinTreeRight(tree);
}
