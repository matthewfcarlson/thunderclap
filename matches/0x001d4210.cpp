#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00422644[];
extern "C" char DAT_00422800[];
class Closure1_1d4210 {
  public:
    virtual void V();
    void Init(const char*, int);
    char pad[0x0c];
    char m10;
    char pad11[7];
    char m18;
    char pad19[3];
    int m1c;
    int m20;
    Closure1_1d4210* Run(const char*, const char*, const char*);
};
Closure1_1d4210* Closure1_1d4210::Run(const char* a, const char* b, const char* c) {
    Init(a, 1);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00422644);
    m1c = (hulk_intptr)c;
    m18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00422800);
    m20 = (hulk_intptr)b;
    return this;
}