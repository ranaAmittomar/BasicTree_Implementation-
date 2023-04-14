// UserDefine_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
#include<list>
#include<math.h>
using namespace std;


class node { //model of a node
public:
    node* left;
    node* right;
    int data;
    node(int dat)
    {
        this->data = dat;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildTree(node* root) //taking input as a node for building a tree.
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the data for the left of : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right of : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}


void levelOrderTraversal(node* root) //ALSO KNOWNN AS -> BFS(BREADTH FIRST SEARCH)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) //PRINTING THE TREE LEVEL BY LEVEL..
        {
            cout << endl; //SEPARATOR FOR NEXT LINE
            if (!q.empty())
            {
                q.push(NULL); //CHECK FOR THE SEPARATOR..
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        
    }
}

void inOrderLNR(node* root) //In Order Traversal..
{
    if (root == NULL)
        return;
    inOrderLNR(root->left);
    cout << root->data << " ";
    inOrderLNR(root->right);
}

void preOrderNLR(node* root) //PreOrder Traversal
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderNLR(root->left);
    preOrderNLR(root->right);
}

void postOrderLNR(node* root) //Post Order Traversal
{
    if (root == NULL)
        return;
    postOrderLNR(root->left);
    postOrderLNR(root->right);
    cout << root->data << " ";
}


int main()
{
    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    cout << endl;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1..
    cout << "In order traversal: ";
    inOrderLNR(root);
    cout << endl;
    cout << " Pre Order Traversal: ";
    preOrderNLR(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    postOrderLNR(root);
    return 0;
}

