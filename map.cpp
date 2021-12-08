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
  for (typename std::map<string,Student>::iterator itr = m.begin(); itr != m.end(); itr++)                                  
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

void mapmanip :: search_map() {
int YearBorn;
string category;
string registered;
string name;

        cout << "Would you like to search by (n)ame, (c)ategory, (y)ear of birth, or (r)egistered"; // need to specify registered or not registered
        char a;
        cin >> a; 

    if(a == 'n'){
        cin >> name;

        v = print_if(m.begin(), m.end(), if_name, cout, name);
        while(true)
        {
cout << "Would you like to search by (c)ategory, (y)ear of birth, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        v = print_if(v.begin(), v.end(), if_Ux, cout, category);
        break;
        case 'y':
        v = print_if(v.begin(), v.end(), if_YoB, cout, YearBorn);
        break;
        case 'r':
        v = print_if(v.begin(), v.end(), if_regstatus, cout, registered);
        break;
        case 'd':
        return;
        default:
        break;
     }
        }
    }
    if(a == 'y')
        cin >> YearBorn;

        v = print_if(m.begin(), m.end(), if_YoB, cout, name);
        while(true)
        {
cout << "Would you like to search by (c)ategory, (n)ame, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        v = print_if(v.begin(), v.end(), if_Ux, cout, category);
        break;
        case 'n':
        v = print_if(v.begin(), v.end(), if_name, cout, YearBorn);
        break;
        case 'r':
        v = print_if(v.begin(), v.end(), if_regstatus, cout, registered);
        break;
        case 'd':
        return;
        default:
        break;
     }
        }
    if(a == 'c')
        {
        cin >> category;
        v = print_if(m.begin(), m.end(), if_Ux, cout, category);
        while(true)
        {
cout << "Would you like to search by (c)ategory, (n)ame, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        v = print_if(v.begin(), v.end(), if_Ux, cout, category);
        break;
        case 'n':
        v = print_if(v.begin(), v.end(), if_name, cout, YearBorn);
        break;
        case 'r':
        v = print_if(v.begin(), v.end(), if_regstatus, cout, registered);
        break;
        case 'd':
        return;
        default:
        break;
            }
        }
    }
}
    
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

bool mapmanip::if_name(Student student, std::string &name)
{
if (student.get_lname() == name) return 1;
else return 0;

}
bool mapmanip::if_YoB(Student student, int YearofB)
{
if (student.getYoB() == YearofB) return 1;
else return 0;
}
bool mapmanip::if_regstatus(Student student, std::string regstatus)
{
if ((student.getreg_status()).substr(0) == (regstatus.substr(0))) return 1;
else return 0;
}
bool mapmanip::if_Ux(Student student, std::string &Ux1)
{
if (student.getUx() == Ux1) return 1;
else return 0;
}

