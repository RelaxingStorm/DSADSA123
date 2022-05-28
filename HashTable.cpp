#include<iostream>

using namespace std;
class HashTable {
  public:
    int index;
    long int mobile;
};
class Hashing {
  HashTable h[10];
  public:
    Hashing() {
      for (int i = 0; i < 10; i++) {
        h[i].index = i;
        h[i].mobile = -1;
      }
    }
  void display();
  void insert(int);
  void search();
  int linearProb(int);
  int quadProb(int);
};
int Hashing::quadProb(int collision_position) {
  for (int i = 1; i < 10; i++) {
    if (h[(collision_position + i * i) % 10].mobile == -1)
      return (collision_position + i * i) % 10;
  }
  return -1;
}
int Hashing::linearProb(int collision_position) {
  for (int i = collision_position; i < 10; i++) {
    if (h[i].mobile == -1)
      return i;
    if (i == 9)
      i = -1;
  }
  return -1;
}
void Hashing::display() {
  for (int i = 0; i < 10; i++) {
    cout << h[i].index;
    cout << " " << h[i].mobile;
    cout << endl;
  }
}
void Hashing::insert(int probeChoice) {
  long int key;
  int position;
  cout << "\nEnter mobile number to insert in to hash table : ";
  cin >> key;
  position = key % 10;
  if (h[position].mobile == -1) {
    h[position].mobile = key;
    cout << "Position = " << position << endl;
  } else if (probeChoice == 1){ // Linear Probing collision
    int temp_position;
    temp_position = linearProb(position);
    h[temp_position].mobile = key;
    cout << "Position = " << temp_position << endl;
  } else if (probeChoice == 2){ // Quadratic Probing for collision
    int temp_position;
    temp_position = quadProb(position);
    h[temp_position].mobile = key;
    cout << "Position = " << temp_position << endl;
  }
}
void Hashing::search() {
  long int key;
  int position;
  cout << "\nEnter mobile no. to search in hash table : ";
  cin >> key;
  position = key % 10;
  int pos = position;
  do {
    if (h[pos].mobile == key) {
      cout << "Given mobile number is found in hash table! " << endl;
      return;
    }
    pos = (pos + 1) % 10;
  } while (pos != position);
  cout << "Given mobile number is not found in hash table... " << endl;
}
int main() {
  Hashing ht;
  int ch;
  do {
    cout << "\n Menu";
    cout << "\n 1. Insert";
    cout << "\n 2. Display";
    cout << "\n 3. Search";
    cout << "\n 4. Exit";
    cout << "\n Enter your choice : ";
    cin >> ch;
    switch (ch) {
    case 1:
      int probeChoice;
      cout << "\nEnter \n1 for Linear Probing \n2 for Quadratic probing\n Enter choice: ";
      cin >> probeChoice;
      ht.insert(probeChoice);
      break;
    case 2:
      ht.display();
      break;
    case 3:
      ht.search();
      break;
    case 4:
      break;
    default:
      cout << "\nWrong choice :";
      break;
    }
  } while (ch != 4);
}