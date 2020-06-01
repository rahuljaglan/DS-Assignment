                                                                       /*    By RAHUL JAGLAN    */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node//This contains tree structure
{
	int dat;
	struct node *rchild;
	struct node *lchild;
	int hgt;
}*root=NULL;

int height(struct node *p)
{
	int lh,rh;
	if(p&&p->lchild)
	{
		lh=p->lchild->hgt;
	}
	else
		lh=0;
		
	if(p&&p->rchild)
	{
		rh=p->rchild->hgt;
	}
	else
		rh=0;

	return lh>rh?lh+1:rh+1;
}

int  BalanceFactor(struct node *p)
{
	int lh,rh;
	if(p&&p->lchild)
	{
		lh=p->lchild->hgt;
	}
	else
		lh=0;
	
	if(p&&p->rchild)
	{
		rh=p->rchild->hgt;
	}
	else
		rh=0;
	return lh-rh;
}

struct node *llrotation(struct node *p)
{
	struct node *a=p->lchild;
	struct node *b=a->rchild;

	a->rchild=p;
	p->lchild=b;

	if(p==root)
		root=a;

	p->hgt=height(p);
	a->hgt=height(a);
	
	return a;
}

struct node *rrrotation(struct node *p)
{
	struct node *a=p->rchild;
	struct node *b=a->lchild;

	a->lchild=p;
	p->rchild=b;

	if(p==root)
		root=a;

	p->hgt=height(p);
	a->hgt=height(a);
	
	return a;
}

struct node *lrrotation(struct node *p)
{
	struct node *a=p->lchild;
	struct node *b=a->rchild;
	
	a->rchild=b->lchild;
	p->lchild=b->rchild;

	b->lchild=a;
	b->rchild=p;

	a->hgt=height(a);
	p->hgt=height(p);
	b->hgt=height(b);
	if(p==root)
		root=b;

	return b;
}

struct node *rlrotation(struct node *p)
{
	struct node *a=p->rchild;
	struct node *b=a->lchild;
	
	a->lchild=b->rchild;
	p->rchild=b->lchild;

	b->lchild=p;
	b->rchild=a;

	a->hgt=height(a);
	p->hgt=height(p);
	b->hgt=height(b);
	if(p==root)
		root=b;

	return b;
}

struct node *Rinsert(struct node *p,int key)
{
	struct node *t=NULL;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->dat=key;
		t->hgt=1;
		t->lchild=t->rchild=NULL;
		return t;
	}

	if(key<p->dat)
	p->lchild=Rinsert(p->lchild,key);
	else if(key>p->dat)
	p->rchild=Rinsert(p->rchild,key);

	p->hgt=height(p);

// Now from here we start rotations
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
	{
		printf("Performing llrotation on %d\n",p->dat);
		return llrotation(p);
	}
	else
	{
		if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
		{
			printf("Performing lrrotation on %d\n",p->dat);
			return lrrotation(p);
		}
		else 
			{
				if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
				{
					printf("Performing rrrotation on %d\n",p->dat);
					return rrrotation(p);
				}
				else 
					{
						if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
						{
							printf("Performing rlrotation on %d\n",p->dat);
							return rlrotation(p);
						}
					}
			}
	} 
	return p;
}

void preorder(struct node *p)
{
	if(p)
	{
		printf("%d ",p->dat);
		preorder(p->lchild);
		preorder(p->rchild);
	}
	else
		return;
}

int main()
{
	printf("Enter the no. of node u want  to enter in binary search tree\n");
	int n,x;
	int i=1;
	scanf("%d",&n);
	printf("Enter the elements of binary search tree in preorder\n");

	scanf("%d",&x);
	root=Rinsert(root,x);

	for(;i<n;i++)
	{
		scanf("%d",&x);
		Rinsert(root,x);//For insertion of element in tree
	}
	
	printf("\nHeight of AVL tree is\n");
	printf("%d\n",root->hgt);

	printf("\nThe preorder traversal of tree is\n");
	preorder(root);
	return 0;
}