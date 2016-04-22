
#include "back.h"

back::back()
{
    root  = new gamelevel;
    root->menuname = "Main Menu";   //root dec
    root->up = NULL;

    gamelevel *weapon = new gamelevel;
    root->childone = weapon;        //weapon menu dec
    weapon->up = root;
    weapon->menuname = "Weapon";

    gamelevel *backpack = new gamelevel;
    root->childtwo = backpack;      //backpack menu dec
    backpack->up = root;
    backpack->menuname = "Backpack";

    gamelevel *scope = new gamelevel;
    gamelevel *trigger = new gamelevel;
    gamelevel *safety = new gamelevel;
    gamelevel *chamber = new gamelevel;
    gamelevel *bolt = new gamelevel;

    weapon->childone = scope;       //scope menu dec
    scope->up = weapon;
    scope->menuname = "Scope";
    weapon->childtwo = trigger;     //trigger menu dec
    trigger->up = weapon;
    trigger->menuname = "Trigger";
    weapon->childthree = safety;    //safety menu dec
    safety->up = weapon;
    safety->menuname = "Safety";
    weapon->childfour = chamber;    //chamber menu dec
    chamber->up = weapon;
    chamber->menuname = "Chamber";
    weapon->childfive = bolt;       //bolt menu dec
    bolt->up = weapon;
    bolt->menuname = "Bolt";

    gamelevel *windage = new gamelevel;
    gamelevel *elevation = new gamelevel;

    scope->childone = windage;      //windage menu dec
    windage->up = scope;
    windage->menuname = "Windage Knob";

    scope->childtwo = elevation;    //elevation menu dec
    elevation->up = scope;
    elevation->menuname = "Elevation Knob";

    gamelevel *binoculars = new gamelevel;
    gamelevel *rangefinder = new gamelevel;
    gamelevel *ammo = new gamelevel;

    backpack->childone = binoculars;    //binocular menu dec
    binoculars->up = backpack;
    binoculars->menuname = "Binoculars";

    backpack->childtwo = rangefinder;   //rangefinder menu dec
    rangefinder->up = backpack;
    rangefinder->menuname = "Rangefinder";

    backpack->childthree = ammo;        //ammo menu dec
    ammo->up = backpack;
    ammo->menuname = "Ammunition";

    gamelevel *rfdist = new gamelevel;
    gamelevel *rfwisp = new gamelevel;

    rangefinder->childone = rfdist;     // rf distance menu dec
    rfdist->up = rangefinder;
    rfdist->menuname = "Distance";

    rangefinder->childtwo = rfwisp;     // rf windspeed menu dec
    rfwisp->up = rangefinder;
    rfwisp->menuname = "Windspeed";

    gamelevel *apammo = new gamelevel;
    gamelevel *amammo = new gamelevel;

    ammo->childone = apammo;            // ammo type 1 menu dec
    apammo->up = ammo;
    apammo->menuname = "AP Ammunition";

    ammo->childtwo = amammo;            // ammo type 2 menu dec
    amammo->up = ammo;
    amammo->menuname = "AM Ammunition";

    gamelevel *current = new gamelevel;


}

back::~back()
{
    //dtor
}

void back::interact(gamelevel* level)
{

}

void back::examine(gamelevel* level)
{

}


void back::EImenu(gamelevel* level)
{
    bool inmenu = false;
    string iminput;

    do
    {
        cout<<endl<<"interact"<<endl;
        cout<<"examine"<<endl;
        if(current != root){cout<<"back"<<endl<<endl;}
        getline(cin,iminput);

        if(iminput == "interact")
        {

        }
        else if(iminput == "examine")
        {

        }
        else if(iminput == "back")
        {

        }
        else
        {
            cout<<endl<<"wrong input"<<endl<<endl;
            inmenu = true;
        }

    }
    while(inmenu == true);
}

void back::upmenu(gamelevel* curr)
{

}

void back::downmenu(gamelevel* curr)
{

}
