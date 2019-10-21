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
  

  //checks if command was valid, and if so, outputs the digraphs in that order
  if( output_all_digraphs(words, argv[2])){
    return 1;
  }
  
  
  cout << "q?>";
  string command;
  int val;

  //repeats while the user wants to input commands
  while (cin >> command){
    //turns the command to all lowercase
    command = make_lowercase(command);

    //checks if the command was to quit
    if (command == "quit"){
      return 0;

      //checks if the command was a number
    }else if (stringstream(command) >> val){
      output_by_number(words, val);

      //otherwise, uses the command as a digraph
    }else{
      output_digraph(words, command);
    }
    cout << "q?>";
  }
  
  return 0;
}
