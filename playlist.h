#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include"doubleLinkedlist.h"
using namespace std;

struct Node_playlist // node of surah
{
    string surah_Name;
    string surah_type;
    string path;

    Node_playlist* next;
    Node_playlist* prev;

    Node_playlist() : surah_Name(" "), surah_type(" "), path(" "), next(nullptr), prev(nullptr) {}
    Node_playlist(string name, string type, string p) : surah_Name(name), surah_type(type), path(p), next(nullptr), prev(nullptr) {}
    
    void Display()const {
        cout << surah_Name << "\t" << surah_type << " \t" << path << endl;
    }
    void Display_specific()const {
        cout << "======================================" << endl;
        cout << "Surah\tType\tPath" << endl;
        cout << "--------------------------------------" << endl;
        cout << surah_Name << "\t"
            << surah_type << "\t"
            << path << endl;
        cout << "======================================" << endl;
    }
};

class Double_playlist
{
private:
    doublelist<Node_playlist> playlist;

public:

    //we don't need the constructor or destructor cause their jop done in doublelinked list

    //Display
    void Display_Playlist()const
    {
        cout << "-----------------------------------------------------------" << endl;
        //cout << "                          playlist : name of reader" << endl;
        cout << "ID\tSurah\tType\tPath " << endl;

        playlist.Display();

        cout << endl;

    }

    //return size
    size_t  GetSize_of_playlist()const
    {
        size_t Size = playlist.Getsize();
        return Size;
    }

    //add surah at first
    Node_playlist* Insert_First_playlist()
    {
      
        string Surah_Name, Surah_type, Path;
        cout << "Enter surah name: ";
        cin >> Surah_Name;
        cout << "Enter surah type: ";
        cin >> Surah_type;
        cout << "Enter surah path: ";
        cin >> Path;
        //Allocate The New Node
        Node_playlist* new_node = new Node_playlist(Surah_Name, Surah_type, Path);
        playlist.Insert_first(new_node);
        return new_node;
    }

    //add surah at end
    void Insert_end_playlist()
    {
      
        string Surah_Name, Surah_type, Path;
        cout << "Enter surah name: ";
        cin >> Surah_Name;
        cout << "Enter surah type: ";
        cin >> Surah_type;
        cout << "Enter surah path: ";
        cin >> Path;

        // Create a new surah node
        Node_playlist* new_node = new Node_playlist(Surah_Name, Surah_type, Path);

        playlist.Inseert_End(new_node);
        

    }

    //add Surah at pos
    void Insert_at_pos_playlist(int pos)
    {
        string Surah_Name, Surah_type, Path;
        cout << "Enter surah name: ";
        cin >> Surah_Name;
        cout << "Enter surah type: ";
        cin >> Surah_type;
        cout << "Enter surah path: ";
        cin >> Path;

        //Allocate The New Node
        Node_playlist* new_node = new Node_playlist(Surah_Name, Surah_type, Path);

        playlist.Insert_at_pos(new_node, pos);
    }

    //Delete At Biginning 
    void Delete_first_playlist()
    {
        playlist.Delete_First();
    }

    //Delete At End
    void Delete_End_playlist()
    {
        playlist.Delete_End();
    }

    //Delete At Pos
    void Delete_pos_playlist(int pos)
    {
        playlist.Delete_at_pos(pos);
    }


    //retun the head of the playlist

    Node_playlist* GetHead_playlist()const
    {
        return playlist.getHead();
    }

    void set_head_playlist(Node_playlist* p)
    {
        playlist.sethead(p);
    }
    

    void Print_Surah_By_Name(const string& surah_name) {
        Node_playlist* current = playlist.getHead();  // Get the head of the playlist
        bool found = false;

        // Traverse the playlist to find the surah by name
        while (current != nullptr) {
            if (current->surah_Name == surah_name) {
                current->Display_specific();  // If found, print the surah's details
                found = true;
                break;  // Exit the loop once the surah is found
            }
            current = current->next;  // Move to the next node in the playlist
        }

        // If the surah was not found, display a message
        if (!found) {
            cout << "Surah with the name \"" << surah_name << "\" was not found in the playlist." << endl;
        }
    }
   void Save_Playlist_To_File(string fileName, string playlist_name) {
        ofstream out(fileName, ios::app);

        Node_playlist* current = playlist.getHead(); // Get the head of the playlist
        if (current == nullptr) {
            cerr << "The playlist is empty. Nothing to save." << endl;
            out.close();
            return;
        }

        // Write playlist contents to file
        out << "Playlist name: " << playlist_name << endl;
        while (current != nullptr) {
            out << "Surah name: " << current->surah_Name << endl;// Write the surah name
            out << "Surah type: " << current->surah_type << endl;
            out << "Surah path: " << current->path << endl;
            out << "_________________________________________" << endl;
            current = current->next;               // Move to the next surah
        }

        out.close();
        cout << "Playlist successfully saved to \"" << fileName << "\"." << endl;
    }

   void Move_Surah_at_Playlist(const string Surah_name, size_t pos) {
       Node_playlist* NodeToMove = playlist.getHead();

       // Find the node to move
       while (NodeToMove) {
           if (NodeToMove->surah_Name == Surah_name) {
               break;
           }
           NodeToMove = NodeToMove->next;
       }

       if (!NodeToMove) {
           cout << "This Surah is not found in this playlist." << endl;
           return;
       }

      

       // Store the node to move in a temporary variable
       Node_playlist* TempNode = NodeToMove;

       // Remove the node from its current position 
       if (NodeToMove->prev) {
           NodeToMove->prev->next = NodeToMove->next;//check if it is not head
       }
       else {
           playlist.sethead(NodeToMove->next);  // Update head if the node is the first node
       }

       if (NodeToMove->next) {
           NodeToMove->next->prev = NodeToMove->prev;//check tail
       }
       pos--;
       // Now, let's insert the node at the desired position
       Node_playlist* Temp = playlist.getHead();
       size_t currentPos = 0;

       // Traverse to the desired position
       while (Temp && currentPos < pos) {
           currentPos++;
           Temp = Temp->next;
       }

       // Insert the node at the new position
       if (Temp) {
           // Insert TempNode before Temp
           TempNode->next = Temp;
           TempNode->prev = Temp->prev;

           if (Temp->prev) {
               Temp->prev->next = TempNode;  // Set the previous node's next pointer to TempNode
           }
           else {
               playlist.sethead(TempNode);  // Update head if we're inserting at the first position
           }

           Temp->prev = TempNode;  // Set Temp's previous pointer to TempNode
       }
       else {
           // If Temp is null, we are at the end of the list, insert TempNode as the last node
           TempNode->next = nullptr;
           if (Temp) {
               Temp->prev = TempNode;
           }

           // Traverse to the end of the list and insert
           if (playlist.getHead() != nullptr) {
               Temp = playlist.getHead();
               while (Temp->next) {
                   Temp = Temp->next;
               }
               Temp->next = TempNode;
               TempNode->prev = Temp;
           }
           else {
               playlist.sethead(TempNode);  // If the list is empty, make TempNode the head
           }
       }
   }

   bool Remove_Surah(string surah_name) {//with container
       bool removed = false;
       Node_playlist* current = playlist.getHead();
       // Traverse the playlist to find the surah
       while (current!= nullptr) {
           if (current->surah_Name == surah_name) {

               // If the node to be removed is the head of the playlist
               if (current == playlist.getHead()) {
                   removed = true;
                   Node_playlist* new_head = current->next;
                   playlist.sethead(new_head);
                       if (new_head != nullptr) {
                           new_head->prev = nullptr;
                           delete current;
                           return removed;
                       }
                   
               }
               // If the node to be removed is the tail of the playlist
               else if (current->next == nullptr) {
                   Node_playlist* new_tail = current->prev;
                   if (new_tail != nullptr) {
                      
                       new_tail->next = nullptr;
                       delete current;
                       removed = true;
                       return removed;
                   }

               }
               // If the node is somewhere in the middle
               else {
                
                    int id;
                    cout << "Enter the ID: ";
                    cin >> id;
                    Delete_pos_playlist(id);
                    removed = true;
                   return removed;
               }
           }
           current = current->next;

       }
       return removed;
      
   }

  
};