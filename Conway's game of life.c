#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define length 40
#define widith 60
int main(void) 
{
    char grid[length][widith],temp[length][widith],character;
    int i,j,k=2,count=0,x=0,y=0,p,m,n,gen;
    
    //initializing a dead generation...
    for(i=0;i<length;i++)
    {
        for(j=0;j<widith;j++)
        {
            grid[i][j]=' ';
        }
    }

    //inputing innitial live cells from a file.
    printf("Enter number generations: ");
    scanf("%d",&gen);
    printf("Enter number of live cells: ");
    scanf("%d",&p);
    printf("Enter the live cells(x1,y1 x2,y2...) :");

    while(p>0)
    {
        scanf("%d,%d",&m,&n);
        grid[m][n]='#';
        p--;
    }

    /*rules implementation and game play*/
    printf("Generation 1\n");
        for(i=0;i<length;i++)
        {
            for(j=0;j<widith;j++)
            {
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }
    while(gen>0)
    {
        for(i=0;i<length;i++)
        {
            for(j=0;j<widith;j++)
            {

                for(int m=i-1;m<=i+1;m++)
                {
                    for(int n=j-1;n<=j+1;n++)
                    {
                        if((m==i && n==j) || m<0 || n<0 || m>length-1 || n>widith-1 )
                        {
                            // continue;
                        }
                        else
                        {
                            if(grid[m][n]=='#')
                            {
                                count++;
                            }
                        }
                    }
                }

                if(grid[i][j]=='#' && count==2){temp[i][j]='#';}
                else if(grid[i][j]=='#' && count==3){temp[i][j]='#';}
                else if(grid[i][j]==' ' && count==3){temp[i][j]='#';}
                else{temp[i][j]=' ';}
                count=0;

            }
        }
        printf("Generation %d\n",k);
        k++;
        for(i=0;i<length;i++)
        {
            for(j=0;j<widith;j++)
            {
                grid[i][j]=temp[i][j];
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }

        gen--;
        printf("Press any button to escape.......");
        if(kbhit()){break;}
        sleep(1);
        system("cls");
    }
    
    return 0;
}