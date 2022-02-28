#include <iostream>
using namespace std;

class Node
{
public:
    int coeff, power;
    Node *next;
    Node(int coeff, int power)
    {
        this->coeff = coeff;
        this->power = power;
        this->next = NULL;
    }
};

void addPolynomials(Node *head1, Node *head2)
{

    if (head1 == NULL && head2 == NULL)
        return;
    else if (head1->power == head2->power)
    {
        cout << " " << head1->coeff + head2->coeff << "x^" << head1->power << " ";
        addPolynomials(head1->next, head2->next);
    }
    else if (head1->power > head2->power)
    {
        cout << " " << head1->coeff << "x^" << head1->power << " ";
        addPolynomials(head1->next, head2);
    }
    else
    {
        cout << " " << head2->coeff << "x^" << head2->power << " ";
        addPolynomials(head1, head2->next);
    }
}

Node *addNode(Node *head,int coeff,int power){
    Node *newNode = new Node(coeff,power);
    if(head == NULL){
        return newNode;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void removeDuplicates (Node *head){
    Node *temp1,*temp2,*temp3;
    temp1 = head;
    while(temp1 != NULL && temp1->next != NULL){
        temp2 = temp1;
        while(temp2->next != NULL){
            if(temp1->power == temp2->next->power){
                temp1->coeff = temp1->coeff + temp2->next->coeff;
                temp3 = temp2->next;
                temp2->next = temp2->next->next;
                delete(temp3);
            } else {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

Node *multiplyPolynomials(Node *head1,Node *head2,Node *head3){
        Node *temp1 = head1,*temp2 = head2;

        while(temp1 != NULL ){

            temp2 = head2;
            while(temp2 != NULL){
                int coeff,power;
                coeff = temp1->coeff * temp2->coeff;
                power = temp1->power + temp2->power;
                head3 = addNode(head3,coeff,power);
                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }
    removeDuplicates(head3);
    return head3;
}

void insert(Node *&head, int coeff, int power)
{
    if (head == NULL)
    {
        head = new Node(coeff, power);
        return;
    }
    Node *new_node = new Node(coeff, power);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(Node *head)
{
    cout<< endl;
    while (head != NULL)
    {
        cout << " " << head->coeff << "x"
             << "^" << head->power;
        head = head->next;
    }
}

int main()
{

    Node *head = NULL;
    cout << "Enter the degree of poly 1 : ";
    int d1;
    cin >> d1;
    for (int i = d1; i >= 0; i--)
    {
        int coeff;
        cout << "Enter the coeff of x pow " << i << " : ";
        cin >> coeff;
        insert(head, coeff, i);
    }
    printList(head);
    cout<<endl;
    cout << "Enter the degree of poly 2 : ";
    Node *head2 = NULL;
    int d2;
    cin >> d2;
    for (int i = d2; i >= 0; i--)
    {
        int coeff;
        cout << "Enter the coeff of x pow " << i << " : ";
        cin >> coeff;
        insert(head2, coeff, i);
    }

    printList(head2);
    cout << endl
         << "Addition :" << endl;
    addPolynomials(head, head2);
    cout<<endl<<"Multiplication :"<<endl;
    Node *head3 = NULL;
    head3 = multiplyPolynomials(head,head2,head3);
    printList(head3);
    cout<<endl;
    return 0;
}
