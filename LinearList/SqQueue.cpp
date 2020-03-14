/**@数据结构:队列->循环队列 
 **@作者:9761滴 
 **@实现方式:静态分配(即分配固定大小的数组，数组长度不可变) 
 **@rear指向最后一个元素的下一个元素 
 **/ 

//一种数据结构的操作无非 创建删除，增删改查
//本文件中实现了循环队列的
	/*1.init
 	**2.enQueue 
	**3.deQueue
	**4.getHead 
	**5.isEmpty
	*/ 
//等操作 
#include<cstdio>
#define MAX_SIZE 10
typedef int ElementType;
typedef struct SqQueue{
	ElementType data[MAX_SIZE];
	int front,rear;
//	int size;	方便判断队空或者队满
//	int tag;	方案二	,入队之后置为1,出队之后置为0		
}Queue;
bool init(Queue &Q){
	Q.front=Q.rear=0;
//  Q.size=0; 
//	Q.tag=0;
	return true;
}
bool enQueue(Queue &Q,ElementType x){
	if((Q.rear+1)%MAX_SIZE==Q.front)
//		if(size==MAX_SIZE)
//		if(Q.tag==1&&Q.rear=Q.front)
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MAX_SIZE;
//	Q.size++;
//	Q.tag=1;
	return true;
}
bool deQueue(Queue &Q,ElementType &x){
	if(Q.rear==Q.front)
//	if(Q.size==0)
//	if(Q.tag==0&&Q.rear=Q.front)
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MAX_SIZE;
//	Q.size--;
//	Q.tag=0;
	return true;
}
bool getHead(Queue Q,ElementType &x){
	if(Q.front==Q.rear)
//	if(Q.size==0)
//	if(Q.tag==0&&Q.rear=Q.front)
		return false;
	x=Q.data[Q.front];
	return true;
}
bool isEmpty(Queue Q){
	if(Q.front==Q.rear)
//	if(Q.size==0)
		return true;
	return false;
}
int main(){
	Queue Q;
	init(Q);
	return 0;
}
