/**@数据结构:树->后序线索二叉树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了先序线索二叉树的
	/**1.后序线索化 
	 **2.线索二叉树的正向和反向遍历
		后序线索二叉树比较难实现正向遍历 ,若想实现，需要使用三叉链表 	
		ThreadNode* LastNode(ThreadNode* p)		//找以p为根节点的树的中序遍历的最后一个结点	 
		ThreadNode* PreNode(ThreadNode* p)		//找中序遍历序列中p的前一个结点 
		void RevInOrder(ThreadTree T)			//反向中序遍历序列遍历二叉树 
	*/ 
//等操作
//建立后续线索二叉树
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
void PostThread(ThreadNode* &p,ThreadNode* &pre){
	if(p!=NULL){
		PostThread(p->lchild,pre);
		PostThread(p->rchild,pre);
		if(p->lchild==NULL){
			p->lchild=pre;
			p->ltag=1;
		} 
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rtag=1;
			pre->rchild=p;
		}
		pre=p;
	}
}
void CreatePostThread(ThreadTree &T){
	if(T!=NULL){
		ThreadNode* pre=NULL;
		PostThread(T,pre);
		if(pre->rchild==NULL)
			pre->rtag=1;
	}
}
//反向遍历后序二叉树
ThreadNode* LastNode(ThreadNode* p){
	return p;
}
ThreadNode* PreNode(ThreadNode* p){
	if(p->ltag==1)
		return p->lchild;
	else{
		if(p->rtag==0)
			return p->rchild;
		else
			return p->lchild;
	}
} 
void RevPostOrder(ThreadTree T){
	for(ThreadNode* p=LastNode(T);p!=NULL;p=PreNode(p)){
		visit(p);
	}
}
int main(){
	return 0;
}
