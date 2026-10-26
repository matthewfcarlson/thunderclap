#include "decls/data/game/global.h"

#include "compat/ptr.h"
extern "C" char DAT_004046dc[];
struct Ctor_001d0480 {
    Ctor_001d0480(int, int);
};
extern char __cdecl Query(const char*);
class Method3_94200 : public Ctor_001d0480 {
  public:
    hulk_intptr v;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int value;
    Method3_94200(int a, int b);
};
Method3_94200::Method3_94200(int a, int b) : Ctor_001d0480(a, 3) {
    v = ((hulk_intptr)DAT_004046dc);
    value = b;
    b18 = Query(((char*)&DAT_0048e100));
    b10 = Query(((char*)&DAT_0048e134));
    b11 = Query(((char*)&DAT_0048e134));
    b12 = Query(&DAT_0048e0e4);
}