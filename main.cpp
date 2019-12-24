#include<stdio.h>
#include<windows.h>
#define MAXSIZE 25
typedef struct{
	int *elem;
	int length;
}SqList;
bool InitList(SqList &L);
bool GetElem(SqList L,int i,int &e);
int LocateElem(SqList L,int e);
bool ListInsert(SqList &L,int i,int e);
bool ListDelete(SqList &L,int i);
int main(){
	SqList L;
	printf("输入不多于25个数值,#号结束\n");
	InitList(L);
    int i=0;
	int n,m;
	int a,b;
	int k;
	do{
		scanf("%d",&L.elem[i]);
        L.length=i++;
	}while(getchar()!='#');
	printf("线性表内容如下：\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n查找第几个元素：");
	scanf("%d",&n);
	if(GetElem(L,n,m))
		printf("该元素是：%d\n",m);
	else
		printf("超过表的范围\n");
	printf("在第几个元素前插入什么元素:");
	scanf("%d %d",&a,&b);
	if(ListInsert(L,a,b)){
	printf("现在线性表内容如下：\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	}else{
	printf("当前位置无法插入\n");
	}
	printf("\n删除哪个位置元素：");
	scanf("%d",&k);
	if(ListDelete(L,k)){
	printf("删除成功！\n现在线性表内容如下：\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	}else
		printf("删除失败！\n");

	system("pause");
	return 0;
}

bool InitList(SqList &L){
	L.elem=new int[MAXSIZE];
	if(!L.elem)
		exit(0);//分配失败退出
	L.length=0;
	return true;
}
bool GetElem(SqList L,int i,int &e){
	if(i<1||i>L.length)
		return false;
	e=L.elem[i-1];
	return true;
}
int LocateElem(SqList L,int e){
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e)
			return i+1;
	return 0;
}
bool ListInsert(SqList &L,int i,int e){
	//在第i个位置前插入元素e
	if((i<1)||(i>L.length+1))
		return false;
	if(L.length==MAXSIZE)
		return false;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];//插入的位置后面的元素后移
	L.elem[i-1]=e;
	++L.length;
	return true;
}
bool ListDelete(SqList &L,int i){
	if((i<1)||(i>L.length))
		return false;
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return true;
}
