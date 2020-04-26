/**@���ݽṹ:��->AVL�� 
 **@����:9761��  
 **@�洢�ṹ������ 
 **/
 
//���ļ���ʵ����AVL����
	/*
		1.����
		2.����
		3.���� 
	*/
	 
//�Ȳ���
#include<cstdio>
#include<stdlib.h>
typedef int ElementType;
typedef struct node{
	int height;
	ElementType data;
	node* lchild;
	node* rchild;
}node,AVLTree;
//����һ���µĽ�� 
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
//������rootΪ���ڵ�������ĸ߶� 
int getHeight(node* root){
	if(root==NULL)
		return 0;
	return root->height;
} 
//����root��ƽ������
int getBalanceFactor(node* root){
	return root->lchild->height-root->rchild->height;
} 
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
//������rootΪ���ڵ�������ĸ߶�
void updateHeight(node* root){
	root->height=max(root->rchild->height,root->lchild->height)+1;
} 
//����AVL����������Ϊx�Ľ�� 
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
//��������
void LeftRotation(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 
//��������
void RightRotation(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp; 
} 
//��AVL���в���һ��������Ϊx���½�㣬������AVL������
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
//����AVL��
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
