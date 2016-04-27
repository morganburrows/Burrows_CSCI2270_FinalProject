#ifndef BACK_H
#define BACK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include<array>

using namespace std;


struct gamelevel
{
    int clicks = 0;
    string state;
    bool interactable;
    string menuname;
    string description;
    string interaction;
    gamelevel* up;
    //gamelevel* down;
    vector<string> subarray;
    gamelevel* childone;
    gamelevel* childtwo;
    gamelevel* childthree;
    gamelevel* childfour;
    gamelevel* childfive;
    gamelevel* next;
};


class back
{
    public:
        back();
        virtual ~back();
        gamelevel* root;
        gamelevel* current;
        gamelevel* searcher;
        vector<string> mainsubarray = {"weapon","backpack"};
        vector<string> weapsubarray = {"scope","trigger","safety","chamber","bolt"};
        vector<string> bpaksubarray = {"binoculars","rangefinder","ammunition"};
        vector<string> scpesubarray = {"elevation knob","windage knob"};
        vector<string> ammosubarray = {"AP ammunition", "AM ammunition"};
        bool loaded = false;
        bool amload = false;
        bool apload = false;
        bool safe = true;
        bool locked = true;
        bool rangefound = false;
        bool tripped = true;
        bool wiset = false;
        bool diset = false;
        bool hit;
        bool win = false;
        int firdist;
        int wisp;
        int dist;

        void interact(gamelevel* level);
        void examine(gamelevel* level);
        void EImenu(gamelevel* level);
        void actionchoice(gamelevel* level);
        void adjust(gamelevel * level);
        void gamewin();
        void initmenu();
        void startmenu();
        void examinecheck(gamelevel* level);
        void interactcheck(gamelevel* level);
    protected:
    private:
};

#endif // BACK_H
