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
//	init(LS);//����ʼ���� ������Ϊ����push���������LS->next 
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
