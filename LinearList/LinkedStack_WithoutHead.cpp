/**@���ݽṹ:ջ->��ջ 
 **@����:9761�� 
 **@�Ƿ��ͷ���:��  
 **/ 

//���ļ���ʵ������ջ��
	/*1.init
 	**2.push
	**3.pop
	**4.getHead 
	**5.isEmpty
	*/ 
//�Ȳ���
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
//	init(LS);//����ʼ�����ᱨ��LS��ʼ���������ǽ�����ΪNULL 
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
