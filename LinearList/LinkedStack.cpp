/**@数据结构:栈->链栈 
 **@作者:9761滴 
 **@是否带头结点:是 
 **/ 

//本文件中实现了链栈的
	/*1.init
 	**2.push
	**3.pop
	**4.getHead 
	**5.isEmpty
	*/ 
//等操作 
#include<cstdio>
#include<stdlib.h> 

typedef int ElementType; 
typedef struct LNode{
	ElementType data;
	LNode *next;
}LNode,*LStack;
bool isEmpty(LStack &LS);
bool init(LStack &LS){
	LS=(LNode*)malloc(sizeof(LNode));
	if(LS==NULL){
		return false;
	}
	LS->next=NULL;
	return true;
}
bool push(LStack &LS,ElementType x){
	LNode* LN=(LNode*)malloc(sizeof(LNode));
	if(LN==NULL)
		return false;
	LN->next=LS->next;
	LN->data=x;
	LS->next=LN;
}

bool pop(LStack &LS,ElementType &x){
	if(isEmpty(LS))
		return false;
	LNode* LN=LS->next;
	LS->next=LS->next->next;
	x=LN->data;
	free(LN);
}

ElementType getHead(LStack &LS){
	if(isEmpty(LS)){
		printf("Stack is already empty");
		return -1;
	}
	return LS->next->data;
}
bool isEmpty(LStack &LS){
	return LS->next==NULL;
}
int main(){
//	LStack LS;
//	init(LS);//不初始化会 报错，因为访问push操作会访问LS->next 
//	for(int i=0;i<10;i++){
//		push(LS,10*i);
//	}
//	for(int i=0;i<10;i++){
//		int x;
//		pop(LS,x);
//		printf("%d\n",x);
//	}
	return 0;
}
