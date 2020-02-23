
/**@���ݽṹ:���Ա�->������
 **@����:9761�� 
 **@�Ƿ��ͷ���:�� 
 **/
 
//һ�����ݽṹ�Ĳ����޷� ����ɾ������ɾ�Ĳ�
//���ļ���ʵ���˵������
	/*1.��ʼ������
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
	L=NULL;					//�ձ���ʱû���κν�� 
	return true; 
}

//������Ľ���	@	β�巨  
bool CreateList_Tail(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	LNode *s;
	LNode *r;
	r=L;
	ElementType e;
	scanf("%d",&e);			//�˴�elementType Ϊ int
	r->data=e;
	scanf("%d",&e);
	while(e!=-9999){			//-9999��ʾ�������	
		s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=NULL;
		r->next=s; 
		r=s;
		scanf("%d",&e);
	}
	return true;
}

//������Ľ���	@	ͷ�巨
bool CreateList_Head(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	LNode *s;
	ElementType e;
	L->data=e;
	L->next=NULL;
	scanf("%d",&e);
	while(e!=-9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L->next;
		L->next=s;
		scanf("%d",&e);
	}
	return true;
} 

//������Ĳ���	@	��λ�����
LNode* GetElem(LinkList L,int i){
	if(i<1)
		return NULL;
	LNode *pre=L;
	int pos=1;
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
	if(i==1){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL)
			return false;
		s->data=e;
		s->next=L;
		L=s;
		return true;	
	}
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
	if(i==1){
		LNode *pre=L;
		L=L->next;
		if(pre==NULL)
			return false; 
		free(pre);
		return true;
	}
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
