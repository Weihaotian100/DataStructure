#include<cstdio>
#include<stdlib.h> 
#include<cstring>
typedef char ElementType; 
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
bool bracketCheck(char str[],int length){
	LStack stack;
	init(stack);
	for(int i=0;i<length;i++){
		char temp=str[i];
		char getPop;
		if(str[i]=='('||str[i]=='['||str[i]=='{')
			push(stack,temp);
		else if(str[i]==')'){
			if(!pop(stack,getPop))
				return false;
			if(getPop!='(')
				return false;
		}
		else if(str[i]==']'){
			if(!pop(stack,getPop))
				return false;
			if(getPop!='[')
				return false;
		}
		else if(str[i]=='}'){
			if(!pop(stack,getPop))
				return false;
			if(getPop!='{')
				return false;
		}
		else
			return false;			
	}
	return isEmpty(stack);
}
int main(){
	char str[]={'{','{','(','(',')',')','[',']','}'};
	printf("%d",bracketCheck(str,strlen(str))); 
	return 0;
} 
