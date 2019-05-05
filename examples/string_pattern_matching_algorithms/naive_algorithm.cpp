
#include <iostream>

// Macroes
#define print(word) std::cout << word << std::endl

void naive_search(std::string, int, std::string, int);

int main(){
    
    std::string str;
    std::string pat;
    std::cout << "enter your pattern: ";
    std::getline(std::cin, pat);

    std::cout << "enter your text: " << std::endl;
    std::getline(std::cin, str);
    naive_search(str, str.size(), pat, pat.size());
      
    return 0;
}


// finding a pattern within a string
void naive_search(std::string str, int n, std::string pat, int m){
    
    int j;
    bool foundOnce = false;
    for(int i = 0; i <= n - m; i++){
    
        j = 0;
        while( j < m && str[i+j] == pat[j]) j++;

        if (j == m){
            print("found pattern at index: " << i);
            foundOnce = true;
        } 
    
    }
    if (!foundOnce) print("pattern was not found in the string");
}

