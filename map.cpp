#include <iostream>                                                                  
#include <map>                                                                                                                                
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

void mapmanip::search_print()  //writes to a file // done
{
    string filename;
   cout << "Filename: ";
    cin >> filename;
ofstream out;
out.open(filename);
if(!out)
{cout << "Error" << endl; return;}

for (Student i : v) // should work ... I think ... runs through v and outputs every element as i
{ // not sure vscode automatically uses range-based
   out << i.get_fname() + i.get_lname() + i.getreg_status() + i.getUx();

}

out.close();

}
                                                                                                                                                        

void mapmanip::input_pair(istream &in) // is fine                                           
{                                                                                    
 Student student;                                                                    
 string lname;                                                                       
 string fname;                                                                       
int YoB;                                                                             

cout << "First name:" ;                                                         
  student.inputfname(); 
  cout << "Last name:";
  student.inputlname();  
  cout << "Input year of birth (w/n 17 years of the season)";                                                            
  student.inputYoB();     
  student.regstatus();  
  student.IsInUx(season_yr);                              
  m.insert(pair <string, Student> (student.get_lname() + " " + student.get_fname(), student)); //the get_names return strings  

 }

std::vector<Student> mapmanip :: search_map() {
int YearBorn;
string category;
string registered;
string lname;
bool cont = true;
 // initialze since search always creates new vector

        cout << "Would you like to search by (n)ame, (c)ategory, (y)ear of birth, or (r)egistered"; // need to specify registered or not registered
        char a;
        cin >> a; 


    if(a == 'n'){
        cin >> lname;
        map<std::string, Student> m1 = m;
        v = print_if_map_name(m1.begin(), m1.end(), lname);
        while(cont)
        {
cout << "Would you like to search by (c)ategory, (y)ear of birth, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        cin >> category;
        v = print_if_vector_category(v.begin(), v.end(), category);
        break;
        case 'y':
        cin >> YearBorn;
        v = print_if_vector_year(v.begin(), v.end(), YearBorn);
        break;
        case 'r':
        v = print_if_vector_registered(v.begin(), v.end());
        break;
        case 'd':
        cont = false;
        break;
        default:
        break;
     }
        }
    }
    if(a == 'y')
    {
        cin >> YearBorn;

        v = print_if_map_year(m.begin(), m.end(), YearBorn);
        while(cont)
        {
cout << "Would you like to search by (c)ategory, (n)ame, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        cin >> category;
        v = print_if_vector_category(v.begin(), v.end(), category);
        break;
        case 'n':
        cout << "Insert Last Name";
        cin >> lname;
        v = print_if_vector_name(v.begin(), v.end(), lname);
        break;
        case 'r':
        v = print_if_vector_registered(v.begin(), v.end());
        break;
        case 'd':
        cont = false;
        break;
        default:
        break;
     }
        }
    }
    if(a == 'c')
        {
        cin >> category;
        v = print_if_map_category(m.begin(), m.end(), category);
        while(cont)
        {
cout << "Would you like to search by (c)ategory, (n)ame, (r)egistered, or (d)isplay?";
    cin >> a;
     switch(a) {
        case 'c':
        cin >> category;
        v = print_if_vector_category(v.begin(), v.end(), category);
        break;
        case 'n':
        cout << "Insert Last Name";
        cin >> lname;
        v = print_if_vector_name(v.begin(), v.end(), lname);
        break;
        case 'r':
        v = print_if_vector_registered(v.begin(), v.end());
        break;
        case 'd':
        cont= false;
        break;
        default:
        break;
            }
        }
    }



if(a == 'r'){

        map<std::string, Student> m1 = m;
        v = print_if_map_registered(m1.begin(), m1.end());
        while(cont)
        {


        }
}
std::vector<Student> v1 = v;
return (v1);  
}

void mapmanip::maindisplay()
{
int regcount = 0;
int unregcount=0;
Student student;
cout <<"The number of total players: ";
cout << m.size() << endl;
for (auto itr = m.begin(); itr != m.end(); itr++)
{
student = (itr -> second);
if(student.getreg_status() == "Registered")
{regcount++;}
else {unregcount++;}
cout << "Registered :" << regcount << endl;
cout << "Unregistered: " << unregcount << endl;
}

}

void mapmanip::next(std::vector<Student>::iterator pos){
if(pos != (v.end() -1))
{pos ++;}
else 
{pos = v.begin();}

}

void mapmanip:: prev(std::vector<Student>::iterator pos)
{
if(pos != (v.begin()))
{pos --;}
else 
{pos = v.end();}
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
//what can I do with season year... get season year function to use IsInUx
int mapmanip::getseasonyr()
{
    return(season_yr);
}


/*bool mapmanip::if__name(Student student, std::string &name)
{
if (student.get_lname() == name) return 1;
else return 0;

}
bool mapmanip::if__YoB(Student student, int YearofB)
{
if (student.getYoB() == YearofB) return 1;
else return 0;
}
bool mapmanip::if__regstatus(Student student, std::string regstatus)
{
if ((student.getreg_status()).substr(0) == (regstatus.substr(0))) return 1;
else return 0;
}
bool mapmanip::if__Ux(Student student, std::string &Ux1)
{
if (student.getUx() == Ux1) return 1;
else return 0;
}*/

void mapmanip:: main_print()
{
    cout << "filename :";
    cin >> filename;
    Student student;
    ofstream out;
    out.open(filename);
    if(!out)
    {cout << "Error: Could not open file";}
    for(auto itr = m.begin(); itr != m.end(); itr++)
    
{
    student = (itr -> second);
    if(student.getUx() == "U17")
    {
    std::cout << "U17\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
    if(student.getUx() == "U14")
    {
    std::cout << "U14\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
    if(student.getUx() == "U12")
    {
    std::cout << "U12\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
    if(student.getUx() == "U10")
    {
    std::cout << "U10\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
    if(student.getUx() == "U8")
    {
    std::cout << "U8\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
    if(student.getUx() == "U6")
    {
    std::cout << "U6\n" << student.get_fname() + " " + student.get_lname() + " " + student.getreg_status();
    }
}

}

void mapmanip::searchdisplay(int number, std::vector<Student>::iterator pos, std::vector<Student> a)
{
cout << (*pos).get_fname() << " " << (*pos).get_lname() << " " << (*pos).getreg_status() << endl;
cout << (*pos).getUx() << endl;
cout << number << "/" << a.size();
}


void mapmanip::edit(std::vector<Student>::iterator pos)
{
cout << "What would you like to edit:" << endl;
cout << "Name (n), Year of Birth (y), Reg Status(r)? " <<endl;
char a;
string name;
cin >> a;
if(a == 'n')
{
    name = (*pos).get_lname();
    (*pos).inputfname(); (*pos).inputlname();
m.erase(name);
m.insert(pair <string, Student> ((*pos).get_lname() + (*pos).get_fname(), *pos));


}
if(a == 'y')
{
    name = (*pos).get_lname();
    (*pos).inputYoB();
m.erase(name);
m.insert(pair <string, Student> ((*pos).get_lname() + (*pos).get_fname(), *pos));

}
if(a == 'r')
{
    name = (*pos).get_lname();
    (*pos).regstatus();
m.erase(name);
m.insert(pair <string, Student> ((*pos).get_lname() + (*pos).get_fname(), *pos));

}
}

// finish edit