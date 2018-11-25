#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cout<<"\nEnter the number of rows:";
	cin>>m;
	cout<<"\nEnter the number of Coloumns:";
	cin>>n;
	int mat[m][n],temp1[m][n],temp2[m][n];
	cout<<"\nEnter the elements of a matrix:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
			temp2[i][j]=mat[i][j];
			temp1[i][j]=mat[i][j];
			
		}
	}
	cout<<"\n\tThe matrix is: \n\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\tDiagonal Elements of a matrix are:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				cout<<mat[i][j]<<"\t";
			}
		}
		cout<<"\n";
	}
	cout<<"\n\tLower Triangular matrix:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>i)
			{
				temp1[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<temp1[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\tUpper Triangular matrix:\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>j)
			{
				temp2[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<temp2[i][j]<<"\t";
		}
		cout<<"\n";
	}
}