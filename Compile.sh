clear
echo "Compilando Node . . ."
g++ cpp/thread/IRunnable.cpp cpp/thread/GenericThread.cpp cpp/actions/ServerActions.cpp cpp/actions/ClientActions.cpp cpp/message/Message.cpp cpp/client/Client.cpp cpp/server/Server.cpp cpp/Node.cpp cpp/Main.cpp -o mainNode -l pthread
echo "Compilado . . ."
