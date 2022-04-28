#include <HTTPParam.h>
#include <stdio.h>
#include <string.h>

using std::string;
HTTPParam::HTTPParam(const char * key, const char * value) {
    strncpy(_key,key,MAX_PARAM_KEY_SIZE - 1);
	strncpy(_value,value,MAX_PARAM_VALUE_SIZE - 1);
}
HTTPParam::HTTPParam() {

}

string HTTPParam::key() {
    return _key;
}

string HTTPParam::value() {
    return _value;
}