#include <iostream>                                                                  
#include <map>                                                                       
#include <fstream>                                                                   
                                                                                     
class mapmanip                                                                       
{                                                                                    
public:                                                                              
                                                                                     
  void input_pair();                                                                 
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
        void replace (const std :: string &restring);
        bool save (char filename []);  //most likely saves to a file must write
        //a function to recove file contents


  // make sure to make a .clear for screen when outputting file contents to dipplay  
                                                                                     
private:                                                                             
  std::map<std::string, Student> m;                                                  
  std::string filename;  // this is here... output into file uses filename
        int top_line = 0;
        int pointer_line = 0;
        int height = 5;                               
                                                                                     
                                                                                     
};