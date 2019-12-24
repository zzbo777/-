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
	printf("���벻����25����ֵ,#�Ž���\n");
	InitList(L);
    int i=0;
	int n,m;
	int a,b;
	int k;
	do{
		scanf("%d",&L.elem[i]);
        L.length=i++;
	}while(getchar()!='#');
	printf("���Ա��������£�\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n���ҵڼ���Ԫ�أ�");
	scanf("%d",&n);
	if(GetElem(L,n,m))
		printf("��Ԫ���ǣ�%d\n",m);
	else
		printf("������ķ�Χ\n");
	printf("�ڵڼ���Ԫ��ǰ����ʲôԪ��:");
	scanf("%d %d",&a,&b);
	if(ListInsert(L,a,b)){
	printf("�������Ա��������£�\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	}else{
	printf("��ǰλ���޷�����\n");
	}
	printf("\nɾ���ĸ�λ��Ԫ�أ�");
	scanf("%d",&k);
	if(ListDelete(L,k)){
	printf("ɾ���ɹ���\n�������Ա��������£�\n");
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	}else
		printf("ɾ��ʧ�ܣ�\n");

	system("pause");
	return 0;
}

bool InitList(SqList &L){
	L.elem=new int[MAXSIZE];
	if(!L.elem)
		exit(0);//����ʧ���˳�
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
	//�ڵ�i��λ��ǰ����Ԫ��e
	if((i<1)||(i>L.length+1))
		return false;
	if(L.length==MAXSIZE)
		return false;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];//�����λ�ú����Ԫ�غ���
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
