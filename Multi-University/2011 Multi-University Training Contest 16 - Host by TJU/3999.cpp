#include <stdio.h>
struct T
{
	int data;
	struct T *left,*right;
}tree[100010];
int total;
void insert(int data,struct T *root)
{
	if(data<root->data)
	{
		if(root->left==NULL)
		{
			root->left=&tree[total];
			tree[total].left=NULL;
			tree[total].right=NULL;
			tree[total].data=data;
			total++;
		}
		else
		{
			insert(data,root->left);
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=&tree[total];
			tree[total].left=NULL;
			tree[total].right=NULL;
			tree[total].data=data;
			total++;
		}
		else
		{
			insert(data,root->right);
		}
	}
}
void print(struct T *root)
{
	if(root->left!=NULL)
	{
		printf(" %d",root->left->data);
		print(root->left);
	}
	if(root->right!=NULL)
	{
		printf(" %d",root->right->data);
		print(root->right);
	}
}
int main()
{
	int N,i,data;
	while(scanf("%d",&N)!=EOF)
	{
		total=1;
		scanf("%d",&tree[0].data);
		tree[0].left=NULL;
		tree[0].right=NULL;
		for(i=1;i<N;i++)
		{
			scanf("%d",&data);
			insert(data,&tree[0]);
		}
		printf("%d",tree[0].data);
		print(&tree[0]);
		printf("\n");
	}
	return 0;
}