#pragma once
#include <iostream>
using namespace std;

template <class NodeType>
class doublelist
{
private:
    NodeType* head;
    NodeType* tail;
    size_t sizee;

public:
    //constructor
    doublelist() : head(nullptr), tail(nullptr), sizee(0) {}

    //destructor
    ~doublelist()
    {
        while (head != nullptr)
        {
            NodeType* Temp = head;
            head = head->next;
            delete Temp;
        }
    }

    //Display
    void Display()const
    {

        if (head == nullptr)
        {
            cout << "No Elements To Display ";
            return;
        }

        NodeType* Temp = head;
        int counter = 0; //we need it to display the id
        while (Temp != nullptr)
        {
            counter++;
            cout << counter << "\t ";

            Temp->Display();
            cout << endl;
            Temp = Temp->next;


        }
        cout << endl;
    }

    //return size
    size_t Getsize()const
    {
        return sizee;
    }

    //add element in first
    void Insert_first(NodeType* new_node)
    {
        //the allocate of the new node is before calling this function cause we don't know the node type now

        //check if ot empty
        if (sizee == 0)
        {
            head = tail = new_node;
            new_node->next = new_node->prev = nullptr;
        }
        else
        {
            new_node->next = head;
            new_node->prev = nullptr;
            if(head!=nullptr)
            head->prev = new_node;
            head = new_node;
        }
        sizee++;
    }

    //add element at end
    void Inseert_End(NodeType* new_node)
    {
        //check if empty
        if (sizee == 0)
        {
            head = tail = new_node;
            new_node->next = new_node->prev = nullptr;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
            new_node->next = nullptr;
        }
        sizee++;
    }

    //add at pos
    void Insert_at_pos(NodeType* new_node,int pos)
    {

        //validation on position
        
        //if insert at beginning
        if (pos == 1)
        {
            Insert_first(new_node);
            return;
        }
        //if insert at End
        if (pos == sizee + 1)
        {
            Inseert_End(new_node);
            return;
        }
        else
        {
            NodeType* Temp = head;
            for (int i = 1; i < pos - 1 && Temp->next != nullptr; i++)
            {
                Temp = Temp->next;
            }
            new_node->next = Temp->next;
            new_node->prev = Temp;
            Temp->next = new_node;
            Temp->next->prev = new_node;
            sizee++;
        }
    }

    //Remonve At Beginning
    void Delete_First()
    {
 
        //check if there one element
         if (sizee == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            NodeType* Temp = head;
            head = head->next;
            if(head!=nullptr)
            head->prev = nullptr;
            delete Temp;
        }
        sizee--;
    }

    //Remove at End
    void Delete_End()
    {
        //if there is one element
         if (sizee == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            NodeType* Temp = tail;
            if (tail != nullptr) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete Temp;
        }
        sizee--;
    }

    //Remove At position
    void Delete_at_pos(int pos)
    {
      
        if (pos == 1)
        {
            Delete_First();
            return;
        }
        if (pos == sizee)
        {
            Delete_End();
            return;
        }
        else
        {
            NodeType* Temp = head;
            for (size_t i = 1; i < pos - 1; i++)
            {
                Temp = Temp->next;
            }
            NodeType* node_delete = Temp->next;
            Temp->next = node_delete->next;
            node_delete->next->prev = Temp;
            delete node_delete;
            sizee--;
        }
    }

   
    //return head
    NodeType* getHead()const
    {
        return head;
    }

    void sethead(NodeType* newhead) //i will use it in add surah to play list and other function that in manager and related to playlist
    {
        head = newhead;
    }



};
