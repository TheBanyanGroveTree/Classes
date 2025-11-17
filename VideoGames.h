#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class VideoGames : public Media {
 public:
  VideoGames();
  VideoGames(char*, int, char*, float);
  char* getPublisher();
  float getRating();
  virtual void printInformation();
  ~VideoGames();
 private:
  char* publisher;
  float rating;
};
