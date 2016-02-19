//developed by harisu fanyui
// a tic tac toe game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
char board[9];
int player=1;
int seeds;
bool fromTo(int x,int y,int player);//to move seed from x to y during the play
void display_board(void);
bool selection(int select,int player);//to carry out selection with the inninial seeds
void checkForWin();
void machine_play();
void supportsite();
int main(){
    int player1Seed=3,player2Seed=3,machineSeed=3;
int who_begins,c;
int play,player2;//lebels for goto statements
int i,previous;
int vlue_frm_function;
int choice_of_player;
int select;
int depart,destination;
srand(time(NULL));
printf("\t\tSMARTSOFT FROM SMARTLAB\n");
printf("do you want to play with a player or with the machine\n");
printf("enter 1 to play with another player or 2 to play with the machine\n");
scanf("%d",&choice_of_player);
for(i=0;i<9;i++)
board[i]=' ';
switch(choice_of_player){
   case 1:
while(board[i]=' '){
    if (player==1){
        display_board();
        checkForWin();
        player1:
            if (player1Seed!=0){
                printf("player X it's is your turn\n");
                printf("Make your box selection\n");
                scanf("%d",&select);
                vlue_frm_function=selection(select,player);\
                 if (vlue_frm_function==false)
                    goto player1;
               // display_board();
                    player1Seed--;
            }
            else {
                    printf("player X it's is your turn\n");
                printf("from___ to __ seperated by space\n");
                scanf("%d%d",&depart,&destination);
            vlue_frm_function=fromTo(depart,destination,player);
             if (vlue_frm_function==false)
                    goto player1;
                //display_board();

            }
            display_board();
              player=2;
    }
//    else if(selection(select,player)==1)
     //   player=2;
    else if (player=2){
        display_board();
         checkForWin();
         player2:
             if (player2Seed!=0){
                printf("player t it's your turn\n");
                printf("make your box selection\n");
                scanf("%d",&select);

               vlue_frm_function= selection(select,player);
                if (vlue_frm_function==false)
                goto player2;
                    player2Seed--;
             }

             else{
                    printf("player t it's your turn\n");
                    printf("from___To___seperated by spaces\n");
                    scanf("%d%d",&depart,&destination);
                    vlue_frm_function=fromTo(depart,destination,player);
                            if(vlue_frm_function==false)
                                goto player2;
             }
            display_board();
          player=1;
       // }

    }
}
break;
   case 2:
   who_begins=rand()%2;
   if(who_begins==1)
   goto play;
      while(board[i]=' '){
          display_board();
         checkForWin();
         previous:
        printf("player X it's your turn\n");
        printf("make your box selection\n");
        scanf("%d",&select);
       vlue_frm_function= selection(select,player);
       if (vlue_frm_function==false)
       goto previous;
       player1Seed--;
           display_board();
          play:
          player='m';
           //the machines turn to play the game
           machine_play();
           machineSeed--;
			display_board();
			checkForWin();
           player=1;

      }
   break;
}
supportsite();
return 0;
}

    void display_board(void){
            system("clear");
            printf("\n    |\t    |\n");
            printf("%c\t%c\t%c\n",board[0],board[1], board[2]);
            printf("____|_______|_____\t\t__1__|____2___|__3___\n");
           printf("\n    |\t    |\n");

            printf("%c\t%c\t%c\n",board[3],board[4], board[5]);
            printf("____|_______|_____\t\t__4__|____5___|__6___\n");

            printf("\n    |\t    |\n");
            printf("%c\t%c\t%c\n",board[6],board[7], board[8]);
             printf("____|_______|_____\t\t__7__|____8___|__9___\n");
            printf("\n    |\t    |\n");

   // return void;
    }
   bool fromTo(int x,int box ,int player){
    if(board[box-1]!=' '){
         printf("box full select a different box it's still your turn\n");
         return false;
         }
        if (player==1){
            board[box-1]='X';
            board[x-1]=' ';
         return true;

       }
        else if (player==2){
            board[box-1]='t';
            board[x-1]=' ';
         return true;
       }
        else if (player=='m'){
         board[box-1]='t';
         board[x-1]=' ';
         return true;
        }
    }


   bool selection(int box,int player){
   if(board[box-1]!=' '){
         printf("box full select a different box it's still your turn\n");
         return false;
         }
        if (player==1){
            board[box-1]='X';
         return true;

       }
        else if (player==2){
            board[box-1]='t';
         return true;
       }
        else if (player=='m'){
         board[box-1]='t';
         return true;
        }
    }

void checkForWin(){
   char store='S';
   if ((board[0]=='X')&&(board[1]=='X')&& (board[2]=='X'))
      store='x';
   else if((board[3]=='X')&&(board[4]=='X')&&(board[5]=='X'))
           store='x';

   else if((board[6]=='X')&&(board[7]=='X')&&(board[8]=='X'))
            store='x';

   else if((board[0]=='X')&&(board[4]=='X')&&(board[8]=='X'))
                 store='x';

   else if((board[2]=='X')&&(board[4]=='X')&&(board[6]=='X'))
           store='x';

   else if((board[0]=='X')&&(board[3]=='X')&&(board[6]=='X'))
           store='x';

   else if((board[1]=='X')&&(board[4]=='X')&&(board[7]=='X'))
            store='x';

   else if((board[2]=='X')&&(board[5]=='X')&&(board[8]=='X'))

           store='x';

   //part for player O

   else if((board[0]=='t')&&(board[1]=='t')&&(board[2]=='t'))
            store='t';

   else if((board[3]=='t')&&(board[4]=='t')&&(board[5]=='t'))
       store='t';
   else if((board[6]=='t')&&(board[7]=='t')&&(board[8]=='t'))
     store='t';
   else if((board[0]=='t')&&(board[4]=='t')&&(board[8]=='t'))
      store='t';
   else if((board[2]=='t')&&(board[4]=='t')&&(board[6]=='t'))
       store='t';
   else if((board[0]=='t')&&(board[3]=='t')&&(board[6]=='t'))
       store='t';
   else if((board[1]=='t')&&(board[4]=='t')&&(board[7]=='t'))
       store='t';
   else if((board[2]=='t')&&(board[5]=='t')&&(board[8]=='t'))
       store='t';



int i,count=0;
   if (store=='x'){
      printf("player X wins\n");
      exit(0);
   }
   else if (store=='t'){
      printf("player t wins\n");
      exit(0);
   }
   else {
            for (i=0;i<9;i++){
               if (board[i]==' ')
                  count++;
            }
            if(count==9)
               printf("the game begins\n");
            else if (count==0){
               printf("draw game\n");
               exit(0);
            }
   }
}
void machine_play(){
   int saveTemp;//to store the return value from the selection function
   int repeat;
   //machine trying to win the game
   if ((board[0]=='t')&&(board[1]=='t')&&(board[2]==' '))
   selection(3,player);
   else if ((board[3]=='t') && (board[4]=='t')&& (board[5]==' '))
    selection(6,player);
    else if ((board[6]=='t') && (board[7]=='t')&& (board[8]==' '))
      selection(9,player);
       else if ((board[0]=='t') && (board[4]=='t')&&(board[8]==' '))
      selection(9,player);
       else if ((board[0]=='t')&&(board[3]=='t')&&(board[6]==' '))
      selection(7,player);
		 else if ((board[0]==' ')&&(board[3]=='t')&&(board[6]=='t'))
      selection(1,player);

      else if ((board[1]=='t')&&(board[4]=='t')&&(board[7]==' '))
      selection(8,player);
      else if ((board[2]=='t')&&(board[5]=='t')&&(board[8]==' '))
      selection(9,player);
       else if ((board[0]==' ')&&(board[4]=='t')&&(board[8]=='t'))
            selection(1,player);
   else if ((board[0]=='t')&&(board[3]==' ')&&(board[6]=='t'))
      selection(4,player);
   else if ((board[6]=='t')&&(board[4]==' ')&&(board[2])=='t')
      selection(5,player);
      else if ((board[2]=='t')&&(board[5]==' ')&&(board[8]=='t'))
      selection(6,player);
   else if ((board[2]=='t')&&(board[4]=='t')&&(board[6]==' '))
      selection(7,player);
	else if ((board[2]==' ')&&(board[5]=='t')&&(board[8]=='t'))
		selection(3,player);

	else if ((board[6]=='t')&&(board[7]==' ')&&(board[8]=='t'))
		selection(8,player);
	else if ((board[6]==' ')&&(board[7]=='t')&&(board[8]=='t'))
		selection(7,player);
    //end of trying to win by the machine

    //start of defending by the machine
   else if ((board[0]=='X') && (board[1]=='X')&&(board[2]==' '))
    selection(3,player);

   else if ((board[3]=='X') && (board[4]=='X')&& (board[5]==' '))
    selection(6,player);
   else if ((board[6]=='X') && (board[7]=='X')&& (board[8]==' '))
      selection(9,player);
      else if ((board[0]=='X') && (board[4]=='X')&&(board[8]==' '))
      selection(9,player);
   else if ((board[0]=='X')&&(board[3]=='X')&&(board[6]==' '))
      selection(7,player);
   else if ((board[1]=='X')&&(board[4]=='X')&&(board[7]==' '))
      selection(8,player);
      else if ((board[2]=='X')&&(board[5]=='X')&&(board[8]==' '))
      selection(9,player);
   else if ((board[0]==' ')&&(board[4]=='X')&&(board[8]=='X'))
            selection(1,player);
   else if ((board[0]=='X')&&(board[3]==' ')&&(board[6]=='X'))
      selection(4,player);
   else if ((board[6]=='X')&&(board[4]==' ')&&(board[2])=='X')
      selection(5,player);
   else if ((board[2]=='X')&&(board[5]==' ')&&(board[8]=='X'))
      selection(6,player);
   else if ((board[2]=='X')&&(board[4]=='X')&&(board[6]==' '))
      selection(7,player);
	  else if ((board[1]==' ')&&(board[4]=='X')&&(board[7]=='X'))
      selection(2,player);
//end of defending by the machine

//random play by the machine particularly when the game just begins
   else{
        checkForWin();

      repeat:
      saveTemp=selection((rand()%9+1),player);
      if (saveTemp==false)
         goto repeat;
   }
}
void supportsite(){
printf("subscrib at my facebook page HARISU FANYUI for more product from smartlab\n");
printf("Or contact me at www.fanyuiharisu@gmail.com ");
printf("Till then enjoy yourself!!!!!!!!!");
}
