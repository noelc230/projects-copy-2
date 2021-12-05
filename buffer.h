#include <vector>
#include <string>
class Buffer {
    private:
        int top_line = 0;
        int pointer_line = 0;
        int height = 5;
        std::vector <std::string> buff;
        char fname [80];

    public:
        void next();
        void prev();
        bool open (char filename []); 
        void display();
        void set_height(int h) {height = h;}
        bool search (std :: string target);
        void up();
        void down();
        void jump(int l);
        void insert (const std::string & instring);
        void erase();
        void replace (const std :: string &restring);
        bool save (char filename []);
};