#include "compat/ptr.h"
extern void* __cdecl Alloc(hulk_uintptr);
extern int KeywordWaitVtable;
class Helper_114b30 {
  public:
    void Init();
};
class SetupObj_114b30 {
  public:
    void Setup();
};
struct KeywordWaitTrack {
    hulk_uintptr vptr;
    unsigned int pad04;
    int field08;
    int field0c;
    float field10;
    char pad14[4];
    char field18[8];
    char field20;
};
KeywordWaitTrack* __cdecl target() {
    KeywordWaitTrack* p = (KeywordWaitTrack*)Alloc(0x28);
    if (p) {
        ((Helper_114b30*)p)->Init();
        p->vptr = (hulk_uintptr)&KeywordWaitVtable;
        p->field0c = 0;
        p->field10 = -1.0f;
        ((SetupObj_114b30*)((char*)p + 0x18))->Setup();
        p->field20 = 0;
        p->field08 = 1;
        return p;
    }
    return 0;
}