
//  main.cpp
//  assignment3
//
//
//

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// adding at the head
Node* add_at_head(Node *head, int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    return temp;
}

// adding at the tail
Node* add_at_tail(Node *head, int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    Node* prev = head;
    while(prev->next != NULL)
        prev = prev->next;
    prev->next = temp;
    return head;
}

// seraching an element in the list
bool search(Node *head, int val){
    while(head!=NULL){
        if(head->data == val)
            return true;
        head = head->next;
    }
    return false;
}

// deleting the list
void del(Node *head){
    if(head == NULL)
        return;
    while(head!=NULL){
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}

// traversing the whole list with printing the values
void traverse(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

// setting head of the list to a given value
Node* set(int val){
    Node *head = new Node();
    head->data = 0;
    head->next = NULL;
    return head;
}



//  answer will be stored in head Linked list
Node* add(string num, Node *head){
    Node *temp = head;
    int carry = 0, sum;
    int len = num.length();
    for(int i=len-1;i>=0;i--){
        if(num[i] >= '0' && num[i]<='9'){
            if(temp != NULL){
                sum = temp->data + num[i] - '0' + carry;
                carry = sum / 10;
                sum = sum % 10;
                temp->data = sum;
                temp = temp->next;
            }
            else{
                sum = num[i] - '0' + carry;
                carry = sum / 10;
                sum = sum % 10;
                head = add_at_tail(head, sum);
            }
        }
    }
    while(carry > 0){
        if(temp == NULL){
            head = add_at_tail(head, carry);
            return head;
        }
        sum = temp->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp->data = sum;
        temp = temp->next;
    }
    return head;
}
//function that reverse the linked list
Node* reverse(Node *head)
{
    //initializing current and prev
    // next pointers

    Node *current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
// this function insertsort the list.
void Insertionsort(Node* current)
{
    Node* head = current;
    Node* insertionpointer = head;
    //cuurent pointing next element in list
    current = current-> next;
     // check for current not equal to NULL
    while(current != NULL)
    {    //pointing at head;
        insertionpointer = head;
        // insertionpointer not equal to current
         while (insertionpointer != current){
             // checking insertionpointer data with current data
             if (insertionpointer->data > current->data){
                 int temp = current -> data;
                 current->data = insertionpointer->data;
                 insertionpointer->data =temp;

             }else{
                 insertionpointer = insertionpointer->next;
             }
         }
         current =current->next;
    }
}



void printAns(Node *head){


    // reversing the list to print the answer
    Node *rHead = reverse(head);
    cout<<"Sum is:";
    traverse(rHead);



    int count = 0;

    Node *temp = rHead;
    cout<<"First 10 digits of sum:";
    while(count<10 && temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
        count++;

    }

    cout<< endl;

}

//main function
int main(){
    //initializing variables
    string line;


    // setting the linked list first element to 0
    Node* head = set(0);

    //openning the text file
    ifstream nums;
    nums.open("nums.txt");

    while(getline(nums,line)){
        cout<<line<<endl;
        head = add(line, head);
    }

    //closing the file
    nums.close();

    printAns(head);
    del(head);





    return 0;
}
