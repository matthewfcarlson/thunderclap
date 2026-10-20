#include "compat/ptr.h"
extern "C" char DAT_0040dc14[];
typedef unsigned int u32_114a70;
void* __cdecl Alloc(hulk_uintptr);
class Base_114a70 {
  public:
    void Init();
};
class Member_114a70 {
  public:
    void Init();
};
class HulkActionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x[10];
};
HulkActionTrack* target() {
    HulkActionTrack* p = (HulkActionTrack*)Alloc(0x28);
    if (p) {
        ((Base_114a70*)p)->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040dc14);
        *(u32_114a70*)((char*)p + 0xc) = 0;
        *(u32_114a70*)((char*)p + 0x10) = 0xbf800000;
        ((Member_114a70*)((char*)p + 0x18))->Init();
        *(u32_114a70*)((char*)p + 0x20) = 0;
        *(u32_114a70*)((char*)p + 8) = 1;
        return p;
    }
    return (HulkActionTrack*)0L;
}