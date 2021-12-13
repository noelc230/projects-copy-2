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
        int getseasonyr();
        void begin_new_season();
        void next(std::vector<Student>::iterator position);
        void prev(std::vector<Student>::iterator position);
        bool open (); // need to integrate with outputintofile function
        void maindisplay(); // display statistics 
        void searchdisplay(int number, std::vector<Student>::iterator pos, std::vector<Student> a);
        std::vector<Student> search_map(); // maybe use a binary predicate algorithm
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
        void edit(std::vector<Student>::iterator pos);

  // make sure to make a .clear for screen when outputting file contents to dipplay  
  
 
// condition takes a function that returns a bool... this bool will activate the function
// compares the 
// what would the call look like print_if(m.begin(), m.end(), print_if(), out)
// what i want in the printif statement is to compare function output 
std::vector<Student> print_if_map_name(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop, std::string lname)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((itr->second).get_lname() == lname)
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_map_year(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop, int y)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if (((itr->second).getYoB()) == y)
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_map_category(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop, std::string cat)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((itr->second).getUx() == cat)
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_map_registered(std::map<std::string, Student>::iterator start, std::map<std::string, Student>::iterator stop)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((itr->second).getreg_status() == "Registered")
        {v1.push_back(itr->second);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_vector_registered(std::vector<Student>::iterator start, std::vector<Student>::iterator stop)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((*itr).getreg_status() == "Registered")
        {v1.push_back(*itr);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_vector_name(std::vector<Student>::iterator start, std::vector<Student>::iterator stop, std::string lname)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((*itr).get_lname() == lname)
        {v1.push_back(*itr);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_vector_year(std::vector<Student>::iterator start, std::vector<Student>::iterator stop, int y)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if (((*itr).getYoB()) == y)
        {v1.push_back(*itr);}                                                         
    }         
    return(v1);                                                                  
}

std::vector<Student> print_if_vector_category(std::vector<Student>::iterator start, std::vector<Student>::iterator stop, std::string cat)         
{   
  std::vector<Student> v1;                                                           
  for(auto itr = start; itr != stop; itr++)                                     
    {                                                                           
      if ((*itr).getUx() == cat)
        {v1.push_back(*itr);}                                                         
    }         
    return(v1);                                                                  
}


std::vector<Student> v;
int n = 1;

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
*/