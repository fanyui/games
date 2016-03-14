#include<gtk/gtk.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
static void start(GtkWidget *button,GtkWidget *window);
//gbolean delet_event();
GtkWidget *entry;
void delay(int x);
int main(int argc,char *argv[]){
GtkWidget *window,*vbox,*hbox1,*hbox2,*hbox3,*hbox4,*sendbutton,*clearbutton,*startbutton,*stagebutton;
GtkWidget *button;
GtkWidget *entry1,*entry2,*entry3;
GtkWidget *textview;

	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"timing game");
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_widget_set_size_request(window,550,250);
		vbox=gtk_vbox_new(TRUE,2);

		hbox1=gtk_hbox_new(FALSE,0);
		//creating buttons
		startbutton=gtk_button_new_with_label("start");
		sendbutton=gtk_button_new_with_label("send");
		clearbutton=gtk_button_new_with_label("clear");
		stagebutton=gtk_button_new_with_label("stage");

//creating entries
		entry=gtk_entry_new();
		entry1=gtk_entry_new();
		entry2=gtk_entry_new();
		entry3=gtk_entry_new();

//connecting signals
	g_signal_connect(G_OBJECT(startbutton),"clicked",G_CALLBACK(start),(gpointer) window);
		//g_signal_connect(G_OBJECT(sendbutton),"clicked",G_CALLBACK(semd),gpointer(window));
		//g_signal_connect(G_OBJECT(clearbutton),"clicked",G_CALLBACK(clear),gpointer(window));
		//g_signal_connect(G_OBJECT(stagebutton),"clicked",G_CALLBACK(stage),gpointer(window));
		
//packing into the specific boxes
		gtk_box_pack_start(GTK_BOX(hbox1),startbutton,FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox1),stagebutton,FALSE,FALSE,0);

//packing the main display entry
		hbox2=gtk_hbox_new(FALSE,0);
			gtk_widget_set_size_request(entry,300,50);
			gtk_box_pack_start(GTK_BOX(hbox2),entry,FALSE,FALSE,0);
			gtk_widget_show(hbox2);
//packing the entries for the user
		hbox3=gtk_hbox_new(FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox3),entry1,FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox3),entry2,FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox3),entry3,FALSE,FALSE,0);
			
		
//packing the send and clear button
		hbox4=gtk_hbox_new(FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox4),sendbutton,FALSE,FALSE,0);
		gtk_box_pack_start(GTK_BOX(hbox4),clearbutton,FALSE,FALSE,0);

		gtk_box_pack_start(GTK_BOX(vbox),hbox1,TRUE,TRUE,0);		//pack into main vbox
		gtk_box_pack_start(GTK_BOX(vbox),hbox2,TRUE,TRUE,0);	//pack into main vbox
		gtk_box_pack_start(GTK_BOX(vbox),hbox3,FALSE,FALSE,0);//pack into main vbox
		gtk_box_pack_start(GTK_BOX(vbox),hbox4,FALSE,FALSE,0);	//pack into main vbox

		gtk_container_add(GTK_CONTAINER(window),vbox);
		gtk_widget_show_all(window);
	gtk_main();
	return 0;

}
static void start(GtkWidget *button,GtkWidget *window){
gtk_entry_set_text(GTK_ENTRY(entry),"waiting");
int num1,num2,num3;
srand(time(NULL));
num1=rand()%100;
num2=rand()%100;
num3=rand()%100;
gtk_widget_show_all(window);
//gtk_entry_set_text(entry," %d  %d  %d",num1,num2,num3);
//printf("%d\t%d\t%d\n",num1,num2,num3);
delay(10);
gtk_entry_set_text(GTK_ENTRY(entry),"gone ");
//system("cls");
/*printf("enter the numbers you saw\n");
scanf("%d %d %d",&resp1,&resp2,&resp3);
if((resp1==num1)&&(resp2==num2)&&(resp3==num3)){
    printf("you got it correct good job mr %s\n",name);
        flag=1;
    }
else {
        printf("sorry mr %s the correct numbers are\n",name);
            flag=0;
}
    printf("\t%d\t%d\t%d\n",num1,num2,num3);
    printf("you gave %d\t%d\t%d\n",resp1,resp2,resp3);

*/
}

//function to pause for the specified time as parameter
void delay(int x){
    unsigned int start,stop;
        start=time(0);
    do{
            stop=time(0);
    }
    while(stop-start!=x);
}