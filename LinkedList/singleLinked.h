

class singleLinked
{
    //Creating 2 nodes, head and tail
private:
    node* head, * tail;
public:

    singleLinked() {

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
            cout << head->data << endl;
            printList(head->link);
        }
    }


};