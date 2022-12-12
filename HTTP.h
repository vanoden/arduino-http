#ifndef HTTP_h
#define HTTP_h

enum class HTTPMethod { GET, POST, HEAD, PUT };

const unsigned int MAX_REQUEST_SIZE = 1536;
const unsigned int MAX_REQUEST_BODY_SIZE = 256;
const unsigned int MAX_ENDPOINT_SIZE = 32;
const unsigned int MAX_URI_SIZE = 128;
const unsigned int MAX_STATUS_SIZE = 128;

const unsigned int MAX_HEADER_SIZE = 196;
const unsigned int MAX_HEADER_KEY_SIZE = 64;
const unsigned int MAX_HEADER_VALUE_SIZE = MAX_HEADER_SIZE - MAX_HEADER_KEY_SIZE;
const unsigned int MAX_HEADER_CNT = 8;


const unsigned int MAX_PARAM_KEY_SIZE = 32;
const unsigned int MAX_PARAM_VALUE_SIZE = 64;
const unsigned int MAX_PARAM_CNT = 8;

const unsigned int MAX_COOKIE_CNT = 3;
const unsigned int MAX_COOKIE_DOMAIN_SIZE = 64;
const unsigned int MAX_COOKIE_KEY_SIZE = 64;
const unsigned int MAX_COOKIE_VALUE_SIZE = 128;

#endif