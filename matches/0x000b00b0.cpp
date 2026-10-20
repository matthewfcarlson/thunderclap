#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" char DAT_00405ea8[];
class Method4_b00b0 {
  public:
    void Init(int, int);
    Method4_b00b0(int, int);
};
extern "C" unsigned char __cdecl Read(const char*);
Method4_b00b0::Method4_b00b0(int a, int b) {
    Init(a, 4);
    *(int*)this = ((int)DAT_00405ea8);
    *(int*)((char*)this + 0x1c) = b;
    *(char*)((char*)this + 0x18) = Read((const char*)((int)((char*)&DAT_0048e100)));
    *(char*)((char*)this + 0x10) = Read((const char*)((int)((char*)&DAT_0048e134)));
    *(char*)((char*)this + 0x11) = Read((const char*)((int)((char*)&DAT_0048e128)));
    *(char*)((char*)this + 0x12) = Read((const char*)((int)((char*)&DAT_0048e128)));
    *(char*)((char*)this + 0x13) = Read((const char*)((int)((char*)&DAT_0048e128)));
}
