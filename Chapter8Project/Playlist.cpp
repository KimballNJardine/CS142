//
// Created by Kimball on 3/23/2022.
//

#include "Playlist.h"
#include <string>
#include <iostream>

Playlist::Playlist(std::string playlistName) {
   this->playlistName = playlistName;
}

Playlist::Playlist() {
   playlistName = "MISSING!!!";
}

void Playlist::AddSongToPlaylist(Song *songToAdd) {
   playlistSongs.push_back(songToAdd);
}

std::string Playlist::GetPlaylistName() {
   return playlistName;
}

void Playlist::PlaySongs() {
   for(long unsigned int i = 0; i < playlistSongs.size(); i++){
      std::cout << playlistSongs.at(i)->PlaySong() << std::endl;
   }
}

void Playlist::ListPlaylistSongs() {
   for(long unsigned int i = 0; i < playlistSongs.size(); i++){
      std::cout << "  " << i << ": " << playlistSongs.at(i)->GetSongTitle() << std::endl;
   }
}

void Playlist::RemoveSong(int songIndex) {
   playlistSongs.erase(playlistSongs.begin() + songIndex);
}

void Playlist::RemoveSong(Song* songToDelete) {
   for(long unsigned int i = 0; i < playlistSongs.size(); i++){
      Song* s = playlistSongs.at(i);
      if(s == songToDelete){
         playlistSongs.erase(playlistSongs.begin() + i);
         break;
      }
   }
}
