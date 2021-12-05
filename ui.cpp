#include <iostream>
#include "map.h" // originally buffer.h
#include "classbuild.h" 
using namespace std;

int main()
{
    int height; 
    char a;
    char filename [80];
    mapmanip manip;
    string target;
    bool error = false;
    int season_yr;
    string answer;
    Student newStudent;
    

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
        manip.open(filename);
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
        manip.input_pair(); //Should add name to map
        cout << "What is students registration status? Registered or unregistered?";
        if (answer.substr(0) == "R" || answer.substr(0) == "r")
        cout << "You entered that this new student is registered";
        //cin >> Not sure how to assign registration status here

        //Print
        case 'g':
        for(auto it = mapmanip.cbegin(); it != mapmanip.cend(); ++it)
        {
        std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
        }
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
    manip.display();
    if (error){
       cout << "Can't find" << target << endl;
       error = false;
    }
}

}