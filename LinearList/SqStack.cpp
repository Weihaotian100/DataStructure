/**@数据结构:栈->顺序栈 
 **@作者:9761滴 
 **@实现方式:静态分配(即分配固定大小的数组，数组长度不可变) 
 **/ 

//一种数据结构的操作无非 创建删除，增删改查
//本文件中实现了顺序栈的
	/*1.init
 	**2.push
	**3.pop
	**4.getHead 
	**5.isEmpty
	*/ 
//等操作 
#include<cstdio>
#define MAX_SIZE 10
typedef int ElementType;
typedef struct{
	ElementType data[MAX_SIZE];
	int top;
}SqStack;
bool isEmpty(SqStack stack);
bool init(SqStack &stack){
	stack.top=-1;
	return true;
}
bool push(SqStack &stack,ElementType x){
	if(stack.top==MAX_SIZE-1)
		return  false;
	stack.data[++stack.top]=x;
	return true;
}
bool pop(SqStack &stack,ElementType &x){
	if(isEmpty(stack))
		return  false;
	x=stack.data[stack.top--];
	return true;
}
ElementType getTop(SqStack stack){
	if(isEmpty(stack)){
		printf("stack is already empty");
		return  -1;
	}
	return stack.data[stack.top];
}
bool isEmpty(SqStack stack){
	return stack.top==-1;
}
int main(){
//	SqStack stack;
//	for(int i=0;i<10;i++){
//		push(stack,10*i);
//	}
//	for(int i=0;i<10;i++){
//		int x;
//		pop(stack,x);
//		printf("%d\n",x);
//	}
	
	return 0;
} 
