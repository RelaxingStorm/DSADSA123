#include <iostream>

using namespace std;
// Hash Table of size 10
class Hasher {
  public:
    int index;
  long int mob;
};
class hashTable {
  public:
    Hasher h[10];
  int cnt; //to check if hash table is full
  hashTable() {
    for (int i = 0; i < 10; i++) {
      h[i].index = i;
      h[i].mob = -1; //bcs key%10 is never -1; thats why we initialize all keys to -1 initially (useful for finding available bucket)
    }
    cnt = 0;
  }
  public:
    void insert(int);
  void display();
  void search(int);
  int linearProbe(int);
  int quadProbe(int);
};

void hashTable::insert(int probe) {
  int key, pos;
  if (cnt == 10) {
    cout << "\nHash Table is Full!";
    return;
  }

  cout << "\nEnter the Number: ";
  cin >> key;
  pos = key % 10;

  if (probe == 1) {
    pos = linearProbe(pos);
  } else if (probe == 2) {
    pos = quadProbe(pos);
    if (pos == -1) { //if pos = -1 returned then do linearProbe (drawback of QuadraticProbe)
      pos = linearProbe(pos);
      cout << "\nQuadratic Probing failed... Attempting Liner Probing";
    }
  }

  if (pos != -1) { //space available
    h[pos].mob = key;
    cout << "\nMobile no. stored at " << pos << " position";
  }
}

int hashTable::linearProbe(int pos) {
  for (int i = pos; i < 10; i++) { //start from pos to bottom
    if (h[i].mob == -1) {
      cnt++;
      return i;
    }
    if (i == 9) //start from top again to chk for available space
      i = -1;
  }
  return -1;
}

int hashTable::quadProbe(int pos) {
  for (int i = 0; i < 10; i++) {
    if (h[(pos + i * i) % 10].mob == -1) { //(pos+i^2)%10; i starts from 0 & goes upto 9
      cnt++;
      return (pos + i * i) % 10;
    }
  }
  return -1;
}

void hashTable::display() {
  for (int i = 0; i < 10; i++) {
    cout << i << " --> " << h[i].mob << "\n";
  }
}

void hashTable::search(int key) {
  int new_pos, pos = key % 10;
  new_pos = pos;
  do {
    if (h[new_pos].mob == key) {
      cout << "\nMobile no. found at Index " << pos;
      return;
    }
    new_pos = (new_pos + 1) % 10;
  } while (new_pos != pos);
  cout << "\nMobile no. not found!";
}

int main() {
  hashTable ht;
  int ch, key, probe = 1;

  do {
    cout << "\n\nHash Table to store mobile no." <<
      "\n1.Select Hashing mode(Default: Linear Probing)" <<
      "\n2.Insert Mobile no.\n3.Display mobile Number" <<
      "\n4.Search Mobile no.\n0.Exit\n";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "\n1.Linear Probing\n2.Quadratic Probing\n";
      cin >> probe;
      if (probe == 1 || probe == 2)
        break;
      else {
        probe = 1;
        cout << "\nEnter valid value!";
      }
      break;
    case 2:
      ht.insert(probe);
      break;
    case 3:
      ht.display();
      break;
    case 4:
      cout << "\nEnter mobile to search: ";
      cin >> key;
      ht.search(key);
      break;
    case 0:
      exit(0);
    default:
      cout << "\nEnter correct option!";

    }
  } while (true);
  return 0;
}