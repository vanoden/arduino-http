#include <HTTPCookie.h>
#include <HTTPHeader.h>
#include <stdio.h>
#include <string.h>

HTTPCookie::HTTPCookie() {

}

void HTTPCookie::name(char * value) {
	int len = strnlen(value,MAX_COOKIE_KEY_SIZE);
	strncpy(_name,value,len - 1);
	_name[len] = '\0';
}

string HTTPCookie::name() {
	return _name;
}

void HTTPCookie::domain(char * value) {
	int len = strnlen(value,MAX_COOKIE_DOMAIN_SIZE);
	strncpy(_domain,value,len - 1);
	_domain[len] = '\0';
}

string HTTPCookie::domain() {
	return _domain;
}

string HTTPCookie::serialize() {
	char cookie[MAX_HEADER_SIZE] = "";

	strcat(cookie,"Cookie: ");
	strncat(cookie,_name, MAX_COOKIE_KEY_SIZE);

	strcat(cookie,"=");
	strncat(cookie,_value, MAX_COOKIE_VALUE_SIZE);

	return cookie;
}