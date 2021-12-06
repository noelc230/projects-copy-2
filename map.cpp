#include <iostream>                                                                  
#include <map>                                                                       
#include "classbuild.h"                                                              
#include <fstream>                                                                   
#include "map.h"                                                                     
                                                                                     
using namespace std;                                                                 
                                                                                     
bool mapmanip::save()         //need new UI to confirm why it is a bool                                           
{                                                                                    
  cin >> filename; // might not need                                                               
  // maybe some vector append here to save filename for future use                   
  ofstream out;                                                                      
  out.open(filename);   if (out.fail()) return true;                                                             
  // something like out<< m[key] << m[key].get_info_stuff_a_bunch_of_times           
  for (auto itr = m.begin(); itr != m.end(); itr++)                                  
    {                                                                                
      cout << itr -> first << " "; //<< " " << itr -> second << " ";                 
      Student student = (itr -> second); //second is an object of class students and
 //dereference and select returns the object                                           
                                                                                     
      student.getYoB(); student.getUx(); student.getreg_status();  
      return false;                  
    }                                                                                
 // ask professor                                                                    
}                                                                                    
                                                                                     
                                                                                     
void mapmanip::input_pair(istream &in) // is fine                                           
{                                                                                    
 Student student;                                                                    
 string lname;                                                                       
 string fname;                                                                       
int YoB;                                                                             

cout << "First and Last name:" ;                                                         
  student.inputname(in);                                                               
  student.inputYoB(in);     
student.regstatus();                                    
    m.insert(pair <string, Student> (student.get_lname() + " " + student.get_fname(), student)); //the get_names return strings                      
 }


 void mapmanip :: jump (int l) {
    if ( l > (m.size () + 1)) l = m.size() + 1;
    if ( l < 0) l = 0;
    top_line = pointer_line = l-1;
}
//dont think we need

void mapmanip :: next ()
{
    if (pointer_line == (m.size() + 1)) return;
    pointer_line--;
    if ( pointer_line < top_line) top_line--;
}
// works fine .. should work in search

void mapmanip:: prev () {
    if (pointer_line == 0) return;
    pointer_line --;
    if (pointer_line < top_line) top_line --;
}
//should work in search... is actually next

/*void Buffer :: insert (const string &instring){
    buff.insert (buff.begin() + pointer_line , instring); // map does not support an insert function... 
}*/

void mapmanip :: replace(const Student &student) {
    auto itr = m.begin();
     itr += (pointer_line - 1);
    (itr -> second) = student; 
                                                    }
                           // map may not support a simple replace... most replace as object of the class classbuild 
//could be extremely similar //do we need this?

void mapmanip::erase() {
    m.erase (m.begin() + (pointer_line-1));
} // map supports some kind of erase .... may need to edit 

void mapmanip :: search (string s) {
    for (auto itr = m.begin(); itr != m.end(); itr++) { //maybe use iterator... itr = map.begin 
    //.... through to map.end searching for string index(most likely first name)
        //if (buff[i].find(s) != string :: npos)
         {if ((itr -> first) != m.find(s))
            top_line = 1;
            return 0;
        }
    }
    return 1;
} //needed but will be somewhat different.... will search by key
// need to have an output parameter to display 
// probably wont return 1 or 0

bool mapmanip::open () {
    string line;
    ifstream instr;
    m.clear();
    cout << "Filename:";
    cin >> filename;
    instr.open(filename);
    while (getline (instr, line)) buff.push_back(line); // cant do that right now
    instr.close();
    strcpy ( fname, filename); // can't do this either
}
// look at output into file... maybe highjack code

/*bool mapmanip::save ( {
    ofstream out;
    out.open(filename);
    if (out.fail()) return true;
    for (string s: buff) out << s << endl;
    out.close();
    return false;
}
 // again highjacks output into file...
*/

void mapmanip :: display() {
    int i;
    int maxline;
    maxline = top_line + height;
    if (maxline > m.size()) maxline = m.size();

    cout << long_dash << endl; //need longdash back... not sure where it went
    for ( int i = top_line; i < maxline; i++) 
    {
        if (i == pointer_line) cout << " > "; else cout << " ";
        if ( i< 9) cout << " " ;
        auto itr = m.begin() + i;
        Student student = (itr -> second);
        cout << i+1 << " " ; student.getYoB(); student.getUx(); student.getreg_status(); << endl;
    }
    cout << long_dash << endl;
    } // the really hard stuff

void mapmanip::begin_new_season()
    {
        string answer;
        cout << "Would you like to start a new season? (Y/N)";
        cin >> answer;
        if (answer.substr(0) == "Y" || answer.substr(0) == "y")
        {
        cout << "What year is this season?";
        cin >> season_yr;
        m.clear();
        }
        else return;

    }