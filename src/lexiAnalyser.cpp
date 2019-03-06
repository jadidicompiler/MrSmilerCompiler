
/*
    this file contains the first
    phase of the compiler which is
    lexical analyser or scanner


    note:
        this code is using 
        a combination of 
        google code style
        and MrSmiler preference
*/



#include <iostream>
#include <string>
#include <fstream>

// first phase of the compiler

int main(){
    
    std::fstream file;

    // open a file for reading the programming language text
    file.open("language.txt", std::fstream::in);
    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    // making buffer
    char *text = new char[length];

    file.read(text, length);
    

    file.close();

    return 0;
}

// this class holds token information
// like <token_type, token_postion>
class Token{
    
    private:
        std::string token_type_;
        int token_pos_;


    public:
        
        Token(std::string token_type, int token_pos){
            this->token_type_ = token_type; 
            this->token_pos_ = token_pos; 
        }

        // void setTokenName(std::string name){this->token_name_ = name;}
        std::string getTokenType(){return this->token_type_;}

        std::string getTokenPos(){return this->token_pos_;}

}


// first phase of compiler
class LexicalAnalyser {

    private: 
        // programming language text
        std::string text; 
        int state;
        int forward;

        int nextChar(){
        
        }



    public:

        LexicalAnalyser(char* fileContent) {
            this->text = fileContent; 
            this->state = 0;
            this->forward = 0;
        }

        // scan the file
        void scan();


};

void LexicalAnalyser::scan(){

    while(this->nextChar()){

        switch(this->state){
        
        }
    } 
    
}



