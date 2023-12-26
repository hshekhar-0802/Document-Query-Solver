// Do NOT add any other includes
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine {
private:
    // You can add attributes/helper functions here

public:
    
    class TreeNode{
    public:
        vector<vector<int>> Occurence_table;
        vector<TreeNode*> Child;
        TreeNode(){
            for(int i = 0;i<54;i++){
                Child.push_back(nullptr);
            }
    
        }
        ~TreeNode(){
            for(int i = 0; i<Child.size();i++){
                if(Child[i] != nullptr){
                    delete Child[i];
                    Child[i] = nullptr;
                }
            }
            Child.clear();
            Occurence_table.clear();
        }
        
    };
    TreeNode*root;
    const int positions[128]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,0,1,2,3,-1,-1,-1,4,5,-1,-1,-1,6,7,8,9,10,11,12,13,14,15,16,-1,-1,17,18,19,-1,-1,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,-1,46,-1,47,48,49,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,50,51,52,53,-2};
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};
