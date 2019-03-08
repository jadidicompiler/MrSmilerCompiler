

#include <iostream>
#include <fstream>
#include <string>


#include "lexiAnalyser.h"


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
