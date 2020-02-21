
//Static allocation the array of the SqList

#include<cstdio>
#define MaxSize 10
#define ERR	-99 
typedef int ElementType;
struct SqList{
	ElementType data[MaxSize];
	int length;
};

void InitList(SqList *L){
	L->length=0;
	//for test
//	for(int i=0;i<L->length;i++) {
//		L->data[i]=i;
//	}
}

int Length(SqList L){
	return L.length;
}

int LocateElem(SqList L,ElementType e){
	//int position=-1;
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return -1;
}

ElementType GetElem(SqList L,int i){
	if(i<1||i>L.length)
		return ERR;
	else
		return L.data[i-1];
}

bool Insert(SqList *L,int i,ElementType e){
	if(i<1||i>L->length+1){
		printf("index error");
		return false;
	}
	if(L->length>=MaxSize){
		printf("SqList is full");
		return false;
	}
	
	for(int j=L->length;j>=i;j--)
		L->data[j]=L->data[j-1];
	L->data[--i]=e;
	L->length++;
	return true;
	
}

ElementType Delete(SqList *L,int i){
	if(L->length==0){
		printf("SqList is already empty"); 
		return ERR;
	}
	if(i>L->length||i==0){
		printf("index error");
		return ERR;
	}
	ElementType e;
	e=L->data[i-1];
	for(int j=i-1;j<L->length-1;j++){
		L->data[j]=L->data[j+1];
	} 
	L->length--;
	return e;
}

void PrintList(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n"); 
}

int main(){
//	SqList L;
//	InitList(&L);
//	printf("%d",LocateElem(L,4));
//	Insert(&L,1,-1);
//	PrintList(L);
//	Delete(&L,1);
//	PrintList(L);
//	printf("%d",L.length);
	return 0;
}
