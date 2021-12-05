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
    cout << "add next previous open quit search";
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
        cout << "New players first name, last name and Year of Birth: ";
        manip.input_pair(cin); //Should add name to map
      break;
        //Edit
         case 'e':
         break;
        //Need to ask thorpe about this
        

        //Next
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

        //Search
        case 's':
        cout << "Target: ";
        cin >> target;
        error = manip.search(target);
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