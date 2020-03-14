/**@���ݽṹ:����->������ 
 **@����:9761�� 
 **@����ͷ��� 
 **/ 

//���ļ���ʵ���������е�
	/*1.init
 	**2.enQueue 
	**3.deQueue
	**4.getHead 
	**5.isEmpty
	*/ 
//�Ȳ��� 
#include<cstdio>
#include<stdlib.h>
typedef int ElementType;
typedef struct LNode{
	ElementType data;
	LNode* next;
}LNode;
typedef struct LQueue{
	LNode* front;
	LNode* rear;
}LQueue;
bool init(LQueue &Q){
	Q.front=Q.rear=NULL;
	return true;
}
bool enQueue(LQueue &Q,ElementType x){
	LNode* L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->data=x;
	L->next=NULL;
	if(Q.rear==NULL){
		Q.front=Q.rear=L;
	}
	else{
		Q.rear->next=L;
		Q.rear=L;
	}

	return true;
}
bool deQueue(LQueue &Q,ElementType &x){
	if(Q.front==Q.rear==NULL)
		return false;
	LNode* L=Q.front;
	x=L->data;
	if(Q.rear==L)			//���ɾ���������һ����㣬��Ҫ�޸�rear��ʹ��ָ��ͷ��� 
		Q.rear=Q.front==NULL;
	free(L);
	return true;
}
bool getHead(LQueue Q,ElementType &x){
	if(Q.front==Q.rear==NULL)
		return false;
	x=Q.front->data;
	return true;
}
bool isEmpty(LQueue Q) {
	if(Q.front==Q.rear==NULL)
		return true;
	return false;
}
int main(){
	LQueue Q;
	init(Q);
	return 0;
}
