#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define PRINT "%s\t\t%s\t\t%d\t\t%s\t\t%s\n ",stu[i].name,stu[i].sex,stu[i].age,stu[i].tele,stu[i].address
 struct Stu
{
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char address[30];

}stu[100],s1;
 	struct Stu stu[] = {{"cx","boy",12,"11455664","yanan"},
						{"ax","girl",15,"1145664","shanxi"},
						{"bx","boy",5,"1531115664","xian"},
						{"dx","girl",2,"16435664","weinan"},
						{"ex","boy",8,"12342141","hebei"}};
int m = 5;
int i = 0;

void Add()
{
	printf("联系人姓名：");
	scanf("%s",stu[m].name);
	printf("联系人性别：");
	scanf("%s",stu[m].sex);
	printf("联系人年龄：");
	scanf("%d",&stu[m].age);
	printf("联系人电话：");
	scanf("%s",stu[m].tele);
	printf("联系人住址：");
	scanf("%s",stu[m].address);
	printf("已添加成功\n");
	m++;
}

void zhiling()
{
	//stu[]
}

void Delete()
{
	char arr[20];
	printf("请输入想要删除联系人的姓名：");
	scanf("%s",arr);
	for(i=0;i<m;i++)
	{
		if( !strcmp(arr,stu[i].name))
		{
			int j = 0;
			for(j=i;j<m;j++)
			stu[j]=stu[j+1];
		}
	}
}

void Search()
{
	char arr[20];
	printf("请输入想要查找联系人的姓名：");
	scanf("%s",arr);
	for(i=0;i<m;i++)
	{
		if( !strcmp(arr,stu[i].name))
		{
	printf("\t姓名 \t  性别 \t  年龄 \t   电话\t          住址\n");
	printf("\t%s  \t %s\t   %d  \t %s \t %s\n ",
			stu[i].name,stu[i].sex,stu[i].age,stu[i].tele,stu[i].address);
		}
	}
}

void Change()
{
	char arr[20];
	printf("请输入想要修改的联系人的姓名：");
	scanf("%s",arr);
	for(i=0;i<m;i++)
	{
		if( !strcmp(arr,stu[i].name))
		{
				printf("联系人新年龄：");
				scanf("%d",&stu[i].age);
				printf("联系人新电话：");
				scanf("%s",stu[i].tele);
				printf("联系人新住址：");
				scanf("%s",stu[i].address);
		}
	}
}

void Printf_all()
{
	printf("\t姓名 \t  性别 \t  年龄 \t   电话\t          住址\n");
	for(i=0;i<m;i++)
	{
		printf("\t%s  \t %s\t   %d  \t %s \t %s\n ",
			stu[i].name,stu[i].sex,stu[i].age,stu[i].tele,stu[i].address);
	}
}

void Delete_all()
{
	for(i=0;i<m;i++)
	{
		stu[i]=s1;
	}
}

void Sort_name()
{
	int j = 0;
	int t = 0;
	struct Stu tmp;
	for(i=0;i<m;i++)
	{
		 t = i;
		for(j=i+1;j<m;j++)
		{
			if(strcmp(stu[t].name,stu[j].name)==1)
				 t = j;
		}
		if(t!=i)
		{
			 tmp = stu[t]; 
			 stu[t] = stu[i]; 
			 stu[i] = tmp;
		}
	}
}

void menu()
{
	printf("*****************************************\n");
	printf("***************欢迎使用******************\n");
	printf("**********请选择想要执行的操作***********\n");
	printf("*********1.增加联系人********************\n");
	printf("*********2.删除指定联系人****************\n");
	printf("*********3.查找指定联系人****************\n");
	printf("*********4.修改指定联系人信息************\n");
	printf("*********5.显示所有联系人信息************\n");
	printf("*********6.清空所有联系人****************\n");
	printf("*********7.以名字排序所有联系人**********\n");
	printf("*********8.退出**************************\n");

}

int main()
{

	int key = 0;
	while(1)
	{
		menu();
		scanf("%d",&key);
		switch(key)
		{
			case 1:Add();
				break;
			case 2:Delete();
				break;
			case 3:Search();
				break;
			case 4:Change();
				break;
			case 5:Printf_all();
				break;
			case 6:Delete_all();
				break;
			case 7:Sort_name();
				break;
			case 8:exit(0);			
				break;
			default:
				break;
		}
	}
	return 0;
}



void _swap(void *n1,void *n2,int sz)
{
	int i = 0;
	char tmp=0;
	for(i=0;i<sz;i++)
	{
		tmp = *((char *)n1+i);
		*((char *)n1+i) = *((char *)n2+i);
		*((char *)n2+i) = tmp;
	}
}

int int_cmp(const void * p1, const void * p2)
{
	//return (char **)p1-(char **)p2;
	//return (*( int *)p1) - (*(int *) p2);
	 return strcmp( * ( char** ) p1, * ( char** ) p2);
}

void Bubble_sort(void *arr,int size,int width,int (*cmp)(void*,void*))
{
	int i = 0;
	int j = 0;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(cmp((char*)arr+j*width,(char*)arr+(j+1)*width)>0)//if (cmp ((char *) base + j*size , (char *)base + (j + 1)*size) > 0)
				_swap((char *)arr+j*width,(char *)arr+(j+1)*width,width);// _swap(( char *)base + j*size, (char *)base + (j + 1)*size, size);
		}
	}
}


int main()
{
	//int arr[]={1,3,5,7,9,2,4,6,8,0};
	char *arr[]={"bbbb","aaaa","cccc","dddd"};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	//Bubble_sort(arr,sz,sizeof(int),int_cmp);
	Bubble_sort(arr,sz,sizeof(char*),int_cmp);
	/*for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}*/
	for(i=0;i<sz;i++)
	{
		printf("%s ",*(arr+i));
	}
	return 0;
}