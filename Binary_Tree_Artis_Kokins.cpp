#include <iostream>
#include <cstdlib>
#include <limits>
#define S 1
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
//-----------------------------------------------------------------------------
Node *CreateNode()
{
    Node *newNode;
    newNode=new Node;
    cin>>newNode->data;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Wrong input! Input an integer number: ";
        cin>>newNode->data;
    }
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//-----------------------------------------------------------------------------
void PrintTree (Node *cur, int space)
{
    if (!cur) return;
    space = space + S;
    PrintTree (cur->right, space);
    for (int i = S; i < space; i++){
        cout<<"\t";
    }
    cout<<cur->data<<"\n";
    PrintTree (cur->left, space);
}
//-----------------------------------------------------------------------------
void AddNode (Node *root)
{
    Node *cur, *cur2, *newNode, *key;
    key=newNode=CreateNode();
    cur=root;
    while((cur->left!=NULL && cur->right!=NULL)||(cur->left!=NULL&&newNode->data<cur->data)||(cur->right!=NULL && newNode->data>cur->data))
    {
        if(newNode->data<cur->data) cur=cur->left; else cur=cur->right;
    }
    if(newNode->data<cur->data)cur->left=newNode; else cur->right=newNode;
}
//-----------------------------------------------------------------------------
Node *SearchNode (Node *root, int look)
{
    Node *cur;
    cur=root;
    while(cur!=NULL)
    {
        if(cur->data==look){return cur;}
        else if(cur->data>look){cur=cur->left;}
            else cur=cur->right;
    }
    return NULL;
}
//-----------------------------------------------------------------------------
Node *SearchNode2 (Node *root, int look, Node **y)
{
    Node *cur;
    if(root==NULL){return NULL;}
    cur = root;
    *y=NULL;
    while(cur!=NULL)
    {
        if(cur->data==look){return cur;}
        else
        {
            *y=cur;
            if(cur->data > look)
            {
                cur=cur->left;
            }
            else {cur=cur->right;}
        }
    }
    return NULL;
}
//-----------------------------------------------------------------------------
Node *DeleteRoot(Node *root)
{
    Node *x, *y, *cur;
    x = root;
    if(x==root)
    {
        if(x->left==NULL&&x->right==NULL){delete x; return NULL;}
        if(x->left==NULL){root=x->right; delete x; return root;}
        cur=x->left;
        y=x->right;
        root=cur;
        while(cur->right!=NULL)
        cur=cur->right;
        cur->right=y;
        delete x;
        return root;
    }
    return root;
}
//-----------------------------------------------------------------------------
Node *DeleteNode(Node *root, int look)
{
    Node *x, *y, *cur;
    x=SearchNode2(root, look, &y);
    if(x==NULL)
        {cout<<"Such node doesn't exist!"<<endl; return root;}
    else
    {
        if(x==root)
        {
            if(x->left==NULL&&x->right==NULL){delete x; return NULL;}
            if(x->left==NULL){root=x->right; delete x; return root;}
            cur=x->left;
            y=x->right;
            root=cur;
            while(cur->right!=NULL)
            cur=cur->right;
            cur->right=y;
            delete x;
            return root;
        }
        if(x->left!=NULL && x->right!=NULL)
        {
            if(y->left==x)
            {
                cur=x->left;
                y->left=x->left;
                while(cur->right!=NULL)
                cur=cur->right;
                cur->right=x->right;
                x->left=NULL;
                x->right=NULL;
            }
            else
            {
                cur=x->right;
                y->right=x->right;
                while(cur->left!=NULL)
                cur=cur->left;
                cur->left=x->left;
                x->left=NULL;
                x->right=NULL;
            }
            delete x; return root;
        }
        if(x->left==NULL&&x->right!=NULL)
        {
            if(y->left==x){y->left=x->right;}
            else{y->right=x->right;}
            x->right=NULL;
            delete x;
            return root;
        }
        if(x->left!=NULL&&x->right==NULL)
        {
            if(y->left==x){y->left=x->left;}
            else{y->right=x->left;}
            x->left=NULL;
            delete x;
            return root;
        }
        if(x->left==NULL&&x->right==NULL)
        {
            if(y->left==x){y->left=NULL;}
            else {y->right = NULL;}
            delete x;
            return root;
        }
    }
    return root;
}
//-----------------------------------------------------------------------------
void PreOrder (Node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
//-----------------------------------------------------------------------------
void InOrder (Node *root)
{
    if (root != NULL)
    {

        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}
//-----------------------------------------------------------------------------
void PostOrder(Node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}
//-----------------------------------------------------------------------------
int CountNodes(Node *root)
{
    int n=0;
    if(root==NULL){return 0;}
    if(root->left!=NULL)
    {
        n = n + CountNodes(root->left);
    }
    if(root->right!=NULL)
    {
        n = n + CountNodes(root->right);
    }
    n++;
    return n;
}
//-----------------------------------------------------------------------------
Node *SwapTree(Node *root)
{
    Node *cur=NULL, *cur2=NULL;
    if(root != NULL)
    {
        cur=SwapTree(root->left);
        cur2=SwapTree(root->right);
        root->right=cur;
        root->left=cur2;
    }
    return root;
}
//-----------------------------------------------------------------------------
int main()
{
    int choice, look, number;
    Node *root=NULL, *cur, *cur3;

    cout<<"\t\tData Structure: Binary Tree"<<endl;
    do
    {
        system("cls");

        cout<<"\nAuthor: Artis Kokins"<<endl;
        cout<<"Binary Search Tree"<<endl;
        cout<<"Date: 04.01.2021"<<endl;
        cout<<"Version 11.2"<<endl<<endl;

        cout<<"\t\tData Structure: Binary Search Tree"<<endl;
        cout<<"1. Create Root"<<endl;
        cout<<"2. Print Root"<<endl;
        cout<<"3. Print Tree"<<endl;
        cout<<"4. Add Node"<<endl;
        cout<<"5. Find Node"<<endl;
        cout<<"6. Delete Root"<<endl;
        cout<<"7. Delete Any Node"<<endl;
        cout<<"8. Pre-Order Traversing (VLR)"<<endl;
        cout<<"9. In-Order Traversing (LVR)"<<endl;
        cout<<"10. Post-Order Traversing (LRV)"<<endl;
        cout<<"11. Number of Nodes"<<endl;
        cout<<"12. Swap Tree"<<endl;
        cout<<"0. End the program"<<endl;
        cout<<"\nChoose an action: ";
        cin>>choice;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Wrong input! Input an integer number: ";
            cin>>choice;
        }

        switch(choice)
        {
            case 1:if(!root)
                    {
                        cout<<"Create Root: ";
                        root = CreateNode();
                        cout<<"Root was created!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root already exists!";
                        system("Pause>>nul");
                    }
                    break;
            case 2:if(root)
                    {
                        cout<<"Root = "<<root->data<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 3:if(root)
                    {
                        cout<<"Binary Search Tree: "<<endl;
                        PrintTree(root, 0);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 4:if(root)
                    {
                        cout<<"Create Node: ";
                        AddNode(root);
                        cout<<"Element added"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!"<<endl;
                        system("Pause>>nul");
                    }
                    break;
            case 5:if(root)
                    {
                        cout<<"Enter node to find: ";
                        cin>>look;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Wrong input! Input an integer number: ";
                            cin>>look;
                        }
                        cur=SearchNode(root, look);
                        if(cur!=NULL){cout<<"Node "<<cur->data<<" found!"<<endl;system("Pause>>nul");}
                        else {cout<<"Node "<<look<<" doesn't exist!"<<endl; system("Pause>>nul");}
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 6:if(root)
                    {
                        root=DeleteRoot(root);
                        cout<<"Root was deleted!"<<endl;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 7:if(root)
                    {
                        cout<<"Enter node to delete: ";
                        cin>>look;
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout<<"Wrong input! Input an integer number: ";
                            cin>>look;
                        }
                        cur3=SearchNode(root, look);
                        if(cur3!=NULL){root=DeleteNode(root, look);
                        cout<<"Node deleted!"<<endl;
                        system("Pause>>nul");}
                        else {cout<<"Such node doesn't exist!"<<endl;system("Pause>>nul");}
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 8:if(root)
                    {
                        cout<<"Pre-Order Traversing (VLR)"<<endl;
                        PreOrder(root);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 9:if(root)
                    {
                        cout<<"In-Order Traversing (LVR)"<<endl;
                        InOrder(root);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 10:if(root)
                    {
                        cout<<"Post-Order Traversing (LRV)"<<endl;
                        PostOrder(root);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 11:if(root)
                    {
                        number=CountNodes(root);
                        cout<<"Number of nodes: "<<number;
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 12:if(root)
                    {
                        cout<<"Swapped Tree: "<<endl;
                        root=SwapTree(root);
                        PrintTree(root, 0);
                        system("Pause>>nul");
                    }
                    else
                    {
                        cout<<"Root doesn't exist! You can't use this function!";
                        system("Pause>>nul");
                    }
                    break;
            case 0: cout<<"End!!!"<<endl;
                    cout<<"Thank you for using the program!"<<endl;
                    break;
            default: cout<<"Incorrect choice!";
                    system("Pause>>nul");
        }

    }
    while(choice!=0);

    system("Pause>>nul");
    return 0;
}
