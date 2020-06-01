                                                                      /*  By RAHUL JAGLAN   */


/*Creation of Binary Search Tree and checking imbalance in it*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node//This contains tree structure
{
	int dat;
	struct node *rchild;
	struct node *lchild;
}*root=NULL;

struct nodestak//A stack for implementation of bst
{
	struct node *data;
	struct nodestak *next;
}*top=NULL;

void push(struct node *x)
{
	struct nodestak *temp;
	temp=(struct nodestak *)malloc(sizeof(struct nodestak));
	temp->data=x;
	temp->next=top;
	top=temp;
}

struct node  *pop()
{
	struct nodestak *temp;
	temp=top;
	struct node *x=temp->data;
	top=top->next;
	free(temp);
	return x;
}

int sttop()
{
	if(top==NULL)
		return INT_MAX;
	else
		return top->data->dat;
}

int height(struct node *p)
{
	int x,y;
	if(p==NULL)
		return 0;

	x=height(p->lchild);
	y=height(p->rchild);
	return x>y?x+1:y+1;
}

void imbalance(struct node *p)
{
	if(p==NULL)
		return;
	int x=height(p->lchild)-height(p->rchild);
	printf("Balance factor of node %d is %d\n",p->dat,x);
	if(x!=-1&&x!=0&&x!=1)
		printf("Thus node %d is imbalanced\n\n",p->dat);
	else
		printf("Thus node %d is balanced\n\n",p->dat);

	imbalance(p->lchild);
	imbalance(p->rchild);
}

int main()
{
	printf("Enter the no. of node u want  to enter in binary search tree\n");
	int n;
	int i=0;
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements of binary search tree in preorder\n");
	for(;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	i=0;
	root=(struct node *)malloc(sizeof(struct node));
	root->dat=A[i++];
	root->rchild=root->lchild=NULL;
	struct node *p=root;
	
	while(i<n)
	{
		if(A[i]<p->dat)
		{
			struct node *t;
			t=(struct node *)malloc(sizeof(struct node));
			t->dat=A[i++];
			t->rchild=t->lchild=NULL;
			p->lchild=t;
			push(p);
			p=t;
		}
		else
		{
			if(A[i]>p->dat&&A[i]<sttop())
			{
				struct node *t;
				t=(struct node *)malloc(sizeof(struct node));
				t->dat=A[i++];
				t->rchild=t->lchild=NULL;
				p->rchild=t;
				p=t;
			}
			else
				p=pop();
		}
	}
	imbalance(root);
	return 0;
}