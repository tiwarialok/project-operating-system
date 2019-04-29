#include<stdio.h>
#include<conio.h>
#define max 25
void bestfit();
void worstfit();
void firstfit();
int main()
{
	int ch;
	printf("Enter your Choice To perform Operation :\n");
	printf("1--> WorstFit\t2--> BestFit\t3--> FirstFit\t4-->Exit\n");
	char t[50];
	a:
	
	printf("Choice :");
	read(0,t,1);
	ch=atoi(t);
	//scanf("%d",&ch);
	while(ch!=4)
	{
		switch(ch){
			case 1:firstfit();
				break;
			case 2:bestfit();
				break;
			case 3:worstfit();
				break;
			default:printf("Enter Correct Choice\n");
				goto a;
		}
		printf("\nChoice :");
		scanf("%d",&ch);
	}	
}
void firstfit()
{
	int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
	static int bf[max],ff[max];
	//clrscr();
	printf("\n\tMemory Management Scheme - Worst Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of files:");
	scanf("%d",&nf);
	
	//file initialization
	
	
	
	
	
	
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++)
	{
		char s[50];
		printf("Block %d:",i);
		read(0,s,6);
		b[i]=atoi(s);
		//scanf("%d",&b[i]);
	}
	printf("Enter the size of the files :-\n");
	for(i=1;i<=nf;i++)
	{
		char s[50];
		printf("File %d:",i);
		read(0,s,6);
		f[i]=atoi(s);
		//scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(bf[j]!=1) //if bf[j] is not allocated
			{
				temp=b[j]-f[i];
				if(temp>=0)
				if(highest<temp)
				{
					ff[i]=j;
					highest=temp;
				}		
			}
		}
		frag[i]=highest;
		bf[ff[i]]=1;
		highest=0;
	}
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");
	for(i=1;i<=nf;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
void bestfit()
{
	int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000;
	static int bf[max],ff[max];
	printf("\n\tMemory Management Scheme - Best Fit");
	//clrscr();
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of files:");
	scanf("%d",&nf);
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++)
	{
		char s[50];
		printf("Block %d:",i);
		read(0,s,6);
		b[i]=atoi(s);
		//scanf("%d",&b[i]);
	}
	printf("Enter the size of the files :-\n");
	for(i=1;i<=nf;i++)
	{
		char s[50];
		printf("File %d:",i);
		read(0,s,6);
		f[i]=atoi(s);
		//scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(bf[j]!=1)
			{
				temp=b[j]-f[i];
				if(temp>=0)
				if(lowest>temp)
				{
					ff[i]=j;
					lowest=temp;
				}
			}
		}
		frag[i]=lowest;
		bf[ff[i]]=1;
		lowest=10000;
	}
	printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
	for(i=1;i<=nf && ff[i]!=0;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);	
}
void worstfit()
{
	int frag[max],b[max],f[max],i,j,nb,nf,temp;
	static int bf[max],ff[max];
//clrscr();
	printf("\n\tMemory Management Scheme - First Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of files:");
	scanf("%d",&nf);
	printf("\nEnter the size of the blocks:-\n");
	
	for(i=1;i<=nb;i++)
	{
		char s[50];
		printf("Block %d:",i);
		read(0,s,6);
		b[i]=atoi(s);
	//scanf("%d",&b[i]);
	}
	printf("Enter the size of the files :-\n");
	for(i=1;i<=nf;i++)
	{
		char s[50];
		printf("File %d:",i);
		read(0,s,6);
		f[i]=atoi(s);
	//+	scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(bf[j]!=1)
			{
				temp=b[j]-f[i];
				if(temp>=0)
				{
					ff[i]=j;
					break;
				}
			}
		}
		frag[i]=temp;
		bf[ff[i]]=1;
	}
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
	for(i=1;i<=nf;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}

