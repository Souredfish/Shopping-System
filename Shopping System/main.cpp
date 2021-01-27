#include"Time.h"
#include"Handle.h"
#include "Message.h"
#include "UI.h"
#include "Warhouse.h"
#include "password.h"
#include"Logs.h"
#include"storage.h"
int main(void)
{
	using namespace std;
	Logs logs;
	password demo;
	demo.assembly();
	BTree btree;
	storage mix;
	Message message(&logs);
	mix.getMessage(&message);
	
	mix.getbtree(&btree);
	mix.getPassword(&demo);
	mix.load();
	UI ui;
	message.msg_getui(&ui);
	message.msg_getbtree(&btree);	
	Handle handle(&message,&btree,&logs);
	Time clock(&message, &handle);
	thread clockthread(&Time::Time_clock, &clock);
	message.msg_control();
	clockthread.join();
	mix.save();
	return 0;
}