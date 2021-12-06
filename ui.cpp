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
    
    //dont think we need an option for height

while(true){
    cout << "(a)dd (b)egin_new_season (q)uit (s)earch (d)isplay (p)rint";// need to update
    cin >> a;
    // quit makes use of save function and returns 0
    cin.get();
    switch (a) {
      
        //b for beginning , asking user for year
        case 'b': 
       manip.begin_new_season(); // works
        break;

     // Add Player
        case 'a' :
        manip.input_pair(cin); //works
      break;

        case 'p': 
        manip.print();  //prints into a file //no need to put filename here 
        break;

        //Quit
        case 'q':
        return 0;
        break;

        case 'd':
        manip.display();
        break;

        //Search
        case 's':
        // need to put switch statement stuff here instead of outside
        //main view only shows stats and prelimiary options
        cin >> target;
        manip.search(target);
        while(true)
             {
         cout << "(n)ext (p)revious (e)dit p(r)int e(x)it (s)top" ; //something like this probably more stuff
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
    if (error){
       cout << "Can't find" << target << endl;
       error = false;
    }
}

}