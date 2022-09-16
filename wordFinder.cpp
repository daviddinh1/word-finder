//
//  main.cpp
//  WordFinder
//
//  Created by David Dinh on 8/22/22.
//

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

void lower(vector<string>& paragraph){
    for(int i = 0 ; i < paragraph.size() ; i++){
        for(auto& c: paragraph[i]){
            c = tolower(c);
        }
    }
}

 void questionOne(vector <string> paragraph, string name) {
    
   
    ofstream fout;
    string output = name + "1" +".txt";
    fout.open(output);


    vector<string> wordHolder;
    int cnt = 0;
    string word;
    string mostCommon;
    string line;
    
   
    vector <string> commonCases;
 
   for(int i = 0 ; i < paragraph.size();i++){
     istringstream ss(paragraph[i]);
     while(ss >> word){
       wordHolder.push_back(word);
     }
   }  

    for (int i = 0; i < wordHolder.size(); i++) {
        if (wordHolder[i][0] == '.'||wordHolder[i][0] == ',') {
            wordHolder[i].replace(0, 1, "");
        }
        int last_index = wordHolder[i].length() - 1;
        if (wordHolder[i][last_index] == ',' || wordHolder[i][last_index] == '.') {
            wordHolder[i].replace(last_index, 1, "");
        }
    }


    
   
    int highest_occ = 0;
    for (string a: wordHolder) {
        int tempCount = 0;
        for (string b : wordHolder) {
            if (a == b) {
                tempCount++;
            }
        }
        if (tempCount >= highest_occ) {
            highest_occ = tempCount;
        }
    }
    
    for (string a : wordHolder) {
        int tempCount = 0;
        for (string b : wordHolder) {
            if (a == b) {
                tempCount++;
            }
        }
        
        if (tempCount == highest_occ) {
            int exists = 0;
            for(int i=0; i < commonCases.size() ; i++) {
                if (commonCases[i] == a) {
                    exists = 1;
                }
            }
            if (!exists) {
                commonCases.push_back(a);   
            }
        }
    }
    
    for(int i=0; i < commonCases.size() ; i++) {
        fout << commonCases[i] << ":" << highest_occ << endl;
    }
    
}
void questionTwo(vector <string> paragraph,string name){


  int cnt =0;
  string word;
  string mostCommon;
  ofstream fout;
  
  
  vector <string> words;
  vector <string> cases;
  vector <int> cnts;

  string output = name + "2" +".txt";

  fout.open(output);



  for(int i = 0 ; i < paragraph.size();i++){
     istringstream ss(paragraph[i]);
     while(ss >> word){
       words.push_back(word);
     }
   } 
  
  for (string a: words){
  bool find = false;
    for (int i=0; i<cases.size(); i++){
        if(a == cases[i]){
          find = true;
          cnts[i]++;
        }
      
    }

    if (find == false){
      int pusher = 1;
      cnts.push_back(pusher);
      cases.push_back(a);
    }
      
    }

  vector <string> maxcases;
  vector <int> max_count;
  int highestcount = 0;
  int highestindex;
  int secondcount = 0;
  int thirdcount = 0;
  for (int i = 0; i <cnts.size();i++){
     if(cnts[i] >highestcount){
       highestcount = cnts[i];
       
     }
      
    }
   for(int i=0; i <cnts.size(); i++){
         if(cnts[i] ==highestcount){
            max_count.push_back(cnts[i]);
            maxcases.push_back(cases[i]);
            cnts.erase(cnts.begin()+i);
          cases.erase(cases.begin()+i);
           i--;
           
         }
     }

 
   highestcount = 0;
  for (int i = 0; i <cnts.size();i++){
     if(cnts[i] >highestcount){
       highestcount = cnts[i];
       
     }
    
 
    }
   
   vector <int> snd_Count;
   vector <string> secondcase;
    for(int i=0; i <cnts.size(); i++){
      
         if(cnts[i] ==highestcount){
            
            snd_Count.push_back(cnts[i]);
            secondcase.push_back(cases[i]);
              cnts.erase(cnts.begin()+i);
          cases.erase(cases.begin()+i);
           i--;
           

           
         }
     }
    
  highestcount = 0;
  for (int i = 0; i <cnts.size();i++){
     if(cnts[i] >highestcount){
       highestcount = cnts[i];
       
     }
    
 
    }
   
   vector <int> third_Count;
   vector <string> third_Case;
    
      for(int i=0; i<cnts.size(); i++){
      
         if(cnts[i] ==highestcount){
           
            third_Count.push_back(cnts[i]);
            third_Case.push_back(cases[i]);
           cnts.erase(cnts.begin()+i);
          cases.erase(cases.begin()+i);
           i--;
 
    
         }
        }
     
    

    for(int i=0; i < third_Count.size(); i++){
     fout << third_Case[i] <<":"<<third_Count[i] << endl;
      }
  }
  
   

void maxFreqSentThe(vector<string> sentenceHolder, string keyWord,string name){
  ofstream fout;
  string output = name + "4" +".txt";
  
  fout.open(output);
  vector<int>indicesHolderThe;
  vector<int>countHolderThe;
  int i;
  int j; 
  int max = 0;
  int cnt;
  for(i = 0 ; i < sentenceHolder.size() ; i++){
    vector<string> wordHolder;
    string hold;
    stringstream jj(sentenceHolder[i]);
    
    while(jj >> hold){
      wordHolder.push_back(hold);
    }
    for(j = 0 ; j < wordHolder.size() ; j++){
      if(wordHolder[j] == keyWord){
        cnt++;
      }
    }
    if(cnt > max){ //max
      max = cnt;
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);
      }

    else if(cnt == max && cnt != 0){ //ties
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);

    }
    
    cnt=0;
    
  }

  int theCountHolder = countHolderThe.size() - 1;
  int theIndicesHolder = indicesHolderThe.back();
  
  int temp_max_the = 0;
  
  for(i = 0 ;i < indicesHolderThe.size() ; i++ ){
    if(countHolderThe.at(i) > temp_max_the){
      temp_max_the = countHolderThe.at(i);
    }
  }
  for(j = 0; j < countHolderThe.size(); j++){
      if(countHolderThe.at(j) == temp_max_the)
      {
        fout << keyWord <<":" <<countHolderThe.at(j)<<":"<<sentenceHolder.at(indicesHolderThe.at(j)) << endl;
      }
      else
      {
         fout << keyWord <<":" <<countHolderThe.at(theCountHolder)<<":"<<sentenceHolder.at(theIndicesHolder) << endl;
        break;
      }
    }
}

void maxFreqSentOf(vector<string> sentenceHolder, string keyWord,string name){
  ofstream fout;
  string output = name + "5" +".txt";
  
  fout.open(output);
  vector<int>indicesHolderThe;
  vector<int>countHolderThe;
  int i;
  int j; 
  int max = 0;
  int cnt;
  for(i = 0 ; i < sentenceHolder.size() ; i++){
    vector<string> wordHolder;
    string hold;
    stringstream jj(sentenceHolder[i]);
    
    while(jj >> hold){
      wordHolder.push_back(hold);
    }
    for(j = 0 ; j < wordHolder.size() ; j++){
      if(wordHolder[j] == keyWord){
        cnt++;
      }
    }
    if(cnt > max){ //max
      max = cnt;
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);

    }

    else if(cnt == max && cnt != 0){ //ties
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);

    }
    
    cnt=0;
    
  }

  int theCountHolder = countHolderThe.size() - 1;
  int theIndicesHolder = indicesHolderThe.back();
  
  int temp_max_the = 0;
  
  for(i = 0 ;i < indicesHolderThe.size() ; i++ ){
    if(countHolderThe.at(i) > temp_max_the){
      temp_max_the = countHolderThe.at(i);
    }
  }
  for(j = 0; j < countHolderThe.size(); j++){
      if(countHolderThe.at(j) == temp_max_the)
      {
        fout << keyWord <<":" <<countHolderThe.at(j)<<":"<<sentenceHolder.at(indicesHolderThe.at(j)) << endl;
      }
      else
      {
         fout << keyWord <<":" <<countHolderThe.at(theCountHolder)<<":"<<sentenceHolder.at(theIndicesHolder) << endl;
        break;
      }
    }
}

void maxFreqSentWas(vector<string> sentenceHolder, string keyWord,string name){
  ofstream fout;
  string output = name + "6" +".txt";
  fout.open(output);
  vector<int>indicesHolderThe;
  vector<int>countHolderThe;
  int i;
  int j; 
  int max = 0;
  int cnt;
  for(i = 0 ; i < sentenceHolder.size() ; i++){
    vector<string> wordHolder;
    string hold;
    stringstream jj(sentenceHolder[i]);
    
    while(jj >> hold){
      wordHolder.push_back(hold);
    }
    for(j = 0 ; j < wordHolder.size() ; j++){
      if(wordHolder[j] == keyWord){
        cnt++;
      }
    }
    if(cnt > max){ //max
      max = cnt;
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);

    }

    else if(cnt == max && cnt != 0){ //ties
      indicesHolderThe.push_back(i);
      countHolderThe.push_back(max);

    }
    
    cnt=0;
    
  }

  int theCountHolder = countHolderThe.size() - 1;
  int theIndicesHolder = indicesHolderThe.back();
  
  int temp_max_the = 0;
  
  for(i = 0 ;i < indicesHolderThe.size() ; i++ ){
    if(countHolderThe.at(i) > temp_max_the){
      temp_max_the = countHolderThe.at(i);
    }
  }
  for(j = 0; j < countHolderThe.size(); j++){
      if(countHolderThe.at(j) == temp_max_the)
      {
        fout << keyWord <<":" <<countHolderThe.at(j)<<":"<<sentenceHolder.at(indicesHolderThe.at(j)) << endl;
      }
      else
      {
         fout << keyWord <<":" <<countHolderThe.at(theCountHolder)<<":"<<sentenceHolder.at(theIndicesHolder) << endl;
        break;
      }
    }
}

void multipleWordMaxfreq7(vector<string> sentenceHolder,string keyWord,string name){
  ofstream fout;

  string output = name + "7" +".txt";
  
  fout.open(output);
  int i;
  int max_temp = 0;
  for(i = 0 ; i < sentenceHolder.size(); i++){
    if(sentenceHolder[i].find(keyWord) != string::npos){
      max_temp++;
      fout <<keyWord<<":"<<max_temp<<":" <<sentenceHolder[i] <<endl;
    }
    else{
      max_temp = 0;
    }
  }
}
void multipleWordMaxfreq8(vector<string> sentenceHolder,string keyWord,string name){
  ofstream fout;

  string output = name + "8" +".txt";
  
  fout.open(output);
  int i;
  int max_temp = 0;
  for(i = 0 ; i < sentenceHolder.size(); i++){
    if(sentenceHolder[i].find(keyWord) != string::npos){
      max_temp++;
      fout <<keyWord<<":"<<max_temp<<":" <<sentenceHolder[i] <<endl;
    }
    else{
      max_temp = 0;
    }
  }
}
void multipleWordMaxfreq9(vector<string> sentenceHolder,string keyWord,string name){
  ofstream fout;

  string output = name + "9" +".txt";
  
  fout.open(output);
  int i;
  int max_temp = 0;
  for(i = 0 ; i < sentenceHolder.size(); i++){
    if(sentenceHolder[i].find(keyWord) != string::npos){
      max_temp++;
      fout <<keyWord<<":"<<max_temp<<":" <<sentenceHolder[i] <<endl;
    }
    else{
      max_temp = 0;
    }
  }
}

int main(int argc, char* argv[]){
    ifstream fin;
    ofstream fout;
  
    int i;
    int j; 
    string words;
    vector<string> paragraph;
    
    string name = argv[2];

    fin.open(argv[1]); 
    fout.open(argv[2]);
    if(!fin.is_open()){
        cout << "file is not found" << endl;
    }
    else{
        while(!fin.eof()){
            getline(fin,words);
            paragraph.push_back(words);
          }
      }
    
  
    lower(paragraph);
    questionOne(paragraph, name);
    questionTwo(paragraph, name);
    
  
  vector<string>line; //holds the old vector
  vector<string>sentenceHolder;
  for(int i = 0; i< paragraph.size();i++){
    string store; //stores individual sentences
    line.push_back(paragraph[i]); //pushes paragraph into new vec
    stringstream tt(line[i]);
    while(getline(tt,store,'.')){
        store = regex_replace(store,regex("^ +| +$() +"),"$1"); //gets rid of spaces
        sentenceHolder.push_back(store);

    }
  }    
    
  
    maxFreqSentThe(sentenceHolder,"the",name);
    maxFreqSentOf(sentenceHolder,"of",name);
    maxFreqSentWas(sentenceHolder,"was",name);
  
    multipleWordMaxfreq7(sentenceHolder,"but the",name);
    multipleWordMaxfreq8(sentenceHolder,"it was",name);
    multipleWordMaxfreq9(sentenceHolder,"in my",name);

    return 0;
}