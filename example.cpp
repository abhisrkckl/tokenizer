#include "tokenizer.hpp"
#include <iostream>

int main(){

    const char str[] = "This is a string.";
    const char delim[] = " ";

    tokens_t tokens(str, delim);
    size_t ntoks = tokens.num();

    std::cout<<"# of tokens = "<<ntoks<<'\n';
    for(int i=0; i<ntoks; i++){
        std::cout<<tokens[i]<<'\n';
    }

    return 0;
}
