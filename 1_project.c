#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include <conio.h>                                   //getch()  kbhit()
 int x=1;
 int y=1;
 int tailx[100] , taily[100];
 int sn=1;
 char dir='d';
 int lose=0;
 int ratx;
int raty;
//  ratx= rand() % 90 + 1;
//  raty= rand() % 30 + 1 ;
ratx= 10;
 raty= 10;
    void setup(){
      system("cls");
      
     int tail=0;
    for (int j=0;j<32;j++)  { 
     for(int i=0;i<92;i++){
      if ( j == 0)
         printf("#");
       if ( j == 31)
         printf("#");
      if ( i == 91 && j!=0 && j!=31)
         printf("#");
       if (i==0 &&  j!=0 )
          printf("#");
      if (i==x && j==y ){

           printf("O");       
      }
    else if (i==ratx && j==raty){
            printf("*");}
     
       else {
                int isTail = 0;
                for (int k = 0; k < sn; k++) {
                    if (tailx[k] == i && taily[k] == j) {
                        printf("o");
                        isTail = 1;
                    }
                }
                if (!isTail && j!=0 && j!=31 && i!=0 && i!=91)
                    printf(" ");
            }
             
         //  if ( j!=0 && j!=31 && i!=0 && i!=91){
         
         //     printf(" ");
         // }
         
      
      }printf("\n");
      
       } 
    }
   
    void input (){

         if (kbhit()){
            switch (getch())
           { //  dir =getch();
            case 'a':
               if (dir!='d')
                dir='a';
               break;
              case 'd':
               if (dir!='a')
                dir='d';
               break;
              case 's':
               if (dir!='w')
                dir='s';
               break;
              case 'w':
               if (dir!='s')
                dir='w';
               break;
            
           
            }
         }


    }
 void logic(){

   // retain previous tail
 int prevX = tailx[0];                     //----------------------------------
    int prevY = taily[0];
    int prev2X, prev2Y;
    
    tailx[0] = x;
    taily[0] = y;
    
    // Move the rest of the tail
    for (int i = 1; i < sn; i++) {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }                                                          //-------------------------------
                




   //move tail
   switch (dir)
   {
   case 'a':
       x-- ;
     break;
   case 'd':
       x++ ;
     break;
   case 'w':
       y--;
     break;
   case 's':
       y++;
     break;
   
   default:
      break;
   }
   
   if(x<1 || x>90 || y<1 || y>30)
        lose =1 ;
    for (int i = 0; i < sn; i++) {
        if (tailx[i] == x && taily[i] == y)
            lose = 1;
    }
      if (x == ratx && y == raty) {
        sn++;
        ratx= rand() % 90 + 1;
        raty= rand() % 30 + 1 ;

 }
 }
int main(){
    srand(time(0));   
      
      while(!lose){
       setup()  ;
      input();
      logic();
      Sleep(100);
   }
        
           printf("\nGame Over!\n");
           printf("\n");
 
        
        
         
    
   return 0;

 }