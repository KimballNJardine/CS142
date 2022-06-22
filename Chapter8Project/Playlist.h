//
// Created by Kimball on 3/23/2022.
//

#ifndef CHAPTER8PROJECT_PLAYLIST_H
#define CHAPTER8PROJECT_PLAYLIST_H
#include <string>
#include "Song.h"
#include <vector>


class Playlist{
   public:
      Playlist();
      Playlist(std::string playlistName);
      void AddSongToPlaylist(Song* songToAdd);
      std::string GetPlaylistName();
      void PlaySongs();
      void ListPlaylistSongs();
      void RemoveSong(int songIndex);
      void RemoveSong(Song* songToDelete);
   private:
      std::string playlistName;
      std::vector<Song*> playlistSongs;
};

#endif //CHAPTER8PROJECT_PLAYLIST_H
