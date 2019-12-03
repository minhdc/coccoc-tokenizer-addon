#include "hello_wrap.h"

Napi::FunctionReference HelloWrap::constructor;

Napi::Object HelloWrap::Init(Napi::Env env, Napi::Object exports){
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "HelloWrap",{
        InstanceMethod("getUserName",&HelloWrap::getUserName)
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("HelloWrap",func);
    return exports;
}

HelloWrap::HelloWrap(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HelloWrap>(info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    Napi::String value = info[0].As<Napi::String>();
    this -> hello_ = new Hello(value.ToString());
}

Napi::Value HelloWrap::getUserName(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    string userName = this -> hello_ -> getUserName();
    return Napi::String::New(env,userName);
}