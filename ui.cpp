#include <iostream>
#include "map.h" // originally buffer.h
#include "classbuild.h" 
using namespace std;

int main()
{
    int height; 
    char a;
    mapmanip manip;
    string target;
    int season_yr;
    string answer;
    
    

cout << "Welcome to soccer team creator."; // Make this Start new season
while(true){
    cout << "(a)dd (o)pen (q)uit (s)earch (d)isplay (b)egin_new_season";// need to update
    cin >> a;
    cin.get();
    switch (a) { //Main
        
        //Need to write display statistics
        //Need to write print
        //Open
        case 'o':
        manip.open(); //not sure if we need an open switch... save essentially does this
        break;

        //b for beginning , asking user for year 
        case 'b': 
        cout << "Would you like to start a new season?";
        cin >> answer;
        if (answer.substr(0) == "Y" || answer.substr(0) == "y")
        cout << "What year is this season?";
        cin >> season_yr;
        break;


        // Add Player
        case 'a' :
        manip.input_pair(cin); //Should add name to map
      break;
        //Edit
         case 'e':
         break;
        //Need to ask thorpe about this

        //Quit
        case 'q':
        return 0;
        break;

        //Search
        case 's':
        // need to put switch statement stuff here instead of outside
        //main view only shows stats and prelimiary options
        cin >> target;
        manip.search(target);
        while(true)
             {
         cout << "(n)ext (p)revious (e)dit p(r)int e(x)it" ; //something like this probably more stuff
        cin >> a;
        switch(a){

        case 'n': 
        manip.next();
        break;

        //Previous
        case 'p':
        manip.prev();
        break;

        case 'r':
        manip.print(); // not written yet
        break;

        //Quit
        case 'x':
        return 0;
        break;
             }
             
             }

        break;
        default:
        break;
    }

}
    cout << static_cast<char> (12);
    /* error = */
    manip.display(); // most likely not needed here
}

