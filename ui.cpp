#include <iostream>
#include "map.h" // originally buffer.h
using namespace std;

int main()
{
    int height; 
    char a;
    mapmanip manip;
    string target;
    int season_yr;
    string answer;
    vector<Student> v1;
    int n = 1;
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
        manip.main_print();  //prints into a file //no need to put filename here 
        break;

        //Quit
        case 'q':
        return 0;
        break;

        case 'd':
        manip.maindisplay();
        break;

        //Search
        case 's':
        // need to put switch statement stuff here instead of outside
        //main view only shows stats and prelimiary options
       
        v1 = manip.search_map();
       vector<Student>::iterator position; 
       position = v1.begin();
        while(true)
             {
         cout << "(n)ext (p)revious (e)dit p(r)int e(x)it (s)top" ; //something like this probably more stuff
        cin >> a;
        switch(a){

        case 'n': 
        manip.next(position);
        n++;
        if(n >= v1.size())
        n=1;
        manip.searchdisplay(n, position, v1);
        break;

        //Previous
        case 'p':
        manip.prev(position);
        n--;
        if(n = 0)
        n = v1.size();
        manip.searchdisplay(n, position, v1);
        break;

        case 'e':
        manip.edit(position);


        case 'r':
        manip.search_print();
        break;

        //Quit=
        case 'x':
        return 0;
        break;
             }
             break;
             }

    }

}
} 
