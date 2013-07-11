#include <node.h>
#include <v8.h>

#include "Kinecter.h"
#include "KinectSensor.h"

using namespace v8;
using namespace std;

Handle<Value> setViewAngle(const Arguments& args) {
	HandleScope scope;

	if(args.Length() != 1) {
		return ThrowException(
			Exception::TypeError(
				String::New("Wrong number of arguments. setViewAngle(n) requires a single int from -27 to 27")
			)
		);
	}

	Local<Integer> integer = args[0]->ToInteger();
	int angle = integer->Value();

	if(angle > 27) {
		return ThrowException(
			Exception::TypeError(
				String::New("Angle greater than 27. setViewAngle(n) requires a single int from -27 to 27")
			)
		);
	} else if(angle < -27) {
		return ThrowException(
			Exception::TypeError(
				String::New("Angle less than -27. setViewAngle(n) requires a single int from -27 to 27")
			)
		);
	}

	KinectSensor *pSensor = new KinectSensor();
	Kinecter *pKinecter = new Kinecter();

	pSensor->setViewAngle(angle);

	return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("setViewAngle"), FunctionTemplate::New(setViewAngle)->GetFunction());
}

NODE_MODULE(kinecter, init)