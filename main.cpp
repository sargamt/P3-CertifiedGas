#include <iostream>
#include <vector>
#include <sstream>

#include <fstream>


#include "quickSort.cpp"

using namespace std;

int main() {
    // Input variables
    string songName;
    string option; // Heap sort or Quick sort
    int playlistSize;
    int attribute; // Holds the comparison attribute

    // Taking user input
    cout << "Please enter a song name\n-";
    cin >> songName;

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
//        for (int k = 0; k < tokens.size(); k++) {
//            cout << k << ": " << tokens[k] << endl;
//        }
        if (songName == tokens[4]) {
            cout << tokens[0] << endl;
        }
    }
    file.close();




    cout << "Please choose the attribute for comparison\n"
            "   1. Popularity\n"
            "   2. Danceability\n"
            "   3. Energy\n"
            "   4. Loudness\n"
            "   5. Speechiness\n"
            "   6. Acousticness\n"
            "   7. Liveness\n"
            "   8. Valence\n"
            "   9. Tempo\n-";
    cin >> attribute;
    cout << "Would you like to use Heap sort or Quick sort (\"H\" for Heap/anything else for Quick)\n-";
    cin >> option;
    cout << "Please enter the number of songs you would like in your playlist\n-";
    cin >> playlistSize;
    if(option == "H" || option == "h"){
        cout << "Using Heap Sort...\n";
    }else{
        cout << "Using Quick Sort...\n";
    }

    // Testing quickSort...
    vector<int> nums{43, 5, 12, 34, 53, 87, 10, 11, 9, 8};
    int n = nums.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    quickSort(nums, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
