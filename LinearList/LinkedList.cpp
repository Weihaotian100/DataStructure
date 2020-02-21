
/**@数据结构:线性表->单链表
 **@作者:9761滴 
 **@是否带头结点:是 
 **/
 
//一种数据结构的操作无非 创建删除，增删改查
//本文件中实现了单链表的
	/*1.创建(即初始化操作) 
	**2.单链表的建立 
			@尾插法
			@头插法 
	**3.查找元素(分按位查找和按值查找) 
	**4.插入操作
			*****位序指的是从1开始的整数 
			单链表的插入操作相对复杂一些，包括： 
			@	按位序插入
			@ 	指定结点的后插操作
			@	指定结点的前插操作 
	**5.删除操作
			@	按位序删除
			@ 	指定结点删除 
	**6.输出整个顺序表 
	*/ 
//等操作 

#include<cstdio>
#include<stdlib.h>
typedef int ElementType;

/** 链表结构体 
**Linklist 是为了有时候强调参数是一个链表，而LNode*强调一个结点 
*/ 
typedef struct LNode{
	ElementType data;
	struct LNode* next;
}LNode,*LinkList;
bool InsertAfter(LNode *p,ElementType e);

//初始化链表 
bool InitList(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)//内存未成功分配 ，可能原因，内存耗尽 
		return false;
	L->next=NULL;
	return true;
}

//单链表的建立	@	尾插法 

//单链表的查找	@	按位序查找
	//&此方法规定可以查找头结点，即位序从0开始 
LNode* GetElem(LinkList L,int i){
	if(i<0)
		return NULL;
	LNode *pre=L;
	int pos=0;
	while(pre!=NULL&&pos<i){
		pre=pre->next;
		pos++;
	}
	return pre;
	 
} 
//单链表的查找	@	按值查找
LNode* LocateElem(LinkList L,ElementType e){
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	} 
	return p;
} 
//插入操作	@	按位序插入
bool Insert(LinkList &L,int i,ElementType e){
	if(i<1)
		return false;
/**找指定位序的前一个位置 
	LNode* pre=L; 				
	int pos=0;				 
	while(pre!=NULL&&pos<i-1){
		pre=pre->next;
		pos++;
	}
	if(pre==NULL)	 
		return false;
**/
	LNode* pre=GetElem(L,i-1); 
/** 修改结点之间链接关系，实现插入
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;//内存分配失败 
	s->data=e;
	s->next=pre->next;
	pre->next=s; 
	return true;
**/
	return InsertAfter(pre,e);

} 
//插入操作	@	指定结点后插
bool InsertAfter(LNode *p,ElementType e){
	if(p==NULL)
		return false;
	LNode *q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)
		return false;//内存分配失败 
	q->data=e;
	q->next=p->next;
	p->next=q;
	return true;
} 
//插入操作	@	指定结点前插
bool InsertBefore(LNode *p,ElementType e){
	if(p==NULL)
		return false;
	LNode *q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)
		return false;//内存分配失败 
	q->next=p->next;
	p->next=q;
	q->data=p->data;
	p->data=e;
	return true;
} 

//删除操作	@	按位序删除
bool Delete(LinkList &L,int i,ElementType &e){
	if(i<1)
		return false;
/**找指定位序的前一个位置 
	LNode* pre=L; 				
	int pos=0;				 
	while(pre!=NULL&&pos<i-1){
		pre=pre->next;
		pos++;
	}

**/
	LNode *pre=GetElem(L,i-1);
	//删除结点
	if(pre==NULL)	 				//要删除的结点不存在 
		return false;
	if(pre->next==NULL)				//要删除的结点不存在 
		return false; 
	LNode* q=pre->next;
	e=q->data; 
	pre->next=q->next; 
	free(q);
	return true;
} 
//删除操作	@删除指定结点	
	//&此方法有局限性，如果p是最后一个结点,则无法成功删除, 但此方法的时间复杂度为o(1) 
bool DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;
	p->data=q->data;
	p->next=q->next;
	free(q);
	return true;	
} 
int main(){
	LinkList L;
	printf("%d",InitList(L));
	return 0;
} 
