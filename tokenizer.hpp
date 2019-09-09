#ifndef _tokenizer_hpp_
#define _tokenizer_hpp_

#include <cstddef>

struct tokens_t{
private:
    char *storage;
    char **tokens;
    size_t size;
    size_t ntoks;

    void tokenize(const char *delim);

public:
    tokens_t(const char *str, const char *delim);
    ~tokens_t();

    const char* operator[](size_t i);
    size_t num() const;

    operator char**(){
        return tokens;
    }
};

#endif
