#include "../../h/client/Client.h"
// #include <unistd.h>

using namespace std;

Client::Client(string ip, int port){
	this->ip = ip;
	this->port = port;
	this->socket_server = socket(PF_INET, SOCK_STREAM,0);
	this->state = 0;

	this->enviado = false;
};

int Client::initializeClient(){
	if (this->socket_server == INVALID_SOCKET){
		return -1;
	} else{
		this->server_address.sin_family = AF_INET;
		this->server_address.sin_addr.s_addr = inet_addr(this->getIp().c_str());
		this->server_address.sin_port = htons(this->getPort());
		memset(&this->server_address.sin_zero, 0, sizeof(this->server_address.sin_zero));
		return 0;
	}
};

int Client::connectClient(){
	if (connect(this->socket_server, (struct sockaddr *)&this->server_address, sizeof(this->server_address)) == INVALID_SOCKET){
		return -1;
	}else{
		return 0;
	}
};

int Client::sendMessage(){
	int s = 0;
	if(this->enviado == false){
		const char *msg = NULL;
		string message = "Hola maldito computador";
		msg = message.c_str();
		int s = send(this->socket_server, msg, strlen(msg), 0);
		if(s == INVALID_SOCKET){
			return INVALID_SOCKET;
		}else{
			this->enviado = true;
			return s;
		}
	}
	return s;
};

/* Getters & Setters */
void Client::setPort(int port){
	this->port = port;
};

int Client::getPort(){
	return this->port;
};

void Client::setIp(string ip){
	this->ip = ip;
};

string Client::getIp(){
	return this->ip;
};

void Client::setSocket_server(int socket_server){
	this->socket_server = socket_server;
};

int Client::getSocket_server(){
	return this->socket_server;
};

void Client::setState(int state){
	this->state = state;
};

int Client::getState(){
	return this->state;
};

void Client::setMessage(Message *message){
	this->message = message;
};

Message Client::getMessage(){
	return *this->message;
};

void Client::setLeftSimpleQueue(SimpleQueue *simpleQueue){
	this->leftSimpleQueue = simpleQueue;
};

SimpleQueue Client::getLeftSimpleQueue(){
	return *this->leftSimpleQueue;
};

void Client::setRightSimpleQueue(SimpleQueue *simpleQueue){
	this->rightSimpleQueue = simpleQueue;
};

SimpleQueue Client::getRightSimpleQueue(){
	return *this->rightSimpleQueue;
};
