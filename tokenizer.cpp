#include <cstring>
#include "tokenizer.hpp"

void tokens_t::tokenize(const char *delim){
    
    tokens[0] = strtok(storage, delim);
    
    int i=1;
    while(tokens[i-1] != NULL) {
        tokens[i] = strtok(NULL, delim);
        i++;
    }
   
    ntoks = i-1;
}

tokens_t::tokens_t(const char *str, const char *delim){
    size = strlen(str);
    storage = new char[size+1];
    tokens = new char*[size/2+2];
    
    strcpy(storage, str);
    
    tokenize(delim);
}
tokens_t::~tokens_t(){
    delete tokens;
    delete storage;
}
const char* tokens_t::operator[](size_t i){
    if(i<ntoks) return tokens[i];
    else return nullptr;
}
size_t tokens_t::num() const{
    return ntoks;
}

