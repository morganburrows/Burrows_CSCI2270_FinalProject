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
        }
        else if(Minput == "quit")
        {
            exit(0);
        }
        else
        {
            cout<<endl<<"wrong input"<<endl<<endl;
            MM = true;
        }
    }
    while(MM == true);




}
