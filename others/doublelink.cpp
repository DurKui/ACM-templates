#include <iostream>
#include <stdio.h>
using namespace std;
class node
{
public:
    int value;
    node *next = NULL;
    node *forward = NULL;
    node(int value = 0)
    {
        this->value = value;
    }
    void addnode(int value)
    {
        node *currentnode = this;
        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
        }
        currentnode->next = new node(value);
        currentnode->next->forward = this;
    }
    node *findnode(int value)
    {
        node *currentnode = this;
        while (currentnode->next != NULL && currentnode->value != value)
        {
            currentnode = currentnode->next;
        }
        return currentnode;
    }
    void insertnode(int value)
    {
        node *nextnode = this->next;
        this->next = new node(value);
        this->next->next = nextnode;
        this->next->forward = this;
        this->next->next->forward = this->next;
    }
    void deletecurrentnode()
    {
        node *nextnode = this->next;
        this->forward->next = nextnode;
        this->next->forward = this->forward;
        delete this;
    }
}head;
int main()
{	
    for (int i = 1; i < 100; i *= 2)
    {
        head.addnode(i);
    }
    node *f1 = head.findnode(32);
    node *f2 = head.findnode(33);
    f1->deletecurrentnode();
    f1->insertnode(50);
    return 0;
}
