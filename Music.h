#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music();
  Music(char*, char*, int, int, char*);
  char* getArtist();
  int getDuration();
  char* getPublisher();
  virtual void printInformation();
  ~Music();
 private:
  char* artist;
  int duration;
  char* publisher;
};
