#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
struct exp
{
    char val;
    exp *right, *left;
};
int isoperator(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
    return 1;
    else
    return 0;
}
void inorder(exp *temp)
{
    if(temp != NULL)
    {
    inorder(temp->left);
    cout<<temp->val;
    inorder(temp->right);
    }
}
exp* newexp(int x)
{
             exp *temp=new exp;
             temp->right=NULL;
             temp->left=NULL;
             temp->val=x;
             return temp;
};
exp* tree(char post[20])
{
    int i;
    stack<exp *>st;
    exp *p,*q,*r;
    for(i=0;i<strlen(post);i++)
    {
    if(!isoperator(post[i]))
    {
        p=newexp(post[i]);
        st.push(p);
    }
    else
    {
        p=newexp(post[i]);
        q=st.top();
        st.pop();
        r=st.top();
        st.pop();
        
        p->right=q;
        p->left=r;
        
        st.push(p);
    }
    }
    p=st.top();
    st.pop();
    return p;
}
int main()
{
             cout<<"Enter the expression \n";
             char post[20];
             cin>>post;
             exp* x=tree(post);
             inorder(x);
             return 0;
}    
