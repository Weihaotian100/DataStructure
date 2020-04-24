/**@���ݽṹ:��->�������������� 
 **@����:9761��  
 **@�洢�ṹ������ 
 **/
 
//���ļ���ʵ��������������������
	/**1.���������� 
	 **2.����������������ͷ������
		ThreadNode* FirstNode(ThreadNode* p)	//����pΪ���ڵ��������������ĵ�һ����� 
		ThreadNode* NextNode(ThreadNode* p)		//���������������p����һ����� 
		void PreOrder(ThreadTree T)				//�����������������T	
		��������������Ƚ���ʵ�ַ������ ,����ʵ�֣���Ҫʹ���������� 
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
//������������������ 
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
//������������� 
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
