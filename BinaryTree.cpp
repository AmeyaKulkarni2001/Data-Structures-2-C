#include <iostream>
using namespace std;
 
class node {
    int data;
    node *left;
    node *right;
    friend class tree;
};

class tree {
    node *root;
    public:
        tree();
        void create_r();
        void create_r(node *);
        void create_nr();
        void inorder_r();
        void inorder_r(node *);
        void preorder_r();
        void preorder_r(node *);
        void postorder_r();
        void postorder_r(node *);

};


void tree :: create_r() {
    root = new node();
    cout<<"\nEnter root data: ";
    cin>>root->data;
    create_r(root);
}



tree::tree()
{
    root=NULL;
}

void tree::create_r(node *temp)
{
    char ch1, ch2;
    cout<<"\nEnter to the left of the "<<temp->data<<" node? (y/n): ";
    cin>>ch1;
    if (ch1 == 'y' || ch1 == 'Y')
    {
        node *curr = new node();
        cout<<"\nEnter Data: ";
        cin>>curr->data;
        temp->left = curr;
        create_r(curr);
    }
    cout<<"\nEnter to the right of the "<<temp->data<<" node? (y/n): ";
    cin>>ch2;
    if (ch2 == 'y' || ch2 == 'Y')
    {
        node *curr = new node();
        cout<<"\nEnter Data: ";
        cin>>curr->data;
        temp->right = curr;
        create_r(curr);
    }
}

void tree::create_nr()
{
    if (root==NULL)
    {
        root = new node();
        cout<<"\nEnter data for root: ";
        cin>>root->data;
        root->left=NULL;
        root->right=NULL;
    }
    char cont;
    do 
    {
        node *temp = root;
        int flag = 0;
        char choice;
        node *curr = new node();
        cout<<"\nEnter data for the next node: ";
        cin>>curr->data;
        while (flag == 0)
        {
            cout<<"\nEnter choice for left or right side(r or l) of "<<temp->data<<" : ";
            cin>>choice;
            if (choice == 'l' || choice == 'L')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag=1;
                }
                temp=temp->left;
            }
            else
            {
                if(choice == 'r' || choice == 'R')
                {
                    if (temp->right == NULL)
                    {
                        temp->right = curr;
                        flag=1;
                    }
                    temp=temp->right;
                }
            }
        }
        
        
        cout<<"\nDo you want to continue adding? (y/n)";
        cin>>cont;
    }
    while(cont == 'y' || cont == 'Y');
    
    
}


void tree :: inorder_r()
{
    inorder_r(root);
}

void tree :: inorder_r(node *temp)
{
    if (temp != NULL)
    {
        inorder_r(temp->left);
        cout<<temp->data<<"\t";
        inorder_r(temp->right);
    }
}


void tree :: preorder_r()
{
    preorder_r(root);
}

void tree :: preorder_r(node *temp)
{
    if (temp != NULL)
    {
        cout<<temp->data<<"\t";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void tree :: postorder_r()
{
    postorder_r(root);
}

void tree :: postorder_r(node *temp)
{
    if (temp != NULL)
    {
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout<<temp->data<<"\t";
    }
}

int main()
{
    tree bt;
    int option;
    do
    {
        cout<<"\n\n------------------Menu-----------------------";
        cout<<"\n1.Create a tree Recursively";
        cout<<"\n2.Create a tree Non-Recursively";
        cout<<"\n3.Inorder Traversal(Recursive)";
        cout<<"\n4.Preorder Traversal(Recursive)";
        cout<<"\n5.Postorder Traversal(Recursive)";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice: ";
        cin>>option;
        switch(option)
        {
            case 1:
                bt.create_r();
                break;
            
            case 2:
                bt.create_nr();
                break;
                
            case 3: 
                bt.inorder_r();
                break;
                
            case 4:
                bt.preorder_r();
                break;
                
            case 5:
                bt.postorder_r();
                break;
            
            case 6:
                return 0;
                
            default:
                cout<<"\nInvalid Choice!";
                break;
        }
    }
    while(option != 6);
}
