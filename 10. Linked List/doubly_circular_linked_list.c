#include<stdio.h>
#include<stdlib.h>
int x;
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *findAfter(struct node *t,int af);
struct node *findPrev(struct node*temp,int r);
struct node *createHeader(){
    if (head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->prev=NULL;
        head->data=-1;
        head->next=head;
    }
    return head;
}
void insert(struct node *t,int x){
    createHeader();
    printf("Head has data %d\n",head->data);
    int af;
    struct node *p,*q;
    printf("Enter the integer after which you want to insert: ");
    scanf("%d",&af);
    p=findAfter(head,af);
    q=(struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->next=p->next;
    q->prev=p;
    p->next=q;
    printf("%d has been inserted\n",q->data);
}
struct node *findAfter(struct node *t,int af){
    while (t->data!=af){
        t=t->next;
    }
    return t;
}
void delete(struct node *t,int r){
    struct node *p,*q;
    p=findPrev(t,r);
    q=p->next;
    p->next=q->next;
    printf("\n%d has been removed\n",q->data);
    free(q);
}
struct node *findPrev(struct node *t,int r){
    while ((t->next)->data!=r){
        t=t->next;
    }
    return t;
}
void display(struct node *temp){
    if (temp==NULL){
        printf("\nThe list is empty");
    }
    else {
        printf("\n");
        while ((temp->next)!=head){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int isempty(struct node *temp){
    if (temp->next==head){
        return 1;
    }
    else {
        return 0;
    }
}
int search(struct node *t,int s){
    int index=0;
    while((t->next)!=head){
        if(t->data==s){
            printf("\nInteger found at index position %d\n",index);
            return 1;
            break;
        }
        else {
            t=t->next;
            index++;
        }
    }
    if (t->data==s){
        printf("\nInteger found at index position %d\n",index);
    }
    else {
        printf("\nInteger not found\n");
    }
    return 0;
}
int main(){
    int input;
    printf("Press 1 to Insert\n");
    printf("Press 2 to Delete\n");
    printf("Press 3 to Display\n");
    printf("Press 4 to check if list is empty\n");
    printf("Press 5 to search any integer in the list\n");
    printf("Press 6 to terminate the program\n");
    scanf("%d",&input);
    if (input==1){
        printf("\nEnter the integer you want to insert: ");
        scanf("%d",&x);
        insert(head,x);
        main();
    }
    else if (input==2){
        if (isempty(head)){
            printf("\nThe list is empty\n");
        }
        else {
            printf("\nEnter the integer you want to delete: ");
            scanf("%d",&x);
            delete(head,x);
        }
        main();
    }
    else if (input==3){
        display(head);
        main();
    }
    else if (input==4){
        if (isempty(head)){
            printf("\nThe list is empty\n");
        }
        else {
            printf("\nThe list is not empty\n");
        }
        main();
    }
    else if (input==5){
        printf("\nEnter the integer you want to search: ");
        scanf("%d",&x);
        search(head,x);
        main();
    }
    else if (input==6){
        exit(0);
    }
    else {
        printf("\nInvalid input, please try again\n");
        main();
    }
    return 0;
}