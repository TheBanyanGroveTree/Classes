#include <iostream>
#include <cstring>
#include "Movies.h"

using namespace std;

// define default constructor
Movies::Movies() {
  director = new char[81];
  duration = 0;
  rating = 0.0;
}

// define constructor with parameters
Movies::Movies(char* userTitle, char* userDirector, int userYear,
	       int userDuration, float userRating):
               Media(userTitle, userYear) {
  director = new char[81];
  strcpy(director, userDirector);

  duration = userDuration;

  rating = userRating;
}

// define accessor method for director var
char* Movies::getDirector() {
  return director;
}

// define accessor method for duration var
int Movies::getDuration() {
  return duration;
}

// define accessor method for rating var
float Movies::getRating() {
  return rating;
}

// define method to print object info
void Movies::printInformation() {
  cout << title << ", " << director << ", " << year << ", "
       << duration << ", " << rating << endl;
}

// define destructor to delete dynamically allocated memory
Movies::~Movies() {
  delete director;
}
