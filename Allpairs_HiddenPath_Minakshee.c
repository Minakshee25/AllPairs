/*
  Experiment 09 : ALL PAIRS SHORTEST PATH
  Name : Minakshee Narayankar
  SE CMPN A
  Batch 1
  Roll No. : 18102A0003
*/
#include<stdio.h>
#define MAX 50
#define inf 10000
int n,e,C[MAX][MAX],A[MAX][MAX],D[MAX][MAX],path[MAX],pathh[MAX],k;
void accept()
{
	int i,j,l,m,n;
	printf("\nEnter edges followed by cost = \n");
	for (i=0; i<e; i++)
	{
		scanf("%d %d %d",&l,&m,&n);
		C[l-1][m-1] = n;
		A[l-1][m-1] = n;
		D[l-1][m-1] = l-1;
	}
}
void initialize()
{
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			D[i][j] = -2;
			if (i==j)
				C[i][j] = A[i][j] = 0;
			else
				C[i][j] = A[i][j] = inf;
		}
}
void all_pairs()
{
	int i,j,k;
	for (k=0; k<n; k++)
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				if (A[i][j] > (A[i][k]+A[k][j]))
				{
					A[i][j] = A[i][k]+A[k][j];
					D[i][j] = k;
				}			
}
void display()
{
	int i,j;
	printf("\nOutput Matrix : \n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
	printf("\nDiagonal matrix = \n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			printf("%d\t",D[i][j]+1);
		printf("\n");
	}
}
void findpath(int a, int b,int path[MAX])
{
	int i,j,l;
	for (i=0; i<n; i++)
		if(i==(a-1))
		{
			l=b-1;
			while(1)
				if(l==-2)
					break;
				else
				{
					path[k++] = l+1;
					l = D[i][l];
				}
		}
	printf("SHORTEST PATH BETWEEN VERTEX %d and %d = ",a,b);
	for(i=k-1; i>=0; i--)
		printf("%d ",path[i]);
}
int main()
{
	int i,j,ch,a,b;
	printf("\nEnter number of vertices = ");
	scanf("%d",&n);
	printf("Enter number of edges = ");
	scanf("%d",&e);
	initialize();
	accept();
	all_pairs();
	display();
	while(1)
	{
		printf("\n\nMenu\n1:Find Shortest path between 2 vertices = \n2:Exit\n\nEnter choice = ");
		scanf("%d",&ch);
		if (ch==1)
		{
			printf("Enter 2 vertices = ");
			scanf("%d %d",&a,&b);
			k=0;
			findpath(a,b,path);
			for(i=k-1; i>0; i--)
			{
				if(C[path[i]-1][path[i-1]-1] == inf)
				{
					printf("\nThere is a hidden path between %d and %d!\n",path[i],path[i-1]);
					k=0;
					findpath(path[i],path[i-1],pathh);
				}
			}
		}
		else if (ch==2)
			break;
	}
	return 0;
}
