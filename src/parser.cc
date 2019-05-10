

/*

    this is the implemention of javascript
    grammer using recursive descent parsing method

*/

#include "parser.h"
#include "token.h"
#include <iostream>

#define ERROR(name, string) string,
const char* Parser::errors[NUM_ERRORS] = {
    ERRORS(ERROR)
};
#undef ERROR


Parser::Parser(std::vector<Token*> tokens){
    this->tokens = tokens;  
    this->nextToken();
}

const char* Parser::getError(int errNum){
    return errors[errNum]; 
}

void Parser::makeError(int errNum){
    this->isError = true;	
    this->parser_errors.push_back(this->getError(errNum));
}

// begin the parsing operation
void Parser::parse(){
    this->ntProgram();
}

// put the next token in lookAhead
void Parser::nextToken(){
    this->lookAhead = this->tokens[++this->token_index];	 
}


void Parser::ntProgram() {
    this->ntElement(); 
    this->ntProgram();

    if (this->isError) {
	this->reject();		 
    }
    else {
	this->accept();	 
    }

}

void Parser::ntElement(){
    if (this->lookAhead->valueIs(TokenList::FUNCTION)) {
	this->nextToken(); 
	if(this->lookAhead->typeIs("id")) {
	    this->nextToken(); 
	}
	else {
	    this->makeError(Parser::FUNCTIONID);
	}

	if (this->lookAhead->valueIs(TokenList::LPAREN)) {
	    this->nextToken();	
	}
	else {
	    this->makeError(Parser::MLPAREN);
	}

	this->ntParameterListOpt();
	if (this->lookAhead->valueIs(TokenList::RPAREN)){
	    this->nextToken();	
	}
	else {
	    this->makeError(Parser::MRPAREN);
	}
	this->ntCompoundStatement();

    } 
    else {
	this->ntStatement();
    }
}

void Parser::ntParameterListOpt() {
    this->ntParameterList();  
}


void Parser::ntCompoundStatement() {
    if (this->lookAhead->valueIs(TokenList::LBRACE)){	 
	this->nextToken();	
    }
    else {
	this->makeError(Parser::MLBRACE);
    }

	this->ntStatements();
       
	if (this->lookAhead->valueIs(TokenList::RBRACE)){
	this->nextToken(); 
    }
    else {
	this->makeError(Parser::MRBRACE);
    }
}

void Parser::ntStatements(){
    this->ntStatement(); 
    //this->ntStatements();
}

void Parser::ntStatement(){
    if (this->lookAhead->valueIs(TokenList::SEMICOLON)){
	this->nextToken(); 
    }
    else {
	this->makeError(Parser::MSIMICOLON);
    }
}

void Parser::ntParameterList(){
    if (this->lookAhead->typeIs("id")){
	this->nextToken();
    }
}

void Parser::accept(){
    std::cout << "source code is valid\n";
}

void Parser::reject(){
    std::cout << "failed to compile, errors: \n";
    for(int i = 0; i < this->parser_errors.size(); i++){
	std::cout << this->parser_errors[i] << std::endl; 
    }
}


