#include <iostream>                                                                  
#include <map>                                                                       
<<<<<<< HEAD
#include <fstream>                                                                   
#include "classbuild.h"

=======
#include <fstream> 
#include "classbuild.h"                                                                  
                                                                                     
>>>>>>> ecb2cedc01719d9513f07293c8dba065e9699f67
class mapmanip                                                                       
{                                                                                    
public:                                                                              
                                                                                     
  void input_pair(istream &in);                                                                 
  void output();                                                           
  void copymap() 
  {std::map<std::string, Student> m1(m);}   

        void next();
        void prev();
        bool open (); // need to integrate with outputintofile function
        void display();
        void set_height(int h) {height = h;}
        bool search (std :: string target);
        void up();
        void down();
        void jump(int l);
        void insert (const std::string & instring);
        void erase();
        void replace (const Student &student);
        bool save ();  //most likely saves to a file must write
        //a function to recove file contents


  // make sure to make a .clear for screen when outputting file contents to dipplay  
                                                                                     
private:                                                                             
  std::map<std::string, Student> m;                                                  
  std::string filename;  // this is here... output into file uses filename
        int top_line = 0;
        int pointer_line = 0;
        int height = 5;                               
                                                                                     
                                                                                     
};