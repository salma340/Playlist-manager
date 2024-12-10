#include <iostream>
#include<irrKlang.h>
#include "doubleLinkedlist.h"
#include"manager.h"
using namespace std;
int main() {

    Double_list_manager manager;
    
  
    int c = -1;
    while (c != 0) {
        cout << "\t\t\t=======================================================================\t\t\t" << endl;
        cout << "\t\t\t|\t\tQuraan PlayList Manager Menu:\t\t\t      |" << endl;
        cout << "\t\t\t=======================================================================\t\t\t" << endl;
        cout << "\t\t\t| 1.Add New PlayList\t\t\t\t\t\t      |" << endl;
        cout << "\t\t\t| 2.Add surah to an existing playlist\t\t\t\t      |" << endl;
        cout << "\t\t\t| 3.Remove surah from an existing playlist\t\t\t      |" << endl;
        cout << "\t\t\t| 4.Update The order of the PlayList\t\t\t\t      |" << endl;
        cout << "\t\t\t| 5.Print all current PlayLists\t\t\t\t\t      |" << endl;
        cout << "\t\t\t| 6.Print all PlayList surah\t\t\t\t\t      |" << endl;
        cout << "\t\t\t| 7.Print surah in a specific PlayList\t\t\t\t      |" << endl;
        cout << "\t\t\t| 8.Print  a specific PlayList\t\t\t\t              |" << endl;
        cout << "\t\t\t| 9.Play surah from a specific playlist\t\t\t\t      |" << endl;
        cout << "\t\t\t| Use left arrow (<-) to play the previous Surah\t\t      |" << endl;
        cout << "\t\t\t| Use right arrow (->) to play the next Surah\t\t\t      |" << endl;
        cout << "\t\t\t| Use up arrow (^) to pause the current Surah\t\t\t      |" << endl;
        cout << "\t\t\t| Use down arrow (v) to resume the current Surah\t\t      |" << endl;
        cout << "\t\t\t| Press q to exit current playlist & return back to menu \t      |" << endl;
        cout << "\t\t\t| 10.Save all playlists to file\t\t\t                      |" << endl;
        cout << "\t\t\t| 11.Load  all  playlists from file\t\t\t              |" << endl;
        cout << "\t\t\t| 12.Save an existing playlist to file\t\t\t              |" << endl;
        cout << "\t\t\t| 13.Load  an existing playlist from file\t\t\t      |" << endl;
        cout << "\t\t\t| 14.Remove existing PlayList\t\t\t\t\t      |" << endl;
        cout << "\t\t\t| 15.Exit\t\t\t\t\t\t\t      |" << endl;
        cout << "\t\t\t+=====================================================================+\t\t\t" << endl;
        cout << "Enter your choice:";        cin >> c;


        switch (c)
        {
        case 1: //add a new playlist
            system("cls");
            manager.Insert_End_Manager();

            break;

        case 2://add surah to an existing playlist
        {
            manager.Add_Surah_To_Playlist();

        }
        break;
        case 3:
            manager.Remove_Surah_From_Playlist();
            system("cls");
            break;

        case 4:
            manager.Move_Surah();
            //system("cls");
            break;

        case 5:    //display all playlists  
            manager.Display_Manager();
            break;

        case 6: //display all playlist Surah
            system("cls");
            manager.Print_All_Playlists_With_Surah();

            break;

        case 7: //display spcific playlist surah
            manager.Display_Specific_Surah();

            break;

        case 8: //display specific playlist
            manager.Display_playlist_of_reader();
            break;

        case 9:
            manager.Play_Playlist();
            //system("cls");
            break;
        case 10:
            manager.Save_All_Playlists_To_File();
            break;

        case 11:
            manager.Load_All_Playlists_From_File();
            break;

        case 12:
            manager.Save_Specific_Playlist_To_File();
            break;
        case 13:
            manager.Load_Specific_Playlist_From_File();
            break;

        case 14:
            manager.Remove_Playlist();
            break;
        case 15:
            cout << "Thanks for using the system :)" << endl;
            c = 0;
            break;

        default:
            cout << "Enter correct number" << endl;
        }
    }
    return 0;
}