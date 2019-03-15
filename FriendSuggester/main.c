#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int c=0;
struct count{
int c;}num;
int a[20][20];
struct nodelink{

     char name[50];
     char friends[10][10];
     int nf;

}nl[10];
void read()
{
    int j;
    printf("Enter the no of entries:");
    scanf("%d",&j);
    c=j;
    //printf("%d",c);
    int i;
    for(i=0;i<c;i++)
    {
        printf("Enter the %dth entry\n",(i+1));
        printf("Enter the name:");
        //gets(nl[i].name);
        scanf("%s",nl[i].name);
        printf("Enter the no of friends:");
        scanf("%d",&nl[i].nf);
        for(j=0;j<nl[i].nf;j++)
        {

            printf("Enter the name of friend:");
            //gets(nl[i].friends[j]);
            scanf("%s",nl[i].friends[j]);
        }

    }



}
void createArray()
{
    //printf("%d",c);
    //printf("Inside create");
    int i,j,k;
    for(i=0;i<c;i++)
    {
        for(j=0;j<nl[i].nf;j++)
        {
            //printf("%d %d",i,j);
            for(k=0;k<c;k++)
            {
                //printf("%d %d %d\n",i,j,k);
                if(i!=k)
                {

                    if(strcmp(nl[i].friends[j],nl[k].name)==0)
                    {
                        //printf("set one%d %d\n",i,k);
                        a[i][k]=1;

                    }
                    else
                    {
                        if(a[i][k]!=1){
                    //printf("set zero%d %d\n",i,k);
                    a[i][k]=0;
                    }
                    }
                }
                else{
                        //printf("set zero%d %d\n",i,k);
                    a[i][k]=0;
                }


            }

        }

    }


}
void printArray()
{
    //printf("Inside print\ncount:%d",c);
    int i,j;
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void suggest()
{
    int i,j,m,n;
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
        {

            if(a[i][j]==1)
            {
                for(m=0;m<c;m++)
                {
                    if(a[j][m]==1)
                    {
                        if(a[i][m]!=1)
                        {
                            if(i!=m){
                            //printf("%d %d %d",i,j,m);
                            printf("\n%s can know %s through %s\n",nl[i].name,nl[m].name,nl[j].name);
                            }
                        }
                    }

                }

            }
        }

    }
}

int main()
{


    read();
    createArray();
    printArray();
    suggest();
    return 0;
}
