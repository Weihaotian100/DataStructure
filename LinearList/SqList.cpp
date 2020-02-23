
/**@数据结构:线性表->顺序表
 **@作者:9761滴 
 **@实现方式:静态分配(即分配固定大小的数组，数组长度不可变) 
 **/ 

//一种数据结构的操作无非 创建删除，增删改查
//本文件中实现了顺序表的
	/*1.创建(即初始化操作) 
	**2.求表长
	**3.查找元素(分按位查找和按值查找) 
	**4.插入操作(在指定位序插入数据元素)
			*****位序指的是从1开始的整数 
	**5.删除操作(删除指定位序的数据元素) 
	**6.输出整个顺序表 
	*/ 
//等操作 
#include<cstdio>
#define MaxSize 10
#define ERR	-99 
typedef int ElementType;

//顺序表结构体 
struct SqList{
	ElementType data[MaxSize];
	int length;
};

//初始化顺序表 
void InitList(SqList *L){
	L->length=0;
}

//求表长 
int Length(SqList L){
	return L.length;
}

//按值查找 
int LocateElem(SqList L,ElementType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return -1;
}

//按位查找 
ElementType GetElem(SqList L,int i){
	if(i<1||i>L.length)
		return ERR;
	else
		return L.data[i-1];
}

//插入指定位置 
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

//删除指定位置 
ElementType Delete(SqList *L,int i){
	if(L->length==0){
		printf("SqList is already empty"); 
		return ERR;
	}
	if(i>L->length||<1){
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

//打印刷出整个表  
void PrintList(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	printf("\n"); 
}

int main(){
	SqList L;
//	SqList &List=L;
//	
	InitList(&L);
	PrintList(L);
	DeleteStoT(L,0,5);
	PrintList(L);
//	L.data[0]=3;
//	PrintList(L);
//	DeleteX(L,3);
//	PrintList(L);
//	printf("%d",LocateElem(L,4));
//	Insert(&L,1,-1);
//	PrintList(L);
//	Delete(&L,1);
//	PrintList(L);
//	printf("%d",L.length);
	return 0;
}
