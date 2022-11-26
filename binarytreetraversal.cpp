#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* createnode(int data){
	struct node* n; // creating a node pointer
	n = (struct node*)malloc(sizeof(struct node)); // allocating memory in the heap
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
void preorder(struct node* root)
{
	if(root != NULL)
	{
			cout<<" "<<root->data;
			preorder(root->left);
			preorder(root->right);
			
	}
	
	
}
void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<< " "<<root->data;
    }
}
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}
int main()
{
	struct node* p = createnode(4);
	struct node* p1 = createnode(1);
	struct node* p2 = createnode(6);
	struct node* p3 = createnode(5);
	struct node* p4 = createnode(2);
	
	/*		4
		  /	  \
		1		6
	  /   \
	5		2		
	*/
	p->left = p1;
	p->right = p2;
	p1->left=p3;
	p1->right=p4;
	
	preorder(p);
	cout<<endl;
	postorder(p);
	cout<<endl;
	inorder(p);
	return 0;
}