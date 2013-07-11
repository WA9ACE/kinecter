#include <node.h>
#include <v8.h>

#include "Kinecter.h"
#include "KinectSensor.h"

using namespace v8;
using namespace std;

Handle<Value> setViewAngle(const Arguments& args) {
	HandleScope scope;

	KinectSensor *pSensor = new KinectSensor();
	Kinecter *pKinecter = new Kinecter();

	pSensor->setViewAngle(args[0]->NumberValue());

	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("setViewAngle"), FunctionTemplate::New(setViewAngle)->GetFunction());
}

NODE_MODULE(kinecter, init)