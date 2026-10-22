#include "compat/ptr.h"
extern "C" char DAT_00421abc[];
struct RoomLoader_1c8f60 {
    virtual void Run();
    RoomLoader_1c8f60* Init(unsigned p);
};
extern RoomLoader_1c8f60* __cdecl Alloc(unsigned n);
class LevelLoader {
  public:
    hulk_uintptr vptr;
    int m4, m8, mc, m10;
    unsigned m14, m18;
    RoomLoader_1c8f60* m1c;
    LevelLoader(unsigned a, unsigned b);
};
LevelLoader::LevelLoader(unsigned a, unsigned b) {
    m4 = 0;
    m8 = 0x60000700;
    mc = 0;
    m10 = 0;
    vptr = ((hulk_intptr)DAT_00421abc);
    m14 = a;
    m18 = b;
    RoomLoader_1c8f60* t = Alloc(0x18);
    RoomLoader_1c8f60* r;
    if (t)
        r = t->Init(m14);
    else
        r = 0;
    m1c = r;
    r->Run();
}
