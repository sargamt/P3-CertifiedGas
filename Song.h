//
// Created by gabri on 4/15/2024.
//

#ifndef DSAFINALPROJECT_SONG_H
#define DSAFINALPROJECT_SONG_H
#include <string>

using namespace std;
class song{
    string id;
    string track_id;
    string artists;
    string album_name;
    string track_name;
    int popularity;
    float danceability;
    float energy;
    float loudness;
    string genre;

    public:
        // Constructor
        song(string ID, string trackID, string artistNames, string albumName, string trackName, int pop, float dance,
             float engy, float loud, string gen): id(ID), track_id(trackID), artists(artistNames),
             album_name(albumName), track_name(trackName), popularity(pop), danceability(dance), energy(engy),
             loudness(loud), genre(gen) {}

        // Getters
        string getID() const { return id; }
        string getTrackId() const { return track_id; }
        string getArtists() const { return artists; }
        string getAlbum() const { return album_name; }
        string getTrackName() const { return track_name; }
        int getPopularity() const { return popularity; }
        float getDanceability() const { return danceability; }
        float getEnergy() const { return energy; }
        float getLoudness() const { return loudness; }
        string getGenre() const { return genre; }
        template<typename T>
        T select_attribute(int i){
            switch(i){
                case 1:
                    return getID();
                case 2:
                    return getTrackId();
                case 3:
                    return getArtists();
                case 4:
                    return getAlbum();
                case 5:
                    return getTrackName();
                case 6:
                    return getPopularity();
                case 7:
                    return getDanceability();
                case 8:
                    return getEnergy();
                case 9:
                    return getLoudness();
                case 10:
                    return getGenre();
            }
        }

    };
#endif //DSAFINALPROJECT_SONG_H
