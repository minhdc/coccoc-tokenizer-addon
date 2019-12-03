#include <napi.h>
#include "hello_wrap.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports){
    return HelloWrap::Init(env,exports);
}

NODE_API_MODULE(testaddon, InitAll)