#include "compat/ptr.h"
extern "C" char DAT_004046dc[];
struct Ctor_001d0480 {
    Ctor_001d0480(int, int);
};
extern char __cdecl Query(const char*);
extern char s0_94200;
extern char s1_94200;
extern char s2_94200;
extern char s3_94200;
class CUnlockablesManager : public Ctor_001d0480 {
  public:
    int v;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int value;
    CUnlockablesManager(int a, int b);
};
CUnlockablesManager::CUnlockablesManager(int a, int b) : Ctor_001d0480(a, 3) {
    v = ((hulk_intptr)DAT_004046dc);
    value = b;
    b18 = Query(&s0_94200);
    b10 = Query(&s1_94200);
    b11 = Query(&s2_94200);
    b12 = Query(&s3_94200);
}