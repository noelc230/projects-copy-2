#include <iostream>                                                                  
#include <map>                                                                       
#include <fstream> 
#include "classbuild.h"   
#include <vector>                                                               
                                                                                     
class mapmanip                                                                       
{                                                                                    
public:                                                                              
                                                                                     
  void input_pair(std::istream &in);                                                                 
  void output();                                                           
  std::map<std::string, Student> copymap() //returns a map
  {std::map<std::string, Student> m1;
  m1=m;
  return(m1);}   

        void begin_new_season();
        void next();
        void prev();
        bool open (); // need to integrate with outputintofile function
        void display(); // display statistics 
        //void set_height(int h) {height = h;}
        void search_map(); // maybe use a binary predicate algorithm
        void up();
        void down();
        void jump(int l);
       /* void insert (const std::string & instring); */// wrong need to integrate
        void erase();
        void replace (const Student &student);
        bool save ();  //most likely saves to a file must write
        //a function to recove file contents
        void search_print();
        bool if__name(Student student, std::string &name);
        bool if__YoB(Student student, int YoB);
        bool if__regstatus(Student student, std::string regstatus);
        bool if__Ux(Student student, std::string &Ux1);
        void main_print();

  // make sure to make a .clear for screen when outputting file contents to dipplay  
  
 
// condition takes a function that returns a bool... this bool will activate the function
// compares the 
// what would the call look like print_if(m.begin(), m.end(), print_if(), out)
// what i want in the printif statement is to compare function output 
std::vector<Student> print_if_map_name(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop, string lname)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((itr->second).get_lname() == lname)
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}




std::vector<Student> v;

  private:                                                                   
  std::map<std::string, Student> m;                                          
  std::string filename;  // this is here... output into file uses filename
        int top_line = 0;
        int pointer_line = 0;
        int height = 5;                               
        int season_yr;                                                                                                                                            
};


/*template <class T, typename BinaryPredicate>
std::vector<Student> print_if(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop, BinaryPredicate condition, T item, char)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if(condition)                                                       
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}    

template <class T, typename BinaryCondition>
std::vector<Student> print_if(std::vector<Student>::iterator start, std::vector<Student>::iterator stop, BinaryCondition condition, T item)         
{   
    std::vector<Student> v1;                                                       
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if(condition)                                                       
        {v1.push_back(*itr);}                                                         
    }         
    return(v1);                                                                  
}
/*