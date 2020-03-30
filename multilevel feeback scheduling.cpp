#include<conio.h>
#include<Stdio.h>
int main()
{   // taking input for number of processes
	printf("\nMulti-level feedback scheduling algorithem\n");
	printf("* * * * * * * * * * * * * * *");
	printf("\nEnter the number of processes\n");
	int number;
	scanf("%d",&number);
	
	//taking input for the batch time for each process
	int bt[number]; 
	printf("\nEnter the batch time for %d process\n",number);
	for(int i=1;i<=number;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("\n Enter the timestamp for first round-robin\n");
	int ts1,ts2;
	scanf("%d",&ts1);
	printf("* * * * * * * * * * * * * * *");
	printf("\nFirst phase of the round robin begins\n");
	printf("* * * * * * * * * * * * * * *");
	int total1=0,total2=0,total3=0;
	int nbt[number];
	for(int i=1;i<=number;i++)
	{
		if(bt[i]==ts1)
		{
			nbt[i]=0;
			total1 = total1 + ts1;
		}
		else
		{
			if(bt[i]>ts1)
			{
				nbt[i] = bt[i]-ts1;
				total1 = total1 + ts1;
			}
			else
			{
				nbt[i] = 0;
				total1 = total1 + bt[i]; 
			}
		}
		
	}
	printf("\nAfter the first round-robin ends we have the following remaining time for the process\n");
	for(int i=1;i<=number;i++)
	{
		printf("\n %d process has remaining time %d \n",i,nbt[i]);
	}
printf("\nthe total time for the first phase is %d seconds\n",total1);


// second round robin cycle
printf("\n* * * * * * * * * * * * * * * * * * * * *\n ");
printf("\n Enter the timestamp for the next round robin cycle\n");
scanf("%d",&ts2);
int nnbt[number];
for(int j =1;j<=number;j++)
{
	if (nbt[j]==0)
	{
		nnbt[j] = 0;
	}
	else
	{
		if(nbt[j]>ts2)
		{
		nnbt[j] = nbt[j] - ts2;
		total2 = total2 + ts2;			
		}
		else
		{
			nnbt[j] = 0;
			total2 = total2 + nbt[j];
		}
	}
}
printf("\nAfter the second round-robin ends we have the following remaining time for the process\n");
	for(int i=1;i<=number;i++)
	{
		printf("\n %d process has remaining time %d \n",i,nnbt[i]);
	}
printf("the total time taken for the second round robin is: %d seconds",total2);

//3rd cycle for the fcfs 
for(int j=1;j<=number;j++)
{
	if(nnbt[j]==0)
	{
		printf("\nprocess already executed\n");
	}
	else
	{
		printf("\nprocess executes in %d seconds\n",nnbt[j]);
		total3 = total3 + nnbt[j];
	}
}
printf("\nall process are compleated after %d seconds\n",total1+total2+total3);
}
