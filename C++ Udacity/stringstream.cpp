#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using std::string;
using std::istringstream;
using std::ifstream;
using std::getline;
using std::replace;
using std::cout;
using std::endl;

class Board {
    public :
     void streamer (const string &path);
   
    private :
      string _line, _value;
};

void Board::streamer (const string &path)
{

  ifstream file (path);
  if (file.is_open()){
      while (getline(file,_line)){
       replace (_line.begin(), _line.end(), ',', ' ');
       istringstream linestream (_line);
       while (linestream>> _value){
        cout<<_value<<" ";
       }
     cout<<endl;
    }

 }
}

int main (){
    Board board;
    board.streamer("1.board");
}
