#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */


int i;
struct node
{
    char ch;
    char str[100];
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *p1=NULL;

void addnodeforpath(char ch) {
if(head1==NULL) {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    head1=New;
    New->ch=ch;
    New->next=NULL;
}

else {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    New->ch=ch;
    New->next=NULL;
    for(p1=head1;p1->next!=NULL;p1=p1->next);
        p1->next=New;
}
}

struct node *p2=NULL;
void displayPaths()
{
    struct node *tmp;
    if(head1 == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = head1;
        while(tmp != NULL)
        {
            printf(" Data = %c\n", tmp->ch);       // prints the data of current node
            tmp = tmp->next;                     // advances the position of current node
        }
    }
}



void pushToHistory(struct node** head_ref, char* new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->str, new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}




/* Given a reference (pointer to pointer) to the head of a list
and a key, deletes the first occurrence of key in linked list */
void deleteFromHistory(struct node **head_ref, char* key)
{
	// Store head node
	  struct node* temp = *head_ref, *prev;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

	// If head node itself holds the key to be deleted
	if (temp != NULL && strcmp(temp->str,key)==0)
	{
		*head_ref = temp->next;
    new_node->next = *head_ref; // Changed head
    strcpy(new_node->str,key);
		free(temp); // free old head
		return;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (temp != NULL && strcmp(temp->str,key)!=0)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL) return;

	// Unlink the node from linked list
	prev->next = temp->next;

	free(temp); // Free memory
  new_node->next = *head_ref; // Changed head
  strcpy(new_node->str,key);
}

void printList(struct node *node)
{
  int i=0;
	while (i<10)
	{
		printf("\n%s", node->str);
		node = node->next;
    i++;
	}
}

// Takes head pointer of
// the linked list and index
// as arguments and return
// data at index
int GetNthFromHistory(struct node* head,
                  int index)
{

    struct node* current = head;

     // the index of the
     // node we're currently
     // looking at
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return(current->str);
        count++;
        current = current->next;
    }

    /* if we get to this line,
       the caller was asking
       for a non-existent element
       so we assert fail */
    assert(0);
}

void PATH(){//geçici---> all path list
  char string[] = "bash: /home/busra/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/opt/mssql-tools/bin:/opt/mssql-tools/bin: No such file or directory";//geçici örnek
	int init_size = strlen(string);
	char delim[] = ":";

	char *pointer = strtok(string, delim);

	while(pointer != NULL)
	{
		printf("\n'%s'\n", pointer);
		pointer = strtok(NULL, delim);
	}
}


void main() {
struct node** head = NULL;

  if (strcmp(args[0], "history") == 0) { //if command is history
    printList(head);
  }

  if (strcmp(args[0], "path") == 0) { //if command is history
      PATH();
  }



  /*if (strcmp(args[0], "history -i 9") == 0) { //if command is a spesific history index
      execute(GetNth(head, 9)));
      deleteFromHistory(head,GetNth(head, 9));
      exit(0);
  }*/

  //GetNthFromHistory(head, 9));



/* Start with the empty list */


pushToHistory(&head, "ar");
pushToHistory(&head, "br");
pushToHistory(&head, "ce");
pushToHistory(&head, "dy");
pushToHistory(&head, "ar");
pushToHistory(&head, "br");
pushToHistory(&head, "ce");
pushToHistory(&head, "dy");
pushToHistory(&head, "ar");
pushToHistory(&head, "br");
pushToHistory(&head, "ce");

puts("Created Linked List: ");
printList(head);
deleteFromHistory(&head, "dy");
puts("\nLinked List after Deletion of a path/dir: ");
printList(head);
PATH();
return 0;


char ch,frm,to;
printf("Enter the string:\n");
while((ch=getchar())!='\n')
    addnodeforpath(ch);
for(p1=head1;p1!=NULL;p1=p1->next){
    printf("\n%c",p1->ch);}
printf("\n------------------------");



}
