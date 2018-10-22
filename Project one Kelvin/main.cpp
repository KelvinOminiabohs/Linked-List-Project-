
//
//  main.cpp
//  Lab 2
//
//  Created by Kelvin Ominiabohs on 8/30/18.
//  Copyright © 2018 Kelvin Ominiabohs. All rights reserved.
//
#include <iostream>

using namespace std;
struct nodeType // the name "nodetype" is just a name, doesn't really matter. Just called that because we are making our own node type
{
    int info; // type of info for node is integer
    nodeType *link; //pointer for node type
    nodeType *back;
};
// A struct for the node, data, and the pointer to the node
// the list of functions I will be using in program

void createList(nodeType*& first, nodeType*& last);
void printList(nodeType*& first);
void dividemid (nodeType*& first, nodeType*& last); // divides linked list
void divideat (nodeType*& first, nodeType*& last); //
void insert(nodeType*& first, nodeType*& last, const int& newitem );

int main()
{
    
    nodeType *first, *last; //pointers to tell who is first and who is last.  2 pointers are made pointer
    //to a node (Struct called nodeType)
    
    createList(first,last);
    insert(first, last, 37);
    insert(first,last,14);
    insert(first,last,68);
    insert(first,last,47);
    insert(first,last,34);
    insert(first,last,35);
    insert(first,last,65);
    insert(first,last,66);
    insert(first,last,69);
    dividemid(first,last);
    divideat(first,last);
    
    system("PAUSE");
    return 0;
}

void createList(nodeType*& first, nodeType*& last) //*& means pass by reference, can be changed
{
    int number;
    nodeType *newNode;
    
    first = NULL;
    last = NULL;
    
    cout<<"Enter an integer (-999 to stop): ";
    cin>>number;
    cout<<endl;
    
    while (number != -999)
    {
        newNode = new nodeType; // create new node
        newNode->info = number; // puts number inputed by user to the newnode's infor
        newNode->link = NULL; // Makes the new node point to nothing
        newNode->back=NULL;
        
        if (first == NULL) // first element in the this
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode; // telling the last thing that it is pointing to point to the next thing
            last = newNode; // telling the pointer itself that it is last
        }
        cout<<"Enter an integer (-999 to stop): ";
        cin>>number;
        cout<<endl;
    } // end of while-loop
    
} // end of build list function

void printList(nodeType*& first)
{
    
    cout<<"print list"<<endl;
    nodeType* current;// makes new pointer
    current = new nodeType; // makes new node
    current = first;// current is now first
    
    while (current != NULL)
    {
        cout << current->info <<endl<<endl;
        current = current->link;
    }
    
    
}



void insert(nodeType*& first, nodeType*& last, const int& newitem)
{
    nodeType *current = NULL; // creates new node
    nodeType *trailcurrent = NULL; // creates another new node
    nodeType *New; // creates another new node lol
    bool found; // bool statement
    
    New= new nodeType; // makes new a node type
    New->info = newitem; // puts whatever number new item is and stores it to info part of the node in "New"
    New->link = NULL; // the node "New" is pointing to nothing
    New->back = NULL;
    
    if (first == NULL) // if the first node is pointing to nothing or the list is empty
    {
        first = New; // first node is new
        last = New; // last node is new
    }
    else // if not
    {
        current=first; // the node "current" now becomes first
        found = false; // bool found statemnet is not true yet
        
        while (current != NULL && !found) // while current is not pointing to nothing and when found is not true
            if (current->info >= newitem) // if current info is greater or equal to new item
                found = true; // found now becomes true.
            else
            {
                trailcurrent=current; // trailcurrent becomes what next current is at this moment
                current = current->link; // current is now the next thing in the list
                
            }
        if (current == first) // if current is the first node
        {
            first->back= New; //first is after new
            New->link= first; // Whatever the new node is pointing to is now the first nod
            first=New; // New node is now first
            
        }
        else
        {
            if(current!=NULL)
            {
                trailcurrent->link =New;
                New->back = trailcurrent;
                New->link=current;
                current ->back= New;
            }
            else
            {
                trailcurrent->link = New;
                New->back = trailcurrent;
                last = New;
            }
        }
    }
    cout<<"after inserted new node updated list list"<<endl;
    //printList(first);
    
}

void dividemid(nodeType*& first, nodeType*& last)
{
    nodeType *current = new nodeType;
    nodeType *trailcurrent = new nodeType;
    nodeType *last2 = new nodeType; // creates new node
    nodeType *first2 = new nodeType;
    last2=last;
    int counter = 0; // counter
    int middle;
    nodeType *x = new nodeType; // creates new node type
    x = first; // new node type is now the first
    // gets the number of linked list
    while (x !=NULL) // while x doesn't point to NULL
    {
        x = x->link;
        counter++;
    }
    //
    cout<<"The length of list is "<< counter <<endl<<endl;
    
    if (counter % 2 == 0)
        middle = counter /2;
    else
        middle = (counter/2)+1;
    
    cout<<"Middle is " <<middle <<endl;
    // the code so far  to here works
    
    current = first;
    trailcurrent = first;
    
    //
    for (int j=1; j<middle;)
    {
        current=current->link;
        j++;
    }
    
    
    //
    last2=last;
    last=current;
    first2=last->link;
    last->link = NULL;
    first2->back=NULL;
    
    cout<<"first number of first list is "<< first->info<<endl;
    cout<<"last number of first list is "<< last->info<<endl;
    cout<<"first number of 2nd list is "<< first2->info<<endl;
    cout<<"first number of 2nd list is "<< last2->info<<endl;
    
    cout<<"first node list"<<endl;
    printList(first);
    
    cout<<"2nd node of list"<<endl;
    printList(first2);
    
}



void divideat(nodeType*& first, nodeType*& last)
{
    nodeType *current = new nodeType;
    nodeType *trailcurrent = new nodeType;
    nodeType *last2 = new nodeType; // creates new node
    nodeType *first2 = new nodeType;
    last2=last;
    int counter = 0; // counter
    int dividenumber;
    
    nodeType *x = new nodeType; // creates new node type
    x = first; // new node type is now the first
    // gets the number of linked list
    while (x !=NULL) // while x doesn't point to NULL
    {
        x = x->link;
        counter++;
    }
    cout<<"what number of list do you want to divide at? "<<endl;
    cin>>dividenumber;
    
    
    
    
    current = first;
    trailcurrent = first;
    
    //
    
    for (int j=1; j<dividenumber;)
    {
        current=current->link;
        j++;
    }
    
    //
    last2=last;
    last=current;
    first2=last->link;
    last->link = NULL;
    first2->back=NULL;
    
    cout<<"after youre chosesn number to split"<<endl;
    
    cout<<"first number of first list is "<< first->info<<endl;
    cout<<"last number of first list is "<< last->info<<endl;
    cout<<"first number of 2nd list is "<< first2->info<<endl;
    cout<<"first number of 2nd list is "<< last2->info<<endl;
    
    cout<<"first list"<<endl;
    printList(first);
    
    cout<<"2nd list"<<endl;
    printList(first2);
    
}














