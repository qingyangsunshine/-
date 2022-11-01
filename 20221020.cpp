#include<stdio.h>
#include<stdlib.h>

typedef struct s_node{
	int data;
	struct s_node *pNext;
}Node;

Node *create_list_head()
{
	Node *head=(Node *)malloc(sizeof(Node));
	if(head!=NULL)
	{
		head->data=-1;
		head->pNext=NULL;
	}
	return head;
}

Node *create_new_node(int node_data)
{
	Node *new_node=(Node *)malloc(sizeof(Node));
	if(new_node!=NULL)
	{
		new_node->data=node_data;
		new_node->pNext=NULL;

	}
	return new_node;
}

int add_node_head(Node* head,Node* new_node)
{
	if(head==NULL || new_node==NULL)
		return -1;
	new_node->pNext=head->pNext;
	head->pNext=new_node;
	return 0;

}

void display_list(Node* head)
{
	if(head==NULL)
		return;
	Node* tmp=head;
	printf("list data:");
	while((tmp=tmp->pNext)!=NULL)
	{
		printf("%d  ",tmp->data);

	}
	printf("\n");
}

void free_list(Node* head)
{
	if(head==NULL)
		return;
	Node* p=head;
	while(p=p->pNext)
	{
		head->pNext=p->pNext;
		free(p);
		p=head;
	}
	free(head);
}

Node* revert_list(Node* head)
{
	if(NULL == head)
		return head;

	Node* p=head->pNext;
	head->pNext=NULL;
	Node* tmp=NULL;
	while(p)
	{
		tmp=p->pNext;
		add_node_head(head,p);
		p=tmp;

	}
	return head;
}

int main(int argc,char* argv[])
{
	Node* head=create_list_head();
	if(head==NULL)
	{
		printf("create_list_head failed!\n");
		return -1;
	}

	int i=0;
	for(i=1;i<8;i++)
		add_node_head(head,create_new_node(i));

	printf("before ");
	display_list(head);

	head=revert_list(head);
	printf("after ");
	display_list(head);

	free_list(head);
	return 0;


}