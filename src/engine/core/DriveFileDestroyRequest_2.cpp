// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275bd0..0x00275c80 (kind game, layer engine, confidence medium), dominant class core::DriveFileDestroyRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fcf3cc66 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcf3cc66 {} using namespace fn_fcf3cc66;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fcf3cc66 {
extern "C" char DAT_0042bc60[];
struct ThisCall_00275600 {
    void BaseInit_00275600(void*);
};
} // namespace fn_fcf3cc66
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_fcf3cc66 {
class DriveFileDestroyRequest {
  public:
    char pad[0x10c];
    DriveFileDestroyRequest* Run(hulk_intptr, char*);
};
namespace core {
struct Inner_275c10 {
    virtual void f0();
    virtual void f1();
};
}
namespace core {
struct Obj_275c10 {
    virtual void g0();
    virtual void g1();
    Inner_275c10 sub;
    char pad[0x14 - 4 - sizeof(Inner_275c10)];
    int count;
};
}
namespace core {
struct Alloc_275c10 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void Free(void* p);
};
}
namespace core {
extern Alloc_275c10* hulk_at_0052a1e4;
}
namespace core {
extern int hulk_at_0052a1c8;
}
namespace core {
void __cdecl Lock_0026d850(void* p);
}
namespace core {
void __cdecl Unlock_0026d840(void* p);
}
namespace core {
extern void* hulk_at_0042b9bc[];
}
namespace core {
extern void* hulk_at_0042b914[];
}
namespace core {
class DriveFileDestroyRequest {
  public:
    int mA;
    Obj_275c10* mObj;
    virtual void* vfunc_0(unsigned flags);
    virtual void vfunc_1();
};
}


// 0x00275bd0 FUN_00275bd0 (59 B): matches/0x00275bd0.cpp
// sym: ?Run@DriveFileDestroyRequest@fn_fcf3cc66@@QAEPAV12@HPAD@Z
DriveFileDestroyRequest* DriveFileDestroyRequest::Run(hulk_intptr a, char* p) {
    ((ThisCall_00275600*)(this))->BaseInit_00275600((void*)a);
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042bc60);
    InitMore();
    strncpy((char*)this + 0xc, p, 0x100);
    ((char*)this)[0x10c] = 0;
    return this;
}


// 0x00275c10 core::DriveFileDestroyRequest::vfunc_0 (102 B): matches/0x00275c10.cpp
// sym: ?vfunc_0@DriveFileDestroyRequest@core@fn_fcf3cc66@@UAEPAXI@Z
namespace core {
void* DriveFileDestroyRequest::vfunc_0(unsigned flags) {
    *(void***)this = hulk_at_0042b9bc;
    mObj->sub.f0();
    mObj->count--;
    mObj->sub.f1();
    mObj->g1();
    *(void***)this = hulk_at_0042b914;
    if (flags & 1) {
        Lock_0026d850(&hulk_at_0052a1c8);
        hulk_at_0052a1e4->Free(this);
        Unlock_0026d840(&hulk_at_0052a1c8);
    }
    return this;
}
}

} // namespace fn_fcf3cc66
