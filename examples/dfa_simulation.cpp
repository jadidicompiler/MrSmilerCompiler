
/*
    this program simulate a dfa
*/

#include <iostream>
#include <string>

#define print(i) std::cout << i << std::endl

int move(int, char);

int main(){


    std::string str;
    std::cin >> str;

    
    // beginning state
    int state = 0;


    // final state
    const int final_state = 3;

    // current character
    char ch;

    // loop over the string until the end of string
    // or until reach a invalid character which is
    // not in the alphabet
    for(int i = 0; i < str.size() && state != -1; i++){
        ch = str[i];
        state = move(state, ch);
    }
    if (state == final_state)
        print("yes");
    else if (state == -1)
        print("error invalid character: " << ch);
    else 
        print("no");

    return 0;
}

// change the state of automata
int move(int state, char ch){
    
    switch(state) {
        
        case 0:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 0;
            else state = -1;

            break;

        case 1:
            if (ch == 'a') state = 1;
            else if ( ch == 'b') state = 2;
            else state = -1;

            break;

        case 2:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 3;
            else state = -1;

            break;
    
        case 3:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 0;
            else state = -1;

            break;
    }

    return state;

}


