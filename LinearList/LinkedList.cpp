
/**@���ݽṹ:���Ա�->������
 **@����:9761�� 
 **@�Ƿ��ͷ���:�� 
 **/
 
//һ�����ݽṹ�Ĳ����޷� ����ɾ������ɾ�Ĳ�
//���ļ���ʵ���˵������
	/*1.����(����ʼ������) 
	**2.������Ľ��� 
			@β�巨
			@ͷ�巨 
	**3.����Ԫ��(�ְ�λ���ҺͰ�ֵ����) 
	**4.�������
			*****λ��ָ���Ǵ�1��ʼ������ 
			������Ĳ��������Ը���һЩ�������� 
			@	��λ�����
			@ 	ָ�����ĺ�����
			@	ָ������ǰ����� 
	**5.ɾ������
			@	��λ��ɾ��
			@ 	ָ�����ɾ�� 
	**6.�������˳��� 
	*/ 
//�Ȳ��� 

#include<cstdio>
#include<stdlib.h>
typedef int ElementType;

/** ����ṹ�� 
**Linklist ��Ϊ����ʱ��ǿ��������һ��������LNode*ǿ��һ����� 
*/ 
typedef struct LNode{
	ElementType data;
	struct LNode* next;
}LNode,*LinkList;
bool InsertAfter(LNode *p,ElementType e);

//��ʼ������ 
bool InitList(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)//�ڴ�δ�ɹ����� ������ԭ���ڴ�ľ� 
		return false;
	L->next=NULL;
	return true;
}

//������Ľ���	@	β�巨 

//������Ĳ���	@	��λ�����
	//&�˷����涨���Բ���ͷ��㣬��λ���0��ʼ 
LNode* GetElem(LinkList L,int i){
	if(i<0)
		return NULL;
	LNode *pre=L;
	int pos=0;
	while(pre!=NULL&&pos<i){
		pre=pre->next;
		pos++;
	}
	return pre;
	 
} 
//������Ĳ���	@	��ֵ����
LNode* LocateElem(LinkList L,ElementType e){
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	} 
	return p;
} 
//�������	@	��λ�����
bool Insert(LinkList &L,int i,ElementType e){
	if(i<1)
		return false;
/**��ָ��λ���ǰһ��λ�� 
	LNode* pre=L; 				
	int pos=0;				 
	while(pre!=NULL&&pos<i-1){
		pre=pre->next;
		pos++;
	}
	if(pre==NULL)	 
		return false;
**/
	LNode* pre=GetElem(L,i-1); 
/** �޸Ľ��֮�����ӹ�ϵ��ʵ�ֲ���
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;//�ڴ����ʧ�� 
	s->data=e;
	s->next=pre->next;
	pre->next=s; 
	return true;
**/
	return InsertAfter(pre,e);

} 
//�������	@	ָ�������
bool InsertAfter(LNode *p,ElementType e){
	if(p==NULL)
		return false;
	LNode *q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)
		return false;//�ڴ����ʧ�� 
	q->data=e;
	q->next=p->next;
	p->next=q;
	return true;
} 
//�������	@	ָ�����ǰ��
bool InsertBefore(LNode *p,ElementType e){
	if(p==NULL)
		return false;
	LNode *q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)
		return false;//�ڴ����ʧ�� 
	q->next=p->next;
	p->next=q;
	q->data=p->data;
	p->data=e;
	return true;
} 

//ɾ������	@	��λ��ɾ��
bool Delete(LinkList &L,int i,ElementType &e){
	if(i<1)
		return false;
/**��ָ��λ���ǰһ��λ�� 
	LNode* pre=L; 				
	int pos=0;				 
	while(pre!=NULL&&pos<i-1){
		pre=pre->next;
		pos++;
	}

**/
	LNode *pre=GetElem(L,i-1);
	//ɾ�����
	if(pre==NULL)	 				//Ҫɾ���Ľ�㲻���� 
		return false;
	if(pre->next==NULL)				//Ҫɾ���Ľ�㲻���� 
		return false; 
	LNode* q=pre->next;
	e=q->data; 
	pre->next=q->next; 
	free(q);
	return true;
} 
//ɾ������	@ɾ��ָ�����	
	//&�˷����о����ԣ����p�����һ�����,���޷��ɹ�ɾ��, ���˷�����ʱ�临�Ӷ�Ϊo(1) 
bool DeleteNode(LNode *p){
	if(p==NULL)
		return false;
	LNode *q=p->next;
	p->data=q->data;
	p->next=q->next;
	free(q);
	return true;	
} 
int main(){
	LinkList L;
	printf("%d",InitList(L));
	return 0;
} 
