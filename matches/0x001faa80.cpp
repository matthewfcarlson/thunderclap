// FUN_001faa80 @ 0x001faa80
#include "compat/ptr.h"
class MyBufferStream {
public:
    virtual void v0();
    int arg0;
    int arg1;
    int zero;
    MyBufferStream(int a, int b) : arg0(a), arg1(b), zero(0) {}
};

struct StreamLoader {
    char data[0xc];
    void FUN_00337870();
    void FUN_00337890();
    bool FUN_00337a30(MyBufferStream* stream, const char* name, int owner, void* self, int flag);
};

class Resource_1faa80 {
public:
    void FUN_003375a0();
};

class Loader_1faa80 {
public:
    char pad0[4];
    Resource_1faa80* res;
    bool FUN_001faa80(int a, int b);
};

bool Loader_1faa80::FUN_001faa80(int a, int b) {
    MyBufferStream stream(a, b);
    StreamLoader loader;
    loader.FUN_00337870();
    if (loader.FUN_00337a30(&stream, "buffer", (hulk_intptr)res, this, 0)) {
        loader.FUN_00337890();
        return true;
    }
    res->FUN_003375a0();
    loader.FUN_00337890();
    return false;
}
