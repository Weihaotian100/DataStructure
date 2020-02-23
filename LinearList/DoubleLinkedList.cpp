
/**@���ݽṹ:���Ա�->˫����
 **@����:9761�� 
 **@�Ƿ��ͷ���:�� 
 **/
 
//һ�����ݽṹ�Ĳ����޷� ����ɾ������ɾ�Ĳ�
//���ļ���ʵ����˫�����
	/*1.��ʼ��
	**2.����(���)
	**3.ɾ��(��ɾ)
	**4.����
	*/ 
//�Ȳ��� 
#include<cstdio>
#include<stdlib.h>
typedef int ElementType;

/** ˫����Ľ��Ľṹ�� 
**DLinklist ��Ϊ����ʱ��ǿ��������һ��˫������DNode*ǿ��һ����� 
*/ 
typedef struct DNode{
	ElementType data;
	DNode *prior;
	DNode *next;
}DNode,*DLinkList; 

//��ʼ������ 
bool InitList(DLinkList &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)//�ڴ�δ�ɹ����� ������ԭ���ڴ�ľ� 
		return false;
	L->prior=NULL;
	L->next=NULL; 
	return true;
}

//�������	@	ָ�������
bool InsertAfter(DNode *p,ElementType e){
	if(p==NULL)
		return false;
	DNode *q=(DNode*)malloc(sizeof(DNode));
	if(q==NULL)
		return false;
	q->data=e;
	q->next=p->next;
	if(q->next!=NULL)
		q->next->prior=q;
	q->prior=p;
	p->next=q;
	return true;
}

//ɾ������	@	ָ������ɾ
bool DeleteAfter(DNode *p){
	if(p==NULL||p->next==NULL)
		return false;
	DNode *q=p->next;
	p->next=p->next->next;
	if(p->next->next!=NULL)
		p->next->next->prior=p;
	free(q);
	return true;
	
} 

//���ٱ�
void Destory(DLinkList &L){
	while(L->next!=NULL){
		DeleteAfter(L);
	}
	free(L);
	L=NULL;
	
} 



int main(){
	return 0;
}
