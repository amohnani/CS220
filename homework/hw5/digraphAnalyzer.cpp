//Abhi Mohnani
//amohnan1
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include "digraph.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::ifstream;
using std::stringstream;

int main(int argc, char *argv[]){

  //checks if user put in correct number of command-line arguments
  if (argc != 3){
    cout << "Invalid arguments." << endl;
    return 1;
  }

  ifstream input(argv[1]);
  if (!input){
    cout << "Invalid file" << endl;
    return 2;
  }

  map<string, vector<string>> words = populate_map(&input);
  /* words["wh"] = {"what", "when"};
  words["sch"] = {};
  words["ou"] = {"thought", "out", "around", "out", "around", "could", "out", "around", "house"};
  words["ee"] = {"see", "need"};
  words["ch"] = {"tichener", "chucking", "tickener", "chucking", "teacher", "chance"};*/

  output_all_digraphs(words, argv[2]);
  
  
  cout << "q?>";
  string command;
  int val;
  while (cin >> command){
    command = make_lowercase(command);
    if (command == "quit"){
      return 0;
    }else if (stringstream(command) >> val){
      output_by_number(words, val);
    }else{
      output_digraph(words, command);
    }
    cout << "q?>";
  }
  
  return 0;
}
