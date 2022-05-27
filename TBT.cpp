#include <iostream>
using namespace std;

class Tnode{
    public:
    int data;
    Tnode *left, *right;
    int lbit, rbit;
};
class TBT{
    Tnode *head, *root;
    public:
    TBT(){
        head = NULL;
        root = NULL;
    }
        void createTBT();
        void inorder();
        void preorder();
};
void TBT::inorder(){
    Tnode *temp;
    temp = root;
    if(root == NULL){
        cout<<"\nTree is Empty.";
        return;
    } else {
        do{
            while(temp->lbit != 0){
                temp = temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rbit == 0){
                temp = temp->right;
                if(temp == head)
                    return;
                cout<<temp->data<<" ";
            }
            temp = temp->right;
        }while(temp != head);
    }
}
void TBT::preorder(){
    Tnode *temp;
    temp = root;
    if(root == NULL){
        cout<<"\nTree is empty.";
        return;
    } else {
        do{
            while(temp->lbit != 0){
                cout<<temp->data<<" ";
                temp = temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rbit == 0){
                temp = temp->right;
                if(temp == head)
                    return;
            }
            temp = temp->right;
        }while(temp != head);
    }
}
void TBT::createTBT(){
    Tnode *temp, *new_node;
    char ans;
    int flag;
    head = new Tnode();
    root = new Tnode();
    
    head->data = -1;
    head->right = head;
    head->left = head;
    head->lbit = 0;
    head->rbit = 0;
    
    cout<<"\nEnter Root Data: ";
    cin>>root->data;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    head->left = root;
    head->lbit = 1;
    do{
        new_node = new Tnode();
        cout<<"\nEnter New node data: ";
        cin>>new_node->data;
        new_node->lbit = 0;
        new_node->rbit = 0;
        temp = root;
        flag = 0;
        while(flag == 0){   //find proper place for new node
            if(new_node->data < temp->data){
                if(temp->lbit == 0){
                    new_node->left = temp->left;
                    temp->left = new_node;
                    new_node->right = temp;
                    temp->lbit = 1;
                    flag = 1;
                } else{
                    temp = temp->left;
                }
            } else if(new_node->data > temp->data){
                if(temp->rbit == 0){
                    new_node->right = temp->right;
                    temp->right = new_node;
                    new_node->left = temp;
                    temp->rbit = 1;
                    flag = 1;
                } else{
                    temp = temp->right;
                }
            } else {
                cout<<"\nData already exists.";
            }
        }
        cout<<"\nDo you want to add more nodes? ";
        cin>>ans;
    }while(ans == 'y'||ans == 'Y');
}
int main(){
    TBT t;
    t.createTBT();
    int ch;
    do{
        cout<<"\n1.Inorder\n2.Preorder\n3.Exit";
        cin>>ch;
        switch(ch){
            case 1: 
            t.inorder();
            break;
            case 2:
            t.preorder();
            break;
            default:
            cout<<"\nEnter correct option";
            break;
        }
    } while(ch != 3);
    return 0;
}