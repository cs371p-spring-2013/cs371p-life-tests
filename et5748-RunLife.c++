#include <cstdlib>
#include <iostream>
#include <vector>
#include "ConwayCell.h"
#include "AbstractCell.h"
#include "Life.h"
#include <fstream>

using namespace std;

int runConway () {
    int cnt = 5;
    ifstream in_stream;
    ofstream out_stream; 

    in_stream.open("RunLifeConway.in");
    out_stream.open("RunLife.out");

    while (cnt > 0) {
      Life thegame("ConwayCell", in_stream, out_stream);
      thegame.initialize();
      thegame.setAlive(in_stream, out_stream);

      for(int i = 0; i <= 5; i++){
          if(i%1 == 0) {
            thegame.printBoard(i, out_stream);
     }
          thegame.check();
          thegame.refresh();
      }
      --cnt;
    }    
    
    in_stream.close();
    out_stream.close();

    return 0;
}

int runFredkin () {
    int cnt = 5;
    ifstream in_stream;
    ofstream out_stream; 

    in_stream.open("RunLifeFredkin.in");
    out_stream.open("RunLife.out", std::ios_base::app);

    while (cnt > 0) {
      Life thegame("FredkinCell", in_stream, out_stream);
      thegame.initialize();
      thegame.setAlive(in_stream, out_stream);
      for(int i = 0; i <= 5; i++){
          if(i%1 == 0) {
            thegame.printBoard(i, out_stream);
	   }
          thegame.check();
          thegame.refresh();
      }
      --cnt;
    }    
    
    in_stream.close();
    out_stream.close();

    return 0;
}

int runCell () {
    int cnt = 5;
    ifstream in_stream;
    ofstream out_stream; 

    in_stream.open("RunLifeCell.in");
    out_stream.open("RunLife.out", std::ios_base::app);

    while (cnt > 0) {
      Life thegame("Cell", in_stream, out_stream);
      thegame.initialize();
      thegame.setAlive(in_stream, out_stream);
      for(int i = 0; i <= 5; i++){
          if(i%1 == 0) {
            thegame.printBoard(i, out_stream);
	   }
          thegame.check();
          thegame.refresh();
      }
      --cnt;
    }    
    
    in_stream.close();
    out_stream.close();

    return 0;
}

int main(int argc, char** argv) {
    runConway();
    runFredkin();
    runCell();
    return 0;
}
