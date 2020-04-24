/**@���ݽṹ:��->�������������� 
 **@����:9761��  
 **@�洢�ṹ������ 
 **/
 
//���ļ���ʵ����������������
	/**1.���������� 
	 **2.����������������ͷ������
		ThreadNode* FirstNode(ThreadNode* p)	//����pΪ���ڵ��������������ĵ�һ����� 
		ThreadNode* NextNode(ThreadNode* p)		//���������������p����һ����� 
		void InOrder(ThreadTree T)				//�����������������T	
		ThreadNode* LastNode(ThreadNode* p)		//����pΪ���ڵ������������������һ�����	 
		ThreadNode* PreNode(ThreadNode* p)		//���������������p��ǰһ����� 
		void RevInOrder(ThreadTree T)			//��������������б��������� 
	*/ 
//�Ȳ��� 
#include<cstdio>
typedef int ElementType; 
typedef struct ThreadNode{
	ElementType data;
	ThreadNode *lchild,*rchild;
	int ltag,rtag;		//tagΪ0��ʾָ��������Һ��ӣ�Ϊ1��ʾָ��������е�ǰ�����ߺ�� 
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
//������������������ 
void CreateInThread(ThreadTree T){
	ThreadTree pre=NULL;
	if(T!=NULL){
		InThread(T,pre);
		pre->rchild=NULL;
		pre->rtag=1;
	}
}
//������������� 
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
//����������������
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

