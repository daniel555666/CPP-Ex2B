#include<string.h>
#include"Direction.hpp"
#include"Notebook.hpp"
using namespace std;                                            //this for me  //to check this why not work without namespace
using namespace ariel;

namespace ariel{

		void Notebook::badInputValuesCheck(int page,int row,int col,Direction d,int strLength,string str){
			const int max99=99;
			const int n32=32;
			const int n126=126;
			Notebook temp=*this;                            // made this to fix conflict error that happen at tidy or test, only way
			if(page<0||row<0||col<0||col>max99||strLength<0){            //check bad input
					throw runtime_error("wrong input");
				}
			if(d==Direction::Horizontal && col+strLength-1>max99){
				throw runtime_error("wrong input");
			}
			for(int i=0;i<str.length();i++){
				if (str.at((unsigned int)i)< n32 ||str.at((unsigned int)i)>n126 ||str.at((unsigned int)i)=='~' ){
					throw runtime_error("wrong input");
				}
			}
		}

		void Notebook::put_(int page,int row){
			const int max100=100;
			this->notebook[page][row]="";
			for(int i=0;i<max100;i++){
				this->notebook[page][row]+="_";
			}
		}

		void Notebook::checkIfCanWrite(int page,int row,int col,Direction d,int strLength){
			for(int h=0,v=0,i=0;i<strLength;i++){
				if(!this->notebook[page][row+v].empty()){
					if(this->notebook[page][row+v].at((unsigned int)(col+h))!='_'){
						throw runtime_error("already wrote in this place");			
					}
				}
				if(d==Direction::Horizontal){
					h++;
				}
				else{ v++;}
			}
		}


        void Notebook::write(int page,int row,int col,Direction d,string str){

			badInputValuesCheck(page,row,col,d,str.length(),str); //check input values
			checkIfCanWrite(page,row,col,d,str.length());     //check if can write their
			
			for(int h=0,v=0,i=0;i<str.length();i++){                     // make the line and write

				if(this->notebook[page][row+v].empty()){
					put_(page,row+v);
				    }
					
				this->notebook[page][row+v].at((unsigned int)(col+h))=str[(unsigned int)i];   //write the char

				if(d==Direction::Vertical){
					v++;
				}
				else {h++;}
			}
		}
		string Notebook::read(int page,int row,int col,Direction d,int size){  

			badInputValuesCheck(page,row,col,d,size,""); //check bad inputs

			string str;
			for(int h=0,v=0,i=0;i<size;i++){                     
				if(notebook[page][row+v].empty()){
					str+="_";
				}
				else{
				str+=this->notebook[page][row+v].at((unsigned int)(col+h));    //add the char to the string
				}

				if(d==Direction::Vertical){
					v++;
				}
				else {h++;}
			}	
			return str;
            }
		void Notebook::erase(int page,int row,int col,Direction d,int size){

			badInputValuesCheck(page,row,col,d,size,"");   	 //check input values

			for(int h=0,v=0,i=0;i<size;i++){                     // make the line and write

				if(this->notebook[page][row+v].empty()){
					put_(page,row+v);
				}
					
				this->notebook[page][row+v].at((unsigned int)(col+h))='~';   //write the char

				if(d==Direction::Vertical){
					v++;
				}
				else {h++;}
			}
		}
		void Notebook::show (int page){
			const int max10=10;
			const int max100=100;
			if(page<0){
        		throw runtime_error("bad input"); 
        	}
			string str0;                      //made empty line
			for(int i=0;i<max100;i++){
				str0+='_';
			}

			map<int,string> m=notebook[page];
			int rowi=m.begin()->first;        	// take the first line number that we wrote on

			for(map<int,string>::iterator row=m.begin(); row!=m.end() ; row++,rowi++){  //print the lines


				while(rowi<row->first){
					string str="line";           //for printing 
					str+=' '+to_string(rowi)+":";
					while(str.length()<max10){
						str+=' ';
					}
					cout<<str<<" "<<str0<<endl;
					rowi++;
				}
				string str="line";           //for printing 
				str+=" "+to_string(rowi)+":";
				while(str.length()<max10){
					str+=' ';
				}
				cout<<str<<" "<<row->second<<endl;
			}
		}

}

// int main(){
// 	Notebook n1;
// 	n1.write(10,10,80,Direction::Horizontal,"daniel");
// 	n1.erase(10,10,80,Direction::Vertical,5);
// 	n1.write(10,5,20,Direction::Horizontal,"hopa");
// 	n1.show(10);

// 	return 0;
// }