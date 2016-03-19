// A timing game developed by harisu using the gtk interface

#include<gtk/gtk.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

static void entry_changed (GtkEditable*, GtkAssistant*);
static void button_toggled (GtkButton* ,GtkAssistant*);
static void button_clicked (GtkButton*, GtkAssistant*);
static void assistant_cancel (GtkAssistant*, gpointer);
static void assistant_close (GtkAssistant*, gpointer);
//callback functions for page 5
static void delay(int x);
static  void startfunc(GtkWidget*,GtkAssistant*);
static void clearAfterTime(GtkWidget*,GtkAssistant*);//function to clear the content of the entry after a particular time elapse depending on the level
static void sendfunc(GtkWidget *button,GtkAssistant *assistant);
static void clearfunc(GtkWidget *button,GtkAssistant *assistant);
static void activate_display(GtkEditable *entry,GtkAssistant *assistant);

int num1,num2,num3;
char result[30];

typedef struct {
GtkWidget *widget;
gint index;
const gchar *title;
GtkAssistantPageType type;
gboolean complete;
} PageInfo;
int level_flag;
GtkWidget *level1,*level2,*level3;//for the check buttons of assistant 3
GtkWidget *entry;//for the name entry in assistant number 2
GtkWidget *display,*input1,*input2,*input3,*info_label, *hbox1_5;//for the entries of assistant 5 to display and accept user response
int main (int argc,
char *argv[])
{
GtkWidget *assistant, *label, *button, *progress, *hbox;
GtkWidget *go_button,*vbox;
guint i;
GtkWidget *vbox5,*hbox2_5,*hbox3_5,*hbox4_5,*send,*clear,*start,l;//page 5 private widgets

PageInfo page[6] = {
{ NULL, -1, "Introduction",GTK_ASSISTANT_PAGE_INTRO, TRUE},
{ NULL, -1, "Register or sign in if you are a new user",GTK_ASSISTANT_PAGE_CONTENT, FALSE},
{ NULL, -1, "Select A Level", GTK_ASSISTANT_PAGE_CONTENT, FALSE},
{ NULL, -1, "Click the Button to start",GTK_ASSISTANT_PAGE_PROGRESS, FALSE},
{ NULL, -1, "Game Begins Click Start", GTK_ASSISTANT_PAGE_CONTENT, FALSE},
{ NULL, -1, "Confirmation",GTK_ASSISTANT_PAGE_CONFIRM, TRUE},
};
gtk_init (&argc, &argv);


/* Create a new assistant widget with no pages. */
assistant = gtk_assistant_new ();
gtk_widget_set_size_request (assistant, 450, 300);
gtk_window_set_title (GTK_WINDOW (assistant), "Timing game first version");
g_signal_connect (G_OBJECT (assistant), "destroy",G_CALLBACK (gtk_main_quit), NULL);
page[0].widget = gtk_label_new ("This is a timing game developed  By harisu fanyui\nthis game is going to help you develope your brain.\nThe conputer will generate numbers and you are\nrequired to store these numbers in your head so that \nwhen you are asked to by the computer you will give it back.\nIt sounds wierd but get your head ready to compute.\nHope you do enjoy it as i do enjoy coding and developing it.");
page[1].widget = gtk_hbox_new (FALSE, 5);
page[2].widget = gtk_vbox_new (FALSE, 5);
page[3].widget = gtk_alignment_new (0.5, 0.5, 0.0, 0.0);
page[4].widget = gtk_vbox_new (FALSE, 5);
page[5].widget = gtk_label_new ("Thank you don't forget to subscribe for more product.\nYour brain is on the go unlock final stage online \nwill be very happy to receive your feedback\ncontact the programmer in facebook at harisu fanyui\nor email me at fanyuiharisu@gmail.com");

//gtk_label_new ("the game proper begins here . If you are done, then\nhere the game begins!");

/* Create the necessary widgets for the second page. */
label = gtk_label_new ("Your Name: ");
entry = gtk_entry_new ();
gtk_box_pack_start (GTK_BOX (page[1].widget), label, FALSE, FALSE, 5);
gtk_box_pack_start (GTK_BOX (page[1].widget), entry, FALSE, FALSE, 5);

//create the necessatry widget for page 3
vbox=gtk_vbox_new(FALSE,5);
level1=gtk_check_button_new_with_label("level 1");
level2=gtk_check_button_new_with_label("level 2");
level3=gtk_check_button_new_with_label("level 3");
go_button=gtk_button_new_with_label("submit");
gtk_box_pack_start(GTK_BOX(vbox),level1,FALSE,FALSE,5);
gtk_box_pack_start(GTK_BOX(vbox),level2,FALSE,FALSE,5);
gtk_box_pack_start(GTK_BOX(vbox),level3,FALSE,FALSE,5);
gtk_box_pack_start(GTK_BOX(vbox),go_button,FALSE,FALSE,5);
gtk_container_add(GTK_CONTAINER (page[2].widget),vbox);

/* Create the necessary widgets for the fourth page. The, Attach the progress bar
* to the GtkAlignment widget for later access.*/
button = gtk_button_new_with_label ("load");
progress = gtk_progress_bar_new ();
hbox = gtk_hbox_new (FALSE, 5);
gtk_box_pack_start (GTK_BOX (hbox), progress, TRUE, FALSE, 5);
gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 5);
gtk_container_add (GTK_CONTAINER (page[3].widget), hbox);
g_object_set_data (G_OBJECT (page[3].widget), "pbar", (gpointer) progress);

//create the necessary widgets for the fifth page
vbox5=gtk_vbox_new(FALSE,2);//main vbox to be packed inside the page[5].widget  widget
hbox1_5=gtk_hbox_new(FALSE,2);
hbox2_5=gtk_hbox_new(FALSE,2);
hbox3_5=gtk_hbox_new(FALSE,2);
hbox4_5=gtk_hbox_new(FALSE,2);
start=gtk_button_new_with_label("START");
display=gtk_entry_new();
gtk_widget_set_size_request(display,300,30);
input1=gtk_entry_new();
input2=gtk_entry_new();
input3=gtk_entry_new();
info_label=gtk_label_new("input the values you saw in the box below");
gtk_widget_hide_all(hbox3_5);
send=gtk_button_new_with_label("Send");
clear=gtk_button_new_with_label("Clear");
gtk_box_pack_start (GTK_BOX (hbox1_5), start, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox1_5), display, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox2_5), input1, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox2_5), input2, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox2_5), input3, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox3_5), info_label, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox4_5), send, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (hbox4_5), clear, TRUE, FALSE, 2);
//packing hbox into vbox5
gtk_box_pack_start (GTK_BOX (vbox5), hbox1_5, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (vbox5), hbox3_5, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (vbox5), hbox2_5, TRUE, FALSE, 2);
gtk_box_pack_start (GTK_BOX (vbox5), hbox4_5, TRUE, FALSE, 2);

gtk_container_add(GTK_CONTAINER(page[4].widget),vbox5);
g_signal_connect(G_OBJECT(start),"clicked",G_CALLBACK(startfunc),(gpointer) assistant);
_signal_connect(G_OBJECT(start),"clicked",G_CALLBACK(clearAfterTime),(gpointer) assistant);
g_signal_connect(G_OBJECT(send),"clicked",G_CALLBACK(sendfunc),(gpointer) assistant);
g_signal_connect(G_OBJECT(clear),"clicked",G_CALLBACK(clearfunc),(gpointer) assistant);
g_signal_connect(G_OBJECT(display),"activate",G_CALLBACK(activate_display),(gpointer) assistant);
//wait for specific number of seconds depending on the level
if(level_flag==1){
	delay(5);
	gtk_entry_set_text(GTK_ENTRY(display)," ");
}else if(level_flag==2){
	delay(3);
	gtk_entry_set_text(GTK_ENTRY(display)," ");
}



/* Add five pages to the GtkAssistant dialog.*/
for (i = 0; i < 6; i++)
{
page[i].index = gtk_assistant_append_page (GTK_ASSISTANT (assistant),page[i].widget);
gtk_assistant_set_page_title (GTK_ASSISTANT (assistant),page[i].widget, page[i].title);
gtk_assistant_set_page_type (GTK_ASSISTANT (assistant),page[i].widget, page[i].type);
//gtk_assistant_set_page_type (GTK_ASSISTANT (assistant),page[i].widget, page[i].type);

/* Set the introduction and conclusion pages as complete so they can be
* incremented or closed. */
gtk_assistant_set_page_complete (GTK_ASSISTANT (assistant),
page[i].widget, page[i].complete);
}
/* Update whether pages 2 through 4 are complete based upon whether there is
* text in the GtkEntry, the check button is active, or the progress bar
* is completely filled. */
g_signal_connect (G_OBJECT (entry), "changed",G_CALLBACK (entry_changed), (gpointer) assistant);
g_signal_connect (G_OBJECT (go_button), "clicked",G_CALLBACK (button_toggled), (gpointer) assistant);
g_signal_connect (G_OBJECT (button), "clicked",G_CALLBACK (button_clicked), (gpointer) assistant);

g_signal_connect (G_OBJECT (assistant), "cancel",G_CALLBACK (assistant_cancel), NULL);
g_signal_connect (G_OBJECT (assistant), "close",G_CALLBACK (assistant_close), NULL);
gtk_widget_show_all (assistant);
gtk_main ();
return 0;
}
/* If there is text in the GtkEntry, set the page as complete. Otherwise,* stop the user from progressing the next page. */
static void entry_changed (GtkEditable *entry,GtkAssistant *assistant)
{
const gchar *text = gtk_entry_get_text (GTK_ENTRY (entry));
gint num = gtk_assistant_get_current_page (assistant);
GtkWidget *page = gtk_assistant_get_nth_page (assistant, num);

gtk_assistant_set_page_complete (assistant, page, (strlen (text) > 0));

}
/* If the check button is toggled, set the page as complete. Otherwise,
* stop the user from progressing the next page. */
static void button_toggled (GtkButton *toggle,GtkAssistant *assistant){

const gchar *text1 = gtk_entry_get_text (GTK_ENTRY (entry));
printf("%s",text1);

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(level1)))
		level_flag=1;
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(level2)))
		level_flag=2;
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(level3)))
		level_flag=3;
	gint num = gtk_assistant_get_current_page (assistant);
	gtk_widget_set_sensitive (GTK_WIDGET (toggle), FALSE);
	GtkWidget *page = gtk_assistant_get_nth_page (assistant, num);
gtk_assistant_set_page_complete (assistant, page, TRUE);
}
/* Fill up the progress bar, 10% every second when the button is clicked. Then,
* set the page as complete when the progress bar is filled. */
static void button_clicked (GtkButton *button,GtkAssistant *assistant){
GtkProgressBar *progress;
GtkWidget *page;
gdouble percent = 0.0;
gtk_widget_set_sensitive (GTK_WIDGET (button), FALSE);
page = gtk_assistant_get_nth_page (assistant, 3);
progress = GTK_PROGRESS_BAR (g_object_get_data (G_OBJECT (page), "pbar"));
while (percent <= 100.0)
{
gchar *message = g_strdup_printf ("%.0f%% Complete", percent);
gtk_progress_bar_set_fraction (progress, percent / 100.0);
gtk_progress_bar_set_text (progress, message);
while (gtk_events_pending ())
gtk_main_iteration ();
g_usleep (500000);
percent += 5.0;
}
gtk_assistant_set_page_complete (assistant, page, TRUE);
}
/* If the dialog is cancelled, delete it from memory and then clean up after* the Assistant structure. */
static void assistant_cancel (GtkAssistant *assistant,gpointer data){
gtk_widget_destroy (GTK_WIDGET (assistant));
}
/* This function is where you would apply the changes and destroy the assistant. */
static void assistant_close (GtkAssistant *assistant,
gpointer data)
{
g_print ("You would apply your changes now!\n");
gtk_widget_destroy (GTK_WIDGET (assistant));
}


static  void startfunc(GtkWidget *button,GtkAssistant *assistant){

srand(time(NULL));
if(level_flag==1){

	num1=rand()%100;
	num2=rand()%100;
	num3=rand()%100;
}
else if(level_flag==2){

	num1=rand()%1000;
	num2=rand()%1000;
	num3=rand()%1000;

}
else if(level_flag==3){

	num1=rand()%10000;
	num2=rand()%10000;
	num3=rand()%10000;
}

sprintf(result,"%d   %d   %d",num1,num2,num3);


//gtk_widget_activate (GTK_WIDGET (display));
gtk_editable_set_editable (GTK_EDITABLE(display),TRUE);
gtk_entry_set_text(GTK_ENTRY(display),result);

//g_signal_stop_emission_by_name((gpointer)display,"activate");

}


static void delay(int x){
    unsigned int start,stop;
        start=time(0);
    do{
            stop=time(0);
    }
    while(stop-start!=x);
}

static void clearAfterTime(GtkWidget*,GtkAssistant*){
	switch(level_flag){
		case 1:
			delay(5);
			gtk_entry_set_text(GTK_ENTRY(display),"");
		break;		
		case 2: 
			delay(3);
			gtk_entry_set_text(GTK_ENTRY(display),"");
		break;
		case 3: 
			delay(2);
			gtk_entry_set_text(GTK_ENTRY(display),"");
		break;
	default gtk_entry_set_text(GTK_ENTRY(display),"improper privilage to this level");
	break;
	}
}
static void sendfunc(GtkWidget *button,GtkAssistant *assistant){
const char *get_input1,*get_input2,*get_input3;
int first,second,third;//to be used by atoi to convert the strings from the entry to integers
//getting the response from the user
get_input1=gtk_entry_get_text(GTK_ENTRY(input1));
get_input2=gtk_entry_get_text(GTK_ENTRY(input2));
get_input3=gtk_entry_get_text(GTK_ENTRY(input3));
//convertint the response to integers
first=atoi(get_input1);
second=atoi(get_input2);
third=atoi(get_input3);
sprintf(result,"%d   %d   %d",num1,num2,num3);
if((first==num1)&&(second==num2)&&(third==num3)){
	gtk_entry_set_text(GTK_ENTRY(display),"good job you win");
	//void gtk_label_set_text (GtkLabel *label,const gchar *str);
	gtk_label_set_text(GTK_LABEL(info_label),result);
}
 else {

 	gtk_entry_set_text(GTK_ENTRY(display),"sorry you did not get it corrent");
 	gtk_label_set_text(GTK_LABEL(info_label),result);
 }
gint num = gtk_assistant_get_current_page (assistant);
GtkWidget *page = gtk_assistant_get_nth_page (assistant, num);
gtk_assistant_set_page_complete (assistant, page, TRUE);
}

//function to clear the content of the page 5 widgets
static void clearfunc(GtkWidget *button,GtkAssistant *assistant){
	gtk_entry_set_text(GTK_ENTRY(display)," ");
	gtk_entry_set_text(GTK_ENTRY(input1)," ");
	gtk_entry_set_text(GTK_ENTRY(input2)," ");
	gtk_entry_set_text(GTK_ENTRY(input3)," ");
	gtk_label_set_text(GTK_LABEL(info_label)," ");

}
static void activate_display(GtkEditable *display,GtkAssistant *assistant){
	

const gchar *text = gtk_entry_get_text (GTK_ENTRY (display));
if(strlen (text) > 0){
	delay(5);
	gtk_entry_set_text(GTK_ENTRY(display),"hello ");

	gtk_widget_show(hbox1_5);
}
}
