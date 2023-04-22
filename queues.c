#include<stdio.h>
int q[10],cq[10],front=-1,rear=-1,f2=-1,r2=-1,f3=-1,r3=-1,dq[10],r4=-1,f4=-1;
struct priorityq
{
	int data;
	int priority;
}pq[10],temp;
void queue()
{
	int ch,val,n;
	front=-1;rear=-1;
	printf("No. of ele:");
		scanf("%d",&n);
	do
	{
		printf("\n1.insert 2.delete 3.isempty 4.isfull5.display6.exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter:");
				scanf("%d",&val);
				if(rear==n-1)
				{
					printf("Overflow");
				}
				else if(front==-1 && rear==-1)//empty
				{
					front=0;rear=0;
					q[rear]=val;
				}
				else
				{
					rear++;
					q[rear]=val;
				}
				break;
			case 2:
				if(rear==-1 && front==-1)
				{
					printf("Underflow");
				}
				else if(rear==front)//single ele
				{
					printf("deleted ele %d",q[front]);
					front=-1;rear=-1;
				}
				else
				{
					printf("deleted ele %d",q[front]);
					front=front+1;
				}
				break;
			case 3:
				if(front==-1 && rear==-1)
				printf("Empty q");
				else
				printf("q not empty");
				break;
			case 4:
				if(rear==n-1)
				printf("q full");
				else
				printf("q not full");
				break;
			case 5:
				printf("Q ele:");
				int i;
				for(i=front;i<=rear;i++)
				{
					printf("%d ",q[i]);
				}
				break;
			case 6: break;
			default:printf("Invalid");	
		}
	}while(ch!=6);
	
}

void cqueue()
{
	int ch,val,i,n;
	f2=-1;r2=-1;
	printf("No. of ele:");
	scanf("%d",&n);
	do{
	printf("\n1.insert 2.delete 3.isempty 4.isfull5.display6.exit :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter ele:");
			scanf("%d",&val);
			if(f2==(r2+1)%n)
			{
				printf("Overflow");
			}
			else if(f2==-1 && r2==-1)
			{
				f2=0;r2=0;
				cq[r2]=val;	
			}
			else
			{
				r2=(r2+1)%n;
				cq[r2]=val;
			}
			break;
		case 2:
			if(r2==-1 && f2==-1)
			{
				printf("Underflow");
			}
			else if(f2==r2)
			{
				printf("deleted ele %d",cq[f2]);
				f2=0;r2=0;
			}
			else
			{
				printf("deleted ele %d",cq[f2]);
				f2=(f2+1)%n;
			}
			break;
		case 3:
			if(r2==-1 && f2==-1)
			{
				printf("cq empty");
			}
			else
			{
				printf("cq not empty");
			}
			break;
		case 4:
			if(f2==(r2+1)%n)
			{
				printf("full");
			}
			else
			{
				printf("not full");
			}
			break;
		case 5:
			for(i=f2;i<=r2;i++)
			{
				printf("%d ",cq[i]);
			}
			break;
		case 6:break;
		default:printf("invalid");
	}
	}while(ch!=6);
}
void sort()
{
	int i,j;
	for(i=f3;i<=r3;i++)
	{
		//printf("%d %d",pq[i].data,pq[i].priority);
		for(j=i+1;j<=r3;j++)
		{
			if(pq[i].priority > pq[j].priority)
		{
			temp.data=pq[i].data;
			pq[i].data=pq[j].data;
			pq[j].data=temp.data;
			
			temp.priority=pq[i].priority;
			pq[i].priority=pq[j].priority;
			pq[j].priority=temp.priority;
		}
		}
		
	}
	printf("on sort:");
	for(i=f3;i<=r3;i++)
				{
					printf("%d->%d ",pq[i].data,pq[i].priority);
				}	
}
void pqueue()
{
	int ch,val,n,pr,i,flag=0;
	f3=-1;r3=-1;
	printf("No. of ele:");
		scanf("%d",&n);
	do
	{
		printf("\n1.insert 2.delete 3.isempty 4.isfull5.display6.exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				flag=0;
				printf("Enter value:");
				scanf("%d",&val);
				printf("enter priority:");
				scanf("%d",&pr);
				if(r3>=0)
				{
				for(i=f3;i<=r3;i++)
				{
					if(pq[i].priority==pr)
					{
					printf("priority exists");
					flag=1;
					break;
					}
				}
				}
				if(flag==0)
				{
					if(r3==n-1)
				{
					printf("Overflow");
				}
				else if(f3==-1 && r3==-1)//empty
				{
					f3=0;r3=0;
					pq[r3].data=val;
					pq[r3].priority=pr;
					printf("%d %d",pq[r3].data,pq[r3].priority);
				}
				else
				{
					r3=r3+1;
					pq[r3].data=val;
					pq[r3].priority=pr;
					printf("%d %d",pq[r3].data,pq[r3].priority);
				}
				sort();
				}
				
				break;
			case 2:
				if(r3==-1 && f3==-1)
				{
					printf("Underflow");
				}
				else if(r3==f3)//single ele
				{
					printf("deleted ele %d",pq[f3].data);
					f3=-1;r3=-1;
				}
				else
				{
					printf("deleted ele %d",pq[f3].data);
					f3=f3+1;
				}
				break;
			case 3:
				if(f3==-1 && r3==-1)
				printf("Empty pq");
				else
				printf("pq not empty");
				break;
			case 4:
				if(r3==n-1)
				printf("pq full");
				else
				printf("pq not full");
				break;
			case 5:
				printf("PQ ele:");
				int i;
				for(i=f3;i<=r3;i++)
				{
					printf("%d->%d ",pq[i].data,pq[i].priority);
				}
				break;
			case 6: break;
			default:printf("Invalid");	
		}
	}while(ch!=6);
	
}
void dequeue()
{
	int ch,val,n;
	f4=-1;r4=-1;
	printf("No. of ele:");
		scanf("%d",&n);
	do
	{
		printf("\n1.insert thru rear 2.delete thru front 3.insert front 4.delete rear 5.display 6.exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter:");
				scanf("%d",&val);
				if(r4==n-1)
				{
					printf("Overflow");
				}
				else if(f4==-1 && r4==-1)//empty
				{
					f4=0;r4=0;
					dq[r4]=val;
				}
				else
				{
					r4++;
					dq[r4]=val;
				}
				break;
			case 2:
				if(r4==-1 && f4==-1)
				{
					printf("Underflow");
				}
				else if(r4==f4)//single ele
				{
					printf("deleted ele %d",dq[f4]);
					f4=-1;r4=-1;
				}
				else
				{
					printf("deleted ele %d",dq[f4]);
					f4=f4+1;
				}
				break;
			case 3:
				printf("Enter val:");
				scanf("%d",&val);
				if(f4==0)
				{
					printf("Overflow at front");
				}
				else if(f4==-1 && r4==-1)//empty
				{
					f4=0;r4=0;
					dq[f4]=val;
				}
				else
				{
					f4--;
					dq[f4]=val;
				}
				break;
			case 4:
				if(r4==-1 && f4==-1)
				{
					printf("Underflow");
				}
				else if(r4==f4)//single ele
				{
					printf("deleted ele %d",dq[f4]);
					f4=-1;r4=-1;
				}
				else
				{
					printf("deleted ele %d",dq[r4]);
					r4--;
				}
				break;
			case 5:
				printf("DQ ele:");
				int i;
				for(i=f4;i<=r4;i++)
				{
					printf("%d ",dq[i]);
				}
				break;
			case 6: break;
			default:printf("Invalid");	
		}
	}while(ch!=6);
}
void main()
{
	int op;
	do
	{
		printf("\n1.queue 2.circular queue 3.priority queue4.deque 5exit:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			queue();
			break;
		case 2:
			cqueue();
			break;
		case 3:
			pqueue();
			break;
		case 4:
		dequeue();
		break;
		case 5:
			break;
		default:printf("Invalid");
	}
	}while(op!=5);	
}
