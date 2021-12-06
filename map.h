#include <iostream>                                                                  
#include <map>                                                                       
#include <fstream> 
#include "classbuild.h"   
#include <vector>                                                               
                                                                                     
class mapmanip                                                                       
{                                                                                    
public:                                                                              
                                                                                     
  void input_pair(istream &in);                                                                 
  void output();                                                           
  void copymap() 
  {std::map<std::string, Student> m1(m);}   

        void begin_new_season();
        void next();
        void prev();
        bool open (); // need to integrate with outputintofile function
        void display(); // display statistics 
        void set_height(int h) {height = h;}
        bool search(std::string &s); // maybe use a binary predicate algorithm
        void up();
        void down();
        void jump(int l);
       /* void insert (const std::string & instring); */// wrong need to integrate
        void erase();
        void replace (const Student &student);
        bool save ();  //most likely saves to a file must write
        //a function to recove file contents
        void search_print();

  // make sure to make a .clear for screen when outputting file contents to dipplay  

     template <class BinaryPredicate, class iterator>
     void print_if(iterator start = m.begin(), iterator end = m.end(), BinaryPredicate &condition, ostream\
 &out)                                                                          
{                                                                               
  for(start; itr != stop; itr++)                                     
    {                                                                           
      if(condition(itr->))                                                       
        {cout << student.get_lname() + " " + student.get_fname() + " " + student.getUx()  + " " + student.getreg_status() << endl;}                                                          
    }                                                                           
}                      

private:                                                                             
  std::map<std::string, Student> m;                                                  
  std::string filename;  // this is here... output into file uses filename
        int top_line = 0;
        int pointer_line = 0;
        int height = 5;                               
        int season_yr;                                                                          
        std::vector<std::string> search;                                                                        
};