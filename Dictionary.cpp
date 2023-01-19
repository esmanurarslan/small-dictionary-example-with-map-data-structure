#include <iostream>
#include <map>
#include <string>

using namespace std;

class Dictionary{
    public:
    map<string,string> dictionary;
    void insertWord(string word,string meaning);
    void searchWord(string word);
    void listDictionary();
    void searchInterval(string word1,string word2);
    void eraseWord(string word);
    void updateMeaning(string word,string newMeaning);
    void countWords();
};

void Dictionary::insertWord(string word,string meaning){
    dictionary.insert({word,meaning});
}

void Dictionary::searchWord(string word){
    if(dictionary.find(word)->first==word){
        cout<<"--------------------------"<<endl;
        cout<<word<<" found"<<endl;
    }else{
        cout<<"--------------------------"<<endl;
        cout<<word<<" not found"<<endl; 
    };   
}

void Dictionary::listDictionary(){
    cout<<"******************************************"<<endl;
    if(!dictionary.empty()){
        for(std::map<string,string>::iterator it=dictionary.begin(); it!=dictionary.end(); it++){
        cout<<it->first<<" : "<<it->second<<'\n';}
        }else{
        cout<<"no words in the dictionary"<<endl;
    }
}

void Dictionary::searchInterval(string word1,string word2){
    cout<<"******************************************"<<endl;
    for(std::map<string,string>::iterator it=dictionary.begin(); it!=dictionary.end(); it++){
      if(it->first==word1){
        cout<<it->first<<" : "<<it->second<<'\n';
      }
      it++;
      word1=it->first;
      it--;
      if(it->first==word2){
        break;
      }
    }
}

void Dictionary::eraseWord(string word){
    if(dictionary.find(word)->first==word){
        dictionary.erase(word); 
    }else{
        cout<<"--------------------------"<<endl;
        cout<<"there is no such word in the dictionary"<<endl;
    }}
           
        

void  Dictionary::updateMeaning(string word,string newMeaning){
    dictionary[word]=newMeaning;
}

void Dictionary::countWords(){
   if(!dictionary.empty()){
    cout<<"dictionary has "<<dictionary.size()<<" words"<<endl;
    }else{
        cout<<"Dictionary is empty"<<endl;
    }
}

int main(){
    Dictionary newDictionary;
    newDictionary.insertWord("apple","elma");
    newDictionary.insertWord("orange","portakal");
    newDictionary.insertWord("banana","muz");
    newDictionary.insertWord("strawberry","çilek");
    newDictionary.insertWord("universal","evrensel");
    newDictionary.insertWord("watermelon","karpuz");
    newDictionary.insertWord("school","okul");
    newDictionary.insertWord("flower","çiçek");
    newDictionary.insertWord("computer","bilgisayar");
    newDictionary.insertWord("torch","meşale");
    newDictionary.searchWord("flower");
    newDictionary.searchWord("pink");
    newDictionary.listDictionary();
    newDictionary.eraseWord("bell");
    newDictionary.updateMeaning("orange","turuncu");
    newDictionary.listDictionary();
    newDictionary.countWords();
    newDictionary.searchInterval("banana","school");
    return 0;
}
