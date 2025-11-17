#include <iostream>
#include <cstring>
#include "Movies.h"

using namespace std;

Movies::Movies() {
  director = new char[81];
  duration = 0;
  rating = 0.0;
}

Movies::Movies(char* userTitle, char* userDirector, int userYear,
	       int userDuration, float userRating):
               Media(userTitle, userYear) {
  director = new char[81];
  strcpy(director, userDirector);

  duration = userDuration;

  rating = userRating;
}

char* Movies::getDirector() {
  return director;
}

int Movies::getDuration() {
  return duration;
}

float Movies::getRating() {
  return rating;
}

void Movies::printInformation() {
  cout << title << ", " << director << ", " << year << ", "
       << duration << ", " << rating << endl;
}
