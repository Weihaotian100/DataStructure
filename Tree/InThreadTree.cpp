/**@数据结构:树->中序线索二叉树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了线索二叉树的
	/**1.中序线索化 
	 **2.线索二叉树的正向和反向遍历
		ThreadNode* FirstNode(ThreadNode* p)	//找以p为根节点的树的中序遍历的第一个结点 
		ThreadNode* NextNode(ThreadNode* p)		//找中序遍历序列中p的下一个结点 
		void InOrder(ThreadTree T)				//中序遍历线索二叉树T	
		ThreadNode* LastNode(ThreadNode* p)		//找以p为根节点的树的中序遍历的最后一个结点	 
		ThreadNode* PreNode(ThreadNode* p)		//找中序遍历序列中p的前一个结点 
		void RevInOrder(ThreadTree T)			//反向中序遍历序列遍历二叉树 
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
void InThread(ThreadTree &p,ThreadTree &pre){
	if(p!=NULL){
		InThread(p->lchild,pre);
		if(p->lchild==NULL){
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre->rchild==NULL&&pre!=NULL){
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		InThread(p->rchild,pre);
	}
}
//建立中序线索二叉树 
void CreateInThread(ThreadTree T){
	ThreadTree pre=NULL;
	if(T!=NULL){
		InThread(T,pre);
		pre->rchild=NULL;
		pre->rtag=1;
	}
}
//遍历中序二叉树 
ThreadNode* FirstNode(ThreadNode* p){
	while(p->ltag==0)
		p=p->lchild;
	return p;
}
ThreadNode* NextNode(ThreadNode* p){
	if(p->rtag==1)
		return p->rchild;
	else{
		return FirstNode(p->rchild);
	}
}
void InOrder(ThreadTree T){
	for(ThreadNode* p=FirstNode(T);p!=NULL;p=NextNode(p)){
		visit(p);
	}
}
//反向遍历中序二叉树
ThreadNode* LastNode(ThreadNode* p){
	while(p->rtag==0)
		p=p->rchild;
	return p;
}
ThreadNode* PreNode(ThreadNode* p){
	if(p->ltag==1)
		return p->lchild;
	else
		return LastNode(p->lchild);
} 
void RevInOrder(ThreadTree T){
	for(ThreadNode* p=LastNode(T);p!=NULL;p=PreNode(p)){
		visit(p);
	}
}
int main(){
	return 0;
}

