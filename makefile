Roster: classbuild.o map.o ui.o
        g++ -std=c++11 classbuild.o ui.o map.o -o Roster

ui.o: ui.cpp classbuild.o map.o
        g++ -std=c++11 -c ui.cpp -o ui.o

map.o: map.cpp map.h                                                     
        g++ -std=c++11 -c map.cpp -o map.o

classbuild.o: classbuild.cpp classbuild.h                                            
        g++ -std=c++11 -c classbuild.cpp -o  classbuild.o