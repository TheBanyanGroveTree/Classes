#include <iostream>
#include <cstring>
#include "VideoGames.h"

using namespace std;

// define default constructor
VideoGames::VideoGames() {
  publisher = new char[81];
  rating = 0.0;
}

// define constructor with parameters
VideoGames::VideoGames(char* userTitle, int userYear,
		       char* userPublisher, float userRating):
                       Media(userTitle, userYear) {
  publisher = new char[81];
  strcpy(publisher, userPublisher);
  rating = userRating;
}

// define accessor method for publisher var
char* VideoGames::getPublisher() {
  return publisher;
}

// define accessor method for rating var
float VideoGames::getRating() {
  return rating;
}

// define method to print object info
void VideoGames::printInformation() {
  cout << title << ", " << year << ", " << publisher << ", " << rating << endl;
}

// define destructor to delete dynamically allocated memory
VideoGames::~VideoGames() {
  delete publisher;
}
