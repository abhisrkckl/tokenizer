#include <cstring>

struct tokens_t{
private:
    char *storage;
    char **tokens;
    size_t size;
    size_t ntoks;

    void tokenize(const char *delim){
        
        tokens[0] = strtok(storage, delim);
        
        int i=1;
        while(tokens[i-1] != NULL) {
            tokens[i] = strtok(NULL, delim);
            i++;
        }
       
        ntoks = i-1;
    }

public:
    tokens_t(const char *str, const char *delim){
        size = strlen(str);
        storage = new char[size+1];
        tokens = new char*[size/2+2];
        
        strcpy(storage, str);
        
        tokenize(delim);
    }
    ~tokens_t(){
        delete tokens;
        delete storage;
    }
    const char* operator[](size_t i){
        if(i<ntoks) return tokens[i];
        else return NULL;
    }
    size_t num() const{
        return ntoks;
    }
};
