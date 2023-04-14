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

void buildFromLevelOrder(node* &root) //Making The Tree as Node 
{
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter left Node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right Node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inOrderLNRforCount(node* root,int &count) //In Order Traversal..
{
    if (root == NULL)
        return;
    inOrderLNRforCount(root->left,count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inOrderLNRforCount(root->right,count);
}

int noOfLeafNodes(node* root)
{
    int count = 0;
    inOrderLNRforCount(root, count);
    return count;
}

int height(node* root) //HEIGHT OF THE TREE -> BASIC IMPORTANT QUESTION.. Time Complexity[O(n^2)]
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<int, int> diameterOptimised(node* root) //Optimised Approach to find the Diameter of the tree. Time Complexity [O(n)]..
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterOptimised(root->left);
    pair<int, int>right = diameterOptimised(root->right);
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second +1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;

}
int diameterOptiCall(node* root)
{
    return diameterOptimised(root).first;
}


int diameterOfTree(node* root)
{
    if (root == NULL)
        return 0;
    int opt1 = diameterOfTree(root->left);
    int opt2 = diameterOfTree(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;
    int ans = max(opt1, max(opt2, opt3));
    return ans;
}

int main()
{
    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    cout << endl << "No of leaf nodes: " << noOfLeafNodes(root);
    cout << endl <<"Height of the Tree : " << height(root);
    cout << endl << "Diamete of the Tree : " << diameterOfTree(root);
    cout << endl << "Diameter of Tree Optimised: " << diameterOptiCall(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1..
    /*
    root = buildTree(root);
    *
    * levelOrderTraversal(root);
    cout << endl;
     cout << "In order traversal: ";
    inOrderLNR(root);
    cout << endl;
    cout << " Pre Order Traversal: ";
    preOrderNLR(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    postOrderLNR(root);
    return 0;
    
    */
}

