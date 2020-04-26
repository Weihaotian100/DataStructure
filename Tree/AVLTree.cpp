/**@数据结构:树->AVL树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了AVL树的
	/*
		1.查找
		2.插入
		3.创建 
	*/
	 
//等操作
#include<cstdio>
#include<stdlib.h>
typedef int ElementType;
typedef struct node{
	int height;
	ElementType data;
	node* lchild;
	node* rchild;
}node,AVLTree;
//生成一个新的结点 
node* newNode(ElementType x){
	node* p=(node*)malloc(sizeof(node));
	if(p==NULL)
		return NULL;
	p->data=x;
	p->height=1;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
//返回以root为根节点的子树的高度 
int getHeight(node* root){
	if(root==NULL)
		return 0;
	return root->height;
} 
//计算root的平衡因子
int getBalanceFactor(node* root){
	return root->lchild->height-root->rchild->height;
} 
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
//跟新以root为根节点的子树的高度
void updateHeight(node* root){
	root->height=max(root->rchild->height,root->lchild->height)+1;
} 
//查找AVL树中数据域为x的结点 
node* search(node* root,ElementType x){
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(x>root->data) 
		return search(root->rchild,x);
	else
		return search(root->lchild,x);
}
//左旋操作
void LeftRotation(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 
//右旋操作
void RightRotation(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp; 
} 
//往AVL树中插入一个数据域为x的新结点，并保持AVL树特性
bool insert(node* &root,ElementType x){
	node* p=newNode(x);
	if(p==NULL)
		return false;
	if(root==NULL){
		root=p;
		return true;
	}
	if(x>root->data){
		insert(root->rchild,x);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				LeftRotation(root);
			}
			else if(getBalanceFactor(root->rchild)==1){
				RightRotation(root->rchild);
				LeftRotation(root);
			}
		}
	}
	else{
		insert(root->lchild,x);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				RightRotation(root);
			}
			else if(getBalanceFactor(root->lchild)==-1){
				LeftRotation(root->lchild);
				RightRotation(root);
			}
		}
	}
}
//创建AVL树
node* Create(ElementType data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
} 
int main(){
	return 0;
}
