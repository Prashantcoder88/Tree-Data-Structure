#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createnode(int data) {
	struct node* n;	//creating a node pointer
	n = (sturct node*)malloc(sizeof(struct node)); 	// allocating memory in the heap
	n->data = data; 	// setting the data
	n->left = NULL;		// setting the left child to NULL
	n->right = NULL;	// setting the right child to NULL
	return n;			// finally returning the created Node
	}
int main()
{
	/*constructing the root node
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = 2;
	p->left = NULL;
	p->right = NULL;
	
	//constructing the second node
	struct node* p1;
	p1= (struct node*)malloc(sizeof(struct node));
	p1->data = 3;
	p1->left = NULL;
	p1->right = NULL;
	
	//constructing the third node
	struct node* p2;
	p2= (struct node*)malloc(sizeof(struct node));
	p2->data = 4;
	p2->left = NULL;
	p2->right = NULL;
	
	//linking the root node to right and left
	p->left = p1;
	p->right = p2;  */
	
	// constructing the root node using the function
	struct node* p = createnode(2);
		struct node* p1 = createnode(3);
			struct node* p2 = createnode(4);
	
	//linking the root node to right and left
	p->left = p1;
	p->right = p2;
	return 0;
}