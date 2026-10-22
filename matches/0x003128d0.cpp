#include "compat/ptr.h"
extern "C" char DAT_0043223c[];
void __cdecl thunk(void*);
struct SkeletonInfo_3128d0 {
    void Dtor();
};
struct SkeletonInfo {
    void* vf;
    char pad[12];
    void* member;
    void Free();
};
void SkeletonInfo::Free() {
    vf = (void*)((hulk_intptr)DAT_0043223c);
    if (member)
        thunk((char*)member - 4);
    ((SkeletonInfo_3128d0*)this)->Dtor();
}
