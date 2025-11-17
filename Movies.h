#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movies : public Media {
 public:
  Movies();
  Movies(char*, char*, int, int, float);
  char* getDirector();
  int getDuration();
  float getRating();
  virtual void printInformation(); 
 private:
  char* director;
  int duration;
  float rating;
};
