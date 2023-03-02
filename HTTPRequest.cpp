#include <Arduino.h>
#include <HTTP.h>
#include <HTTPRequest.h>
#include <HTTPHeader.h>
#include <HTTPCookie.h>
#include <HTTPParam.h>
#include <stdio.h>
#include <string.h>

HTTPRequest::HTTPRequest() {
	HTTPHeader header("Content-Type","application/x-www-form-urlencoded");
	addHeader(header);
	//addHeader("Content-type","application/form-www-urlencoded");
}

void HTTPRequest::endpoint(const char * value) {
	strncpy(_endpoint,value,MAX_ENDPOINT_SIZE - 1);
}

void HTTPRequest::uri(const char * value) {
	strncpy(_uri,value,MAX_URI_SIZE - 1);
}

string HTTPRequest::uri() {
	return _uri;
}

const string HTTPRequest::method() {
	switch (_method) {
		case HTTP_GET:
			return "GET";
			break;
		case HTTP_PUT:
			return "PUT";
			break;
		case HTTP_POST:
			return "POST";
			break;
		case HTTP_HEAD:
			return "HEAD";
			break;
		default:
			return "GET";
			break;
	}
}

string HTTPRequest::status() {
	char status[MAX_STATUS_SIZE] = "";

	// Start with HTTP Method
	char meth[8] = "";
	strncpy (meth,method().c_str(),7);
	strncpy(status,meth,MAX_STATUS_SIZE - 1);

	// Add a space
	strncat(status," ",MAX_STATUS_SIZE - 1);

	// Add URI
	strncat(status,uri().c_str(),MAX_STATUS_SIZE - 1);

	// Add a space and HTTP version
	char version[] = " HTTP/1.0";
	strncat(status,version,MAX_STATUS_SIZE - 1);

	return status;
}

void HTTPRequest::agent(const char * value) {
	HTTPHeader header("User-Agent",value);
	addHeader(header);
}

HTTPHeader HTTPRequest::addHeader(HTTPHeader header) {
	_headers[_headerCnt] = header;
	_headerCnt ++;

	return header;
}

HTTPHeader HTTPRequest::addHeader(const char * key, const char * value) {
	HTTPHeader header(key,value);
	_headers[_headerCnt] = header;

	_headerCnt ++;

	return header;
}

HTTPCookie HTTPRequest::addCookie(HTTPCookie cookie) {
	_cookies[_cookieCnt] = cookie;
	_cookieCnt ++;
	return cookie;
}

HTTPParam HTTPRequest::addParam(const char * key, const char * value) {
	HTTPParam param(key,value);
	_params[_paramCnt] = param;
	_paramCnt ++;
	return param;
}
void HTTPRequest::body(const char * value) {
	strncpy(_body,value,MAX_REQUEST_BODY_SIZE - 1);
}

string HTTPRequest::serialize() {
	char request[MAX_REQUEST_SIZE] = "";

	// Build Body First to get Content Length
	if (_method == POST) {
		if (_paramCnt > 0) {
			strncpy(_body,"",MAX_REQUEST_BODY_SIZE - 1);
			for (unsigned int i = 0; i < _paramCnt; i ++) {
				if (i > 0) strncat(_body,"&",MAX_REQUEST_BODY_SIZE - 1);
				strncat(_body,_params[i].key().c_str(),MAX_REQUEST_BODY_SIZE - 1);
				strncat(_body,"=",MAX_REQUEST_BODY_SIZE - 1);
				strncat(_body,_params[i].value().c_str(),MAX_REQUEST_BODY_SIZE - 1);
			}
		}
	}

	// Add body length as header Content-Length
	char len[5];
	int bodyLen = strnlen(_body,MAX_REQUEST_BODY_SIZE - 1);
	sprintf(len,"%d",bodyLen);
	addHeader("Content-Length",len);

	// Add Status Line
	char stat[MAX_STATUS_SIZE] = "";
	strncpy (stat,status().c_str(),MAX_STATUS_SIZE-1);
	strncpy(request,stat,MAX_REQUEST_SIZE - 1);
	strncat(request,"\r\n",MAX_REQUEST_SIZE);

	// Add Headers
	for (unsigned int i = 0; i < _headerCnt; i ++) {
		char header[MAX_HEADER_SIZE] = "";
		strncpy(header,_headers[i].serialize().c_str(),MAX_HEADER_SIZE-1);
		strncat(request,header,MAX_REQUEST_SIZE-1);
		strncat(request,"\r\n",MAX_REQUEST_SIZE-1);
	}

	// Add Cookies
	for (unsigned int i = 0; i < _cookieCnt; i ++) {
		char header[MAX_HEADER_SIZE] = "";
		strncpy(header,_cookies[i].serialize().c_str(),MAX_HEADER_KEY_SIZE);
		strncat(request,header,MAX_REQUEST_SIZE);
		strncat(request,"\r\n",MAX_REQUEST_SIZE);
	}
	strncat(request,"\r\n",MAX_REQUEST_SIZE);
	strncat(request,_body,MAX_REQUEST_SIZE - 1);

	return request;
}