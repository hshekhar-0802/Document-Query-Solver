#include<bits/stdc++.h>
#include "Node.cpp"
//#include "qna_tool.h"
#include"qna_tool.cpp"
#include"search.cpp"

using namespace std;

int main(){

    QNA_tool qna_tool;

    int num_books;
    cout<<"Enter the number of books you want to insert: ";
    cin>>num_books;
    std::string filename;
    cout<<"Enter the general name of the books. (Your text files must be named serially starting from 1 and they must have the same string name till the integer. For example, \"Shakespeare-1\", \"Shakespeare-2\", etc.): ";
    cin>>filename;
    for(int i = 1; i <= num_books; i++){

        std::cout << "Inserting book " << i << std::endl;

        filename += to_string(i);
        filename += ".txt";

        std::ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to open the input file mahatma-gandhi." << std::endl;
            return 1;
        }

        std::string tuple;
        std::string sentence;


        while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
            // Get a line in the sentence
            tuple += ')';

            std::vector<int> metadata;    
            std::istringstream iss(tuple);

            // Temporary variables for parsing
            std::string token;

            // Ignore the first character (the opening parenthesis)
            iss.ignore(1);

            // Parse and convert the elements to integers
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
                    metadata.push_back(num);
                } else {
                    // Convert the element to integer
                    int num = std::stoi(token);
                    metadata.push_back(num);
                }
            }

            // Now we have the string in sentence
            // And the other info in metadata
            // Add to the dictionary

            // Insert in the qna_tool
            qna_tool.insert_sentence(metadata[0], metadata[1], metadata[2], metadata[3], sentence);
        }

        inputFile.close();

    }
    cout<<"Please enter your question: ";
    string question ;
    cin>>question;
    // long long mincount=10000000000000;
    // vector<string> topwords;
    // for(int i =0;i<qna_tool.S.D.table.size();i++){
    //     for(int j=0;j<qna_tool.S.D.table[i].size();j++){
    //         if(topwords.size()<10000){
    //             topwords.push_back(qna_tool.S.D.table[i][j].key);
    //             mincount =min(mincount,qna_tool.S.D.table[i][j].count);
    //         }
    //         else{

    //         }
    //     }
    // }
    /*
        Part-1 : Get the top-k paragraphs
        Checking Correctness
    */
    // string res = qna_tool.get_paragraph(6,1,1);
    // cout<<res<<endl;
    // res = qna_tool.get_paragraph(6,1,2);
    // cout<<res<<endl;
    // res = qna_tool.get_paragraph(6,1,3);
    // cout<<res<<endl;
    // Let's try to ask a simple question to the qna_tool
    // Node* head = qna_tool.query(question,"abcd");
    
    // vector<string> paras1;
    // while(head != nullptr){
    //     std::cout<<head->book_code<<endl;
        
    //     std::cout<<head->page<<endl;
    //     std::cout<<head->paragraph<<endl;
    //     string res = qna_tool.get_paragraph(head->book_code, head->page, head->paragraph);
    //     paras1.push_back(res);
    //     head = head->right;
    // }
    

    // for(int i = 0; i < (int)paras1.size(); i++){
    //     std::cout << paras1[i] << endl << endl << endl;
    // }

    /*
        Part-2 : Query the LLM
    */
    qna_tool.query(question, "bonus.py");
    
    return 0;
}