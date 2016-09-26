#include "../thread/IRunnable.h"
#include "../server/Server.h"

#include<iostream>

using namespace std;

class ServerActions:public IRunnable{

public:

  ServerActions(Server *);

  void run();

  void setSocket_conn();
  int getSocket_conn();

private:
  Server *server;
  bool state;
};