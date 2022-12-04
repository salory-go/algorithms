#include<cstdio>
#include<iostream>
using namespace std;

#define max 4

typedef struct Quene{
    int Data[max];
    int Front;
    int Rear;
}Quene;
    // 设定为Front和Rear都指向的是空

Quene* quene_creat(){
    Quene* quene;
    quene = (Quene*)malloc(sizeof(Quene));
    quene->Front = max-1;
    quene->Rear = 0;
    for(int i=0;i<max;i++){
        quene->Data[i] = 0;
    }
    return quene;
}

int Quene_isempty(Quene* quene){
    return (quene->Front+1)%max==quene->Rear;
}
int Quene_isfull(Quene* quene){
    return quene->Rear==quene->Front;
}

void Quene_add(Quene* quene,int data){
    if(!Quene_isfull(quene)){
        quene->Data[quene->Rear] = data;
        quene->Rear = (quene->Rear+1)%max;
    }
}

int Quene_delete(Quene* quene){
    if(!Quene_isempty(quene)){
        quene->Front = (quene->Front+1)%max;
        int a = quene->Data[quene->Front];
        quene->Data[quene->Front] = 0;
        return a;
    }
    return 0;
}

int main(){
    Quene* quene;
    quene = quene_creat();
    Quene_add(quene,10);
    Quene_add(quene,10);
    Quene_add(quene,10);
    cout<<Quene_delete(quene)<<endl;
    for(int i=0;i<max;i++){
        cout<<"Data[i] is:"<<quene->Data[i]<<endl;
    }
}
