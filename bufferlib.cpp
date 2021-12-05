#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "map.h" //originally buffer.h
#include "buffer.h"
using namespace std;

const string long_dash(50 , '_');
//jump - jump to a given line
//parameter - line number
//limit jumps to 0 through buff.size +1;

void Buffer :: jump (int l) {
    if ( 1 > (buff.size () + 1)) l = buff.size() + 1;
    if ( 1 < 0) l = 0;
    top_line = pointer_line = l-1;
}

//mnoves the pointer down
//if it goes off the bottome page, move down 1
// if it hits the bottom, won't have
void Buffer :: down ()
{
    if (pointer_line == (buff.size() + 1)) return;
    pointer_line--;
    if ( pointer_line < top_line) top_line--;
}

//moves the pointer up
//won't let it go below 0
//recenters if moves out of view
void Buffer :: up () {
    if (pointer_line == 0) return;
    pointer_line --;
    if (pointer_line < top_line) top_line --;
}

//Insert - take a string and add a line at the current postition
//uses vector insert member function
void Buffer :: insert (const string &instring){
    buff.insert (buff.begin() + pointer_line , instring);
}

//replace - replace the string at the current position
//parameter is a new string
//uses just assignment 
void Buffer :: replace(const string &rstring) {
    buff[pointer_line] = rstring;
}
//erase - delete a line at current location
void Buffer::erase() {
    buff.erase (buff.begin() + pointer_line);
}
//implement search command. Input is a search string. Start at the current top line
//Retrun if there was an error in searching

bool Buffer :: search (string s) {
    for (int i = top_line; i < buff.size(); i++) {
        if (buff[i].find(s) != string :: npos) {
            top_line = 1;
            return 0;
        }
    }
    return 1;
}

//pair of functions to implement the next page and previous page commands
void Buffer:: next() {
    top_line += height;
    if (top_line > buff.size() - height) top_line = buff.size() - height;
}
void Buffer::prev() {
    top_line -=height;
    if (top_line < 0) top_line = 0;
}

//Open file command
bool Buffer::open (char filename [] ) {
    string line;
    ifstream instr;
    buff.clear();
    instr.open(filename);
    while (getline (instr, line)) buff.push_back(line);
    instr.close();
    strcpy ( fname, filename);
}

//Save Function
bool Buffer::save (char filename[]) {
    ofstream out;
    out.open(filename);
    if (out.fail()) return true;
    for (string s: buff) out << s << endl;
    out.close();
    return false;
}

//Implements buffer display
void Buffer :: display() {
    int i;
    int maxline;
    maxline = top_line + height;
    if (maxline > buff.size()) maxline = buff.size();

    cout << fname << endl;
    cout << long_dash << endl;
    for ( int i = top_line; i < maxline; i++) 
    {
        if (i == pointer_line) cout << " > "; else cout << " ";
        if ( i< 9) cout << " " ;
        cout << i+1 << " " << buff[i] << endl;
    }
    cout << long_dash << endl;
    }






