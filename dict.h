// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict {
private:
    // You can add attributes/helper functions here
    class TrieNode{
    public:
        int count;
        TrieNode* child[54]={nullptr};

        TrieNode(){
            count=0;
        }
        
        ~TrieNode(){
            for(int i=0;i<54;i++){
                if(child[i]!=nullptr){
                    delete child[i];
                    child[i]=nullptr;
                }
            }
        }
    };
    TrieNode* top;
    void dump_the_dictionary(ofstream& infile, string word, TrieNode* node);
const int positions[128]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,0,1,2,3,-1,-1,-1,4,5,-1,-1,-1,6,7,8,9,10,11,12,13,14,15,16,-1,-1,17,18,19,-1,-1,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,-1,46,-1,47,48,49,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,50,51,52,53,-2};
const char characters[54]={'#','$','%','&','*','+','/','0','1','2','3','4','5','6','7','8','9','<','=','>','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\\','^','_','`','{','|','}','~'};
public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};
