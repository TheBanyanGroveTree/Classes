#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

// define default constructor
Media::Media() {
  title = new char[81];
  year = 0;
}

// define constructor with parameters
Media::Media(char* userTitle, int userYear) {
  title = new char[81];
  strcpy(title, userTitle);
  year = userYear;
}

// define accessor method for title var
char* Media::getTitle() {
  return title;
}

// define accessor method for year var
int Media::getYear() {
  return year;
}

// define method to print object info
void Media::printInformation() {
  cout << title << ", " << year << endl;
}

// define destructor to delete dynamically allocated memory
Media::~Media() {
  delete title;
}
