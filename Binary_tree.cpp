/*
          10
    20          30
40     _      _     _
*/ 

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
//Print nodes at a distance k
void print_k_distance(node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        print_k_distance(root->left,k-1);
        print_k_distance(root->right,k-1);
    }
}

// Height of tree
int height(node *root)
{
    if(root==NULL)
        return 0;
    else 
        return max(height(root->left),height(root->right))+1;
}

void inorder(node *root)
{
    
    if(root==NULL)
        return;
    inorder(root->left);
        cout<<root->key<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Level order Traversal 
// ~ Time and space complexity : O(n)
void level_order(node *root)
{
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}

// Size of binary tree : number of nodes in an binary tree 
// Time complexity and auxiliary space : O(n)
int getsize(node *root)
{
    if(root==NULL)
        return 0;
    return (1+getsize(root->left)+getsize(root->right));
}

//Maximum element in binary tree
int getmax(node *root)
{
    if(root==NULL)
        return INT_MIN;
    else 
        return max(  root->key , max(getmax(root->left),getmax(root->right))  );
}

int main()
{
    cout<<endl;
    node *root= new node(10);
    root->left= new node(20);
    root->right = new node(30);
    root->left->left= new node(40);
    
    cout<<"Height of Tree : "<<height(root)<<endl;

        cout<<"Preorder Traversal : ";
        preorder(root);
    cout<<endl;
        cout<<"Inorder Traversal : ";
        inorder(root);
    cout<<endl;
        cout<<"Postorder Traversal : ";
        postorder(root);
    cout<<endl;
        
        cout<<"Level Order Traversal : ";
        level_order(root);
    
    cout<<endl;
        cout<<"Nodes at distance k(2) : ";
        print_k_distance(root,2);
    cout<<endl;

    cout<<"Size of Tree : "<<getsize(root)<<endl;
    
    if(getmax(root)!=INT_MIN)
        cout<<"Maximum element in Tree : "<<getmax(root)<<endl;
    else
        cout<<"No maximum element exist"<<endl;

    cout<<endl<<endl;
    return 0;
}