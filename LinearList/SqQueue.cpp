/**@���ݽṹ:����->ѭ������ 
 **@����:9761�� 
 **@ʵ�ַ�ʽ:��̬����(������̶���С�����飬���鳤�Ȳ��ɱ�) 
 **@rearָ�����һ��Ԫ�ص���һ��Ԫ�� 
 **/ 

//һ�����ݽṹ�Ĳ����޷� ����ɾ������ɾ�Ĳ�
//���ļ���ʵ����ѭ�����е�
	/*1.init
 	**2.enQueue 
	**3.deQueue
	**4.getHead 
	**5.isEmpty
	*/ 
//�Ȳ��� 
#include<cstdio>
#define MAX_SIZE 10
typedef int ElementType;
typedef struct SqQueue{
	ElementType data[MAX_SIZE];
	int front,rear;
//	int size;	�����ж϶ӿջ��߶���
//	int tag;	������	,���֮����Ϊ1,����֮����Ϊ0		
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
