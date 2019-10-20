//Abhi Mohnani
//amohnan1

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "digraph.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::ifstream;

//creates a map of all digraphs and their corresponding words using the file 
map<string, vector<string>> populate_map(ifstream *input){
  map<string, vector<string>> words;
  int num_digraphs;
  string temp;

  //inputs number of digraphs and initializes vectors for each digraph to empty
  *input >> num_digraphs;
  for (int i = 0; i < num_digraphs; i++){
    *input >> temp;
    words[temp] = {};
  }

  while (*input >> temp){
    temp = make_lowercase(temp);
    temp = remove_punctuation(temp);
    for (map<string, vector<string>>::iterator i = words.begin();
	 i != words.cend(); i++){
      if (contains_digraph(temp, i->first)){
	  i->second.push_back(temp);
	}
    }
  }
  
  return words;
}


bool contains_digraph(string word, string digraph){
  if (word.find(digraph) != string::npos){
    return true;
  }
  return false;
}

//given one digraph, outputs all of the words that contain the digraph
void output_digraph(map<string, vector<string>> words, string digraph)
{
  //converts the digraph to lowercase
  digraph = make_lowercase(digraph);

  //checks if digraph is in the list
  if (words.find(digraph) == words.end()){
    cout << "No such digraph" << endl;
    return;
  }

  //outputs number of words containing digraph
  cout << words[digraph].size() << endl;

  //outputs all words one by one that contain the digraph
  for (vector<string>::const_iterator i = words[digraph].cbegin();
       i != words[digraph].cend();   i++){
    cout << *i << endl;
  }
}

//outputs all the digraphs that have a given number of corresponding words
void output_by_number(map<string,vector<string>> words, int count){
  bool check = true;
  //iterates through digraphs in map
  for (map<string, vector<string>>::const_iterator i = words.cbegin();
       i != words.cend(); i++){
    //checks if size is equal to given number
      if (i->second.size() == (unsigned)count){
	cout << i->first << endl;
	check = false;
	//if so, outputs the digraph and its corresponding words
	for (vector<string>::const_iterator j = i->second.cbegin();
	     j != i->second.cend(); j++){
	  cout << *j << endl;
	}
      }
  }

  //if no digraphs have that count
  if (check){
    cout << "None" << endl;
  }
}

//outputs all digraphs based on a command argument
int output_all_digraphs(map<string,vector<string>> words, string command){
  if (command == "a"){
    //outputs all digraphs in ASCII order
    output_all_forwards(words);
  } else if (command == "r"){
    //outputs all digraphs in reverse ASCII order
    output_all_reverse(words);
  } else if (command == "c"){
    //outputs all digraphs by their count in descending order
    output_all_count(words);
  } else {
    //case of invalid argument
    cout << "Invalid arguments." << endl;
    return 1;
  }
  return 0;
}

//outputs all digraphs and corresponding words in ASCII order
void output_all_forwards(map<string,vector<string>> words){
  //iterates through all digraphs in map
  for (map<string, vector<string>>::const_iterator i = words.cbegin();
       i != words.cend(); i++){
    cout << i->first << ": [";
    //iterates through all words corresponding to each digraph
    for (vector<string>::const_iterator j = i->second.cbegin();
	 j != i->second.cend(); j++){
      //outputs all words
      if (j == i->second.cend() - 1){
	cout << *j;
      }else{
	cout << *j << ", ";
      }
    }
    cout << "]" << endl;
  }
}

//outputs all digraphs and corresponding words in reverse ASCII order
void output_all_reverse(map<string,vector<string>> words){
  //iterates through all digraphs in reverse using a reverse iterator
  for (map<string, vector<string>>::const_reverse_iterator i = words.crbegin();
       i != words.crend(); i++){
    cout << i->first << ": [";
    //outputs all words associated with each digraph
    for (vector<string>::const_iterator j = i->second.cbegin();
	 j != i->second.cend(); j++){
      if (j == i->second.cend() - 1){
	cout << *j;
      }else{
	cout << *j << ", ";
      }
    }
    cout << "]" << endl;
  }
}

//outputs all digraphs and corresponding words in order of descending
//count of words per digraph
void output_all_count(map<string,vector<string>> words){
  map<int, vector<string>> counts;
  //fills a new map with the count as the integer key
  for (map<string, vector<string>>::const_iterator i = words.cbegin();
       i != words.cend(); i++){
    counts[i->second.size()].push_back(i->first);
  }

  //iterates through each count
  for (map<int,vector<string>>::const_reverse_iterator i = counts.crbegin();
       i != counts.crend(); i++){
    cout << "(Count = " << i->first << ") ";
    //iterates through all digraphs for each count
    for (vector<string>::const_iterator j = i->second.cbegin();
	 j != i->second.cend(); j++){
      cout << *j << ": [";
      //outputs all words for each digraph
      for (vector<string>::const_iterator k = words[*j].cbegin();
	   k != words[*j].cend(); k++){
	if (k == words[*j].cend() - 1){
	  cout << *k;
	}else{
	  cout << *k << ", ";
	}
      }
      cout << "]" << endl;
    }
  }
}

//function that makes a string lowercase
string make_lowercase(string word ){
  //iterates through each character and turns uppercase to lowercase
  for (unsigned i = 0; i < word.length(); i++){
    if (word[i] >= 'A' && word[i] <= 'Z'){
      word[i] += 'a' - 'A';
    }
  }
  return word;
}

string remove_punctuation(string word){
  
    if (word[0] == '.' || word[0] == '?' ||
	word[0] == '!' || word[0] == ','){
      word = word.substr(1);
    }
    int length = word.length();
    if (word[length-1] == '.' || word[length-1] == '?' ||
	word[length-1] == '!' || word[length-1] == ','){
      word.pop_back();
    }
  
  return word;
}
