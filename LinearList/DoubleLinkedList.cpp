
/**@数据结构:线性表->双链表
 **@作者:9761滴 
 **@是否带头结点:是 
 **/
 
//一种数据结构的操作无非 创建删除，增删改查
//本文件中实现了双链表的
	/*1.初始化
	**2.插入(后插)
	**3.删除(后删)
	**4.销毁
	*/ 
//等操作 
#include<cstdio>
#include<stdlib.h>
typedef int ElementType;

/** 双链表的结点的结构体 
**DLinklist 是为了有时候强调参数是一个双链表，而DNode*强调一个结点 
*/ 
typedef struct DNode{
	ElementType data;
	DNode *prior;
	DNode *next;
}DNode,*DLinkList; 

//初始化链表 
bool InitList(DLinkList &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)//内存未成功分配 ，可能原因，内存耗尽 
		return false;
	L->prior=NULL;
	L->next=NULL; 
	return true;
}

//插入操作	@	指定结点后插
bool InsertAfter(DNode *p,ElementType e){
	if(p==NULL)
		return false;
	DNode *q=(DNode*)malloc(sizeof(DNode));
	if(q==NULL)
		return false;
	q->data=e;
	q->next=p->next;
	if(q->next!=NULL)
		q->next->prior=q;
	q->prior=p;
	p->next=q;
	return true;
}

//删除操作	@	指定结点后删
bool DeleteAfter(DNode *p){
	if(p==NULL||p->next==NULL)
		return false;
	DNode *q=p->next;
	p->next=p->next->next;
	if(p->next->next!=NULL)
		p->next->next->prior=p;
	free(q);
	return true;
	
} 

//销毁表
void Destory(DLinkList &L){
	while(L->next!=NULL){
		DeleteAfter(L);
	}
	free(L);
	L=NULL;
	
} 



int main(){
	return 0;
}
