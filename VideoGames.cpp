#include <iostream>
#include <cstring>
#include "VideoGames.h"

using namespace std;

VideoGames::VideoGames() {
  publisher = new char[81];
  rating = 0.0;
}

VideoGames::VideoGames(char* userTitle, int userYear,
		       char* userPublisher, float userRating):
                       Media(userTitle, userYear) {
  publisher = new char[81];
  strcpy(publisher, userPublisher);
  rating = userRating;
}

char* VideoGames::getPublisher() {
  return publisher;
}

float VideoGames::getRating() {
  return rating;
}
