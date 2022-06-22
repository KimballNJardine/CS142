//
// Created by Kimball on 3/23/2022.
//
#include "Song.h"
#include <string>
Song::Song(){
   songTitle = "MISSING!!!";
   songFirstLine = "MISSING!!!";
   numTimesPlayed = 0;
}
Song::Song(std::string title) {
   songTitle = title;
   songFirstLine = "MISSING!!!";
   numTimesPlayed = 0;
}
Song::Song(std::string title, std::string firstLine) {
   songTitle = title;
   songFirstLine = firstLine;
   numTimesPlayed = 0;
}

std::string Song::ListSong() {
   std::string result = songTitle;
   result.append(": \"" + songFirstLine + "\", " + std::to_string(numTimesPlayed) + " play(s).");
   return result;
}

std::string Song::GetSongTitle() {
   return songTitle;
}

std::string Song::PlaySong() {
   numTimesPlayed++;
   return songFirstLine;
}
