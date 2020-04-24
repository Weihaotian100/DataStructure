/**@数据结构:树->二叉树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了二叉树的
	/*1.前 中 后序遍历以及层序遍历 的递归算法和非递归算法 
		**PreOrder()
		**InOrder()
		**PostOrder() 
		**LevelOrder()
	*/ 
//等操作 
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
typedef int ElementType;
//二叉树结点的结构体 
typedef struct BNode{
	ElementType data;
	BNode *lchild,*rchild;
}BNode,*BTree;
//线索二叉树结点的结构体

void visit(BTree T){
	printf("%d\n",T->data);
}
//前序遍历，递归实现 
void PreOrder(BTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	} 
}

//前序遍历，非递归实现 
void PreOrder2(BTree T){
	stack<BNode*> S;
	BTree P=T;
	while(P!=NULL||!S.empty()){
		if(P){
			visit(P);
			S.push(P);
			P=P->lchild;
		}
		else{
			P=S.top();
			S.pop();
			P=P->rchild;
		}
	}
}
//中序遍历，递归实现
void InOrder(BTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);	
	}
} 
//中序遍历，非递归实现 
void InOrder2(BTree T){
	stack<BNode*> S;
	BTree P=T;
	while(!S.empty()||P!=NULL){
		if(P!=NULL){
			S.push(P);
			P=P->lchild;
		}
		else{
			P=S.top();
			S.pop();
			visit(P);
			P=P->rchild;
		}
	}
}
//后序遍历，递归实现 
void  PostOrder(BTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
//后序遍历，非递归实现
void  PostOrder2(BTree T){
	stack<BNode*> S;
	BTree P=T;
	BTree R=NULL;
	while(P!=NULL||!S.empty()){
		if(P!=NULL){
			S.push(P);
			P=P->lchild;
		}
		else{
			P=S.top();
			if(P->rchild==NULL){
				visit(P);
				S.pop();
				R=P;
				P=NULL;
			}
			else if(R!=P->rchild){
				P=P->rchild;
				S.push(P);
				P=P->lchild;
			}

		}
	}
}
//层序遍历 
void LevelOrder(BTree T){
	queue<BNode*> Q;
	Q.push(T);
	BTree P;
	while(!Q.empty()){
		P=Q.front();
		Q.pop();
		visit(P);
		if(P->lchild){
			Q.push(P->lchild);
		}
		if(P->rchild){
			Q.push(P->rchild);
		}
	}
}
int main(){
	return 0;
} 
