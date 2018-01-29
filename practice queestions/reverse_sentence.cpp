#include<stdio.h>
#include<string.h>
int main()
{
	char p[1000];int i,t;void reve(char *);int j=0;char *temp=new char[100];
	scanf("%[^\n]",p);
	for(i=strlen(p)-1;i>=0;i--)
	{
		if(i==0)
		{
			temp[j++]=p[i];
			temp[j]='\0';
			break;
		}
		if(p[i]!=' ')
		temp[j++]=p[i];
		else
		{
			temp[j]='\0';
			reve(temp);
			j=0;delete temp;
			char *temp=new char[100];printf(" ");
		}
	}
	reve(temp);
	
}
void reve(char *p)
{
	char *temp1=new char[100];
	int k=0;
	for(int y=strlen(p)-1;y>=0;y--)
	temp1[k++]=p[y];
	temp1[k]='\0';
	printf("%s",temp1);
}
