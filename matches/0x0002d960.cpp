#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
extern "C" char DAT_003f423c[];
struct ThisCall_001d0480 {
    void Init(void*, int);
};
extern "C" unsigned char __cdecl Get(void*);
class Method5 {
  public:
    virtual void Dummy();
    char pad4[12];
    unsigned char x10;
    unsigned char x11;
    unsigned char x12;
    unsigned char x13;
    unsigned char x14;
    char pad15[3];
    unsigned char x18;
    char pad19[3];
    int arg;
    Method5* Build(void* p2, int p3);
};
Method5* Method5::Build(void* p2, int p3) {
    ((ThisCall_001d0480*)(this))->Init(p2, 5);
    *(void**)this = (void*)((hulk_intptr)DAT_003f423c);
    arg = p3;
    x18 = Get(((char*)&DAT_0048e100));
    x10 = Get(((char*)&DAT_0048e0f0));
    x11 = Get(((char*)&DAT_0048e0f0));
    x12 = Get(((char*)&DAT_0048e128));
    x13 = Get(((char*)&DAT_0048e128));
    x14 = Get(((char*)&DAT_0048e128));
    return this;
}
