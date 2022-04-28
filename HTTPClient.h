#ifndef HTTPClient_h
#define HTTPClient_h

#include "HTTPClient.h"
#include "IPAddress.h"
#include "HTTP.h"
#include <iostream>

using std::string;

class HTTPClient {
	public:
		IPAddress senderAddress();
		void senderAddress(IPAddress address);
		IPAddress targetAddress();
		void targetAddress(IPAddress address);

	private:
		IPAddress _senderAddress;
		IPAddress _targetAddress;
};
#endif