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
	}
};

node *createTree()
{
	int x;
	cout << "Enter value (enter -1 to stop): ";
	cin >> x;

	if (x == -1)
		return NULL;

	node *Node = new node(x);
	cout << "Left child of Node " << x << endl;
	Node->left = createTree();

	cout << "Right child of Node " << x << endl;
	Node->right = createTree();

	return Node;
}

void preorder(node *root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main()
{
	cout << "Root:" << endl;
	node *root = createTree();

	cout << endl;
	cout << "Pre-order Traversal  : ";
	preorder(root);

	cout << endl;
	cout << "In-order Traversal   : ";
	inorder(root);

	cout << endl;
	cout << "Post-order Traversal : ";
	postorder(root);
	return 0;
}