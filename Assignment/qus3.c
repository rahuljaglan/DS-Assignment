                                                                               /*    By RAHUL JAGLAN    */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>         

typedef struct node{
    char data[10];      
      
    struct node* left;
    struct node* right;
} tnode;

tnode* root;

tnode* newnode(char s[20])
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    
    strcpy(new->data,s);

    new->left=NULL;
    new->right=NULL;
    
    return new;

}
void initialise()
{
    root=newnode("Arthi");
    
    root->right=newnode("Christy");
    
    root->right->right=newnode("Dorothy");
    
    root->right->right->right=newnode("Fraser");
    
    root->right->right->right->left=newnode("Eliza");

}

void insert(struct node* t,char* s)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=t;
    while(1)
    {
        if(temp)
        {
            if(strcmp(temp->data,s)>0)
            {                
                if(temp->left)
                    temp=temp->left;
                
                else
                {
                    temp->left=newnode(s);
            
                    return;
                }                
            }
            else
            {
                if(temp->right)
                    temp=temp->right;
                
                else
                {
                    temp->right=newnode(s);
            
                    return;
                }               
            }
        }
    }
}
/*to print the tree in preorder*/
void preorder(struct node* t)
{
    if(!t)
    {
        return;
    }
    if(t)
    {        
        puts(t->data);
        preorder(t->left);
        preorder(t->right);
    }   
}

void main()
{
    printf("\n (3). insterting a node in a B.S.T. of strings\n");

    initialise();
    
    printf("\n Initially the binary tree in preorder is : \n");

    preorder(root);

    printf("\n Now, after inserting \"David\" into this BST : \n");

    insert(root,"David");
    preorder(root);
}