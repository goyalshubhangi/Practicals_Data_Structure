#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct TREE{
	int data;
	struct TREE*right;
	struct TREE*left;
}TREE;

TREE *InsertTree(int data,TREE *tree)
{
	if(!tree)
	{
		tree=(TREE *)malloc(sizeof(TREE));
		tree->data=data;
		tree->left=NULL;
		tree->right=NULL;
		return(tree);
			}
			if(data<tree->data)
				tree->left=InsertTree(data,tree->left);
			else
				tree->right=InsertTree(data,tree->right);
			return(tree);
}

TREE *printTree(TREE *tree,int level)
{
	if(tree)
	{
		printTree(tree->right,level+1);
		cout<<"\n\t";
		for(int i=0;i<level;i++)
		{
			cout<<"   ";
		}
		cout<<tree->data;
		printTree(tree->left,level+1);
	}
}
int internal_nodes(TREE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else 
	{
		if(root->left==NULL&&root->right==NULL)
			return 0;
		int xl=internal_nodes(root->left);
		int xr=internal_nodes(root->right);
		return(xl+xr+1);
	}
}
int leaf_nodes(TREE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else 
	{
		if(root->left==NULL&&root->right==NULL)
			return 1;
		int xl=internal_nodes(root->left);
		int xr=internal_nodes(root->right);
		return(xl+xr);
	}
}
int height_tree(TREE *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else 
	{
		if(root->left==NULL&&root->right==NULL)
			return 0;
		int xl=internal_nodes(root->left);
		int xr=internal_nodes(root->right);
		return(max(xl,xr)+1);
	}
}
int max( int xl,int xr)
{
	return xl>xr?xl:xr;
}
int main()
{
int data;
TREE *tree=NULL;
while(1)
{
	cout<<"\nKey to Insert|";
	cin>>data;
	if(data==0)
		break;
	tree=InsertTree(data,tree);
	cout<<"\n\tTree Display\n";
	printTree(tree,1);	
}
cout<<"\nInternalNodes"<<internal_nodes(tree);
cout<<"\nLeaf Nodes"<<leaf_nodes(tree);
cout<<"\nHeight of a tree"<<height_tree(tree);
}