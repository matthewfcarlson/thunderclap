#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00404c60[];
struct InitBase_9aba0 {
    void Init(void*, int);
};
class Method4_9aba0 : public InitBase_9aba0 {
  public:
    Method4_9aba0* Init(void*, void*);
    int vf;
    char pad04[0x0c];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    void* member1c;
};
Method4_9aba0* Method4_9aba0::Init(void* a, void* p) {
    InitBase_9aba0::Init(a, 4);
    vf = ((int)DAT_00404c60);
    member1c = p;
    b18 = FUN_001d04d0((const void*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const void*)((int)((char*)&DAT_0048e0e4)));
    b11 = FUN_001d04d0((const void*)((int)((char*)&DAT_0048e0e4)));
    b12 = FUN_001d04d0((const void*)((int)((char*)&DAT_0048e0e4)));
    b13 = FUN_001d04d0((const void*)((int)((char*)&DAT_0048e128)));
    return this;
}