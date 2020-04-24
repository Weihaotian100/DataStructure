/**@数据结构:树->先序线索二叉树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了先序线索二叉树的
	/**1.先序线索化 
	 **2.线索二叉树的正向和反向遍历
		ThreadNode* FirstNode(ThreadNode* p)	//找以p为根节点的树的先序遍历的第一个结点 
		ThreadNode* NextNode(ThreadNode* p)		//找先序遍历序列中p的下一个结点 
		void PreOrder(ThreadTree T)				//中序遍历线索二叉树T	
		先序遍历二叉树比较难实现反向遍历 ,若想实现，需要使用三叉链表 
	*/ 
//等操作
#include<cstdio>
typedef int ElementType; 
typedef struct ThreadNode{
	ElementType data;
	ThreadNode *lchild,*rchild;
	int ltag,rtag;		//tag为0表示指向左或者右孩子，为1表示指向遍历序列的前驱或者后继 
}ThreadNode,*ThreadTree; 
void visit(ThreadNode* P){
	printf("%d ",P->data);
}
//建立先序线索二叉树 
void PreThread(ThreadNode* &p,ThreadNode* &pre){
	if(p!=NULL){
		if(p->lchild==NULL){
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		if(p->ltag!=1)
			PreThread(p->lchild,pre);
		PreThread(p->rchild,pre); 
	}
}
void CreatePreThread(ThreadTree &T){
	if(T!=NULL){
		ThreadNode* pre=NULL;
		PreThread(T,pre);
		pre->rtag=1;
		pre->rchild=NULL;
	}
}
//遍历先序二叉树 
ThreadNode* FirstNode(ThreadNode* p){
	return p;
}
ThreadNode* NextNode(ThreadNode* p){
	if(p->rtag==1)
		return p->rchild;
	else{
		if(p->ltag==0)
			return FirstNode(p->lchild);
		else
			return FirstNode(p->rchild);
	}
}
void PreOrder(ThreadTree T){
	for(ThreadNode* p=FirstNode(T);p!=NULL;p=NextNode(p)){
		visit(p);
	}
}
int main(){
	return 0;
}
