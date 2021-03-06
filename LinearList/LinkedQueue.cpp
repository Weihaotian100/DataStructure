/**@数据结构:队列->链队列 
 **@作者:9761滴 
 **@带头结点 
 **/ 

//本文件中实现了链队列的
	/*1.init
 	**2.enQueue 
	**3.deQueue
	**4.getHead 
	**5.isEmpty
	*/ 
//等操作 
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
	Q.front=Q.rear=(LNode*)malloc(sizeof(LNode));
	if(Q.front==NULL||Q.rear==NULL)
		return false;
	Q.front->next=NULL;
	return true;
}
bool enQueue(LQueue &Q,ElementType x){
	LNode* L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->data=x;
	L->next=NULL;
	Q.rear->next=L;
	Q.rear=L;
	return true;
}
bool deQueue(LQueue &Q,ElementType &x){
	if(Q.front==Q.rear)
		return false;
	LNode* L=Q.front->next;
	x=L->data;
	Q.front->next=L->next;
	if(Q.rear==L)			//如果删除的是最后一个结点，需要修改rear，使其指向头结点 
		Q.rear=Q.front;
	free(L);
	return true;
}
bool getHead(LQueue Q,ElementType &x){
	if(Q.front->next==Q.rear)
		return false;
	x=Q.front->next->data;
	return true;
}
bool isEmpty(LQueue Q) {
	if(Q.front==Q.rear)
		return true;
	return false;
}
int main(){
	LQueue Q;
	init(Q);
	return 0;
}
