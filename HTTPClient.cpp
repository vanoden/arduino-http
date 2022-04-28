#include <HTTPClient.h>

void HTTPClient::senderAddress(IPAddress address) {
	_senderAddress = address;
}

IPAddress HTTPClient::senderAddress() {
	return _senderAddress;
}

void HTTPClient::targetAddress(IPAddress address) {
	_targetAddress = address;
}

IPAddress HTTPClient::targetAddress() {
	return _targetAddress;
}