#include <iostream>                                                                  
#include <map>                                                                       
#include <string>                                                                    
#include "classbuild.h"                                               
                                                                                     
using namespace std;                                                                 
                                                                                     
void Student :: regstatus()                                                          
  {                                                                                  
    string answer;                                                                   
    cout << "Is the student registered? (Y/N)";                                      
    cin >> answer;                                                                   
    if(answer.substr(0) == "Y" || answer.substr(0) == "y")                           
      { reg_status = true;}                                                          
  }                                                                                  
                                                                                     
void Student :: IsInUx(const int &season_yr)  //have to include to add                                   
{                                                                                    
  if(((season_yr - YoB) < 6) && ((season_yr - YoB) >=4))                             
    {Ux = "U6";}                                                                     
  if(((season_yr - YoB) < 8) && ((season_yr - YoB) >= 6))
    {Ux = "U8";}                                                                     
if(((season_yr - YoB) < 10) && ((season_yr - YoB) >= 8))                             
    {Ux = "U10";}                                                                    
if(((season_yr - YoB) < 12) && ((season_yr - YoB) >= 10))                            
    {Ux = "U12";}                                                                    
if(((season_yr - YoB) < 14) && ((season_yr - YoB) >= 12))                            
    {Ux = "U14";}                                                                    
if(((season_yr - YoB) < 17) && ((season_yr - YoB) >= 14))                            
    {Ux = "U17";}                                                                    
 if((season_yr - YoB) >= 17)                                                         
   {cout << "Error: Birth year is not compatible with any of the existing age divisions" << endl;}
}