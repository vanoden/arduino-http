#ifndef HTTPRequest_h
#define HTTPRequest_h

#include "HTTP.h"
#include "HTTPRequest.h"
#include "HTTPHeader.h"
#include "HTTPCookie.h"
#include "HTTPParam.h"
#include <iostream>

class HTTPRequest {
	public:
		HTTPRequest();
		const string method();
		string uri();
		void uri(const char * value);
		string status();
		void body(const char * value);
		string serialize();
		void agent(const char * value);
		void endpoint(const char * value);
		HTTPHeader addHeader(HTTPHeader header);
		HTTPHeader addHeader(const char * key, const char * value);
		HTTPCookie addCookie(HTTPCookie cookie);
		HTTPParam addParam(const char * key, const char * value);
	private:
		char _uri[MAX_URI_SIZE] = "/";
		char _endpoint[MAX_ENDPOINT_SIZE];
		HTTPMethod _method = POST;
		HTTPHeader _headers[MAX_HEADER_CNT];
		int _headerCnt = 0;
		HTTPCookie _cookies[MAX_COOKIE_CNT];
		int _cookieCnt = 0;
		HTTPParam _params[MAX_PARAM_CNT];
		int _paramCnt = 0;
		char _body[MAX_REQUEST_BODY_SIZE] = "";
};
#endif