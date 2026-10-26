#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
extern "C" char DAT_00404c20[];
extern char __cdecl Convert(const char*);
class Method3_9a8e0 {
  public:
    void Init(void*, int);
    Method3_9a8e0(void*, int);
    char a[0x10];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int field1c;
};
Method3_9a8e0::Method3_9a8e0(void* p, int value) {
    Init(p, 3);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00404c20);
    field1c = value;
    b18 = Convert(((char*)&DAT_0048e100));
    b10 = Convert(((char*)&DAT_0048e128));
    b11 = Convert(((char*)&DAT_0048e128));
    b12 = Convert(((char*)&DAT_0048e0e4));
}