#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" unsigned char GetValue(const char*);
extern void* g_vftable_1f0ed0;
class Base_1f0ed0 {
  public:
    void Init(void*, int);
};
class Method6_1f0ed0 {
  public:
    Method6_1f0ed0(void* p, int x);
    void* vptr;
    char pad4[12];
    unsigned char m10, m11, m12, m13, m14, m15;
    char pad16[2];
    unsigned char m18;
    char pad19[3];
    int m1c;
};
Method6_1f0ed0::Method6_1f0ed0(void* p, int x) {
    ((Base_1f0ed0*)this)->Init(p, 6);
    vptr = &g_vftable_1f0ed0;
    m1c = x;
    m18 = GetValue(((char*)&DAT_0048e100));
    m10 = GetValue(((char*)&DAT_0049cad8));
    m11 = GetValue(((char*)&DAT_0049cad8));
    m12 = GetValue(((char*)&DAT_0049cad8));
    m13 = GetValue(((char*)&DAT_0048e128));
    m14 = GetValue(((char*)&DAT_0048e128));
    m15 = GetValue(((char*)&DAT_0048e128));
}
