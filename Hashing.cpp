#include <iostream>
using namespace std;
int n;
class Student
{
public:
    int roll_number;
    string name;
    char grade;
    friend class Hash;
};

class Hash
{

    Student HashTable[10],HashTable2[10], temp;

public:
    Hash();
    void create();
    void LinearProb_Without(Student HashTab, int key);
    void display();
    void display2();
    void LinearProb_With(Student HashTab, int key);
};
void Hash::create()
{
    Student s;
    cout << "\nEnter the Number of Students:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "------------------------------------------------\n";
        cout << "\nEnter name:";
        cin >> s.name;
        cout << "\nEnter Roll Number of Student:";
        cin >> s.roll_number;
        cout << "\nEnter Grade of Student:";
        cin >> s.grade;
        LinearProb_Without(s, s.roll_number);
        LinearProb_With(s,s.roll_number);
    }
}
Hash::Hash()
{
    for (int i = 0; i < 10; i++)
    {
        HashTable[i].roll_number = -1;
        HashTable2[i].roll_number = -1;
    }
}

void Hash::LinearProb_Without(Student Stud, int key)
{
    int loc = key % 10;

    if (HashTable[loc].roll_number == -1)
    {
        HashTable[loc].roll_number = key;
        HashTable[loc].name = Stud.name;
        HashTable[loc].grade = Stud.grade;
    }
    else
    {
        int j = (loc + 1) % 10;
        while (j != loc)
        {
            if (HashTable[j].roll_number == -1)
            {

                HashTable[j].roll_number = key;
                HashTable[j].name = Stud.name;
                HashTable[j].grade = Stud.grade;
                break;
            }

            j = (j + 1) % 10;
        }
        if (j == loc)
        {
            cout << "\nHash is Full";
        }
    }
}
void Hash::LinearProb_With(Student Stud, int key){
    int loc = key % 10;

    if (HashTable2[loc].roll_number == -1)
    {
        HashTable2[loc].roll_number = key;
        HashTable2[loc].name = Stud.name;
        HashTable2[loc].grade = Stud.grade;
    }
    else
    {
        temp=Stud;
        int newloc=HashTable2[loc].roll_number%10;
        if(loc!=newloc){
            temp=HashTable2[loc];
            HashTable2[loc].roll_number = key;
            HashTable2[loc].name = Stud.name;
            HashTable2[loc].grade = Stud.grade;

        }
        int j = (loc + 1) % 10;
        while (j != loc){
            if (HashTable2[j].roll_number == -1)
            {

                HashTable2[j].roll_number = temp.roll_number;
                HashTable2[j].name = temp.name;
                HashTable2[j].grade = temp.grade;
                break;
            }

            j = (j + 1) % 10;
        }
        if (j == loc)
        {
            cout << "\nHash is Full";
        }
    }
}
void Hash::display()

{

    cout<<"Index\t\tRoll No.\tName\t\tGrade\n";
    for (int i = 0; i < 10; i++)
    {
        if (HashTable[i].roll_number != -1)
        {
            cout<<i<<"\t\t"<<HashTable[i].roll_number<<"\t\t"<<HashTable[i].name<<"\t\t"<<HashTable[i].grade<<endl;
        }
    }
}
void Hash::display2()

{

    cout<<"Index\t\tRoll No.\tName\t\tGrade\n";
    for (int i = 0; i < 10; i++)
    {
        if (HashTable2[i].roll_number != -1)
        {
            cout<<i<<"\t\t"<<HashTable2[i].roll_number<<"\t\t"<<HashTable2[i].name<<"\t\t"<<HashTable2[i].grade<<endl;
        }
    }
}

int main()
{
    Hash s;
    int c=0;
    s.create();
    do{
        cout<<"\n1. Displaying with Replacement";
        cout<<"\n2. Displaying without Replacement";
        cout<<"\n3. Exit";
        cout<<"\n";
        cin>>c;
        switch(c){
            case 1:
                cout<<"\nDisplaying with Replacement:\n";
                s.display2();
                break;
            case 2:
                cout<<"\nDisplaying without Replacement:\n";
                s.display();
            case 3:
                cout<<"\nExited";
                break;
        }

    } while (c!=3);
}
