#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
};
node* newNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void sortintodoubly(node * root,node *&head)
{
    if(!root){
        return;
    }
    sortintodoubly(root->right,head);

    root->right=head;
    if(head)
        head->left=root;
    head=root;
    sortintodoubly(root->left,head);
}
node * listtobst(node *&head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    node * left=listtobst(head,n/2);
    node * root=head;
    root->left=left;
    head=head->right;
    root->right=listtobst(head,n-n/2-1);
    return root;
}
void inorder(node * root){
    if(root){
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
	node* root = NULL;

	root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(16);

	root->left->left = newNode(1);
	root->left->right = newNode(6);

	root->right->left = newNode(12);
	root->right->right = newNode(18);


    node * head=NULL;
    sortintodoubly(root,head);
    node * curr=head;
    int n=0;
    while(curr){
        n++;
        cout<<curr->data<<" ";
        curr=curr->right;
    }

    node * newbst=listtobst(head,n);
    cout<<"\n";
    inorder(newbst);
	return 0;
}

