#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root)
{
    cout << "Enter data for node: "<< endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1)
        return NULL;
    cout << "Enter data for left child of " << data << ": " << endl;
    root->left = buildtree(root->left); //recursive call to build left subtree
    cout << "Enter data for right child of " << data << ": " << endl;
    root->right = buildtree(root->right); //recursive call to build right subtree
    return root; 
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl; // purana level complete traverse ho chuka hai
            if(!q.empty()) // agar queue abhi bhi empty nahi hui hai
            {
                q.push(NULL); 
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}   
void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/**********************************************************************************************************                                        
                                        USING ITERATIVE APPROACH

   void inorderTraversal(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
} *******************************************************************************************************/
                 
int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}   


int main()
{
    node* root = NULL;

    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Level Order Traversal of the tree is: " << endl;
    levelOrderTraversal(root);
    cout << "Inorder Traversal of the tree is: " ;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal of the tree is: " ;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal of the tree is: " ;
    postorder(root);
    cout << endl;
    cout << "Height of the tree is: " << height(root) << endl;
}
