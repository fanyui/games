//a program to play the tower of hanoi game
//developed by harisu fanyui
// a smartsoft product from smartlab
//go and win the game while you play with others
#include<stdio.h>
#include<stdlib.h>
typedef int * tower;//pointer to integer to be used as the towers
int cnt;//to keep track of the operations taking place
void move(int n,tower a,tower b,tower c,int size);//move  elmt from tower a to c using b as temporal
int topindex(tower a,int size);//returns the top index of a tower so we can use the value in it later
int get_n();//collects the number of disk availabel
void showmoves(tower a,tower b,tower c,int d,int size);//prints the moves out on the screen
int main(){
tower a,b,c;//creating towers
int i;
int n,size;
cnt=0;
n=get_n();//returns the number of disk the user provided
size=n+1;//more than number of disk to store the lebel at index 0;

a=calloc(size,sizeof(int));//allocating memmory for the towers
b=calloc(size,sizeof(int));
c=calloc(size,sizeof(int));

a[0]='A';//putting lebble in the first indexes
b[0]='B';
c[0]='C';
for(i=1;i<size;i++)//innitialising first tower with the values of the loop
a[i]=i;
showmoves(a,b,c,0,size);
move(n,a,b,c,size);




}
//returns the index of the top element
int topindex(tower a,int size){
    int i;
    for (i=1;i<size && a[i]==0;i++)
    ;
    return i;
}
//functionn to display the moves on the monitor
void showmoves(tower a,tower b,tower c,int d,int size){
    if(cnt==0)
    printf("%5d%-26s\n", cnt, ": Start:");
    else
    printf("%5d%s%d%s%c%s%c%s\n",cnt,": Move disk ",d," from ",a[0]," to ",c[0],":");
}
//function to receive the number of disc
int get_n(){
    int n;
printf("how many disk do you have to arranged\n");
    while(1){
    if (scanf("%d",&n)!=1||n<1)
        printf("Error! please input a positive interger\n");
        else
    return n;
    }

}
//function to move from tower a to c passing through b
void move(int n,tower a ,tower b ,tower c,int size){
    int i;//to store the top indes of the departure tower(element)
    int j;//to store the top index of the destination tower
    int d;//stores the element of the departing tower
    cnt++;//count for successful placement of the first element in it right position
    if(n==1){//if only one disc is available
    j=topindex(c,size);
    i=topindex(a,size);
    d=a[i];
    a[i]=0;
    c[j-1]=d;
    showmoves(a,b,c,d,size);//display the moves that is taking place on the screen

    }
    else{
    move(n-1,a,c,b,size);//moves n-1 element to intermediate b tower
    move(1,a,b,c,size);//moves the remaining last (n) to tower c
    move(n-1,b,a,c,size);//moves the n-1 from b to c through intermediate a
}
}
