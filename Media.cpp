#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {
  title = new char[81];
  year = 0;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
