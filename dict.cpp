// Do NOT add any other includes
#include "dict.h"

Dict::Dict(){
    // Implement your function here
    top=new TrieNode();
}

Dict::~Dict(){
    // Implement your function here
     delete top;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    //Implement your function here
    TrieNode* pointer=top;
    bool sep=false;
    for(int i=0;i<sentence.length();i++){
        sep=false;
        char c=sentence[i];
        int idx=positions[int(c)];
        if(idx>=0){
            if(pointer->child[idx]==nullptr){
                pointer->child[idx]=new TrieNode();
            }
            pointer=pointer->child[idx];
        }
        else{
            sep=true;
            pointer->count++;
            pointer=top;
        }
    }
    if(!sep){
        pointer->count++;
        pointer=top;
    }
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here
    TrieNode* pointer=top;
    for(int i=0;i<word.length();i++){
        char c=word[i];
        int idx=positions[c];
        if(idx>=0){
            if(pointer->child[idx]==nullptr){
                return 0;
            }
            else{
                pointer=pointer->child[idx];
            }
        }
    }
    return pointer->count;
}

void Dict::dump_the_dictionary(ofstream& infile, string word, TrieNode* node){
    if(node==nullptr){
        return;
    }
    else{
        if(node->count>0){
            infile<<word<<", "<<node->count<<"\n";
        }
        for(int i=0;i<54;i++){
            string input=word+characters[i];
            dump_the_dictionary(infile,input,node->child[i]);
        }
    }
}

void Dict::dump_dictionary(string filename){
    // Implement your function here
    ofstream infile;
    string word="";
    infile.open(filename);
    dump_the_dictionary(infile, word, top);
    return;
}

// int main(){
//     Dict D;
//     D.insert_sentence(0,0,0,0,"I am a good boy.");
//     D.dump_dictionary("results.txt");
// }
