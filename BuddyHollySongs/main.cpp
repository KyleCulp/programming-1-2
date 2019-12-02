#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include <cctype>
#include <cstdlib>
using namespace std;

struct Song {
	string song_name;
	int position;
} song_name, position;

struct Album {
	string album_name;
	int year;
	vector<Song> songs;
} album_name, year, songs;

vector<Album> Albums;

void createAlbum(string line) {

}

bool isNum(string line) {
	for(int i=0; i < line.length(); i++) {
		if(!isdigit(line[i])) {
			return false;
		}
	}
	return true;
}

int main() {

	int fileSize = 0;
	ifstream in("buddy-holly-songs.txt");
	string hold; // Useless arg filler
	while(getline(in, hold)) {
		fileSize++;
	}

	ifstream songsFile; // open the input file
	songsFile.open("buddy-holly-songs.txt");
    while (songsFile.is_open()) {  
		bool startOfNewAlbum = true;
		int loopTracker = 0;
		Album currentAlbum;

		for(string line; getline(songsFile, line); loopTracker++) {
			// loopTracker++;
			cout << loopTracker << endl;

			// Line == Line Breaks
			if(line[0] == '=') {
				startOfNewAlbum = true;
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
				// Create song struct
				Song song;
				song.song_name = line.substr(3, line.length());
				song.position = atoi(line.substr(0, 1).c_str());

				// Push this song instance into currentAlbum
				currentAlbum.songs.push_back(song);

				// Check to see if at end of songs file
				// if(loopTracker)
				continue;
			}
			


			// Albums.push_back(currentAlbum);
			


			// cout << line << endl;
        	// if(!line.find("=")) {
			// 	startOfNewAlbum = true;
			// 	continue;
			// }
			// if(startOfNewAlbum) {
			// 	currentAlbum.album_name = line;
			// 	startOfNewAlbum = false;
			// 	continue;
			// }
			// if(currentLineYear) {
			// 	currentAlbum.year = line;
			// 	currentLineYear = false;
			// 	continue;
			// }

			// cout << currentAlbum.album_name;
			



    	}

		songsFile.close();
	}

	return 0;
}
