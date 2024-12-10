#pragma
#include <iostream>
#include<irrKlang.h>
#include<string>
#include<fstream>
#include"doubleLinkedlist.h"
#include"playlist.h"
#include<conio.h>
using namespace std;
using namespace irrklang;


struct Node_manager
{
    string Name_reader;
    Node_playlist* headplaylist; //head of the playlist

    Node_manager* next;
    Node_manager* prev;


    Node_manager(string& name) : Name_reader(name), headplaylist(nullptr), next(nullptr), prev(nullptr) {}

    // we put this function there to choose the data we want to display

    void Display()const {
        cout << Name_reader << " ";
    }
    void set_headplaylist(Node_playlist* h)
    {
        headplaylist = h;
    }

};


class Double_list_manager
{
private:

    doublelist<Node_manager> list_reader;

public:

    //we don't need the constructor or destructor cause their jop done in doublelinked list

    //Display
    void Display_Manager()const
    {
        cout << "===============================" << endl;
        cout << "      Current Playlists        " << endl;
        cout << "===============================" << endl;

        cout << "ID\tPlaylist" << endl;
        cout << "-------------------------------" << endl;

        list_reader.Display(); // Display the playlists
        cout << endl;

    }

    size_t GetSize_Manager()const
    {
        list_reader.Getsize();
    }

    //add element at first 
    void Insert_First_Manager()
    {
        string name;
        cout << "Enter the playlist name: ";
        cin >> name;

        //Allocate The New Node
        Node_manager* new_node = new Node_manager(name);  //creation of new node (manager node)(have a pointer to playlist)

        //for each reader his playlist 
        Double_playlist* playlist = new Double_playlist();  //creation of playlist (carries surahs)
        new_node->set_headplaylist(playlist->GetHead_playlist());  //(the link between the reader and his playlist)

        list_reader.Insert_first(new_node);

    }

    //add element at end
    void Insert_End_Manager()
    {

        string name;
        cout << "Enter the playlist name: ";
        cin >> name;

        //Allocate The New Node
        Node_manager* new_node = new Node_manager(name);  //creation of new node (manager node)(have a pointer to playlist)

        //for each reader his playlist 
        Double_playlist* playlist = new Double_playlist();   //creation of playlist (carries surahs)
       new_node->set_headplaylist(playlist->GetHead_playlist());  //(the link between the reader and his playlist)

        list_reader.Inseert_End(new_node);

    }

    //add at pos
    void Insert_at_pos_Manager(int pos)
    {
        string name;
        cout << "Enter the playlist name: ";
        cin >> name;

        //Allocate The New Node
        Node_manager* new_node = new Node_manager(name);

        //for each reader his playlist 
        Double_playlist* playlist = new Double_playlist();   //creation of playlist (carries surahs)
        new_node->set_headplaylist(playlist->GetHead_playlist());  //(the link between the reader and his playlist)

        list_reader.Insert_at_pos(new_node, pos);


    }
    //Remove At First 
    void Remove_first_Manager()
    {
        list_reader.Delete_First();
    }

    //Remove At End 
    void Remove_End_Manager()
    {
        list_reader.Delete_End();
    }

    //Rmove At Pos
    void Remove_at_pos_Manager(int& pos)
    {
        list_reader.Delete_at_pos(pos);
    }

    //search by reader name
    Node_manager* Search_By_Name_Reader(const string& reader_name) {

        //allocate temp node that will traverse on manager playlist
        Node_manager* current = list_reader.getHead();

        //traverse
        while (current != nullptr) {

            if (current->Name_reader == reader_name) {
                return current; // Found the node
            }
            current = current->next;
        }
        return nullptr; // Not found
    }

    
    void Add_Surah_To_Playlist() {
        char c = 'y';
        while (c == 'y' || c == 'Y') {
            system("cls");
            Display_Manager();

            string Reader_Name;
            cout << "Enter the playlist name: ";
            cin >> Reader_Name;
            Node_manager* ReaderNode = Search_By_Name_Reader(Reader_Name);

            if (ReaderNode == nullptr) {
                cout << "The Reader Not Found :(" << endl;
                return;
            }

            // Case 1: If the playlist is empty (headplaylist is nullptr), create the first surah
            if (ReaderNode->headplaylist == nullptr) {
                string Surah_Name, Surah_type, Path;
                cout << "Enter surah name: ";
                cin >> Surah_Name;
                cout << "Enter surah type: ";
                cin >> Surah_type;
                cout << "Enter surah path: ";
                cin >> Path;

                // Create the first surah node and set it as the head
                Node_playlist* new_node = new Node_playlist(Surah_Name, Surah_type, Path);
                ReaderNode->headplaylist = new_node;  // Set the first surah as the head of the playlist

            }
            // Case 2: If playlist is not empty, add a surah at the end
            else {
                // Insert the new surah at the end of the existing playlist
               string Surah_Name, Surah_type, Path;
                cout << "Enter surah name: ";
                cin >> Surah_Name;
                cout << "Enter surah type: ";
                cin >> Surah_type;
                cout << "Enter surah path: ";
                cin >> Path;

                // Create a new surah node
                Node_playlist* new_node = new Node_playlist(Surah_Name, Surah_type, Path);
               
               
                // Insert the node at the end of the current playlist
               
               Node_playlist* current = ReaderNode->headplaylist;
                while (current->next != nullptr) {
                    current = current->next;  // Traverse to the last node
                }
                current->next = new_node;   // Attach new surah at the end
                new_node->prev = current; 
                 // Link the new node back to the last node

            }

            // Ask the user if they want to add another surah
            cout << "Add Another Surah To The Current List? Press (y) or (n): ";
            cin >> c;
        }
    }

    void Display_playlist_of_reader()
    {
        Display_Manager();

        string Reader_Name;
        cout << "Enter the playlist name: ";
        cin >> Reader_Name;

        Node_manager* ReaderNode = Search_By_Name_Reader(Reader_Name);

        if (ReaderNode == nullptr)
        {
            cout << "The Reader Not Found :(" << endl;
            return;
        }

        cout << "-----------------------------------------------------------" << endl;
        cout << "                          playlist : " << Reader_Name << endl;

        Double_playlist p;
       p.set_head_playlist(ReaderNode->headplaylist);
       p.Display_Playlist();

    }

    void Remove_Surah_From_Playlist() {
        char c = 'y';
        while (c == 'y' || c == 'Y') {
        system("cls");
        Display_Manager();

        // Get the playlist name
        string Reader_Name;
        cout << "Enter the playlist name: ";
        cin >> Reader_Name;
        Node_manager* ReaderNode = Search_By_Name_Reader(Reader_Name);

        if (ReaderNode == nullptr) {
            cout << "The playlist \"" << Reader_Name << "\" was not found." << endl;
            return;
        }
        Double_playlist* playlist = new Double_playlist();
        // Display surahs in the playlist
        playlist->set_head_playlist(ReaderNode->headplaylist);

        // Display the surahs in the playlist
        playlist->Display_Playlist();

        // Get the surah name to remove
        string Surah_Name;
        cout << "Enter the name of the surah to remove: ";
        cin >> Surah_Name;

        // Remove the surah by name
       bool r= playlist->Remove_Surah(Surah_Name);
       if (r == true) {
           cout << "Surah removed successfully from the playlist." << endl;
       }
       else {
           // Surah not found
           cout << "Surah "<< " was not found in the playlist." << endl;
       }

        // After removal, we need to update the head pointer in Node_manager if the head of the playlist changed
        Node_playlist* new_head = playlist->GetHead_playlist();  // Get the new head after removal

        if (ReaderNode->headplaylist != new_head) {
            ReaderNode->set_headplaylist(new_head);  // Update the head pointer in the manager node
        }
        cout << "Remove Another Surah To The Current List? Press (y) or (n): ";
        cin >> c;
        }
    }
    
    void Display_Specific_Surah() {
        string Reader_Name, Surah_Name;
        cout << "Enter the playlist name: ";
        cin >> Reader_Name;

        // Search for the reader's playlist
        Node_manager* ReaderNode = Search_By_Name_Reader(Reader_Name);
        if (ReaderNode == nullptr) {
            cout << "The reader \"" << Reader_Name << "\" was not found." << endl;
            return;
        }

        // Get the name of the surah to display
        cout << "Enter the name of the surah to display: ";
        cin >> Surah_Name;

        // Create a playlist object and set the head to the reader's playlist
        Double_playlist* playlist = new Double_playlist();
        playlist->set_head_playlist(ReaderNode->headplaylist);

        // Call the function to print the surah by name
        playlist->Print_Surah_By_Name(Surah_Name);
    }

    void Print_All_Playlists_With_Surah() {
        Node_manager* currentReader = list_reader.getHead();  // Get the first reader node

        // Traverse all readers (managers)
        while (currentReader != nullptr) {
            cout << "Playlist for Reader: " << currentReader->Name_reader << endl;
            Double_playlist *playlist=new Double_playlist();
            playlist->set_head_playlist(currentReader->headplaylist);
            playlist->Display_Playlist();

            // Move to the next reader
            currentReader = currentReader->next;

            cout << "-------------------------------------------" << endl;
        }
    }

    void Remove_Playlist() {
        Display_Manager();
        string playlistName;
        cout << "Enter the name of the playlist to remove: ";
        cin >> playlistName;
        Node_manager* playlistNode = Search_By_Name_Reader(playlistName);

        if (playlistNode == nullptr) {
            cout << "Playlist " << playlistName << " was not found." << endl;
            return;
        }
        int position = 1;  // Position of the node in the list
        Node_manager* current = list_reader.getHead(); 
        while (current != nullptr) {
            if (current == playlistNode) {
                list_reader.Delete_at_pos(position);

                cout << "Playlist \"" << playlistName << "\" has been successfully removed." << endl;
                return;
            }
            current = current->next;
            position++;
        }

        cout << " Playlist " << playlistName << "\" was not found." << endl;
    }
    void Save_Specific_Playlist_To_File() {
        system("cls");
        Display_Manager(); // This function should display all the available playlists

        // Get the playlist name from the user
        string playlistName;
        cout << "Enter the name of the playlist to save: ";
        cin >> playlistName;

        // Search for the playlist in the manager
        Node_manager* playlistNode = Search_By_Name_Reader(playlistName); // Assuming Search_By_Name_Reader is defined

        if (playlistNode == nullptr) {
            cout << "Playlist \"" << playlistName << "\" was not found." << endl;
            return;
        }

        // Get the head of the playlist
        Node_playlist* current = playlistNode->headplaylist;
        if (current == nullptr) {
            cout << "The playlist is empty. Nothing to save." << endl;
            return;
        }

        // Open the file for writing (overwrite the existing file)
        ofstream out("playlist.txt",ios::app);

        // Write playlist name to the file
        out << "Playlist name: " << playlistName << endl;
        out << "-----------------------------------" << endl;

        // Write surah details to the file
        while (current != nullptr) {
            out << "Surah name: " << current->surah_Name << endl;
            out << "Surah type: " << current->surah_type << endl;
            out << "Surah path: " << current->path << endl;
            out << "___________________________________" << endl;
            current = current->next; // Move to the next surah
        }

        out.close();
        cout << "Playlist \"" << playlistName << "\" successfully saved to file." << endl;
    }
    void Load_Specific_Playlist_From_File() {
        system("cls");
        Display_Manager();

        // Get the playlist name from the user
        string playlistName;
        cout << "Enter the name of the playlist to load: ";
        cin >> playlistName;

        // Open the file to load the playlist
        ifstream inFile("playlist.txt");
        string line;
        bool playlistFound = false;
        Double_playlist* playlist = nullptr;

        // Read through the file to find the specific playlist
        while (getline(inFile, line)) {
            if (line == "Playlist name: " + playlistName) {
                playlistFound = true;
                playlist = new Double_playlist(); // Create a new playlist instance
                break; // Start reading the surah details after this line
            }
        }

        if (!playlistFound) {
            cout << "Playlist \"" << playlistName << "\" not found in file." << endl;
            inFile.close();
            return;
        }

        // Read the surah details and add them to the playlist
        cout << "Playlist: " << playlistName << endl;
        string surahName, surahType, surahPath;
        while (getline(inFile, line)) {
            if (line == "_________________________________________") {
                // End of current surah, continue to the next one
                continue;
            }
         
                if (line.find("Surah name: ") != string::npos) {
                    cout << line << endl;  // Surah name
                    getline(inFile, line);  // Surah type
                    cout << line << endl;
                    getline(inFile, line);  // Surah path
                    cout << line << endl;
               

                
            }
                if (line == "=========================================") {
                    // End of playlist
                    break;
                }
        }

        inFile.close();
        cout << "Playlist \"" << playlistName << "\" loaded successfully." << endl;
    }
    void Save_All_Playlists_To_File() {
        system("cls");

        if (list_reader.getHead() == nullptr) {
            cout << "No playlists to save. The manager is empty." << endl;
            return;
        }

        ofstream out("playlist.txt");

        Node_manager* currentManager = list_reader.getHead();

        // Iterate through all playlists in the manager
        while (currentManager != nullptr) {
            out << "Playlist name: " << currentManager->Name_reader << endl;

            Node_playlist* currentPlaylist = currentManager->headplaylist;

            if (currentPlaylist == nullptr) {
                out << "The playlist is empty." << endl;
            }
            else {
                while (currentPlaylist != nullptr) {
                    out << "Surah name: " << currentPlaylist->surah_Name << endl;
                    out << "Surah type: " << currentPlaylist->surah_type << endl;
                    out << "Surah path: " << currentPlaylist->path << endl;
                    out << "_________________________________________" << endl;
                    currentPlaylist = currentPlaylist->next;
                }
            }

            out << "=========================================" << endl;
            currentManager = currentManager->next;
        }

        out.close();
        cout << "All playlists have been successfully saved to file"  << endl;
    }
     
    void Load_All_Playlists_From_File()
    {
        ifstream in("playlist.txt");
        if (in.is_open())
        {
            string line;
            while (getline(in, line))
            {
                cout << line << endl;
            }

        }
    }

    
    void Move_Surah()
    {
        Display_Manager();

        cout << "Enter the Playlist (Reader) Name : " << endl;
        string Reader;
        cin >> Reader;

        //find the play list in manager (readers) linkedlist
        Node_manager* ReaderNode = Search_By_Name_Reader(Reader);


        if (!ReaderNode)
        {
            cout << Reader << " Not Found :( " << endl;
            return;
        }


        Double_playlist* playlist = new Double_playlist();
        playlist->set_head_playlist(ReaderNode->headplaylist);

        // Display the surahs in the playlist
        playlist->Display_Playlist();

        // Get the surah name to move
        string Surah_Name;
        int pos;
        cout << "Enter the name of the surah to move: " << endl;
        cin >> Surah_Name;
        cout << "Enter The Position " << endl;
        cin >> pos;

        playlist->Move_Surah_at_Playlist(Surah_Name, pos);
        ReaderNode->headplaylist = playlist->GetHead_playlist();

    }

    
    void Play_Playlist() {
        Display_Manager();
        string playlistName;
        Node_manager* currentReader = nullptr;

        while (true) {
            cout << "Enter the playlist name: ";
            cin >> playlistName;

            currentReader = Search_By_Name_Reader(playlistName);
            if (currentReader == nullptr) {
                cout << "Playlist not found! Try again." << endl;
            }
            else {
                break;
            }
        }

        ISoundEngine* engine = createIrrKlangDevice();
        if (!engine) {
            cout << "Error initializing sound engine!" << endl;
            return;
        }

        Node_manager* firstPlaylist = currentReader; // Track the first playlist
        Node_manager* temp = firstPlaylist;

        // Ensure firstPlaylist points to the actual first playlist
        while (temp->prev != nullptr) {
            temp = temp->prev;
        }
        firstPlaylist = temp;

        Node_manager* lastPlaylist = currentReader; // Track the last playlist
        Node_manager* temp1 = lastPlaylist;

        // Ensure lastPlaylist points to the actual last playlist
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        lastPlaylist = temp1;

        while (true) {
            if (currentReader->headplaylist == nullptr) {
                cout << "No surahs in \"" << currentReader->Name_reader << "\"." << endl;

                currentReader = currentReader->next ? currentReader->next : firstPlaylist;
                continue;
            }

            Node_playlist* currentSurah = currentReader->headplaylist;

            // Validation for media
            string fullPath = currentSurah->path;
            if (fullPath.find("media\\") == string::npos) {
                fullPath = "media\\" + fullPath;
            }

            engine->stopAllSounds();
            engine->play2D(fullPath.c_str(), true);
            cout << "Playing Surah: " << currentSurah->surah_Name << " from Playlist: " << currentReader->Name_reader << endl;

            char c;
            bool playlistEnded = false;

            while (true) {
                c = _getch();

                if (c == 75 && currentSurah->prev != nullptr) {
                    engine->stopAllSounds();
                    currentSurah = currentSurah->prev;
                    fullPath = currentSurah->path;
                    if (fullPath.find("media\\") == string::npos) {
                        fullPath = "media\\" + fullPath;
                    }
                    engine->play2D(fullPath.c_str(), true);
                    cout << "Playing Surah: " << currentSurah->surah_Name << endl;
                }
                else if (c == 75 && currentSurah->prev == nullptr) {
                    char userChoice;
                    cout << "You're at the beginning of the playlist. Loop backward (y) or move to the previous playlist (n)? ";
                    cin >> userChoice;

                    if (userChoice == 'y' || userChoice == 'Y') {
                        engine->stopAllSounds();
                        currentSurah = currentReader->headplaylist;
                        while (currentSurah->next != nullptr) {
                            currentSurah = currentSurah->next;
                        }
                        fullPath = currentSurah->path;
                        if (fullPath.find("media\\") == string::npos) {
                            fullPath = "media\\" + fullPath;
                        }
                        engine->play2D(fullPath.c_str(), true);
                        cout << "Looping in: " << currentSurah->surah_Name << endl;
                    }
                    else if (userChoice == 'n' || userChoice == 'N') {
                        engine->stopAllSounds();
                        currentReader = currentReader->prev ? currentReader->prev : lastPlaylist;

                        while (currentReader->headplaylist == nullptr) {
                            cout << "No surahs in \"" << currentReader->Name_reader << "\"." << endl;
                            currentReader = currentReader->prev ? currentReader->prev : lastPlaylist;

                            if (currentReader == currentReader->prev) {
                                cout << "No playable playlists found." << endl;
                                return;
                            }
                        }

                        currentSurah = currentReader->headplaylist;
                        fullPath = currentSurah->path;
                        if (fullPath.find("media\\") == string::npos) {
                            fullPath = "media\\" + fullPath;
                        }
                        engine->play2D(fullPath.c_str(), true);
                        cout << "Playing Surah: " << currentSurah->surah_Name << " from Playlist: " << currentReader->Name_reader << endl;
                    }
                }
                else if (c == 77 && currentSurah->next != nullptr) { // Right arrow key
                    engine->stopAllSounds();
                    currentSurah = currentSurah->next;
                    fullPath = currentSurah->path;
                    if (fullPath.find("media\\") == string::npos) {
                        fullPath = "media\\" + fullPath;
                    }
                    engine->play2D(fullPath.c_str(), true);
                    cout << "Playing Surah: " << currentSurah->surah_Name << endl;
                }
                else if (c == 77 && currentSurah->next == nullptr) { // End of playlist
                    playlistEnded = true;
                    break;
                }
                else if (c == 72) { // Up arrow key
                    engine->setAllSoundsPaused(true);
                    cout << "Paused." << endl;
                }
                else if (c == 80) { // Down arrow key
                    engine->setAllSoundsPaused(false);
                    cout << "Resumed." << endl;
                }
                else if (c == 'n') { // Move to next playlist
                    engine->stopAllSounds();
                    cout << "Switching to next playlist" << endl;
                    currentReader = currentReader->next ? currentReader->next : firstPlaylist;
                    cout << "Moving forward to " << currentReader->Name_reader << endl;
                    break;
                }
                else if (c == 'p') {
                    engine->stopAllSounds();
                    cout << "Switching to previous playlist" << endl;
                    currentReader = currentReader->prev ? currentReader->prev : lastPlaylist;

                    while (currentReader->headplaylist == nullptr) {
                        cout << "No surahs in \"" << currentReader->Name_reader << "\"." << endl;
                        currentReader = currentReader->prev ? currentReader->prev : lastPlaylist;

                        if (currentReader == currentReader->prev) {
                            cout << "No playable playlists found." << endl;
                            return;
                        }
                    }

                    currentSurah = currentReader->headplaylist;
                    fullPath = currentSurah->path;
                    if (fullPath.find("media\\") == string::npos) {
                        fullPath = "media\\" + fullPath;
                    }
                    engine->play2D(fullPath.c_str(), true);
                    cout << "Playing Surah: " << currentSurah->surah_Name << " from Playlist: " << currentReader->Name_reader << endl;
                }
                else if (c == 'q') { // Quit
                    engine->stopAllSounds();
                    cout << "Exiting" << endl;
                    engine->drop();
                    return;
                }
            }

            if (playlistEnded) {
                char userChoice;
                cout << "You're at the end of the playlist. Loop in current playlist (y) or move to next (n)? ";
                cin >> userChoice;

                if (userChoice == 'y' || userChoice == 'Y') {
                    cout << "Looping in " << currentReader->Name_reader << endl;
                }
                else {
                    currentReader = currentReader->next ? currentReader->next : firstPlaylist;
                    cout << "Moving to " << currentReader->Name_reader << endl;

                    if (currentReader == firstPlaylist) {
                        cout << "Looping back to first playlist: " << firstPlaylist->Name_reader << endl;
                    }
                }
            }
        }

        engine->drop();
        cout << "Playback finished." << endl;
    }
};