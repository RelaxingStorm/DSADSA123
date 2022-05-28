#include<iostream>

using namespace std;
#define SIZE 10
#define MAX 20
class Queue {
  int front, rear;
  int arr[MAX];
  public:
    Queue() {
      front = rear = -1;
    }
  void insert_ele(int x) {
    if (!isFull()) {
      if (front == -1)
        front++;
      rear++;
      arr[rear] = x;
    }
  }
  int delete_ele() {
    if (!isEmpty()) {
      int x = arr[front];
      for (int i = front; i < rear; i++) {
        arr[i] = arr[i + 1];
      }
      if (front == rear)
        front--;
      rear--;
      return x;
    }
    return 0;
  }
  bool isEmpty() {
    if (rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (rear == MAX - 1)
      return true;
    else
      return false;
  }
 };
class Stack {
  int arr[MAX];
  int top;
  public:
    Stack() {
      top = -1;
    }
  void push(int x) {
    if (!isFull()) {
      top++;
      arr[top] = x;
    }
  }
  int pop() {
    if (!isEmpty()) {
      int x = arr[top];
      top--;
      return x;
    }
    return 0;
  }
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == MAX - 1)
      return true;
    else
      return false;
  }
};
class Graph {
  int i, j;
  int visited[20];
  public:
    int cnt;
  int adj_mat[SIZE][SIZE];
  int ver_arr[SIZE];
  int ver_cnt;
  Graph() {
    cnt = 0;
  }
  void DFS();
  void BFS();
  void display(string s) {
    cout << "\n" << s << " Traversal : ";
    for (i = 0; i < cnt; i++) {
      cout << visited[i] << " ";
    }
  }
  int search(int x) {
    for (i = 0; i < cnt; i++) {
      if (visited[i] == x)
        return 1;
    }
    return 0;
  }
  void create_adjmat() {
    cout << "\nEnter the total number of nodes in the graph (nodes < 10) : ";
    cin >> ver_cnt;
    cout << "\nEnter the values of the nodes :\n";
    for (i = 1; i <= ver_cnt; i++) {
      cin >> ver_arr[i];
    }
    cout << "\nEnter 1 if edge present between nodes else enter 0\n";
    for (i = 1; i <= ver_cnt; i++) {
      for (j = 1; j <= ver_cnt; j++) {
        cout << "Node " << ver_arr[i] << " and Node " << ver_arr[j] << " : ";
        cin >> adj_mat[i][j];
      }
    }
  }
  void display_adjmat() {
    cout << "\nAdjacency Matrix \n\n ";
    for (i = 1; i <= ver_cnt; i++)
      cout << ver_arr[i] << " ";
    cout << "\n";
    for (i = 1; i <= ver_cnt; i++) {
      cout << ver_arr[i] << " ";
      for (j = 1; j <= ver_cnt; j++) {
        cout << adj_mat[i][j] << " ";
      }
      cout << "\n";
    }
  }
};
void Graph::DFS() {
  int curr_ver;
  Stack stk;
  int i, j, flag = 0;
  cout << "Enter starting vertex : ";
  cin >> curr_ver;
  cnt = 0;
  stk.push(curr_ver);
  visited[cnt++] = curr_ver;
  curr_ver = stk.pop();
  for (i = curr_ver; i <= ver_cnt;) {
    if (flag == 0) {
      for (j = 1; j <= ver_cnt; j++) {
        if (adj_mat[i][j] == 1) {
          stk.push(j);
        }
      }
      flag = 1;
    }
    curr_ver = stk.pop();
    if (search(curr_ver) == 0) {
      visited[cnt++] = curr_ver;
      flag = 0;
    }
    i = curr_ver;
    if (cnt == ver_cnt) {
      break;
    }
  }
  display("DFS");

}
void Graph::BFS() {
  int curr_ver;
  Queue que;
  int i, j, flag = 0;
  cout << "Enter starting vertex : ";
  cin >> curr_ver;
  cnt = 0;
  que.insert_ele(curr_ver);
  visited[cnt++] = curr_ver;
  curr_ver = que.delete_ele();
  for (i = curr_ver; i <= ver_cnt;) {
    if (flag == 0) {
      for (j = 1; j <= ver_cnt; j++) {
        if (adj_mat[i][j] == 1) {
          que.insert_ele(j);
        }
      }
      flag = 1;
    }
    curr_ver = que.delete_ele();
    if (search(curr_ver) == 0) {
      visited[cnt++] = curr_ver;
      flag = 0;
    }
    i = curr_ver;
    if (cnt == ver_cnt) {
      break;
    }
  }
  display("BFS");
}
int main() {
  Graph gph;
  int choice;
  do {
    cout << "\nMENU";
    cout << "\n1. Create Matrix\n2. Display Matrix\n3. Perform DFS Traversal\n4. Perform BFS Traversal\n5. Exit\n";
    cout << "\n Enter your choice : ";
    cin >> choice;
    switch (choice) {
    case 1:
      gph.create_adjmat();
      break;
    case 2:
      gph.display_adjmat();
      break;
    case 3:
      gph.DFS();
      break;
    case 4:
      gph.BFS();
      break;
    case 5:
      break;
    default:
      cout << "Invalid choice";
    }
  } while (choice != 5);
  return 0;
}