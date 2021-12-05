#include <iostream>                                                                  
#include <string>                                                                    
                                                                                     
                                                                                     
class Student {  //every student has an analogous object of class student            
                                                                                     
public:                                                                              
  void regstatus(); //may not need values in ()                                      
  void getname(){std::cout << fname << " " << lname << std::endl;}                   
  void getYoB(){std::cout << YoB << std::endl;}                                      
  void getUx(){std::cout << Ux;}                                                     
  void getreg_status(){if(reg_status) std::cout << "Registered";                     
    else std::cout << "Not Registered";}                                             
  void IsInUx(const int &season_yr); // changes value of private Ux to some string i\
ndicated by the division names... list of if statements... subtracts season_yr by Yo\
B                                                                                    
      void inputname(istream &in){std::cin >> fname >> lname;}                                  
      void inputYoB(istream &in){std::cin >> YoB;}                                              
// what would i like with this? ... I would like to take some season year - some yea\
r of birth and get the int... then maybe create a vector of vectors????              
//such that takes the season year if defined in UI... then seasonyear-yob            
//and U as vector will update //maybe too complicated right now//write a bunch of if\
 statements                                                                          
                                                                                     
                                                                                     
private:                                                                             
  int YoB;                                                                           
  std::string fname;                                                                 
  std::string lname;                                                                 
  bool reg_status; //registration status is a boolean w/ registered = 1 else 0;      
  std::string Ux;                                                                    
  std::string answer;                                                                
}; 