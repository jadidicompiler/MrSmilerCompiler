
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
#include <vector>

std::string createString(int, int, std::string);
bool isAlpha(char);
bool isNumber(char);

class LexicalAnalyser;

template <class T>
class Token;

int main(){
    
    std::fstream file;

    // open a file for reading the programming language text
    file.open("language.txt", std::fstream::in);
    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    // making a buffer
    char *text = new char[length];

    file.read(text, length);
    file.close();
    
    LexicalAnalyser lexi(text);
    lexi.scan();
    lexi.printTokens();
    

    return 0;
}

// this class holds token information
// like <token_type, token_postion>

template <class T> 
class Token{
    
    private:
        std::string token_type_;
        T token_value_;


    public:
        
        Token(std::string token_type, T token_value){
            this->token_type_ = token_type; 
            this->token_value_ = token_value; 
        }

        // void setTokenName(std::string name){this->token_name_ = name;}
        std::string getTokenType(){return this->token_type_;}
        std::string getTokenPos(){return this->token_value_;}

};


// first phase of compiler
class LexicalAnalyser {

    private: 
        // programming language text
        std::string text; 

        std::vector<Token*> tokens;
        
        // state of a automata
        int state;

        // pointer to the text index;
        int forward;

        // pointer to the beginning of a word
        int word_begin;

        // current character
        char current_char;

        // the token type
        std::string token_type;

        // increment the text pointer
        int nextChar(){
            this->forward++;     
            this->current_char = this->text[forward];
            return this->current_char;
        }

        // get current character from text
        char getChar(){
            return this->current_char; 
        }


    public:

        LexicalAnalyser(char* fileContent) {
            this->text = fileContent; 
            this->state = 0;
            this->forward = -1;
        }

        // scan the file
        void scan();
        void printTokens();


};

void LexicalAnalyser::printTokens(){
    for(int i = 0; i < this->tokens.size(); i++){
        std::cout << this->tokens[i] << std::endl; 
    }

}

void LexicalAnalyser::scan(){

    // loop over the text until the end of text
    while(this->nextChar()){

        // current character
        char ch = this->getChar();
        // automata implemention
        switch(this->state){
            
            // automata state 0
            case 0:
               
                if (isAlpha(ch)) {
                    this->state = 1;  
                }
                else {
                    this->word_begin = this->forward + 1;
                }
                
                break;
            case 1: 

                if (isAlpha(ch) || isNumber(ch)) {
                    this->state = 1;  
                }
                else {
                    this->state = 2;  
                    this->token_type = "id";
                }

                break;

            case 2: 
                this->forward--;
                Token* token;
                if (this->token_type == "id") {
                    token = new Token<std::string>("id",
                    createString(this->word_begin, this->forward, this->text))
                }
                this->tokens.push_back(token);
                this->word_begin = this->forward + 1;
                this->state = 0;

                break;
        }
    } 
    
}

// create std::string word from beginnig and end index of the text
std::string createString(int begin, int end, std::string pstr){
    int pstr_length = end - begin + 1;


    char* str = new char[pstr_length];
    int l = 0;
    for (int i = begin; i < end; i++){
        str[l++] = pstr[i]; 
    }
    str[l] = '\0';

    std::string new_str = str;
    delete [] str;
    
    return new_str;
}

// this determines a character is alphabet character
bool isAlpha(char ch){
    if ((ch > 64 && 
        ch < 91) ||
        (ch > 96 && 
        ch < 122)) {
         
        return true;
    }
    else {
        return false; 
    }
}

// this determines a character is number
bool isNumber(char ch){
    return (ch > 47 && ch < 58)? true: false;
}



