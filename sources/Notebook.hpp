#include<string.h>
#include"Direction.hpp"
#include<iostream>
#include<map>

using namespace std;                                            //this for me  //to check this why not work without namespace
using namespace ariel;

namespace ariel{
    class Notebook
    {
    
    public:
        map<int,map<int,string>> notebook;

        void write(int page,int row,int col,Direction d,string str);
		string read(int page,int row,int col,Direction d,int size);
		void erase(int page,int row,int col,Direction d,int size);
		void show(int page);

    private:
        void checkIfCanWrite(int page,int row,int col,Direction d,int strLength);
        void put_(int page,int row);
        void badInputValuesCheck(int page,int row,int col,Direction d,int strLength,string str);
        
    };
}