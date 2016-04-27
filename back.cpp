#include "back.h"

back::back()
{

}
back::~back()
{
    //dtor
}

void back::interact(gamelevel* level)
{
    if(level->menuname == "weapon")
    {
        EImenu(level);

    }
    else if(level->menuname == "backpack")
    {
        EImenu(level);
    }
    else if(level->menuname == "scope")
    {
        EImenu(level);
    }
    else if(level->menuname == "trigger")
    {
        EImenu(level);

    }
    else if(level->menuname == "safety")
    {
        EImenu(level);

    }
    else if(level->menuname == "chamber")
    {
        EImenu(level);

    }
    else if(level->menuname == "bolt")
    {
        EImenu(level);

    }
    else if(level->menuname == "windage knob")
    {
        EImenu(level);

    }
    else if(level->menuname == "elevation knob")
    {
        EImenu(level);

    }
    else if(level->menuname == "rangefinder")
    {
        EImenu(level);

    }
    else if(level->menuname == "binoculars")
    {
        EImenu(level);

    }
    else if(level->menuname == "ammunition")
    {
        EImenu(level);

    }
    else if(level->menuname == "distance")
    {
        EImenu(level);

    }
    else if(level->menuname == "windspeed")
    {
        EImenu(level);

    }
    else if(level->menuname == "AP ammunition")
    {
        EImenu(level);

    }
    else if(level->menuname == "AM ammunition")
    {
        EImenu(level);

    }
    else
    {
        cout<<"# wrong input"<<endl;
    }
}

void back::interactcheck(gamelevel* level)
{
    bool inmenu;
    string iminput;
    int tick = 0;
    do
    {
        cout<<"#"<<endl;
        cout<<"# with:"<<endl;
        getline(cin,iminput);

        searcher = current->childone;
        if(searcher->menuname == iminput)
        {
            interact(searcher);
        }
        else if(searcher->menuname != iminput)
        {
            while(searcher->menuname != iminput)
            {
                searcher = searcher->next;
                tick++;
                if(tick > 10)
                {
                    cout<<"# wrong input"<<endl;
                    EImenu(level);
                }
            }
            interact(searcher);
        }
        else
        {
            cout<<"# wrong input"<<endl;
            inmenu = true;
        }
    }
    while(inmenu == true);
}

void back::examine(gamelevel* level)
{
    string ainput;
    bool winput = false;
    string einput;

    do
    {

        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"#"<<endl;
        cout<<level->description<<endl;
        if(level->interactable == true)
        {
            cout<<"#"<<endl;
            cout<<"#############"<<endl;
            cout<<"#"<<endl;
            if(level->menuname == "windage knob" || level->menuname == "elevation knob")
            {
                cout<<"# "<<level->clicks<<" "<<level->state<<endl;
            }
            else if(level->menuname == "rangefinder"&& rangefound == true)
            {
                cout<<"#"<<endl;
                cout<<"# distance: "<<dist<<endl;
                cout<<"#"<<endl;
                cout<<"# windspeed: "<<wisp<<endl;
            }
            else if(level->menuname == "binoculars" && win == true)
            {
                gamewin();
            }
            else
            {
                cout<<"# "<<level->state<<endl;
            }
        }
        cout<<"#"<<endl;
        cout<<"#############"<<endl;
        cout<<"#"<<endl;
        cout<<"# back"<<endl;

        getline(cin,einput);
        if(einput == level->interaction)
        {
            actionchoice(level);
        }
        else if(einput == "back")
        {
            EImenu(level->up);
        }
        else
        {
            cout<<"#"<<endl;
            cout<<"# wrong input"<<endl;
            winput = true;
        }
    }
    while(winput == true);
}

void back::examinecheck(gamelevel* level)
{
    bool inmenu = false;
    string iminput;
    int tick = 0;
    current = level;

    if(level->interactable == false)
    {
        do
        {
            inmenu = false;
            cout<<"#"<<endl;
            cout<<"# what:"<<endl;
            getline(cin,iminput);

            searcher = current->childone;
            if(searcher->menuname == iminput)
            {
                examine(searcher);
            }
            else if(searcher->menuname != iminput)
            {
                while(searcher->menuname != iminput)
                {
                    searcher = searcher->next;
                    tick++;
                    if(tick > 10)
                    {
                        cout<<"# wrong input"<<endl;
                        EImenu(level);
                    }
                }
                examine(searcher);
            }
        }
        while(inmenu == true);
    }
}

void back::EImenu(gamelevel* level)
{
    bool inmenu = false;
    string iminput;
    current = level;

    do
    {
        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"#############"<<endl;
        cout<<"# "<<current->menuname<<endl;
        cout<<"#############"<<endl;
        for(unsigned int i = 0; i < current->subarray.size(); i++)
        {
        cout<<"#"<<endl;
        cout<<"# "<<current->subarray[i]<<endl;
        }

        cout<<"#"<<endl;
        cout<<"#############"<<endl;
        cout<<"#"<<endl;
        cout<<"# actions:"<<endl;
        if(level->interactable == true)
        {
            cout<<"#"<<endl;
            cout<<"# "<<level->interaction<<endl;
        }
        else if(level->interactable == false)
        {
            cout<<"#"<<endl;
            cout<<"# interact"<<endl;
            cout<<"# examine"<<endl;
        }
        if(current != root){cout<<"# back"<<endl<<endl;}
        else if(current == root){cout<<"# quit"<<endl;}
        getline(cin,iminput);

        if(iminput == "interact" && level->interactable == false)
        {
            interactcheck(level);
        }
        else if(iminput == level->interaction && level->interactable == true)
        {
            actionchoice(level);
        }
        else if(iminput == "examine")
        {
            examinecheck(level);
        }
        else if(iminput == "back")
        {
            if(current == root)
            {
                cout<<endl<<"wrong input"<<endl<<endl;
                inmenu = true;
            }
            else
                EImenu(current->up);
        }
        else if(iminput == "quit")
        {
            exit(0);
        }
        else
        {
            cout<<endl<<"wrong input"<<endl<<endl;
            inmenu = true;
        }
    }
    while(inmenu == true);
}

void back::actionchoice(gamelevel* level)
{
    if(level->interaction == "pull")
    {
        if(safe == true)
        {
            cout<<"#"<<endl;
            cout<<"# trigger cannot be pulled while safety is on"<<endl;
        }
        else if(safe == false && locked == false)
        {
            cout<<"#"<<endl;
            cout<<"# pulling the trigger does nothing"<<endl;
        }
        else if(safe == false && locked == true && loaded == false)
        {
            cout<<"#"<<endl;
            cout<<"# the weapon clicks as the firing pin is released"<<endl;
        }
        else if(safe == false && locked == true && loaded == true)
        {
            cout<<"#"<<endl;
            cout<<"# pulling the trigger fires the weapon"<<endl;
            hit = false;
        }
        else if(safe == false && locked == true && loaded == true && diset == true && wiset == true)
        {
            cout<<"#"<<endl;
            cout<<"# pulling the trigger fires the weapon"<<endl;
            hit = true;
            win = true;
        }
        EImenu(level);
    }

    else if(level->interaction == "switch")
    {
        if(level->state == "safe")
        {
            safe = false;
            level->state = "fire";
            cout<<"#"<<endl;
            cout<<"# weapon switched to fire"<<endl;
        }
        else if(level->state == "fire")
        {
            safe = true;
            level->state = "safe";
            cout<<"#"<<endl;
            cout<<"# weapon switched to safe"<<endl;
        }
        EImenu(level);
    }

    else if(level->interaction == "check")
    {
        if(locked == true)
        {
            cout<<"#"<<endl;
            cout<<"# cannot check chamber when bolt is closed"<<endl;
        }
        else if(locked == false)
        {
            if(loaded == true)
            {
                cout<<"#"<<endl;
                cout<<"# a round is in the chamber"<<endl;
            }
            else if (loaded == false)
            {
                cout<<"#"<<endl;
                cout<<"# the chamber is empty"<<endl;
            }
        }
        EImenu(level);
    }

    else if(level->interaction == "open")
    {
        if(locked == true)
        {
            cout<<"#"<<endl;
            cout<<"# opening the bolt exposes the chamber"<<endl;
            cout<<"# and disengages the trigger"<<endl;
            locked = false;
            level->state = "open";
            level->interaction = "close";
        }
        else if(locked == false)
        {
            cout<<"#"<<endl;
            cout<<"# the bolt is already open"<<endl;
        }
        EImenu(level);
    }

    else if(level->interaction =="close")
    {
        if(locked == false)
        {
            cout<<"#"<<endl;
            cout<<"# closing the bolt locks the chamber"<<endl;
            cout<<"# and primes the firing pin"<<endl;
            locked = true;
            level->interaction = "open";
            level->state = "closed";
        }
        else if(locked == true)
        {
            cout<<"#"<<endl;
            cout<<"# the bolt is already open"<<endl;
        }
        EImenu(level);
    }

    else if(level->interaction == "focus")
    {
        if(level->state == "out of focus")
        {
            level->state = "in focus";
            if(tripped == false)
            {
                level->description = "# long distance binoculars. \n# target is an enemy combatant";
            }
            else if(tripped == true)
            {
                level->description = "# long distance binoculars. \n# target is an enemy vehicle";
            }
        }
        else
        {
            cout<<"#"<<endl;
            cout<<"# already in focus"<<endl;
        }
        EImenu(level);
    }

    else if(level->interaction == "use")
    {
        rangefound = true;
        level->state = "target found";
        level->description = "# laser rangefinder. \n# used to calculate distance, also checks windspeed.";
        if(tripped == false)
        {
            dist = 500;
            wisp = 20;
        }
        else if(tripped == true)
        {
            dist = 800;
            wisp = 5;
        }
        EImenu(level);
    }

    else if(level->interaction == "load")
    {
        if(loaded == true)
        {
            cout<<"#"<<endl;
            cout<<"# already loaded"<<endl;
            EImenu(level);
        }
        else
        {
            if(locked == false)
            {
                if(level->menuname == "AP ammunition")
                {
                    loaded = true;
                    apload = true;
                    EImenu(level);
                }
                else if(level->menuname == "AM ammunition")
                {
                    loaded = true;
                    amload = true;
                    EImenu(level);
                }
            }
            else
            {
                cout<<"#"<<endl;
                cout<<"# cartridges cannot be loaded while bolt is closed"<<endl;
                EImenu(level);
            }
        }
    }

    else if(level->interaction == "adjust")
    {
        adjust(level);
    }
}

void back::adjust(gamelevel *level)
{

    if(level->menuname == "elevation knob")
    {
        string choose;
        cout<<"#"<<endl;
        cout<<"# +/-"<<endl;
        getline(cin,choose);
        if(choose == "+")
        {
            level->clicks++;
            if(level->clicks*100 == dist)
            {
                diset = true;
            }
        }
        else if(choose == "-")
        {
            level->clicks--;
            if(level->clicks*100 == dist)
            {
                diset = true;
            }
        }
        else
        {
            cout<<"# wrong input"<<endl;
            actionchoice(level);
        }
    }
    else if(level->menuname == "windage knob")
    {
        string choose;
        cout<<"#"<<endl;
        cout<<"# +/-"<<endl;
        getline(cin,choose);
        if(choose == "+")
        {
            level->clicks++;
            if(level->clicks*100 == dist)
            {
                diset = true;
            }
        }
        else if(choose == "-")
        {
            level->clicks--;
            if(level->clicks*5 == wisp)
            {
                wiset = true;
            }
        }
        else
        {
            cout<<"# wrong input"<<endl;
            actionchoice(level);
        }
    }
    EImenu(level);
}

void back::gamewin()
{
    string ex;
    for(int i = 0; i < 18; i++)
    {
        cout<<endl;
    }

    cout<<"    ###         ###  ###  #####    ###  #####    ### ######  ###### "<<endl;
    cout<<"   ###         ###  ###  ### ##   ###  #####    ### ###     ###  ###"<<endl;
    cout<<"  ###   ###   ###  ###  ###  ##  ###  ###  ##  ### ######  ######   "<<endl;
    cout<<" ### ####### ###  ###  ###   ## ###  ###   ## ### ###     ###  ###  "<<endl;
    cout<<"######   ######  ###  ###    #####  ###    ##### ######  ###    ### "<<endl;

    cout<<"exit"<<endl;
    getline(cin,ex);
    exit(0);
}

void back::initmenu()
{
    root  = new gamelevel;
    root->menuname = "main menu";   //root dec
    root->up = NULL;
    root->subarray = mainsubarray;
    root->interactable = false;

    gamelevel *weapon = new gamelevel;
    root->childone = weapon;        //weapon menu dec
    weapon->up = root;
    weapon->menuname = "weapon";
    weapon->description = "# a long range, bolt action rifle. \n# carries an adjustable scope.";
    weapon->subarray = weapsubarray;
    weapon->interactable = false;

    gamelevel *backpack = new gamelevel;
    root->childtwo = backpack;      //backpack menu dec
    backpack->up = root;
    backpack->menuname = "backpack";
    backpack->description = "# a light, durable pack.\n# contains a pair of binoculars, a rangefinder, and ammunition.";
    backpack->subarray = bpaksubarray;
    backpack->interactable = false;

    weapon->next = backpack;
    backpack->next = weapon;

    gamelevel *scope = new gamelevel;
    gamelevel *trigger = new gamelevel;
    gamelevel *safety = new gamelevel;
    gamelevel *chamber = new gamelevel;
    gamelevel *bolt = new gamelevel;

    weapon->childone = scope;       //scope menu dec
    scope->up = weapon;
    scope->menuname = "scope";
    scope->description = "# an adjustable, long distance scope. \n# has a pair of knobs for windage and elevation";
    scope->subarray = scpesubarray;

    weapon->childtwo = trigger;     //trigger menu dec
    trigger->up = weapon;
    trigger->menuname = "trigger";
    trigger->description = "# a trigger";
    trigger->interactable = true;
    trigger->interaction = "pull";

    weapon->childthree = safety;    //safety menu dec
    safety->up = weapon;
    safety->menuname = "safety";
    safety->description = "# a two setting safety. \n# settings are safe and fire";
    safety->interactable = true;
    safety->interaction = "switch";
    safety->state = "safe";

    weapon->childfour = chamber;    //chamber menu dec
    chamber->up = weapon;
    chamber->menuname = "chamber";
    chamber->description = "# chamber of the firearm. \n# accepts an ammunition cartridge";
    chamber->interactable = true;
    chamber->interaction = "check";
    chamber->state = "empty";
    //chamber->

    weapon->childfive = bolt;       //bolt menu dec
    bolt->up = weapon;
    bolt->menuname = "bolt";
    bolt->description = "# bolt of the firearm. \n# open to extract empty casing or check the chamber \n# close to lock a round in the chamber";
    bolt->interactable = true;
    bolt->interaction = "open";
    bolt->state = "closed";

    scope->next = trigger;
    trigger->next = safety;
    safety->next = chamber;
    chamber->next = bolt;
    bolt->next = scope;

    gamelevel *windage = new gamelevel;
    gamelevel *elevation = new gamelevel;

    scope->childone = windage;      //windage menu dec
    windage->up = scope;
    windage->menuname = "windage knob";
    windage->description = "# adjustable knob to account for windspeed. \n# measured in clicks \n# 5mph/click ";
    windage->interactable = true;
    windage->interaction = "adjust";
    windage->clicks = 0;
    windage->state = " clicks";

    scope->childtwo = elevation;    //elevation menu dec
    elevation->up = scope;
    elevation->menuname = "elevation knob";
    elevation->description = "# adjustable knob to account for distance. \n# measured in clicks \n# 100 yds/click";
    elevation->interactable = true;
    elevation->interaction = "adjust";
    elevation->clicks = 0;
    elevation->state = " clicks";

    windage->next = elevation;
    elevation->next = windage;

    gamelevel *binoculars = new gamelevel;
    gamelevel *rangefinder = new gamelevel;
    gamelevel *ammo = new gamelevel;

    backpack->childone = binoculars;    //binocular menu dec
    binoculars->up = backpack;
    binoculars->menuname = "binoculars";
    binoculars->description = "# long distance binoculars. \n# must be focused to view target clearly";
    binoculars->interactable = true;
    binoculars->interaction = "focus";
    binoculars->state = "out of focus";

    backpack->childtwo = rangefinder;   //rangefinder menu dec
    rangefinder->up = backpack;
    rangefinder->menuname = "rangefinder";
    rangefinder->description = "# laser rangefinder. \n# used to calculate distance, also checks windspeed";
    rangefinder->interactable = true;
    rangefinder->interaction = "use";
    rangefinder->state = "no target selected";

    backpack->childthree = ammo;        //ammo menu dec
    ammo->up = backpack;
    ammo->menuname = "ammunition";
    ammo->description = "# cartridges of high caliber ammunition. \n# one pack of AP, one pack of AM";
    ammo->subarray = ammosubarray;

    binoculars->next = rangefinder;
    rangefinder->next = ammo;
    ammo->next = binoculars;

    gamelevel *rfdist = new gamelevel;
    gamelevel *rfwisp = new gamelevel;

    rangefinder->childone = rfdist;     // rf distance menu dec
    rfdist->up = rangefinder;
    rfdist->menuname = "distance";

    rangefinder->childtwo = rfwisp;     // rf windspeed menu dec
    rfwisp->up = rangefinder;
    rfwisp->menuname = "windspeed";

    rfdist->next = rfwisp;
    rfwisp->next = rfdist;

    gamelevel *apammo = new gamelevel;
    gamelevel *amammo = new gamelevel;

    ammo->childone = apammo;            // ammo type 1 menu dec
    apammo->up = ammo;
    apammo->menuname = "AP ammunition";
    apammo->description = "# armor penetrating ammunition. \n# used against targets wearing body armor";
    apammo->interactable = true;
    apammo->interaction = "load";

    ammo->childtwo = amammo;            // ammo type 2 menu dec
    amammo->up = ammo;
    amammo->menuname = "AM ammunition";
    amammo->description = "# anti material ammunition. \n# used against armored vehicles";
    amammo->interactable = true;
    amammo->interaction = "load";

    apammo->next = amammo;
    amammo->next = apammo;
}

void back::startmenu()
{
    /*
    time.wait(1);
    cout<<"Blazing sun"<<endl;
    time.wait(1.5);
    cout<<"No plan B"<<endl;
    time.wait(1.5);
    cout<<"One shot"<<endl;
    time.wait(1.5);
    cout<<"Make it count"<<endl<<endl<<endl;
    */

    cout<<"     ######  #####    ###  ###  ######    ######  ######   "<<endl;
    cout<<"    ###     ### ##   ###  ###  ###  ###  ###     ###  ###  "<<endl;
    cout<<"   ######  ###  ##  ###  ###  ######    ######  ######     "<<endl;
    cout<<"     ###  ###   ## ###  ###  ###       ###     ###  ###    "<<endl;
    cout<<" ######  ###    #####  ###  ###       ######  ###    ###   "<<endl<<endl<<endl;
}
