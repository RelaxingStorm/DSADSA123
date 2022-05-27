#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct stud{
    int roll;
    char name[10];
    char divi;
    char add[10];
} rec;

class student{
    public:
    void insert();
    void deleteRec();
    int search();
    void display();
};
void student::insert(){
    ofstream fout;
    char ans;
    fout.open("stud.dat", ios::out | ios::binary);
    do{
        cout<<"\n\tEnter Roll No.: ";
        cin>>rec.roll;
        cout<<"\tEnter Name: ";
        cin>>rec.name;
        cout<<"\tEnter Division: ";
        cin>>rec.divi;
        cout<<"\tEnter Address: ";
        cin>>rec.add;
        fout.write((char*) &rec, sizeof(rec))<<flush;
        cout<<"\tEnter More Records?: ";
        cin>>ans;
    } while(ans == 'Y' || ans == 'y');
    fout.close();
}
void student::display(){
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    fin.seekg(0, ios::beg);
    cout<<"\n\tThe contents of File are: ";
    cout<<"\n\tRoll No.\tName\tDiv\tAddress";
    while(fin.read((char*) &rec, sizeof(rec))){
            cout << "\n\t" << rec.roll << "\t\t" << rec.name << "\t" << rec.divi << "\t" << rec.add;
    }
    fin.close();
}
int student::search(){
    int r, i = 1;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    fin.seekg(0, ios::beg);
    cout<<"\n\tEnter the Roll no.: ";
    cin>>r;
    while(fin.read((char*) &rec, sizeof(rec))){
        if(rec.roll == r){
            cout<<"\n\tRecord Found!";
            cout<<"\n\tRoll No.\tName\tDiv\tAddress";
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.divi<<"\t"<<rec.add;
            return i;   //record found; i>=1 returned
        }
        i++;
    }
    fin.close();
    return 0;   //record not found
}
void student::deleteRec(){
    int pos, r, flag = 0;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
  
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);
  
    cout<<"\n\tEnter Roll No. to Delete Record: ";
    cin>>r;
    while (fin.read((char*) &rec, sizeof(rec))) {
        if (rec.roll != r) {    /*writing records to temp file that are not equal to given roll*/
            fout.write((char*) &rec, sizeof(stud));
        }
    }
    //closing files
    fout.close();
    fin.close();
  
    // delete the old file
    remove("stud.dat");
    // rename new file to the older file
    rename("temp.dat", "stud.dat");
    cout<<"\n\tOperation performed successfully";
}
int main(){
    student obj;
    int ch;
    do{
        cout<<"\n\t************* Student Information *************";
        cout<<"\n\t1.Create\n\t2.Display\n\t3.Search\n\t4.Delete\n\t5.Exit\n\t";
        cin>>ch;
        switch(ch){
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display();
                break;
            case 3:
            {
                int key = obj.search();
                if(key == 0)
                    cout<<"\n\tRecord not Found.";
                break;
            }
            case 4:
                obj.deleteRec();
                break;
            case 5:
                exit(0);
            default:
                cout<<"\nEnter Correct option!";
        }
    } while(true);
    return 0;
}