//Bankers algorithm

#include <stdio.h>
#include <stdlib.h>
# include "a.h"
void disp();
void safe_state();
struct proc
{

	int alloc[5];

	int need[5];

	int max[5];

};



struct proc p[5];

char r[]={'A','B','C','D','E'};

int r_tot[5],r_avail[5],r_inter[5],pn=2,rn;

void main()

{

	int i,j,k=0;

	//printf("\nEnter number of processes ?\n");

	//scanf("%d",&pn);

	printf("\nEnter number of resources ?\n");

	scanf("%d",&rn);



	for(i=0;i<pn;i++)

	{

		for(j=0;j<rn;j++)

		{

			printf("\nEnter number of instances of %c allocated to P%d \n",r[j],i);

			scanf("%d",&p[i].alloc[j]);



		}

	}



	for(i=0;i<pn;i++)

	{

		for(j=0;j<rn;j++)

		{

			printf("\nEnter maximum instances of %c required for P%d \n",r[j],i);

			scanf("%d",&p[i].max[j]);



		}

	}



	for(i=0;i<pn;i++)

	{

		for(j=0;j<rn;j++)

		{

			p[i].need[j] = p[i].max[j] - p[i].alloc[j];

		}

	}





	for(i=0;i<rn;i++)

	{

		printf("Enter the total instances of resource %c \n",r[i]);

		scanf("%d",&r_tot[i]);

	}



	for(i=0;i<5;i++)

		r_inter[i]=0;





	for(i=0;i<pn;i++)

	{

		for(j=0;j<rn;j++)

		{

			r_inter[j] = r_inter[j] + p[i].alloc[j];



		}

	}



	for(i=0;i<rn;i++)

	{

		k=r_tot[i]-r_inter[i];

		if(k<0)

		{

			printf("\nNot enough resources !");

			getchar();

			exit(0);

		}

		r_avail[i]=r_tot[i]-r_inter[i];

	}



	disp();
	safe_state();


}





void disp()

{

	int i,j;



	printf("\n\nAllocation Matrix\n");

	printf("\t");

	for(i=0;i<rn;i++)

	{

		printf("\t %c",r[i]);

	}



	for(i=0;i<pn;i++)

	{

		printf("\n Process P%d",i);

		for(j=0;j<rn;j++)

		{

			printf("\t %d",p[i].alloc[j]);

		}

	}





	printf("\n\nNeed Matrix\n");

	printf("\t");

	for(i=0;i<rn;i++)

	{

		printf("\t %c",r[i]);

	}



	for(i=0;i<pn;i++)

	{

		printf("\n Process P%d",i);

		for(j=0;j<rn;j++)

		{

			printf("\t %d",p[i].need[j]);

		}

	}



	printf("\n\nMaximum Matrix\n");

	printf("\t");

	for(i=0;i<rn;i++)

	{

		printf("\t %c",r[i]);

	}



	for(i=0;i<pn;i++)

	{

		printf("\n Process P%d",i);

		for(j=0;j<rn;j++)

		{

			printf("\t %d",p[i].max[j]);

		}

	}





	printf("\n\nInstances of resources available\n");

	for(i=0;i<rn;i++)

	{

		printf("\t %c",r[i]);

	}

	printf("\n");

	for(i=0;i<rn;i++)

	{

		printf("\t %d",r_avail[i]);

	}



}





void safe_state()
{

int q[2]={0,1},order=0,ttr,cnt,j,k,head=1,tail=0,i,temp,tp,t,safe=0;

for(ttr=0;ttr<(pn-1);ttr++)
{
order=0;
for(i=0;i<pn;i++)
{
k=q[tail+1];
cnt=0;
for(j=0;j<rn;j++)
{
	if(p[k].need[j]<=r_avail[j])
	{
	cnt++;
	continue;
	}
}

if(cnt==rn)
{
order =(order*10)+(k+1);
for(t=0;t<rn;t++)
{
r_avail[t]=r_avail[t]+p[k].need[t]+p[k].alloc[t];
}
}
}

if(order>10)
{
printf("\n Safe sequence is %d",order);
safe=1;
break;
}
else
{
temp=q[head];
for(tp=head;tp>tail;tp--)
{
q[tp]=q[tp-1];
}
q[tail] =temp;
}
}

if(safe==0)
printf("\nDeadlocked.....");

}
