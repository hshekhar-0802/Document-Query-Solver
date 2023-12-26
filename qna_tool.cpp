#include <assert.h>
#include <sstream>
#include "qna_tool.h"
// #include "minheap.h"

using namespace std;
class HeapNode{
  public:
  double val;
    int bookcode;
    int page;
    int para;
    int sentsence_no;
  HeapNode* par;
  HeapNode* left;
  HeapNode* right;
  
    HeapNode(){
        par = nullptr;
        left = nullptr;
        right = nullptr;
    };
    HeapNode(double _val, int _book, int _page, int _para, int _sentence){
        par = nullptr;
        left = nullptr;
        right = nullptr;
        val = _val;
        bookcode = _book;
        page = _page;
        para = _para;
        sentsence_no = _sentence;
    };
  
    ~HeapNode(){
        if(left!=nullptr){
            delete left;
        }
        if(right!=nullptr){
            delete right;
        }
    };
};

class MinHeap{
  private:
  
  
  
  public:
    int size;
    HeapNode* root;
    MinHeap(){
        size = 0;
        root = nullptr;
    }
    ~MinHeap(){
        delete root;
    }

    void push_heap(QNA_tool::ParaNode* p){
        if(size == 0){
            root = new HeapNode(p->score,p->book,p->page,p->para,1);
            size++;
        }
        else if(size==1){
            root->left = new HeapNode(p->score,p->book,p->page,p->para,1);
            size++;
            root->left->par = root;
            if(root->val>root->left->val){
                double tempval = root->val ;
                int tempbook = root->bookcode;
                int temppage = root->page;
                int temppara = root->para;
                int tempsentence = root->sentsence_no;
                root->val = root->left->val;
                root->page = root->left->page;
                root->bookcode = root->left->bookcode;
                root->para = root->left->para;
                root->sentsence_no = root->left->sentsence_no;
                root->left->val = tempval;
                root->left->page = temppage;
                root->left->bookcode = tempbook;
                root->left->para = temppara;
                root->left->sentsence_no = tempsentence;
            }
        
        }
        else if(size==2){
            root->right = new HeapNode(p->score,p->book,p->page,p->para,1);
            size++;
            root->right->par = root;
            if(root->val>root->right->val){
                double tempval = root->val ;
                int tempbook = root->bookcode;
                int temppage = root->page;
                int temppara = root->para;
                int tempsentence = root->sentsence_no;
                root->val = root->right->val;
                root->page = root->right->page;
                root->bookcode = root->right->bookcode;
                root->para = root->right->para;
                root->sentsence_no = root->right->sentsence_no;
                root->right->val = tempval;
                root->right->page = temppage;
                root->right->bookcode = tempbook;
                root->right->para = temppara;
                root->right->sentsence_no = tempsentence;        }
        }
        else{
            
            int h = 0;
            int sz = size+1;
            while(sz!=0){
                sz /=2;
                h++;
            }
            sz = size+1;
            int bin[h];
            int i = 0;
            while(i!=h-1){
                bin[i] = sz%2;
                sz /=2;
                i++;
            }
            i--;
            HeapNode*last = root;
            while(i!=0){
                if(bin[i]==0){
                    last = last->left;
                    i--;
                }
                else{
                    last = last->right;
                    i--;
                }
            }
            if(bin[0] == 0){
                
                last->left = new HeapNode(p->score,p->book,p->page,p->para,1);
                last->left->par = last;
                size++;
                if(last->val>last->left->val){
                    double tempval = last->val ;
                    int tempbook = last->bookcode;
                    int temppage = last->page;
                    int temppara = last->para;
                    int tempsentence = last->sentsence_no;
                    last->val = last->left->val;
                    last->page = last->left->page;
                    last->bookcode = last->left->bookcode;
                    last->para = last->left->para;
                    last->sentsence_no = last->left->sentsence_no;
                    last->left->val = tempval;
                    last->left->page = temppage;
                    last->left->bookcode = tempbook;
                    last->left->para = temppara;
                    last->left->sentsence_no = tempsentence;
                    
                    while(last->par!=nullptr){
                        if(last->par->val>last->val){
                            double tempval = last->val ;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->par->val;
                            last->page = last->par->page;
                            last->bookcode = last->par->bookcode;
                            last->para = last->par->para;
                            last->sentsence_no = last->par->sentsence_no;
                            last->par->val = tempval;
                            last->par->page = temppage;
                            last->par->bookcode = tempbook;
                            last->par->para = temppara;
                            last->par->sentsence_no = tempsentence;
                            last = last->par;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else{
                
                last->right = new HeapNode(p->score,p->book,p->page,p->para,1);
                last->right->par = last;
                size++;
                if(last->val>last->right->val){
                    double tempval = last->val ;
                    int tempbook = last->bookcode;
                    int temppage = last->page;
                    int temppara = last->para;
                    int tempsentence = last->sentsence_no;
                    last->val = last->right->val;
                    last->page = last->right->page;
                    last->bookcode = last->right->bookcode;
                    last->para = last->right->para;
                    last->sentsence_no = last->right->sentsence_no;
                    last->right->val = tempval;
                    last->right->page = temppage;
                    last->right->bookcode = tempbook;
                    last->right->para = temppara;
                    last->right->sentsence_no = tempsentence;
                    
                    while(last->par!=nullptr){
                        if(last->par->val>last->val){
                            double tempval = last->val ;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->par->val;
                            last->page = last->par->page;
                            last->bookcode = last->par->bookcode;
                            last->para = last->par->para;
                            last->sentsence_no = last->par->sentsence_no;
                            last->par->val = tempval;
                            last->par->page = temppage;
                            last->par->bookcode = tempbook;
                            last->par->para = temppara;
                            last->par->sentsence_no = tempsentence;
                            last  = last->par;
                        }
                        else{
                            break;
                        }
                    }
                }
                
                
            }
        }
    } // Insert num into the heap
    void push_heap(QNA_tool::SentenceNode* s){
        if(size == 0){
            root = new HeapNode(s->score,s->book,s->page,s->para,s->sentence);
            size++;
        }
        else if(size==1){
            root->left = new HeapNode(s->score,s->book,s->page,s->para,s->sentence);
            size++;
            root->left->par = root;
            if(root->val>root->left->val){
                double tempval = root->val ;
                int tempbook = root->bookcode;
                int temppage = root->page;
                int temppara = root->para;
                int tempsentence = root->sentsence_no;
                root->val = root->left->val;
                root->page = root->left->page;
                root->bookcode = root->left->bookcode;
                root->para = root->left->para;
                root->sentsence_no = root->left->sentsence_no;
                root->left->val = tempval;
                root->left->page = temppage;
                root->left->bookcode = tempbook;
                root->left->para = temppara;
                root->left->sentsence_no = tempsentence;
            }
        
        }
        else if(size==2){
            root->right = new HeapNode(s->score,s->book,s->page,s->para,s->sentence);
            size++;
            root->right->par = root;
            if(root->val>root->right->val){
                double tempval = root->val ;
                int tempbook = root->bookcode;
                int temppage = root->page;
                int temppara = root->para;
                int tempsentence = root->sentsence_no;
                root->val = root->right->val;
                root->page = root->right->page;
                root->bookcode = root->right->bookcode;
                root->para = root->right->para;
                root->sentsence_no = root->right->sentsence_no;
                root->right->val = tempval;
                root->right->page = temppage;
                root->right->bookcode = tempbook;
                root->right->para = temppara;
                root->right->sentsence_no = tempsentence;        }
        }
        else{
            
            int h = 0;
            int sz = size+1;
            while(sz!=0){
                sz /=2;
                h++;
            }
            sz = size+1;
            int bin[h];
            int i = 0;
            while(i!=h-1){
                bin[i] = sz%2;
                sz /=2;
                i++;
            }
            i--;
            HeapNode*last = root;
            while(i!=0){
                if(bin[i]==0){
                    last = last->left;
                    i--;
                }
                else{
                    last = last->right;
                    i--;
                }
            }
            if(bin[0] == 0){
                
                last->left = new HeapNode(s->score,s->book,s->page,s->para,s->sentence);
                last->left->par = last;
                size++;
                if(last->val>last->left->val){
                    double tempval = last->val ;
                    int tempbook = last->bookcode;
                    int temppage = last->page;
                    int temppara = last->para;
                    int tempsentence = last->sentsence_no;
                    last->val = last->left->val;
                    last->page = last->left->page;
                    last->bookcode = last->left->bookcode;
                    last->para = last->left->para;
                    last->sentsence_no = last->left->sentsence_no;
                    last->left->val = tempval;
                    last->left->page = temppage;
                    last->left->bookcode = tempbook;
                    last->left->para = temppara;
                    last->left->sentsence_no = tempsentence;
                    
                    while(last->par!=nullptr){
                        if(last->par->val>last->val){
                            double tempval = last->val ;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->par->val;
                            last->page = last->par->page;
                            last->bookcode = last->par->bookcode;
                            last->para = last->par->para;
                            last->sentsence_no = last->par->sentsence_no;
                            last->par->val = tempval;
                            last->par->page = temppage;
                            last->par->bookcode = tempbook;
                            last->par->para = temppara;
                            last->par->sentsence_no = tempsentence;
                            last = last->par;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else{
                
                last->right = new HeapNode(s->score,s->book,s->page,s->para,s->sentence);
                last->right->par = last;
                size++;
                if(last->val>last->right->val){
                    double tempval = last->val ;
                    int tempbook = last->bookcode;
                    int temppage = last->page;
                    int temppara = last->para;
                    int tempsentence = last->sentsence_no;
                    last->val = last->right->val;
                    last->page = last->right->page;
                    last->bookcode = last->right->bookcode;
                    last->para = last->right->para;
                    last->sentsence_no = last->right->sentsence_no;
                    last->right->val = tempval;
                    last->right->page = temppage;
                    last->right->bookcode = tempbook;
                    last->right->para = temppara;
                    last->right->sentsence_no = tempsentence;
                    
                    while(last->par!=nullptr){
                        if(last->par->val>last->val){
                            double tempval = last->val ;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->par->val;
                            last->page = last->par->page;
                            last->bookcode = last->par->bookcode;
                            last->para = last->par->para;
                            last->sentsence_no = last->par->sentsence_no;
                            last->par->val = tempval;
                            last->par->page = temppage;
                            last->par->bookcode = tempbook;
                            last->par->para = temppara;
                            last->par->sentsence_no = tempsentence;
                            last  = last->par;
                        }
                        else{
                            break;
                        }
                    }
                }
                
                
            }
        }
    }
    double get_min(){
        return root->val;
    } // Returns min of the heap (which must be at root)
    void pop(){
        if(size==1){
            delete root;
            root = nullptr;
            size--;
        }
        else if(size==2){
            root->val = root->left->val;
            root->page = root->left->page;
            root->bookcode = root->left->bookcode;
            root->para = root->left->para;
            root->sentsence_no = root->left->sentsence_no;
            delete root->left;
            root->left = nullptr;
            size--;
        }
        else if(size==3){
            if(root->left->val<root->right->val){
                root->val = root->left->val;
                root->page = root->left->page;
                root->bookcode = root->left->bookcode;
                root->para = root->left->para;
                root->sentsence_no = root->left->sentsence_no;
                root->left->val = root->right->val;
                root->left->page=root->right->page;
                root->left->bookcode=root->right->bookcode;
                root->left->sentsence_no=root->right->sentsence_no;
                root->left->para=root->right->para;

                delete root->right;
                root->right = nullptr;
                size--;
            }
            else{
                root->val = root->right->val;
                root->page = root->right->page;
                root->bookcode = root->right->bookcode;
                root->para = root->right->para;
                root->sentsence_no = root->right->sentsence_no;
                delete root->right;
                root->right = nullptr;
                size--;
            }
            
        }
        else{
            int h = 0;
            int sz = size;
            while(sz!=0){
                sz /=2;
                h++;
            }
            sz = size;
            int bin[h];
            int i = 0;
            while(i!=h-1){
                bin[i] = sz%2;
                sz /= 2;
                i++;
            }
            i--;
            HeapNode*last = root;
            if(i == 0){
                
            }
            while(i!=0){
                if(bin[i]==0){
                    last = last->left;
                    i--;
                }
                else{
                    last = last->right;
                    i--;
                }
            }
            if(bin[0]==0){
                root->val = last->left->val;
                root->page = last->left->page;
                root->bookcode = last->left->bookcode;
                root->para = last->left->para;
                root->sentsence_no = last->left->sentsence_no;
                delete last->left;
                size--;
                last->left = nullptr;
            }
            else{
                root->val = last->right->val;
                root->page = last->right->page;
                root->bookcode = last->right->bookcode;
                root->para = last->right->para;
                root->sentsence_no = last->right->sentsence_no;
                delete last->right;
                size--;
                last->right = nullptr;
            }
            last = root;
            while(true){
                
                if(last->left==nullptr&&last->right==nullptr){
                    break;
                }
                else if(last->right==nullptr){
                    if(last->left->val<last->val){
                        double tempval = last->val ;
                        int tempbook = last->bookcode;
                        int temppage = last->page;
                        int temppara = last->para;
                        int tempsentence = last->sentsence_no;
                        last->val = last->left->val;
                        last->page = last->left->page;
                        last->bookcode = last->left->bookcode;
                        last->para = last->left->para;
                        last->sentsence_no = last->left->sentsence_no;
                        last->left->val = tempval;
                        last->left->page = temppage;
                        last->left->bookcode = tempbook;
                        last->left->para = temppara;
                        last->left->sentsence_no = tempsentence;
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(last->left->val<last->val&&last->right->val<last->val){
                        if(last->left->val<last->right->val){
                            double temp = last->val;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->left->val;
                            last->page = last->left->page;
                            last->bookcode = last->left->bookcode;
                            last->para = last->left->para;
                            last->sentsence_no = last->left->sentsence_no;
                            last->left->val = temp;
                            last->left->page = temppage;
                            last->left->bookcode = tempbook;
                            last->left->para = temppara;
                            last->left->sentsence_no = tempsentence;
                            last= last->left;
                        }
                        else{
                            double temp = last->val;
                            int tempbook = last->bookcode;
                            int temppage = last->page;
                            int temppara = last->para;
                            int tempsentence = last->sentsence_no;
                            last->val = last->right->val;
                            last->page = last->right->page;
                            last->bookcode = last->right->bookcode;
                            last->para = last->right->para;
                            last->sentsence_no = last->right->sentsence_no;
                            last->right->val = temp;
                            last->right->page = temppage;
                            last->right->bookcode = tempbook;
                            last->right->para = temppara;
                            last->right->sentsence_no = tempsentence;
                            last = last->right;
                        }
                    }
                    else if (last->left->val<last->val){
                        double temp = last->val;
                        int tempbook = last->bookcode;
                        int temppage = last->page;
                        int temppara = last->para;
                        int tempsentence = last->sentsence_no;
                        last->val = last->left->val;
                        last->page = last->left->page;
                        last->bookcode = last->left->bookcode;
                        last->para = last->left->para;
                        last->sentsence_no = last->left->sentsence_no;
                        last->left->val = temp;
                        last->left->page = temppage;
                        last->left->bookcode = tempbook;
                        last->left->para = temppara;
                        last->left->sentsence_no = tempsentence;
                        last  = last->left;
                    }
                    else if (last->right->val<last->val){
                        double temp = last->val;
                        int tempbook = last->bookcode;
                        int temppage = last->page;
                        int temppara = last->para;
                        int tempsentence = last->sentsence_no;
                        last->val = last->right->val;
                        last->page = last->right->page;
                        last->bookcode = last->right->bookcode;
                        last->para = last->right->para;
                        last->sentsence_no = last->right->sentsence_no;
                        last->right->val = temp;
                        last->right->page = temppage;
                        last->right->bookcode = tempbook;
                        last->right->para = temppara;
                        last->right->sentsence_no = tempsentence;
                        last = last->right;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    } // Deletes the min element from the heap
};


QNA_tool::QNA_tool(){
    Word_Finder = new SearchEngine();
    Occroot = new OccNode();
    int count=0;
        std::ifstream inputFile("unigram_freq.csv");
        // Check if the file is open
        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to open the input file."<< std::endl;
        }
    std::string line;
    while (std::getline(inputFile, line)) {
        // Use a string stream to split the line into fields
        std::istringstream line1(line);
        std::string word;
        std::vector<std::string> table;
        
        while (std::getline(line1, word, ',')) {
            table.push_back(word);
        }
        word  = table[0];
        
        OccNode*temp = Occroot;
        if(count>0){
            long long occ = stoll(table[1]);
            for(int a = 0; a<word.size(); a++){
                if(temp->Child[positions[word[a]]]==nullptr){
                    temp->Child[positions[word[a]]] = new OccNode();
                    temp = temp->Child[positions[word[a]]];
                }
                else{
                    temp = temp->Child[positions[word[a]]];
                }
                if (a==word.size()-1){
                    temp->count = occ;
                }
                
            }
            
            
            
        }
        count++;}
    // Implement your function here
}

QNA_tool::~QNA_tool(){
    if(Word_Finder!=nullptr){
        delete Word_Finder;
        Word_Finder = nullptr;
    }
    // Implement your function here
}

void QNA_tool::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    Word_Finder->insert_sentence(book_code, page, paragraph, sentence_no, sentence);
    if(book_code>max_books){
        max_books = book_code;
    }
    if(page>max_pages){
        max_pages = page;
    }
    if(paragraph>max_para){
        max_para = paragraph;
    }
    if(sentence_no>max_sentence){
        max_sentence = sentence_no;
    }
}

Node* QNA_tool::get_top_k_para(string question, int k) {
    vector<vector<vector<ParaNode*>>> visitedpara;
    vector<ParaNode*> final_paras;
    for(int i = 0; i<max_books+1; i++){
        vector<vector<ParaNode*>>A;
        for (int j = 0; j<max_pages+1; j++) {
            vector<ParaNode*>B;
            for(int l = 0; l<max_para+1; l++){
                B.push_back(nullptr);
            }
            A.push_back(B);
        }
        visitedpara.push_back(A);
    }
    vector<string>words;
    string A = "";
    for(int i = 0; i<question.size(); i++){
        if(positions[question[i]]==-1){
            words.push_back(A);
            A = "";
        }
        else{
            A+=question[i];
        }
    }
    if(A!=""){
        words.push_back(A);
    }
    for(string word:words){
        int no_of_occ_my = 0;
        long long no_of_occ_their = 0;
        OccNode*temp = Occroot;
        for(char c:word){
            if(temp->Child[positions[c]]==nullptr){
                no_of_occ_their = 1;
            }
            else{
                temp = temp->Child[positions[c]];
            }
        }
        if( no_of_occ_their != 1){
            no_of_occ_their = temp->count+1;
        }
        
        Node*word_list = Word_Finder->search(word, no_of_occ_my);
        
        double score = (double(no_of_occ_my)+1)/double(no_of_occ_their);
        
        while(word_list!=nullptr){
            if(visitedpara[word_list->book_code][word_list->page][word_list->paragraph]==nullptr){
                visitedpara[word_list->book_code][word_list->page][word_list->paragraph] = new ParaNode(word_list->book_code,word_list->page,word_list->paragraph,score);
                
                final_paras.push_back(visitedpara[word_list->book_code][word_list->page][word_list->paragraph]);
                
                word_list = word_list->right;
                
            }
            else{
                visitedpara[word_list->book_code][word_list->page][word_list->paragraph]->score+=score;
                
                word_list = word_list->right;
            }
        }
    }
    if(k>final_paras.size()){
        k = final_paras.size()-1;
    }
    
        MinHeap topK;
        for(int i=0;i<k;i++){
            topK.push_heap(final_paras[i]);
            
            
        }
        for(int i = k; i<final_paras.size();i++){
            if(topK.get_min()<final_paras[i]->score){
                topK.pop();
                topK.push_heap(final_paras[i]);
            }
        }
        for(int i = 0; i< final_paras.size(); i++){
            delete final_paras[i];
            final_paras[i] = nullptr;
        }
        final_paras.clear();
        visitedpara.clear();
    Node*tempprev = nullptr;
        Node*temp = nullptr;
    Node*tempnext = nullptr;
    int h  = topK.size;
        for(int i = 0; i< h; i++){
            temp = new Node(topK.root->bookcode,topK.root->page,topK.root->para,1,0);
            
            topK.pop();
            
            temp->left = tempnext;
            temp->right = tempprev;
            tempprev = temp;
            temp  = tempnext;
            tempnext = nullptr;
        }
        return tempprev;
    }

void QNA_tool::query(string question, string filename){
     vector<vector<vector<ParaNode*>>> visitedpara;
    vector<ParaNode*> final_paras;
    int k = 10;
    for(int i = 0; i<max_books+1; i++){
        vector<vector<ParaNode*>>A;
        for (int j = 0; j<max_pages+1; j++) {
            vector<ParaNode*>B;
            for(int l = 0; l<max_para+1; l++){
                B.push_back(nullptr);
            }
            A.push_back(B);
        }
        visitedpara.push_back(A);
    }
    vector<string>words;
    string A = "";
    for(int i = 0; i<question.size(); i++){
        if(positions[question[i]]==-1){
            words.push_back(A);
            A = "";
        }
        else{
            A+=question[i];
        }
    }
    if(A!=""){
        words.push_back(A);
    }
    for(string word:words){
        int no_of_occ_my = 0;
        long long no_of_occ_their = 0;
        OccNode*temp = Occroot;
        for(char c:word){
            if(temp->Child[positions[c]]==nullptr){
                no_of_occ_their = 1;
            }
            else{
                temp = temp->Child[positions[c]];
            }
        }
        if( no_of_occ_their != 1){
            no_of_occ_their = temp->count+1;
        }
        
        Node*word_list = Word_Finder->search(word, no_of_occ_my);
        
        double score = double(1/((double(no_of_occ_my)+1)*(double(no_of_occ_my)+1)))*100000;
        
        while(word_list!=nullptr){
            if(visitedpara[word_list->book_code][word_list->page][word_list->paragraph]==nullptr){
                visitedpara[word_list->book_code][word_list->page][word_list->paragraph] = new ParaNode(word_list->book_code,word_list->page,word_list->paragraph,score);
                
                final_paras.push_back(visitedpara[word_list->book_code][word_list->page][word_list->paragraph]);
                
                word_list = word_list->right;
                
            }
            else{
                visitedpara[word_list->book_code][word_list->page][word_list->paragraph]->score+=score;
                
                word_list = word_list->right;
            }
        }
    }
    if(k>final_paras.size()){
        k = final_paras.size()-1;
    }
    
        MinHeap topK;
        for(int i=0;i<k;i++){
            topK.push_heap(final_paras[i]);
            
            
        }
        for(int i = k; i<final_paras.size();i++){
            if(topK.get_min()<final_paras[i]->score){
                topK.pop();
                topK.push_heap(final_paras[i]);
            }
        }
        for(int i = 0; i< final_paras.size(); i++){
            delete final_paras[i];
            final_paras[i] = nullptr;
        }
        final_paras.clear();
        visitedpara.clear();
    Node*tempprev = nullptr;
        Node*temp = nullptr;
    Node*tempnext = nullptr;
    int h  = topK.size;
        for(int i = 0; i< h; i++){
            temp = new Node(topK.root->bookcode,topK.root->page,topK.root->para,1,0);
            
            topK.pop();
            
            temp->left = tempnext;
            temp->right = tempprev;
            tempprev = temp;
            temp  = tempnext;
            tempnext = nullptr;
        }

 
    // for(int i = 0; i<words.size(); i++){
    //     A = words[i]+" ";
    // }
    // cout<<"hulsls"<<endl;
    // temp = get_top_k_para(question, 5);
    // Node*temp2 = temp->right->right->right->right;
    // temp2->right = tempprev;
    // return temp;
     

    query_llm(filename, tempprev, 10, "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",question);
//    return temp->right;
}

std::string QNA_tool::get_paragraph(int book_code, int page, int paragraph){

    cout << "Book_code: " << book_code << " Page: " << page << " Paragraph: " << paragraph << endl;
    
    std::string filename = "mahatma-gandhi-collected-works-volume-";
    filename += to_string(book_code);
    filename += ".txt";

    std::ifstream inputFile(filename);

    std::string tuple;
    std::string sentence;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file " << filename << "." << std::endl;
        exit(1);
    }

    std::string res = "";

    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
        // Get a line in the sentence
        tuple += ')';

        int metadata[5];
        std::istringstream iss(tuple);

        // Temporary variables for parsing
        std::string token;

        // Ignore the first character (the opening parenthesis)
        iss.ignore(1);

        // Parse and convert the elements to integers
        int idx = 0;
        while (std::getline(iss, token, ',')) {
            // Trim leading and trailing white spaces
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                token = token.substr(start, end - start + 1);
            }
            
            // Check if the element is a number or a string
            if (token[0] == '\'') {
                // Remove the single quotes and convert to integer
                int num = std::stoi(token.substr(1, token.length() - 2));
                metadata[idx] = num;
            } else {
                // Convert the element to integer
                int num = std::stoi(token);
                metadata[idx] = num;
            }
            idx++;
        }

        if(
            (metadata[0] == book_code) &&
            (metadata[1] == page) &&
            (metadata[2] == paragraph)
        ){
            res += sentence;
        }
    }

    inputFile.close();
    return res;
}

void QNA_tool::query_llm(string filename, Node* root, int k, string API_KEY, string question){

    // first write the k paragraphs into different files

    Node* traverse = root;
    int num_paragraph = 0;
 

    while(num_paragraph < k){
        assert(traverse != nullptr);
        string p_file = "paragraph_";
        p_file += to_string(num_paragraph);
        p_file += ".txt";
        // delete the file if it exists
        remove(p_file.c_str());
        ofstream outfile(p_file);
        string paragraph = get_paragraph(traverse->book_code, traverse->page, traverse->paragraph);
        assert(paragraph != "$I$N$V$A$L$I$D$");
        outfile << paragraph;
        outfile.close();
        traverse = traverse->right;
        num_paragraph++;
    }

    // write the query to query.txt
    ofstream outfile("query.txt");
    outfile << "These are the excerpts from Mahatma Gandhi's books.\nOn the basis of this, ";
    outfile << question;
    // You can add anything here - show all your creativity and skills of using ChatGPT
    outfile.close();

    // you do not need to necessarily provide k paragraphs - can configure yourself

    // python3 <filename> API_KEY num_paragraphs query.txt
    string command = "python3 ";
    command += filename;
    command += " ";
    command += API_KEY;
    command += " ";
    command += to_string(k);
    command += " ";
    command += "query.txt";

    system(command.c_str());
    return;
}
