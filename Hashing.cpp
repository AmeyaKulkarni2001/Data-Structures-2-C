#include <iostream>
#define max 10
using namespace std;
class student
{
	int roll_no;
	string name;
	char grade;
	public :
		student()
		{
			roll_no=-1;
			name="";
			grade=' ';
		}
		void accept()
		{
		cout<<"\nEnter the student details\n";
		cout<<"Roll number: ";
		cin>>roll_no;
		cout<<"Name: ";
		cin>>name;
		cout<<"Grade: ";
		cin>>grade;
		}
		friend class Hash;
};

class Hash
{
	student Hashtable[max];
	public :
		Hash()
		{
			for(int i=0;i<max;i++)
				Hashtable[i].roll_no=-1;
		}
		void linear_without(student );
		void linear_with(student );
		void search(int);
		void display();
		void display_wo();
};

void Hash :: linear_with(student s)
{
	int loc=s.roll_no%max;
	if(Hashtable[loc].roll_no==-1)		//if the home address is blank
	{
		Hashtable[loc].roll_no=s.roll_no;
		Hashtable[loc].name=s.name;
		Hashtable[loc].grade=s.grade;
		return ;
	}
	else
	{
	    cout << "\nCOLLISION OCCURRED\n";
		student temp;
		temp=s;
		if(loc!=(Hashtable[loc].roll_no%max))	//if the element already present does not have the home address at this position
		{
			temp=Hashtable[loc];
			Hashtable[loc]=s;
		}
		int i=(loc+1)%max;
		while(i!=loc)
		{
			if(Hashtable[i].roll_no==-1)	//place the replaced element at the next blank position in the table
			{
				Hashtable[i]=temp;
				return ;
			}
			i=(i+1)%max;
		}
		if(i==loc)
			cout<<"\nHashtable is full\n";
	}
}

void Hash :: linear_without(student s)
{
	int loc=s.roll_no%max;
	if(Hashtable[loc].roll_no==-1)			//if the home address is blank
	{
		Hashtable[loc].roll_no=s.roll_no;
		Hashtable[loc].name=s.name;
		Hashtable[loc].grade=s.grade;
		return ;
	}
	else				//if home address is not blank place the element in the next available blank position
	{
	    cout << "\nCOLLISION OCCURRED\n";
		int i=(loc+1)%max;
		while(i!=loc)
		{
			if(Hashtable[i].roll_no==-1)
			{
				Hashtable[i]=s;
				return ;
			}
			i=(i+1)%max;
		}
		if(i==loc)
			cout<<"\nHashtable is full\n";
	}
}

void Hash :: search(int r)
{
	int i;
	int loc=r%max;
	if(Hashtable[loc].roll_no==r)	//the element to be searched is at the home address
	{
		cout<<"Student Details found at location "<<loc<<"\n";
		cout<<"Roll number :"<<Hashtable[loc].roll_no<<endl<<"Name : "<<Hashtable[loc].name<<endl<<"Grade : "<<Hashtable[loc].grade<<endl;
	}
	else		//else check all other locations in table unless the entry is found
	{
		i=(loc+1)%max;
		while(i!=loc)
		{
			if(Hashtable[i].roll_no==r)
			{
				cout<<"Student Details found at location "<<i<<"\n";
				cout<<"Roll number :"<<Hashtable[i].roll_no<<endl<<"Name : "<<Hashtable[i].name<<endl<<"Grade : "<<Hashtable[i].grade<<endl;
				break;
			}
			i=(i+1)%max;
		}
	}
	if(i==loc)
		cout<<"Student Details not found in database\n";
}

void Hash ::display()
{
	cout<<"\nThe students records are as follows:\n";
	cout<<"\tRollNo.\t\tNAME\tGRADE\n";
	for(int i=0;i<max;i++)
	{
	    cout<<i<<"\t"<<Hashtable[i].roll_no<<"\t\t"<<Hashtable[i].name<<"\t"<<Hashtable[i].grade<<"\n";
	}
}

void Hash ::display_wo()
{
	cout<<"\nThe students records are as follows:\n";
	cout<<"\tRollNo.\t\tNAME\tGRADE\n";
	for(int i=0;i<max;i++)
	{
	    cout<<i<<"\t"<<Hashtable[i].roll_no<<"\t\t"<<Hashtable[i].name<<"\t"<<Hashtable[i].grade<<"\n";
	}
}


int main()
{
int r,c;
char ch;
Hash h;
    do{
		cout<<"\nMENU\n1.Display Linear Probing Without Replacement\n2.Display Linear Probing With Replacement"<<endl;
		cout << "3.Search Record\n4.Exit.";
		cout << "\nEnter Your Choice: ";
		cin >> c;
		switch(c)
		{
			case 1:
				   do
				  {
					student s;
					s.accept();
					h.linear_without(s);
					cout<<"\nWould you like to continue(y/n): ";
					cin>>ch;
				  } while(ch=='y'||ch=='Y');
				    h.display_wo();
				    break;
				    
			case 2:
				   do
				   {
				   student s;
			 	   s.accept();
				   h.linear_with(s);
				   cout<<"\nWould you like to continue(y/n): ";
				   cin>>ch;
				    }while(ch=='y'||ch=='Y');
				   h.display();
				   break;
				    
			case 3:
				   cout<<"\nEnter the roll no to be searched:";
				   cin>>r;
				   h.search(r);
				   break;
				
			case 4:
				   cout << "\nExiting..\n";
				   break;
				   
			default:
				cout<<"\nInvalid choice.\n";
		}
	}while(ch!=4);
	return 0;
}
