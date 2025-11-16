#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  Media(char*, int);
  char* getTitle();
  int getYear();
 protected:
  char* title;
  int year;
};

#endif
