/**@���ݽṹ:��
 **@����:9761��  
 **@�洢�ṹ��1.˫�ױ�ʾ��
 			  2.���ӱ�ʾ��
			  3.�ֵܽ���ʾ�� 
 **/
 
//���ļ���ʵ�����������ִ洢�ṹ 
#include<cstdio>
typedef int ElementType;
#define MAX_SIZE 10 
//˫�ױ�ʾ��,���ڵ��±�Ϊ0����αָ����Ϊ-1 
//typedef struct{
//	ElementType data;
//	int parent;
//}node;
//typedef struct{
//	node N[MAX_SIZE];
//	int n;
//}Tree;

//���ӱ�ʾ��
//typedef struct child{
//	int n;
//	child* next;	
//}*nextChild;
//typedef struct{
//	ElementType data;
//	child* firstChild;
//}node;
//typedef struct{
//	node N[MAX_SIZE];
//	int n,r;			//��������͸��ڵ�	
//}Tree; 

//�����ֵܱ�ʾ��
typedef struct node{
	ElementType data;
	struct node* firstChild;
	struct node* nextSibling;	
}node,*Tree;
void visit(node* n){
	printf("%d ",n->data);
}

int main(){
	return 0;
} 
