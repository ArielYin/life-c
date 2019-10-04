#include <stdio.h>
#include <stdlib.h> 


#define ROW 60

#define COL 80

int main(void)
{
   int i, j, k;
   int p, q, t1, t2, t3, flag=0;
   int time=0;
   int a[ROW][COL] = {0}, b[ROW][COL]={0}, c[ROW][COL]={0},tot[ROW][COL]={0};
   for(i=0;i<(ROW*COL/5);i++){
      p=rand()% ROW;
      q=rand()% COL;
      a[p][q]=1;
      b[p][q]=1;
   }
   do{
      ++time;
      printf("%d",time);
     
      for(j=0; j< ROW; j++){
         for(k=0; k< COL; k++){
            c[j][k]=a[j][k];
         }
      }
      for(j=0; j< ROW; j++){
         for(k=0; k< COL; k++){
            a[j][k]=b[j][k];
         }
      }
     
/*print borad*/
      for(j=0; j < ROW; j++){
         printf("\n");
         for(k=0; k < COL; k++){
            printf("%d",b[j][k]);
         }
      }
      printf("\n");
/*center of board*/
      for(j=1; j<ROW-1; j++){
         for(k=1; k<COL-1; k++){
            t1=b[j-1][k-1]+b[j][k-1]+b[j+1][k-1];
            t2=b[j+1][k]+b[j-1][k];
            t3=b[j-1][k+1]+b[j][k+1]+b[j+1][k+1];
            tot[j][k]=t1+t2+t3;
         }
      }
/*four concer of board*/
      if(b[0][0])
        tot[0][0]=b[0][1]+b[1][1]+b[1][0];
      if(b[0][COL-1])
        tot[0][COL-1]=b[0][COL-2]+b[1][COL-2]+b[1][COL-1];     
      if(b[ROW-1][0])
        tot[ROW-1][0]=b[ROW-2][0]+b[ROW-2][1]+b[ROW-1][1];
      if(b[ROW-1][COL-1])
        tot[ROW-1][COL-1]=b[ROW-2][COL-2]+b[ROW-2][COL-1]+b[ROW-1][COL-2];
    
/*four edges of board*/
      for(k=1; k < COL-1; k++)
         tot[0][k]=b[0][k-1]+b[0][k+1]+b[1][k-1]+b[1][k]+b[1][k+1];
      for(k=1; k < COL-1; k++)
         tot[ROW-1][k]=b[ROW-1][k-1]+b[ROW-1][k+1]+b[ROW-2][k]+b[ROW-2][k-1]+b[ROW-2][k+1];
      for(j=1; j< ROW-1; j++)
         tot[j][0]=b[j-1][0]+b[j+1][0]+b[j-1][1]+b[j][1]+b[j+1][1];
      for(j=1; j< ROW-1; j++)
         tot[j][COL-1]=b[j-1][COL-2]+b[j][COL-2]+b[j+1][COL-2]+b[j-1][COL-1]+b[j+1][COL-1];
        
      for(j=0; j<ROW; j++){
         for(k=0; k<COL; k++){
            if(b[j][k])
               if(tot[j][k]!=2 && tot[j][k]!=3)
                  b[j][k]=0;
            else
               if(tot[j][k]==3)
                  b[j][k]=1;
         }
      }
      flag=0;
      for(j=0; j< ROW; j++){
         for(k=0; k< COL; k++){
            if(c[j][k]!= b[j][k])
               flag++;
         }
      }

   } while(flag);
   
   printf("\n");
   return 0;
}
