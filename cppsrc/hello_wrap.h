#include <napi.h>
#include "hello.hpp"

class HelloWrap : public Napi::ObjectWrap<HelloWrap>{
    public:
        static Napi::Object Init(Napi::Env, Napi::Object exports);
        HelloWrap(const Napi::CallbackInfo& info);
    private:
        static Napi::FunctionReference constructor;
        Napi::Value getUserName(const Napi::CallbackInfo& info);
        Hello *hello_;
};
