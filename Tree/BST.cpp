/**@数据结构:树->二叉排序树 
 **@作者:9761滴  
 **@存储结构：链表 
 **/
 
//本文件中实现了二叉排序树的
	/**1.查找 
	 **2.插入 
	 **3.删除
	 **4.构造 
	*/ 
//等操作
#include<cstdio>
#include<cstdlib>
typedef int ElementType;
typedef struct node{
	ElementType data;
	node* left;
	node* right;
}node,*BST;
//查找，递归实现,间复杂度O(h),h为递归层数 
node* find(BST T,ElementType X){
	if(!T)
		return NULL;
	if(X>T->data)
		find(T->right,X);
	else if(X<T->data)
		find(T->left,X);
	else
		return T;
}
//查找，非递归实现,空间复杂度O(1) 
node* find2(BST T,ElementType X){
	while(T){
		if(X>T->data)
			T=T->right;
		else if(X<T->data)
			T=T->left;
		else
			return T;
	}
	return NULL;
} 
//插入,递归算法实现,空间复杂度O(h) 
bool insert(BST &T,ElementType X){
	if(!T){
		node* p=(node*)malloc(sizeof(node));
		p->data=X;
		p->left=p->right=NULL;
		T=p;
		return true;
	}
	if(T->data==X)
		return false;
	if(X>T->data)
		insert(T->right,X);
	else
		insert(T->left,X);
} 
//插入，非递归算法实现,空间复杂度O(1) 
bool insert2(BST &T,ElementType X){
	while(T){
		if(T->data==X)
			return false;
		if(X<T->data)
			T=T->left;
		else
			T=T->right;
	} 
	return true;
}
node* findMax(BST T){
	while(T->right!=NULL){
		T=T->right;
	}
	return T;
}
//删除			//删除完了之后需要保持BST的特性 
bool deleteElem(BST &T,ElementType X){
	node* pre=NULL;
	int mark;		//记录T是pre的左还是右孩子,0左，1右 
	while(T){
		if(T->data==X){
			if(T->left==NULL&&T->right==NULL){
				free(T);
				if(pre!=NULL){
					if(mark==0)
						pre->left=NULL;
					else
						pre->right=NULL;
				}
				return true;
			}
			else if(T->left!=NULL&&T->right==NULL){
				if(pre!=NULL){
					if(mark==0){
						pre->left=T->left;
						free(T); 
					}
					else{
						pre->right=T->left;
						free(T);
					}	
					return true;
				}
				else{
					free(T);
					return true;
				}	
			}
			else if(T->right!=NULL&&T->left==NULL){
				if(pre!=NULL){
					if(mark==0){
						pre->left=T->right;
						free(T); 
					}
					else{
						pre->right=T->right;
						free(T);
					}	
					return true;
				}
				else{
					free(T);
					return true;
				}
			}
			else{
				node* p=findMax(T->left);
				T->data=p->data;
				if(p->left!=NULL){
					p->data=p->left->data;
					free(p->left);
					p->left=NULL;
				}
				else
					free(p);
				return true;
			}
		}
		else if(T->data>X){
			pre=T;
			mark=0;
			T=T->left;
		} 
		else{
			pre=T;
			mark=1;
			T=T->right;
		} 
	}
	return false;
}
//BST的构造
void CreateBST(BST &T,ElementType X[],int n){
	T=NULL;
	for(int i=0;i<n;i++){
		insert(T,X[i]);
	}
}
void visit(node* N){
	if(N!=NULL)
		printf("%d",N->data);
	else
		printf("NULL");
}
int main(){
//	测试代码 
//	BST T;
//	int X[5]={3,2,5,4,1};
//	CreateBST(T,X,5);
//	BST tem=T;
//	deleteElem(tem,4);
//	visit(find(T,4));
	return 0;
} 
