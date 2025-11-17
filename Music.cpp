#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

// define default constructor
Music::Music() {
  artist = new char[81];
  duration = 0;
  publisher = new char[81];
}

// define constructor with parameters 
Music::Music(char* userTitle, char* userArtist, int userYear,
	     int userDuration, char* userPublisher):
             Media(userTitle, userYear) {
  artist = new char[81];
  strcpy(artist, userArtist);

  duration = userDuration;

  publisher = new char[81];
  strcpy(publisher, userPublisher);
}

// define accessor method for artist var
char* Music::getArtist() {
  return artist;
}

// define accessor method for duration var
int Music::getDuration() {
  return duration;
}

// define accessor method for publisher var
char* Music::getPublisher() {
  return publisher;
}

// define method to print object info
void Music::printInformation() {
  cout << title << ", " << artist << ", " << year << ", "
       << duration << ", " << publisher << endl;
}

// define destructor to delete dynamically allocated memory
Music::~Music() {
  delete artist, publisher;
}
