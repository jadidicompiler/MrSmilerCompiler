

#include <iostream>
#include <fstream>
#include <string>


#include "lexiAnalyser.h"
//#include "parser.h"
#include "token.h"


int main(int argc, char* argv[]){
    
    // file address not specified
    if (!argv[1]){
	std::cout << "please specify the programming language file address\n"; 
	return 1;
    }

    std::fstream file;
    std::string addr = argv[1];
    //std::vector<Token*> tokens;
    // open a file for reading the programming language text
    //std::cout << addr << std::endl;
    file.open(addr, std::fstream::in);
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
    /* Parser parser(lexi.getTokens()); */
    /* parser.parse(); */

    // clean up
    delete text;

    return 0;
}
