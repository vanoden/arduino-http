#include <Arduino.h>
#include <HTTPHeader.h>
#include <stdio.h>
#include <string.h>

using std::string;

HTTPHeader::HTTPHeader(const char * key, const char * value) {
	strncpy(_key,key,MAX_HEADER_KEY_SIZE - 1);
	strncpy(_value,value,MAX_HEADER_VALUE_SIZE - 1);
}

HTTPHeader::HTTPHeader() {

}

void HTTPHeader::key(char * val) {
	int len = strnlen(val,MAX_HEADER_KEY_SIZE - 1);
	strncpy(_key,val,len - 1);
	_key[len] = '\0';
}

void HTTPHeader::value(char * val) {
	int len = strnlen(val,MAX_HEADER_VALUE_SIZE - 1);
	strncpy(_value,val,len - 1);
	_value[len] = '\0';
}

string HTTPHeader::key() {
	return _key;
}

string HTTPHeader::value() {
	return _value;
}

string HTTPHeader::serialize() {
	char header[MAX_HEADER_SIZE] = "";

	strncpy(header,_key,MAX_HEADER_SIZE - 1);
	strncat(header,": ",MAX_HEADER_SIZE - 1);
	strncat(header,_value,MAX_HEADER_SIZE - 1);

	return header;
}