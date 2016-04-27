#include "back.h"
#include "Timer.h"

using namespace std;

int main()
{
    bool inmenu = true;
    bool MM = false;
    string mainmenu;

    Timer time;
    back backend;
    gamelevel level;

    backend.initmenu();
    backend.startmenu();
    string Minput;

    do
    {
        cout<<"play"<<endl;
        cout<<"quit"<<endl<<endl;
        getline(cin,Minput);

        if(Minput == "play")
        {
            MM = false;
            backend.current = backend.root;
            backend.EImenu(backend.current);
            backend.tripped = false;
        }
        else if(Minput == "quit")
        {
            exit(0);
        }
        else
        {
            cout<<endl<<"wrong input"<<endl<<endl;
            MM = true;
            if(backend.tripped != false)
            {
                backend.tripped = true;
            }
        }
    }
    while(MM == true);




}
