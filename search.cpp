// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine(){
    root  = new TreeNode();
}

SearchEngine::~SearchEngine(){
    // Implement your function here
    if(root!=nullptr){
        delete root;
        root = nullptr;
    }
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    TreeNode*temp = root;
    for(int i = 0; i<sentence.size(); i++){
        if(positions[sentence[i]]<0){
            continue;
        }
            if(temp->Child[positions[sentence[i]]]==nullptr){
                temp->Child[positions[sentence[i]]] = new TreeNode();
                if(i==sentence.size()-1||positions[sentence[i+1]]==-1){
                    vector<int> A = {book_code, page, paragraph, sentence_no, i};
                    temp->Child[positions[sentence[i]]]->Occurence_table.push_back(A);
                    
                    i++;
                    temp = root;}
                else{
                    temp = temp->Child[positions[sentence[i]]];
                }
               
            }
            else{
                
                if(i==sentence.size()-1||positions[sentence[i+1]]==-1){
                    vector<int> A = {book_code, page, paragraph, sentence_no, i};
                    temp->Child[positions[sentence[i]]]->Occurence_table.push_back(A);
                    
                    i++;
                    temp = root;}
                else{
                    temp = temp->Child[positions[sentence[i]]];
                }
                
            }
    }
    // Implement your function here
    return;
}

Node* SearchEngine::search(string pattern, int& n_matches){
    TreeNode*temp = root;
    if(pattern.size()==0){
        return nullptr;
    }
    for(char a:pattern){
        if(temp->Child[positions[a]]==nullptr){
            
            return nullptr;
        }
        else{
            temp = temp->Child[positions[a]];
            
        }
    }
    if(temp->Occurence_table.size()==0){
        return nullptr;
    }
    Node*head = new Node(temp->Occurence_table[0][0],temp->Occurence_table[0][1],temp->Occurence_table[0][2],temp->Occurence_table[0][3],temp->Occurence_table[0][4]-pattern.size()+1);
    Node*temp2 = head;
    for(int  i = 1; i<temp->Occurence_table.size(); i++){
        Node*A = new Node(temp->Occurence_table[i][0],temp->Occurence_table[i][1],temp->Occurence_table[i][2],temp->Occurence_table[i][3],temp->Occurence_table[i][4]-pattern.size()+1);
        temp2->right = A;
        A->left = temp2;
        temp2 = A;
    }
    n_matches  = temp->Occurence_table.size();
    temp2->right=nullptr;
    // Implement your function here
    return head;
}
