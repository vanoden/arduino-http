#ifndef HTTPHeader_h
#define HTTPHeader_h

#include "HTTPHeader.h"
#include "HTTP.h"
#include <iostream>

using std::string;

class HTTPHeader {
	public:
		HTTPHeader(const char * key, const char * value);
		HTTPHeader();
		void key(char * val);
		void value(char * val);
		string key();
		string value();
		string serialize();

	protected:
		char _key[64];
		char _value[128];
};
#endif