
/**@数据结构:线性表->静态链表
 **@作者:9761滴 
 **@是否带头结点:是 
 **/
 


#include<cstdio>
#include<stdlib.h>
#define MAXSIZE 10
typedef int ElementType;

//静态链表结点的结构,SLinkList[MAXSIZE]表示声明了一个maxsize大小的数组 
typedef struct SNode{
	ElementType data;
	int next;
}SNode,SLinkList[MAXSIZE]; 

//静态链表的初始化
bool InitList(SLinkList &L){
	L[0].next=-1;				//-1表示该结点后续无结点 
	for(int i=1;i<MAXSIZE;i++){
		L[i].next=-2;			//-2表示该结点未使用，方便后续插入操作 
	}
	return true;
}
int main(){
	return 0;
}
