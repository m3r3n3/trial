#include<stdio.h>
void display(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf(" %d",a[i]);
	}
}
void insort(int a[],int n)
{
int i,j,temp;
for(i=2;i<=n;i++)
{
temp=a[i];
j=i-1;
while(temp<a[j] &&j>=0)
{
a[j+1]=a[j];j--;
}
a[j+1]=temp;
printf("After pass %d: ",i);
display(a,n);
}
printf("Sorted:");
display(a,n);
}

void qsort(int a[],int p,int r)
{
int temp,i,j,pivot,n=r;
if(p<r)
{
pivot=a[p];
i=p;j=r+1;
do
{
do
{
i++;
}while(a[i]<=pivot);

do
{
j--;
}while(a[j]>pivot);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
//printf("\n");
//display(a,n);
temp=a[j];
a[j]=a[p];
a[p]=temp;

qsort(a,p,j-1);
qsort(a,j+1,r);
//printf("After pass:");
//display(a,n);
}
//printf("Sorted:");
//display(a,n);
}

void selsort(int a[],int n)
{
int i,temp;
for(i=1;i<=n;i++)
{
int min_val=a[i];
int min_ind=i;
int j;
for(j=i+1;j<=n;j++)
{
if(a[j]<min_val)
{
min_val=a[j];
min_ind=j;
}
}
temp=a[i];
a[i]=a[min_ind];
a[min_ind]=temp;
printf("After pass:");
display(a,n);
}
printf("Sorted:");
display(a,n);
}

merge(int a[],int start,int mid,int end)
{
	int i=start,j=mid+1,res[10],k=1;
	while(i<=mid &&j<=end)
	{
		if(a[i]<=a[j])
		{
			res[k]=a[i];
			k++;i++;
		}
		else
		{
			res[k]=a[j];
			k++;j++;
		}
	}
	if(i>mid)
	{
		while(j<=end)
	{
		res[k]=a[j];
		k++;j++;
	}
	}
	else
	{
		while(i<=mid)
	{
		res[k]=a[i];
		k++;i++;
	}
	}
	for(i=start,j=1;i<=end;i++,j++)
	{
		a[i]=res[j];
	}
}
void msort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		msort(a,start,mid);
		msort(a,mid+1,end);
		merge(a,start,mid,end);
		//printf("\nafter pass:");
		//display(a,start);
	}
	else
	return;
	//display(a,end);
	
}

void main()
{
int ch,i,n,a[10],b[10],c[10],d[10];
do{

printf("\n1.insertion 2.quick 3.selection 4.merge:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter no. of ele");
scanf("%d",&n);
printf("Enter ele");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);}
insort(a,n);
break;
case 2:
 //ivdeeeeee
 printf("enter no. of ele:");
 scanf("%d",&n);
 printf("Enter ele");
 for(i=1;i<=n;i++)
{
scanf("%d",&b[i]);}
qsort(b,1,n);
printf("sorted:");
display(b,n);
break;
case 3:
	printf("enter no. of ele:");
 scanf("%d",&n);
 printf("Enter ele");
 for(i=1;i<=n;i++)
 {
   scanf("%d",&c[i]);}
  selsort(c,n);
  break;
case 4 :
printf("enter no. of ele:");
 scanf("%d",&n);
 printf("Enter ele");
 for(i=1;i<=n;i++)
 {
   scanf("%d",&d[i]);}
  msort(d,1,n);
  printf("Sorted:");
  display(d,n);
  break;
default:printf("INVALID");
}
}while(ch!=4);
}
