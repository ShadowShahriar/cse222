#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;

	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

int countNodes(node *root)
{
	if (root == NULL)
		return 0;

	int l = countNodes(root->left);
	int r = countNodes(root->right);
	return 1 + l + r;
}

int countLeafNodes(node *root)
{

	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
	//          154
	//        /    \
    //      122   408
	//     /   \
    //   147  148
	node *root = new node(154);
	root->left = new node(122);
	root->right = new node(408);
	root->left->left = new node(147);
	root->left->right = new node(148);

	cout << "Total Nodes: " << countNodes(root) << endl;
	cout << " Leaf Nodes: " << countLeafNodes(root) << endl;
	return 0;
}