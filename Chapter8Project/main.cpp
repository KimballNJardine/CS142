//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);
int GetUserInt(const std::string& prompt);
void PrintPlaylists(std::vector<Playlist*> allPlaylists);
void PrintSongs(std::vector <Song*> allSongs);



int main() {
   std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

   std::vector<Song*> allSongs;
   std::vector<Playlist*> allPlaylists;

   std::string userMenuChoice = "none";
   bool continueMenuLoop = true;
   while (continueMenuLoop) {
      userMenuChoice = GetUserString("Enter your selection now: ");

      if (userMenuChoice == "add") {
         const std::string DONE_KEYWORD = "DONE";
         std::cout << "Enter songs' names and first lines"
                  << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

         std::string songName = "none";
         std::string firstLine = "none";

         songName = GetUserString("Song Name: ");
         while (songName != DONE_KEYWORD) {
            firstLine = GetUserString("Song's first line: ");
            allSongs.push_back(new Song(songName, firstLine));
            songName = GetUserString("Song Name: ");
         }
      }
      else if (userMenuChoice == "list") {
         for(unsigned int i = 0; i < allSongs.size(); i++){
            std::cout << allSongs.at(i)->ListSong() << std::endl;
         }
         std::cout << std::endl;
      }
      else if (userMenuChoice == "addp") {
         std::string playlistName = "none";
         playlistName = GetUserString("Playlist name:");
         allPlaylists.push_back(new Playlist(playlistName));
      }
      else if (userMenuChoice == "addsp") {
         PrintPlaylists(allPlaylists);
         int playlistIndex = GetUserInt("Pick a playlist index number:");
         PrintSongs(allSongs);
         int songIndexNumber = GetUserInt("Pick a song index number:");
         allPlaylists.at(playlistIndex)->AddSongToPlaylist(allSongs.at(songIndexNumber));
         std::cout << std::endl;
      }
      else if (userMenuChoice == "listp") {
         PrintPlaylists(allPlaylists);
         std::cout << std::endl;
      }
      else if (userMenuChoice == "play") {
         PrintPlaylists(allPlaylists);
         int playlistIndex = GetUserInt("Pick a playlist index number:");
         std::cout << std::endl;
         Playlist* playlistPicked = allPlaylists.at(playlistIndex);
         std::cout << "Playing songs from playlist: " << playlistPicked->GetPlaylistName() << std::endl;
         playlistPicked->PlaySongs();
         std::cout << std::endl;
      }
      else if (userMenuChoice == "remp") {
         PrintPlaylists(allPlaylists);
         int indexToRemove = -1;
         indexToRemove = GetUserInt("Pick a playlist index number to remove:");
         delete allPlaylists.at(indexToRemove);
         allPlaylists.erase(allPlaylists.begin() + indexToRemove);
         std::cout << std::endl;
      }
      else if (userMenuChoice == "remsp") {
         PrintPlaylists(allPlaylists);
         int playlistIndex = -1;
         playlistIndex = GetUserInt("Pick a playlist index number:");
         Playlist* pickedPlaylist = allPlaylists.at(playlistIndex);
         pickedPlaylist->ListPlaylistSongs();
         int indexToRemove = -1;
         indexToRemove = GetUserInt("Pick a song index number to remove:");
         pickedPlaylist->RemoveSong(indexToRemove);
         std::cout << std::endl;
      }
      else if (userMenuChoice == "remsl") {
         PrintSongs(allSongs);
         int indexToRemove = GetUserInt("Pick a song index number to remove:");
         Song* songToDelete = allSongs.at(indexToRemove);
         for(unsigned int i = 0; i < allPlaylists.size(); i++){
            allPlaylists.at(i)->RemoveSong(songToDelete);
         }
         delete allSongs.at(indexToRemove);
         allSongs.erase(allSongs.begin() + indexToRemove);
         std::cout << std::endl;
      }
      else if (userMenuChoice == "options") {
         std::cout << "add      Adds a list of songs to the library" << std::endl
            << "list     Lists all the songs in the library" << std::endl
            << "addp     Adds a new playlist" << std::endl
            << "addsp    Adds a song to a playlist" << std::endl
            << "listp    Lists all the playlists" << std::endl
            << "play     Plays a playlist" << std::endl
            << "remp     Removes a playlist" << std::endl
            << "remsp    Removes a song from a playlist" << std::endl
            << "remsl    Removes a song from the library (and all playlists)" << std::endl
            << "options  Prints this options menu" << std::endl
            << "quit     Quits the program" << std::endl << std::endl;
      }
      else if (userMenuChoice == "quit") {
         while(allPlaylists.size() > 0){
            delete allPlaylists.at(0);
            allPlaylists.erase(allPlaylists.begin() + 0);
         }
         while(allSongs.size() > 0) {
            delete allSongs.at(0);
            allSongs.erase(allSongs.begin() + 0);
         }
         std::cout << "Goodbye!" << std::endl;
         continueMenuLoop = false;
      }
      else {
         std::cout << "add      Adds a list of songs to the library" << std::endl
            << "list     Lists all the songs in the library" << std::endl
            << "addp     Adds a new playlist" << std::endl
            << "addsp    Adds a song to a playlist" << std::endl
            << "listp    Lists all the playlists" << std::endl
            << "play     Plays a playlist" << std::endl
            << "remp     Removes a playlist" << std::endl
            << "remsp    Removes a song from a playlist" << std::endl
            << "remsl    Removes a song from the library (and all playlists)" << std::endl
            << "options  Prints this options menu" << std::endl
            << "quit     Quits the program" << std::endl << std::endl;
      }
   }

   return 0;
}
void PrintPlaylists(const std::vector<Playlist*> allPlaylists){
   for (long unsigned int i = 0; i < allPlaylists.size(); i++) {
      std::cout << "  " << i << ": " << allPlaylists.at(i)->GetPlaylistName() << std::endl;
   }
}
void PrintSongs(const std::vector <Song*> allSongs){
   for(long unsigned int i = 0; i < allSongs.size(); i++) {
      std::cout << "  " << i << ": " << allSongs.at(i)->GetSongTitle() << std::endl;
   }
}

std::string GetUserString(const std::string& prompt) {
   std::string userAnswer = "none";

   std::cout << prompt;
   std::getline(std::cin, userAnswer);
   std::cout << std::endl;
   return userAnswer;
}
int GetUserInt(const std::string& prompt) {
   int userAnswer = 0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}

