#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {
  title = new char[81];
  year = 0;
}

Media::Media(char* userTitle, int userYear) {
  title = new char[81];
  strcpy(title, userTitle);
  year = userYear;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

void Media::printInformation() {
  cout << title << ", " << year << endl;
}

// define destructor to delete dynamically allocated memory
Media::~Media() {
  delete title;
}
