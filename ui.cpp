#include <iostream>
#include "map.h" // originally buffer.h
using namespace std;

int main()
{
    int height; 
    char a;
    char filename [80];
    Buffer buffer;
    string target;
    bool error = false;

cout << "How high should the window be?";
cin >> height;
buffer.set_height(height);

while(true){
    cout << "next previous open quit search";
    cin >> a;
    cin.get();
    switch (a) {
        case 'o':
        cout << "Filename : ";
        cin >> filename;
        buffer.open(filename);
        break;
        case 'n': 
        buffer.next();
        break;
        case 'p':
        buffer.prev();
        break;
        case 'q':
        return 0;
        break;
        case 's':
        cout << "Target: ";
        cin >> target;
        error = buffer.search(target);
        break;
        default:
        break;
    }
    cout << static_cast<char> (12);
    buffer.display();
    if (error){
       cout << "Can't find" << target << endl;
       error = false;
    }
}

}