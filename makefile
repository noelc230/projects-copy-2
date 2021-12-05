classbuild.o: classbuild.cpp classbuild.h                                            
        g++ -std=c++11 -c classbuild.cpp -o  classbuild.o                            
                                                                                     
map.o: map.cpp map.h classbuild.h                                                    
        g++ -std=c++11 -c map.cpp -o map.o