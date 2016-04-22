#ifndef BACK_H
#define BACK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;


struct gamelevel
{
    string menuname;
    gamelevel* up;
    //gamelevel* down;
    gamelevel* childone;
    gamelevel* childtwo;
    gamelevel* childthree;
    gamelevel* childfour;
    gamelevel* childfive;
    gamelevel* current;
};

struct weapon
{
    string weapon;
    bool safety = true;
    bool loaded = false;
    bool armed = false;
    struct weapon *scope;
};

struct scope
{
    string scope;
    int elevation;
    int windage;
};

struct backpack
{
    string backpack;
    struct backpack *ammo;
    struct backpack *rangefinder;
    struct backpack *binoculars;
};

struct ammo
{
    string ammo;
    string type;
};

struct rangefinder
{
    string rangefinder;
    int RFdistance;
    int RFwindspeed;
};

struct binoculars
{
    string binoculars;
    int focus;
    bool infocus;
};

struct target
{
    string target;
    int targetdist;
    string targettype;
};

struct conditions
{
    string conditions;
    int Cwindspeed;
    int Cdistance;
};

class back
{
    public:
        back();
        virtual ~back();
        gamelevel* root;
        gamelevel* current;

        void interact(gamelevel* level);
        void examine(gamelevel* level);
        void EImenu(gamelevel* level);
        void upmenu(gamelevel* level);
        void downmenu(gamelevel* level);
        void EIprompt(string);
    protected:
    private:
};

#endif // BACK_H
