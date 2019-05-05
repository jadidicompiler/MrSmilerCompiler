
/*
    finding a specific word
    in a string
*/

#include <iostream>
#include <string>

#define print(str) std::cout << str << std::endl;

int main(){

    std::string str; 

    // read line from console
    std::getline(std::cin, str);

    int state = 0;
    bool found = false;
    char ch;
    // const int final_state = 4;

    for(int i = 0; i < str.size() && !found; i++){
        
        ch = str[i]; 

        switch(state){
            case 0:
                if (ch == 'l') state = 1;
                break;

            case 1:
                if (ch == 'o') state = 2;
                else if (ch == 'l') state = 1;
                else state = 0;

                break;

            case 2:
                if (ch == 'a') state = 3;
                else if (ch == 'l') state = 1;
                else state = 0;

                break;

            case 3:
                if (ch == 'd') state = 4;
                else if (ch == 'l') state = 1;
                else state = 0;
                
                break;

            case 4:
                found = true;
                break;

        }
    }

    if (found){
        print("found the word load");
    }
    else {
        print("did not find the word load");
    }
    
    
    return 0;
}








