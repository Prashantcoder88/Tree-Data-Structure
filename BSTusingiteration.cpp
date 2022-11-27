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

int isBST(struct node* root)
{
    static struct node *prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node* search(struct node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(key == root->data)
    {
        return root;
    }
    else if(root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
    
    
    
}
struct node* searchitr(struct node* root, int key)
{
    while(root != NULL){
    if(key == root->data)
    {
        return root;
    }
    else if(key < root->data)
    {
        root = root -> left;
    }
    else
    {
        root = root -> right;
    }
    }   
    return NULL;
}
int main()
{
	struct node* p = createnode(5);
	struct node* p1 = createnode(3);
	struct node* p2 = createnode(6);
	struct node* p3 = createnode(1);
	struct node* p4 = createnode(4);
	
	/*		5
		  /	  \
		3		6
	  /   \
	1		4		
	*/
	p->left = p1;
	p->right = p2;
	p1->left=p3;
	p1->right=p4;
	
	/*preorder(p);
	cout<<endl;
	postorder(p);
	cout<<endl;
	inorder(p);
	cout<<endl;
	cout<<isBST(p);*/
	
	struct node* n = search(p,6);
	if(n != NULL){
	cout<<"Element found using recursion: "<<n->data;
	}
	else
	{
	    cout<<"Element not found";
	}
	cout<< "\n";
	struct node* m = searchitr(p,6);
	if(n != NULL){
	cout<<"Element found using iteration : "<<n->data;
	}
	else
	{
	    cout<<"Element not found";
	}
	return 0;
}