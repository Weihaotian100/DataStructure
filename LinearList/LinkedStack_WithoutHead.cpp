/**@数据结构:栈->链栈 
 **@作者:9761滴 
 **@是否带头结点:否  
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
bool isEmpty(LStack LS);
bool init(LStack &LS){
	LS==NULL;
} 
bool push(LStack &LS,ElementType x){
	if(LS==NULL){
		LS=(LNode*)malloc(sizeof(LNode));
		if(LS==NULL)
			return false;
		LS->data=x;
		LS->next=NULL;
	}
	else{
		LNode *LN=(LNode*)malloc(sizeof(LNode));
		if(LN==NULL)
			return false;
		LN->data=x;
		LN->next=LS;
		LS=LN;
	}
	return true;
}
bool pop(LStack &LS,ElementType &x){
	if(isEmpty(LS)){
		printf("Stack is already empty");
		return false;
	}
	else{
		LNode *LN=LS;
		x=LN->data;
		LS=LS->next;
		free(LN);
	}
	return true;
}
ElementType getHead(LStack LS){
	if(isEmpty(LS)){
		printf("Stack is already empty");
		return false;
	}
	else{
		ElementType x=LS->data;
		return x;
	}

}
bool isEmpty(LStack LS){
	return LS==NULL;
}
int main(){
//	LStack LS;
//	init(LS);//不初始化不会报错，LS初始化本来就是将它置为NULL 
//	for(int i=0;i<10;i++){
//		push(LS,10*i);
//	}
//	for(int i=0;i<10;i++){
//		int x;
//		pop(LS,x);
//		printf("%d\n",x);
//	}
//	return 0;
} 
