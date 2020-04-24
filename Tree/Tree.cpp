/**@数据结构:树
 **@作者:9761滴  
 **@存储结构：1.双亲表示法
 			  2.孩子表示法
			  3.兄弟结点表示法 
 **/
 
//本文件中实现了树的三种存储结构 
#include<cstdio>
typedef int ElementType;
#define MAX_SIZE 10 
//双亲表示法,根节点下标为0，其伪指针域为-1 
//typedef struct{
//	ElementType data;
//	int parent;
//}node;
//typedef struct{
//	node N[MAX_SIZE];
//	int n;
//}Tree;

//孩子表示法
//typedef struct child{
//	int n;
//	child* next;	
//}*nextChild;
//typedef struct{
//	ElementType data;
//	child* firstChild;
//}node;
//typedef struct{
//	node N[MAX_SIZE];
//	int n,r;			//结点数量和根节点	
//}Tree; 

//孩子兄弟表示法
typedef struct node{
	ElementType data;
	struct node* firstChild;
	struct node* nextSibling;	
}node,*Tree;
void visit(node* n){
	printf("%d ",n->data);
}

int main(){
	return 0;
} 
