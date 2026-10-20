#include "compat/ptr.h"
struct Ctor_0027b070 {
    Ctor_0027b070();
};
extern void* alloc(hulk_uintptr);
extern int CPatrolPath_vtable;
class CPatrolPath : public Ctor_0027b070 {
  public:
    hulk_intptr vt;
    char pad4[12];
    void* mData;
    int mCount;
    char pad18[4];
    CPatrolPath(int count);
};
CPatrolPath::CPatrolPath(int count) : Ctor_0027b070() {
    unsigned int size = count * 0x24;
    vt = (hulk_intptr)&CPatrolPath_vtable;
    *(char*)((char*)this + 0x18) = 0;
    mData = alloc(size);
    mCount = count;
}
