#include <iostream>
using namespace std;

void accept(int heap[20])                                               //function to accept marks of all students in heap array
{
    char ch;
    cout<<"\nEnter marks obtained by students in the on-line exam of DS :- "<<endl;
    int i=1;
    do
    {
        int key;
        cout<<"\nMarks of student "<<i<<" :- "<<endl;
        cin>>key;
        heap[i]=key;
        i=i+1;
        cout<<"\nDo you want to add marks of more students ? (y/n)"<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    heap[i]=999;
}

void display(int heap[20])                                     //function to display the heap
{
    int i=1;
    while(heap[i]!=999)
    {
        cout<<"\n"<<heap[i];
        i++;
    }
}

void heapify_max(int heap[20],int i)                        //heapify_up function for max heap
{
    int j=i;
    int temp=heap[i];
    while(j>1 && temp>heap[j/2])                            //swap the nodes if child is greater than parent
    {
        int l=j/2;
        heap[j]=heap[l];
        j=j/2;
    }
    heap[j]=temp;
}

int create_max(int heap[20])                                      //function to create max heap
{
    int max_heap[20];       //local array max_heap to store the max heap
    int i=1;
    while(heap[i]!=999)
    {
        max_heap[i]=heap[i];                                     // initially copy heap[] into max_heap[]
        i++;
    }
    i=1;
    while(heap[i]!=999)
    {
        heapify_max(max_heap,i);                                 //heapify each element as it is added
        i++;
    }
    max_heap[i]=999;
    int maximum = max_heap[1];
    cout<<"\nThe MAX heap of marks is :- "<<endl;
    display(max_heap);                           //call to display function to display max heap
    return maximum; //return mazimum value
}

void heapify_min(int heap[20],int i)                        //heapify_up function for min heap
{
    int j=i;
    int temp=heap[i];
    while(j>1 && temp<heap[j/2])                             //swap the nodes if child is smaller than parent
    {
        int l=j/2;
        heap[j]=heap[l];
        j=j/2;
    }
    heap[j]=temp;
}

int create_min(int heap[20])                               //function to create min heap
{
    int min_heap[20];            //local array min_heap to store the min heap
    int i=1;
    while(heap[i]!=999)
    {
        min_heap[i]=heap[i];                               //initially copy heap[] into max_heap[]
        i++;
    }
    i=1;
    while(heap[i]!=999)
    {
        heapify_min(min_heap,i);                           //heapify each element as it is added
        i=i+1;
    }
    min_heap[i]=999;
    int minimum = min_heap[1];
    cout<<"\nThe MIN heap of marks is :- "<<endl;
    display(min_heap);                                     //call to display function to display min heap
    return minimum;  //return minimum element
}


int main()
{
    int ch,ch1;
    int min_mrks,max_mrks;
    int heap[20];
    do
    {
        cout<<"\n*************** MENU ****************"<<endl;
        cout<<"\n1. Enter marks.\n2. Display max heap.\n3. Display min heap.\n4. Find minimum and maximum marks.\n5. Exit"<<endl;
        cout<<"\n*******************************"<<endl;
        cout<<"\nEnter your choice :- "<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            accept(heap);
            break;
        case 2:
            max_mrks = create_max(heap);
            break;
        case 3:
            min_mrks = create_min(heap);
            break;
        case 4:
            cout<<"\nMaximum marks are:- "<<max_mrks<<endl;
            cout<<"\nMinimum marks are:- "<<min_mrks<<endl;
            break;
        case 5:
            break;
        default:
            cout<<"\nWrong choice."<<endl;
        }
    }while(ch!=5);
}
