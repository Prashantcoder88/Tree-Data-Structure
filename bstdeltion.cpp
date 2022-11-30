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
struct node* inorderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int key)
{
    struct node* iPre;
    //base condition for recursion
    if(root == NULL)
    {
        return NULL;
        
    }
    if(root ->left == NULL && root -> right == NULL)
    {
        free(root);
        return NULL;
    }
    // search for the node to be deleteNode
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
        
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inorderPredecessor(root);
        root -> data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
	
/*struct node* n = search(p,6);
	if(n != NULL){
	cout<<"Element found : "<<n->data;
	}
	else
	{
	    cout<<"Element not found";
	}*/
	inorder(p);
	deleteNode(p,5);
	cout<<"\n";
	inorder(p);
	return 0;
}