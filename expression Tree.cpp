#include <iostream>
#include <string.h> //strlen()

using namespace std;
struct node {
  char data;
  node * left;
  node * right;
};

class tree {
  char prefix[20];
  public:
    node * top;
  void expression(char[]);
  void inorder(node * );
  void preorder(node * );
  void non_rec_postorder(node * );
  void del(node * );
};

class stack1 {
  node * data[30];
  int top;
  public:
    stack1() {
      top = -1;
    }
  int empty() {
    if (top == -1)
      return 1;
    return 0;
  }
  void push(node * p) {
    data[++top] = p;
  }
  node * pop() {
    return (data[top--]);
  }
};

void tree::expression(char prefix[]) {
  char c;
  stack1 s;
  node * t1, * t2;
  int len, i;
  len = strlen(prefix);
  for (i = len - 1; i >= 0; i--) {
    top = new node;
    top -> left = NULL;
    top -> right = NULL;
    if (isalpha(prefix[i])) {
      top -> data = prefix[i];
      s.push(top);
    } else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' || prefix[i] == '/') {
      t2 = s.pop();
      t1 = s.pop();
      top -> data = prefix[i];
      top -> left = t2;
      top -> right = t1;
      s.push(top);
    }
  }
  top = s.pop();
}

void tree::non_rec_postorder(node * top) {
  stack1 s1, s2; //stack s1 used for flag. NULL data = right subtree not visited
  node *temp = top;
  s1.push(temp);
  while (!s1.empty()) {
    temp = s1.pop();
    s2.push(temp);
    if (temp -> left != NULL)
      s1.push(temp -> left);
    if (temp -> right != NULL)
      s1.push(temp -> right);
  }
  while (!s2.empty()) {
    top = s2.pop();
    cout << top -> data << " ";
  }
}
void tree::del(node * node) {
  if (node == NULL)
    return;
  del(node -> left);
  del(node -> right);
  cout << "Deleting node: " << node -> data << endl;
  free(node);
}
int main() {
  char expr[20];
  tree t;
  cout << "Enter prefix Expression : ";
  cin >> expr;
  t.expression(expr);
  cout << "\nNon recursive PostOrder Traversal: ";
  t.non_rec_postorder(t.top);
  cout << "\n\n";
  t.del(t.top);
}