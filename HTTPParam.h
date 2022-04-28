#ifndef HTTPParam_h
#define HTTPParam_h

#include "HTTPParam.h"
#include "HTTP.h"
#include <iostream>

using std::string;
class HTTPParam {
    public:
        HTTPParam(const char * key, const char * value);
		HTTPParam();
        string key();
        string value();
    private:
        char _key[MAX_PARAM_KEY_SIZE];
        char _value[MAX_PARAM_VALUE_SIZE];
};

#endif