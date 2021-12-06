#include <iostream>
#include "map.h" // originally buffer.h
#include "classbuild.h" 
using namespace std;

int main()
{
    int height; 
    char a;
    char filename [80]; // probably not needed
    mapmanip manip;
    string target;
    bool error = false;
    int season_yr;
    string answer;
    
    

cout << "How high should the window be?";
cin >> height;
manip.set_height(height);

while(true){
    cout << "(a)dd (n)ext (p)revious (o)pen (q)uit (s)earch";// need to update
    cin >> a;
    cin.get();
    switch (a) {
        
        //Open
        case 'o':
        cout << "Filename : ";
        cin >> filename;
        manip.open();
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
         cout << "(n)ext (p)revious (q)uit" ; //something like this probably more stuff
        case 'n': 
        manip.next();
        break;

        //Previous
        case 'p':
        manip.prev();
        break;

        //Quit
        case 'q':
        return 0;
        break;

     
        }
        break;
        default:
        break;
    }
    cout << static_cast<char> (12);
    /* error = */
    manip.display(); // need to make manip.display output error
    if (error){
       cout << "Can't find" << target << endl;
       error = false;
    }
}

}