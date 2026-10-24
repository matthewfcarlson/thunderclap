#include "gen/global.h"

#include "compat/ptr.h"
typedef unsigned int u32_fcb10;
struct CCharacterAgent_fcb10 {
    void InitBase(u32_fcb10);
};
struct CChaseAgent_nv_fcb10 {
    void InitBase(u32_fcb10);
};
extern char CChaseAgent_vftable;

CChaseAgent* CChaseAgent::FUN_000fcb10(unsigned int __p0) { u32_fcb10 x = (u32_fcb10)__p0;

    ((CChaseAgent_nv_fcb10*)(((CCharacterAgent_fcb10*)this)))->InitBase(x);
    (*(u32_fcb10 *)&this->f_08) = 0;
    (*(u32_fcb10 *)&this->f_70) = 0;
    this->f_6c = 0;
    *(hulk_uintptr*)this = (hulk_uintptr)&CChaseAgent_vftable;
    (*(float *)&this->f_68) = -1.0f;
    return (CChaseAgent*)(this);
}
