#include "../../h/thread/IRunnable.h"

IRunnable::IRunnable(){
}

IRunnable::~IRunnable(){
}

bool IRunnable::isStart(){
	return start;
}

void IRunnable::setStart(bool start){
	this->start = start;
}
