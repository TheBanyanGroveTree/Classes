#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music() {
  artist = new char[81];
  duration = 0;
  publisher = new char[81];
}

Music::Music(char* userTitle, char* userArtist, int userYear,
	     int userDuration, char* userPublisher):
             Media(userTitle, userYear) {
  artist = new char[81];
  strcpy(artist, userArtist);

  duration = userDuration;

  publisher = new char[81];
  strcpy(publisher, userPublisher);
}

char* Music::getArtist() {
  return artist;
}

int Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}

void Music::printInformation() {
  cout << title << ", " << artist << ", " << year << ", "
       << duration << ", " << publisher << endl;
}

Music::~Music() {
  delete artist, publisher;
}
