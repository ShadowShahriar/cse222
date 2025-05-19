#include <iostream>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

struct node *insert(struct node *node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	struct node *root = NULL;
	int x;
	while (x != -1)
	{
		cout << "Enter value (-1 to stop): ";
		cin >> x;
		if (x != -1)
			root = insert(root, x);
	}

	cout << "Inorder traversal:" << endl;
	inorder(root);
	return 0;
}