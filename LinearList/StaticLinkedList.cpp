
/**@���ݽṹ:���Ա�->��̬����
 **@����:9761�� 
 **@�Ƿ��ͷ���:�� 
 **/
 


#include<cstdio>
#include<stdlib.h>
#define MAXSIZE 10
typedef int ElementType;

//��̬������Ľṹ,SLinkList[MAXSIZE]��ʾ������һ��maxsize��С������ 
typedef struct SNode{
	ElementType data;
	int next;
}SNode,SLinkList[MAXSIZE]; 

//��̬����ĳ�ʼ��
bool InitList(SLinkList &L){
	L[0].next=-1;				//-1��ʾ�ý������޽�� 
	for(int i=1;i<MAXSIZE;i++){
		L[i].next=-2;			//-2��ʾ�ý��δʹ�ã��������������� 
	}
	return true;
}
int main(){
	return 0;
}
