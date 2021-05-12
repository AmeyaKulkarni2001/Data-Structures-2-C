#include<iostream>
#include<stdlib.h>
using namespace std;

class node_tbt
{
  char inp[10];
  int lit;
  int rit;
  node_tbt* left;
  node_tbt* right;
  friend class tbt;
  public:
     node_tbt()
      {
        lit=1;
        rit=1;
       }
};
class tbt
{
  node_tbt *head;
  public:
    void create(void);
    void inorder(void);
    void preorder(void);
    node_tbt* insuccesor(node_tbt* temp);
    node_tbt* presuccesor(node_tbt* temp);
    tbt()
     {
       head=new node_tbt();
       head->rit=0;
       head->left=head;
       head->right=head;
      }
};
void tbt::create()
{
  node_tbt* root = new node_tbt();
  cout<<" Please enter the data for the root node = ";
  cin>>root->inp;
  head->lit=0;
  root->left=head;
  root->right=head;
  head->left=root;
  char choice;
  node_tbt* temp = new node_tbt();
  int flag=0;
  do
   {
     flag=0;
     temp=root;
     node_tbt* curr=new node_tbt();
     cout<<" Please enter the data for the new node = ";
     cin>>curr->inp;
     while(flag==0)
     {
       char ch;
       cout<<" Where do you want to add the node?(l/r) ";
       cin>>ch;
       if(ch=='l')
        {
          if(temp->lit==1)
           {
            curr->right=temp;
            curr->left=temp->left;
            temp->left=curr;
            temp->lit=0;
            flag=1;
            }
           else
            temp=temp->left;
         }
       if(ch=='r')
        {
         if(temp->rit==1)
          {
            curr->left=temp;
            curr->right=temp->right;
            temp->right=curr;
            temp->rit=0;
            flag=1;
           }
         else
           temp=temp->right;
        }
      }
     cout<<" Want to add more nodes?(y/n) ";
     cin>>choice;
    }
   while(choice=='y');
}
void tbt::inorder()
{
  node_tbt* temp=new node_tbt();
  temp=head;
  while(1)
   {
     temp=insuccesor(temp);
     if(temp==head)
        break;
     cout<<" "<<temp->inp<<"->";
    }
    cout<<endl;
}
node_tbt* tbt::insuccesor(node_tbt *temp)
{
  node_tbt* x=new node_tbt();
  x=temp->right;
  if(temp->rit==0)
   {
     while(x->lit==0)
      {
        x=x->left;
       }
   }
  return x;
}
void tbt::preorder()
{
  node_tbt* temp=new node_tbt();
  temp=head->left;
  while(temp!=head)
   {
     cout<<" "<<temp->inp<<"->";
     while(temp->lit!=1)
      {
        temp=temp->left;
        cout<<" "<<temp->inp<<"->";
       }
     while(temp->rit==1)
       temp=temp->right;
       temp=temp->right;
    }
    cout<<endl;
}

int main(void)
{
  tbt t1;
  while (1)
   {
     int ch;
     cout<<"\n   **Menu**\n 1. Create a threaded Binary Tree\n 2. Display Inorder\n 3. Display Preorder\n 4. Exit\n Your choice : ";
     cin>>ch;
     switch(ch)
      {
        case 1:
            t1.create();
            break;
        case 2:
            t1.inorder();
            break;
        case 3:
            t1.preorder();
            break;
        case 4:
            return 0;
        default:
            cout<<" Invalid choice!\n";
            break;
        }
    }
}
