//
// Created by gabri on 4/15/2024.
//

#ifndef DSAFINALPROJECT_SONG_H
#define DSAFINALPROJECT_SONG_H
#include <string>

using namespace std;
class song{
  string track_id;
  string name;
  string artist;
  string album;
  string genre;
  bool expl;
  int pop;
  int key;
  int duration;
  int mode;
  int time_sig;
  float tempo;
  float valence;
  float liveness;
  float instrumentalness;
  float speechiness;
  float dance;
  float energy;

    class song {
    private:
        string track_id;
        string name;
        string artist;
        string album;
        string genre;
        bool expl;
        int pop;
        int key;
        int duration;
        int mode;
        int time_sig;
        float tempo;
        float valence;
        float liveness;
        float instrumentalness;
        float speechiness;
        float dance;
        float energy;

    public:
        // Constructor
        song(string track_id, string name, string artist, string album, string genre,
             bool expl, int pop, int key, int duration, int mode, int time_sig,
             float tempo, float valence, float liveness, float instrumentalness,
             float speechiness, float dance, float energy)
                : track_id(track_id), name(name), artist(artist), album(album), genre(genre),
                  expl(expl), pop(pop), key(key), duration(duration), mode(mode),
                  time_sig(time_sig), tempo(tempo), valence(valence), liveness(liveness),
                  instrumentalness(instrumentalness), speechiness(speechiness), dance(dance),
                  energy(energy) {}

        // Getters
        string getTrackId() const { return track_id; }
        string getName() const { return name; }
        string getArtist() const { return artist; }
        string getAlbum() const { return album; }
        string getGenre() const { return genre; }
        bool isExplicit() const { return expl; }
        int getPopularity() const { return pop; }
        int getKey() const { return key; }
        int getDuration() const { return duration; }
        int getMode() const { return mode; }
        int getTimeSignature() const { return time_sig; }
        float getTempo() const { return tempo; }
        float getValence() const { return valence; }
        float getLiveness() const { return liveness; }
        float getInstrumentalness() const { return instrumentalness; }
        float getSpeechiness() const { return speechiness; }
        float getDanceability() const { return dance; }
        float getEnergy() const { return energy; }
    };
#endif //DSAFINALPROJECT_SONG_H
