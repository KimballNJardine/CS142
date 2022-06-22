//
// Created by Kimball on 3/23/2022.
//
#ifndef CHAPTER8PROJECT_SONG_H
#define CHAPTER8PROJECT_SONG_H
#include <string>

class Song{
   public:
      Song();
      Song(std::string title);
      Song(std::string title, std::string firstLine);
      std::string ListSong();
      std::string GetSongTitle();
      std::string PlaySong();
   private:
      std::string songTitle;
      std::string songFirstLine;
      int numTimesPlayed;
};


#endif //CHAPTER8PROJECT_SONG_H
