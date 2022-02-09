#include <node.h>

void Increment(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  // Validate the number of arguments.
  if (info.Length() < 1) {
    Nan::ThrowTypeError("Arity mismatch");
    return;
  }

  // Validate the type of the first argument.
  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Argument must be a number");
    return;
  }

  // Get the number value of the first argument. A JavaScript `number` will be a `double` in C++.
  double arg = info[0]->NumberValue();

  // Allocate a new local variable of type "number" in the JavaScript VM for our return value.
  v8::Local<v8::Number> num = Nan::New(arg + 1);

  // Set the return value.
  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  // Bind the `Increment` function as the `increment` export.
  exports->Set(Nan::New("increment").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Increment)->GetFunction());
}

NODE_MODULE(addon, Init)