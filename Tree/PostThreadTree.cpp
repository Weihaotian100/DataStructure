/**@���ݽṹ:��->�������������� 
 **@����:9761��  
 **@�洢�ṹ������ 
 **/
 
//���ļ���ʵ��������������������
	/**1.���������� 
	 **2.����������������ͷ������
		���������������Ƚ���ʵ��������� ,����ʵ�֣���Ҫʹ���������� 	
		ThreadNode* LastNode(ThreadNode* p)		//����pΪ���ڵ������������������һ�����	 
		ThreadNode* PreNode(ThreadNode* p)		//���������������p��ǰһ����� 
		void RevInOrder(ThreadTree T)			//��������������б��������� 
	*/ 
//�Ȳ���
//������������������
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
//����������������
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
