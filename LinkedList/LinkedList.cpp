// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Creating node structure
struct node
{
    int data; //Holds the data for node
    node* link; //Link node for next part of list
};

class singleLink
{
    //Creating 2 nodes, head and tail
private:
    node* head, * tail;
public:

    singleLink() {

        //Set head and tail to null since there are no values added
        head = NULL;
        tail = NULL;
    }

    //Adds to linked list
    void addSingle(int num) {

        //Allocating space for node, tmp points to space
        node* tmp = new node;
        tmp->data = num; //Giving value of tmp
        tmp->link = NULL; //link pointer set to null

        //Checks if head is null (Null head means no linked list, tmp node becomes head and tail as a single node)
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        //Linked list already exists, add node to end of list
        else {
            tail->link = tmp;
            tail = tail->link;
        }

    }

    //Gets node head
    node* getHead() {
        return head;
    }

    //Traversing/printing list with recursion
    void printList(node* head) {

        //Print NULL if list is empty
        if (head == NULL) {
            cout << "NULL" << endl;

        }
        //Otherwise print the data from head and enter the linked node into recursion
        else {
            cout << head->data << " ";
            printList(head->link);
        }
    }

    //Concatenate lists a and b
    static void concatenate(struct node*a, struct node *b) {

        if (a!= NULL && b!= NULL) { //Checking if lists are null
            
            if (a->link == NULL) { //If a is finished, change link to values of b
                a->link = b;
            }
            else {
                concatenate(a->link, b); //Else, keep looking through a
            }

        }
        else {
            cout << "One of these lists is null" << endl;
        }

    }

};

int main()
{
    singleLink a;
    singleLink b;


    //Adding to list
    a.addSingle(6);
    a.addSingle(13);
    a.addSingle(15);

    b.addSingle(10);
    b.addSingle(133);
    b.addSingle(53);

    //Printing list
    a.printList(a.getHead());
    b.printList(b.getHead());

    //Concatenate a and b
    singleLink::concatenate(a.getHead(),b.getHead());
    a.printList(a.getHead());
    

    return 0;
};