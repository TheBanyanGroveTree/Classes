/* Description:
   Author: Aahana Sapra
   Date: 11/16/25
 */

// headers
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <ios>
#include <algorithm>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

// define function prototypes
void addEntry(vector<Media*> &database, const int &INPUT_LENGTH);
void searchEntry(vector<Media*> &database, const int &INPUT_LENGTH);
void deleteEntry(vector<Media*> &database, const int &INPUT_LENGTH);

int main() {
  // create vector
  vector<Media*> database;

  // declare char arr for user input
  const int INPUT_LENGTH = 81;
  char userCommand[INPUT_LENGTH];

  // continue prompting user for input until QUIT command
  bool keepModifying = true;
  while (keepModifying) {
    // read in user input
    cout << "Enter a command (ADD, SEARCH, DELETE, QUIT): ";
    cin.getline(userCommand, INPUT_LENGTH);
    
    // convert input to uppercase for comparison
    for (int i = 0; i < strlen(userCommand); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }
    
    // validate input
    if (strcmp(userCommand, "ADD") == 0) {
      addEntry(database, INPUT_LENGTH);
    } else if (strcmp(userCommand, "SEARCH") == 0) {
      searchEntry(database, INPUT_LENGTH);
    } /*else if (strcmp(userCommand, "DELETE") == 0) {
      //      deleteEntry(database, INPUT_LENGTH);
      } */else if (strcmp(userCommand, "QUIT") == 0) {
      keepModifying = false;
    } else {
      cout << "Please enter ADD, SEARCH, DELETE, or QUIT." << endl;
    }
  }
  
  return 0;
}

// define add function to create a new media entry
void addEntry(vector<Media*> &database, const int &INPUT_LENGTH) {
  // prompt user for media type
  char mediaType[INPUT_LENGTH];
  cout << "Enter a type of media (VIDEOGAMES, MUSIC, MOVIES): ";
  cin.getline(mediaType, INPUT_LENGTH);

  // read in input for common fields
  char title[INPUT_LENGTH];
  int year = 0;

  cout << "Enter the title: ";
  cin.getline(title, INPUT_LENGTH);

  cout << "Enter the year: ";
  cin >> year;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
  
  // read in input for class specific fields
  if (strcmp(mediaType, "VIDEOGAMES") == 0) {
    char publisher[INPUT_LENGTH];
    float rating = 0.0;

    cout << "Enter the publisher: ";
    cin.getline(publisher, INPUT_LENGTH);

    cout << "Enter the rating: ";
    cin >> rating;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // initialize object
    VideoGames* vg = new VideoGames(title, year, publisher, rating);
    // add object to database vector
    database.push_back(vg);
  } else if (strcmp(mediaType, "MUSIC") == 0) {
    char artist[INPUT_LENGTH];
    int duration = 0;
    char publisher[INPUT_LENGTH];

    cout << "Enter the artist: ";
    cin.getline(artist, INPUT_LENGTH);

    cout << "Enter the duration in seconds: ";
    cin >> duration;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the publisher: ";
    cin.getline(publisher, INPUT_LENGTH);

    Music* music = new Music(title, artist, year, duration, publisher);
    
    database.push_back(music);
  } else if (strcmp(mediaType, "MOVIES") == 0) {
    char director[INPUT_LENGTH];
    int duration = 0;
    float rating = 0.0;

    cout << "Enter the director: ";
    cin.getline(director, INPUT_LENGTH);

    cout << "Enter the duration in minutes: ";
    cin >> duration;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the rating: ";
    cin >> rating;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Movies* movie = new Movies(title, director, year, duration, rating);

    database.push_back(movie);
  }
}

// define search function to search for and print objects in media database
void searchEntry(vector<Media*> &database, const int &INPUT_LENGTH) {
  // prompt user for title of media
  char title[INPUT_LENGTH];
  cout << "Enter the title: ";
  cin.getline(title, INPUT_LENGTH);

  // search for all entries that match given title
  for (auto it = database.begin(); it != database.end(); ++it) {
    // print entry if it is a match
    if (strcmp(title, (*it)->getTitle()) == 0) {
      (*it)->printInformation();
    }
  }
}

// define delete function to delete an item from the database
void deleteEntry(vector<Media*> &database, const int &INPUT_LENGTH) {
  // prompt user for title of media
  char title[INPUT_LENGTH];
  cout << "Enter the title: ";
  cin.getline(title, INPUT_LENGTH);

  // erase-remove idiom
  // define lambda function to deallocate memory for media being removed
  auto removeMedia = remove_if(database.begin(), database.end(), [&title](Media *ptr) {
    if (strcmp(title, ptr->getTitle()) == 0) {
      // confirm delete action
      ptr->printInformation();
      char confirmDelete = 'y';
      cout << "Do you want to proceed with this action (y/n)? ";
      cin >> confirmDelete;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      if (tolower(confirmDelete) == 'y') {
	delete ptr;
	return true;
      }
    }
    return false;
  });

  // erase nullified ptr
  database.erase(removeMedia, database.end());
}
