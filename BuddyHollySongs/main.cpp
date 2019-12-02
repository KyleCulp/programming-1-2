#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include <cctype>
#include <cstdlib>
using namespace std;

/*
* Author: Kyle Culp
* Assignment: Sort Buddy Holly Songs
* Due: December 2nd, 2019
* Description: Take in a file containing albums from Buddy Holly, and:
* 	- Sort each albums songs alphabetically
*	- Sort the albums alphabetically
*	- Print the sorted albums
*/

struct Album {
	string album_name;
	int year;
	vector<string> songs;
} album_name, year, songs;

vector<Album> Albums;

bool isNum(string line) {
	for(int i=0; i < line.length(); i++) {
		if(!isdigit(line[i])) {
			return false;
		}
	}
	return true;
}

void createAlbums() {
	// Get file's line count
	int fileSize = 0;
	ifstream in("buddy-holly-songs.txt");
	string hold; // Useless arg filler
	while(getline(in, hold)) {
		fileSize++;
	}

	// Read in file, creating Albums and filling
	// a vector of Album's to sort and manipulate
	ifstream songsFile; // open the input file
	songsFile.open("buddy-holly-songs.txt");

	bool startOfNewAlbum = true; // Easily tell when to enter the album name
	int loopTracker = 1; // Use to measure if at end of file
	Album currentAlbum; // Temp album


	for(string line; getline(songsFile, line); loopTracker++) {
		// Line == Line Breaks
		if(line[0] == '=') {
			startOfNewAlbum = true;
			Albums.push_back(currentAlbum);
			currentAlbum.songs.clear();
			continue;
		}

		// Line == Album Name
		if(startOfNewAlbum) {
			currentAlbum.album_name = line;
			startOfNewAlbum = false;
			continue;
		}

		// Line == Date
		if(isNum(line.substr(0, 3))) {
			currentAlbum.year = atoi(line.c_str());
			continue;
		}

		// Line == Song
		if(line[2] == '.') {
			currentAlbum.songs.push_back(line);

			// Check to see if at end of songs file
			// As the last line in the file will be 
			// a song or an equals line 
			if(loopTracker == fileSize) {
				Albums.push_back(currentAlbum);
			}
			continue;
		}
	}

	songsFile.close();
}

Album organizeSongsInAlbum(Album currentAlbum) {
	for(int i=0; i < currentAlbum.songs.size(); i++) {
		for(int k=0; k < currentAlbum.songs.size() - 1; k++) {
			string currentSong = currentAlbum.songs[k].substr(4, currentAlbum.songs[k].length());
			string nextSong = currentAlbum.songs[k + 1].substr(4, currentAlbum.songs[k + 1].length());
			string temp;

			int identifier = currentSong.compare(nextSong);
			// Greater Than == Ascending Order Alphabetically
			// Lesser Than == Descending Order Alphabetically
            if(identifier > 0) {
                // Assign current song to temp
                temp = currentAlbum.songs[k];
                // Sign next song over current song
                currentAlbum.songs[k] = currentAlbum.songs[k + 1];
                // Sign current person to next persons spot
                currentAlbum.songs[k + 1] = temp;
           }
		}
	}

	return currentAlbum;
}

void organizeAlbumsAlphabetically() {
	for(int i=0; i < Albums.size(); i++) {
		for(int k=0; k < Albums.size() - 1; k++) {
			Album AlbumHolder;

			int identifier = Albums[k].album_name.compare(Albums[k + 1].album_name);
			// Greater Than == Ascending Order Alphabetically
			// Lesser Than == Descending Order Alphabetically
            if(identifier > 0) {
                // Assign current song to temp
                AlbumHolder = Albums[k];
                // Sign next song over current song
                Albums[k] = Albums[k + 1];
                // Sign current person to next persons spot
                Albums[k + 1] = AlbumHolder;
           }
		}
	}
}

int main() {
	// Take in albums into Albums
	createAlbums();

	// Sort each Album in Albums
	for(int i=0; i < Albums.size(); i++) {
		Albums[i] = organizeSongsInAlbum(Albums[i]);
	}

	// Sort Albums
	organizeAlbumsAlphabetically();

	// Print out Albums in their sorted state
	for(int i=0; i < Albums.size(); i++) {
		cout << Albums[i].album_name << endl;
		cout << Albums[i].year << endl;
		for(int k=0; k < Albums[i].songs.size(); k++) {
			cout << Albums[i].songs[k] << endl;
		}
		cout << "\n";
	}

	return 0;
}
