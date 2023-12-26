#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include "dict.h"
#include "search.h"

using namespace std;

class QNA_tool {

private:

    // You are free to change the implementation of this function
    void query_llm(string filename, Node* root, int k, string API_KEY, string question);
    // filename is the python file which will call ChatGPT API
    // root is the head of the linked list of paragraphs
    // k is the number of paragraphs (or the number of nodes in linked list)
    // API_KEY is the API key for ChatGPT
    // question is the question asked by the user

    // You can add attributes/helper functions here

public:
    SearchEngine *Word_Finder;
    class ParaNode{
    public:
        double score;
        int book;
        int page;
        int para;
        ParaNode(int _book, int  _page, int _para, double _score){
            book = _book;
            page = _page;
            para  = _para;
            score = _score;
        }
    };
    class SentenceNode{
    public:
        double score;
        int book;
        int page;
        int para;
        int sentence;
        SentenceNode(int _book, int  _page, int _para, int _sentence, double _score){
            book = _book;
            page = _page;
            para  = _para;
            score = _score;
            sentence = _sentence;
        }
    };
    class OccNode{
    public:
        long long count;
        vector<OccNode*> Child;
        OccNode(){
            for(int i = 0;i<54;i++){
                Child.push_back(nullptr);
            }
    
        }
        ~OccNode(){
            for(int i = 0; i<Child.size();i++){
                if(Child[i] != nullptr){
                    delete Child[i];
                    Child[i] = nullptr;
                }
            }
            Child.clear();
        }
        
    };
    OccNode*Occroot;
    int max_books = 0;
    int max_pages = 0;
    int max_para = 0;
    int max_sentence = 0;
    const int positions[128]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,0,1,2,3,-1,-1,-1,4,5,-1,-1,-1,6,7,8,9,10,11,12,13,14,15,16,-1,-1,17,18,19,-1,-1,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,-1,46,-1,47,48,49,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,50,51,52,53,-2};
    const char characters[54]={'#','$','%','&','*','+','/','0','1','2','3','4','5','6','7','8','9','<','=','>','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\\','^','_','`','{','|','}','~'};
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    const vector<std::string> fillerWords = {"s","mahatma",
            "the", "and", "but", "or", "for", "nor", "so", "yet",
            "a", "an", "is", "am", "are", "was", "were", "be", "being", "been",
            "I", "you", "he", "she", "it", "we", "they", "me", "him", "her", "us", "them",
            "this", "that", "these", "those", "here", "there", "where",
            "of", "in", "on", "at", "by", "with", "about", "against", "between", "into", "through", "during",
            "to", "from", "up", "down", "out", "over", "under", "above", "below",
            "when", "while", "before", "after", "since", "until", "as", "because", "although", "though", "if", "unless", "until",
            "such", "so", "as", "too", "enough",
            "not", "no", "none", "neither", "nor", "nothing", "nobody", "nowhere",
            "with", "without", "within", "outside", "beyond",
            "any", "some", "every", "all", "most", "few", "several", "many", "much", "little", "more", "less",
            "what", "which", "who", "whom", "whose","how",
            "whereas", "while",
            "also", "either", "neither", "whether"
        };
    QNA_tool(); // Constructor
    ~QNA_tool(); // Destructor

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    // This function is similar to the functions in dict and search
    // The corpus will be provided to you via this function
    // It will be called for each sentence in the corpus

    Node* get_top_k_para(string question, int k);
    // This function takes in a question, preprocess it
    // And returns a list of paragraphs which contain the question
    // In each Node, you must set: book_code, page, paragraph (other parameters won't be checked)

    std::string get_paragraph(int book_code, int page, int paragraph);
    // Given the book_code, page number, and the paragraph number, returns the string paragraph.
    // Searches through the corpus.

    void query(string question, string filename);
    // This function takes in a question and a filename.
    // It should write the final answer to the specified filename.

    /* -----------------------------------------*/
    /* Please do not touch the code above this line */

    // You can add attributes/helper functions here
};
			
