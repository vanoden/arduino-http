#ifndef HTTPCookie_h
#define HTTPCookie_h

#include "HTTPHeader.h"
#include "HTTPCookie.h"
#include "HTTP.h"
#include <iostream>

class HTTPCookie: public HTTPHeader {
	public:
		HTTPCookie(char * name, char * value);
		HTTPCookie();
		void domain(char * value);
		string domain();

		void name(char * value);
		string name();

		string serialize();
	private:
		char _domain[MAX_COOKIE_DOMAIN_SIZE];
		char _name[MAX_COOKIE_KEY_SIZE];
		char _expires[32] = "";
		char _path[64] = "";
};
#endif