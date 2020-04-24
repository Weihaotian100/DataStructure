/**@���ݽṹ:��->������ 
 **@����:9761��  
 **@�洢�ṹ������ 
 **/
 
//���ļ���ʵ���˶�������
	/*1.ǰ �� ��������Լ�������� �ĵݹ��㷨�ͷǵݹ��㷨 
		**PreOrder()
		**InOrder()
		**PostOrder() 
		**LevelOrder()
	*/ 
//�Ȳ��� 
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
typedef int ElementType;
//���������Ľṹ�� 
typedef struct BNode{
	ElementType data;
	BNode *lchild,*rchild;
}BNode,*BTree;
//�������������Ľṹ��

void visit(BTree T){
	printf("%d\n",T->data);
}
//ǰ��������ݹ�ʵ�� 
void PreOrder(BTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	} 
}

//ǰ��������ǵݹ�ʵ�� 
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
//����������ݹ�ʵ��
void InOrder(BTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);	
	}
} 
//����������ǵݹ�ʵ�� 
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
//����������ݹ�ʵ�� 
void  PostOrder(BTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
//����������ǵݹ�ʵ��
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
//������� 
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
