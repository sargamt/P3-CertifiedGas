#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <chrono>

#include "quickSort.cpp"
#include "Song.h"

using namespace std;

int main() {

    string sourceGenre;

    unordered_set<string> set1{"acoustic", "guitar", "piano"};
    unordered_set<string> set2{"afrobeat", "reggae", "ska", "dub"};
    unordered_set<string> set3{"brazil", "reggaeton", "pagode", "forro", "mpb"};
    unordered_set<string> set4{"british"};
    unordered_set<string> set5{"classical", "opera"};
    unordered_set<string> set6{"comedy"};
    unordered_set<string> set7{"country", "honky-tonk", "bluegrass", "blues"};
    unordered_set<string> set8{"dance", "dancehall"};
    unordered_set<string> set9{"disco", "groove"};
    unordered_set<string> set10{"disney"};
    unordered_set<string> set11{"dubstep"};
    unordered_set<string> set12{"edm", "electro", "house", "electronic", "techno", "club", "idm", "breakbeat", "minimal-techno", "detroit-techno", "chicago-house", "progressive-house", "trance", "deep-house", "garage", "hardstyle", "drum-and-bass"};
    unordered_set<string> set13{"folk"};
    unordered_set<string> set14{"french"};
    unordered_set<string> set15{"german", "industrial"};
    unordered_set<string> set16{"gospel", "world-music"};
    unordered_set<string> set17{"goth", "emo", "funk", "hardcore"};
    unordered_set<string> set18{"happy"};
    unordered_set<string> set19{"heavy-metal", "death-metal", "metal", "metalcore", "grindcore", "black-metal"};
    unordered_set<string> set20{"hip-hop", "trip-hop"};
    unordered_set<string> set21{"indian", "pop-film"};
    unordered_set<string> set22{"indie-pop", "indie"};
    unordered_set<string> set23{"iranian"};
    unordered_set<string> set24{"j-dance", "anime", "j-idol", "j-pop", "j-rock", "k-pop"};
    unordered_set<string> set25{"jazz"};
    unordered_set<string> set26{"kids", "children"};
    unordered_set<string> set27{"mandopop", "cantopop", "malay"};
    unordered_set<string> set28{"party"};
    unordered_set<string> set29{"pop", "power-pop", "synth-pop"};
    unordered_set<string> set30{"r-n-b", "soul"};
    unordered_set<string> set31{"rock-n-roll", "rock", "alt-rock", "psych-rock", "punk-rock", "punk", "hard-rock", "alternative", "rockabilly", "grunge"};
    unordered_set<string> set32{"romance"};
    unordered_set<string> set33{"sad"};
    unordered_set<string> set34{"salsa", "spanish", "latin", "latino", "tango", "samba", "sertanejo"};
    unordered_set<string> set35{"show-tunes"};
    unordered_set<string> set36{"singer-songwriter", "songwriter"};
    unordered_set<string> set37{"sleep", "study", "ambient", "chill", "new-age"};
    unordered_set<string> set38{"swedish"};
    unordered_set<string> set39{"turkish"};

    // Put unordered sets into a vector
    vector<unordered_set<string>> sets = {set1, set2, set3, set4, set5, set6, set7, set8, set9, set10,
                                          set11, set12, set13, set14, set15, set16, set17, set18, set19, set20,
                                          set21, set22, set23, set24, set25, set26, set27, set28, set29, set30,
                                          set31, set32, set33, set34, set35, set36, set37, set38, set39};

    // Input variables
    string songName;
    string option; // Heap sort or Quick sort
    int playlistSize;
    int attribute; // Holds the comparison attribute
    bool songFound = false; // exits loop when the song is found
    bool isHeapSort; // Will contain true for Heap Sort and false for Quick Sort
    vector<song> recList; // Used only for quick sort to gather the data quick sort will be sorting

    song srcSong;

    // Taking user input
    cout << "Please enter a song name\n-";
    getline(cin, songName);

    while(!songFound){
        //parsing data
        string filename = "../dataset.csv";
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
        }

        string space;

        string line;
        getline(file, line); // to ignore the first line with the column titles
        for (int i = 0; i < 131; i++) {
            getline(file, line);
            stringstream ss(line);

            vector<string> tokens;
            string token;
            bool inQuotes = false;
            string field;

            while (getline(ss, token, ',')) {
                if (inQuotes == false) {
                    if (token.front() == '"' && token.back() != '"') {
                        inQuotes = true;
                        field = token + ",";
                    }
                    else {
                        tokens.push_back(token);
                    }
                }
                else {
                    field += token;
                    if (token.back() == '"') {
                        inQuotes = false;
                        tokens.push_back(field);
                    }
                    else {
                        field += ",";
                    }
                }
            }
            if (songName == tokens[4]) {
                srcSong = song(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4],stoi(tokens[5]), stof(tokens[8]), stof(tokens[9]), stof(tokens[11]), tokens[20]); // comparison = 0 because it is being compared to itself
                sourceGenre = tokens[20];
                songFound = true;
            }
        }
        file.close();
        if(!songFound){
            cout << "This song was not found. Please enter another song name.\n-";
            getline(cin, songName);
        }
    }

    cout << "Please choose the attribute for comparison\n" // enter 1, 2, 3, or 4
            "   1. Popularity\n"
            "   2. Danceability\n"
            "   3. Energy\n"
            "   4. Loudness\n-";
    cin >> attribute;
    cout << "Would you like to use Heap sort or Quick sort (\"H\" for Heap/anything else for Quick)\n-";
    cin >> option;
    cout << "Please enter the number of songs you would like in your playlist\n-";
    cin >> playlistSize;
    if(option == "H" || option == "h"){
        cout << "Using Heap Sort...\n";
        isHeapSort = true;
    }else{
        cout << "Using Quick Sort...\n";
        isHeapSort = false;
    }

    unordered_set<string> foundSet;

    for (unordered_set<string> eachSet : sets) {
        for (string genreFromSet : eachSet) {
            if (genreFromSet == sourceGenre) {
                foundSet = eachSet;
            }
        }
    }

    auto start = chrono::high_resolution_clock::now();

    for (string aGenre: foundSet) {
        //parsing data
        string filename = "../dataset.csv";
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
        }

        string space;

        string line;
        getline(file, line); // to ignore the first line with the column titles
        int numSongs = 0;
        while (numSongs < 999) {
            getline(file, line);
            stringstream ss(line);

            vector<string> tokens;
            string token;
            bool inQuotes = false;
            string field;

            while (getline(ss, token, ',')) {
                if (inQuotes == false) {
                    if (token.front() == '"' && token.back() != '"') {
                        inQuotes = true;
                        field = token + ",";
                    }
                    else {
                        tokens.push_back(token);
                    }
                }
                else {
                    field += token;
                    if (token.back() == '"') {
                        inQuotes = false;
                        tokens.push_back(field);
                    }
                    else {
                        field += ",";
                    }
                }
            }
            if (aGenre == tokens[20]) {
                numSongs++;
                // check if H or Q
                if(isHeapSort){
                    // heapify -> heap sort
                }else{
                    int att = -1;
                    if(attribute == 1){
                        att = 5;
                    }else if(attribute == 2){
                        att = 8;
                    }else if(attribute == 3){
                        att = 9;
                    }else if(attribute == 4){
                        att = 11;
                    }
                    // Making a new song and adding it to the playlist
                    recList.push_back(song(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], stoi(tokens[5]), stof(tokens[8]), stof(tokens[9]), stof(tokens[11]), tokens[20], abs(srcSong.generalGet(attribute) - stof(tokens[att]))));
                }
                // do what is necessary to apply whichever sort was asked for
            }
        }
        file.close();
    }

    if(isHeapSort){
        //Do anything else you need for heap sort
        auto stopHeap = chrono::high_resolution_clock::now();
        auto heapDuration = chrono::duration_cast<chrono::microseconds>(stopHeap - start); // Time Heap Sort took
        //print heap sort stuff
        // Make sure to use playlistSize

        cout << "\nTotal time for Heap Sort = " << heapDuration.count() << " microseconds.";
    }else{
        int counter = 1; // used for UI element
        // call quicksort
        quickSort(recList, 0, recList.size()-1);
        auto stopQuick = chrono::high_resolution_clock::now();
        auto quickDuration = chrono::duration_cast<chrono::microseconds>(stopQuick - start); // Time Heap Sort took
        // print
        for(int i = 0; i < playlistSize; i++){
            cout << counter << ".------------------------------------------------------------------------------------\n"
                               "\t~Song Name: " << recList[i].getTrackName() << "\n\t~Artist: " << recList[i].getArtists() << "\n\t~Album: " << recList[i].getAlbum() << "\n\t~Genre: " << recList[i].getGenre() << "\n\t~Comparison Value: " << recList[i].getComparison() << "\n";
            counter++;
        }
        cout << "\nTotal time for Quick Sort = " << quickDuration.count() << " microseconds.";
    }

    return 0;
}
