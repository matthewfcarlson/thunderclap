// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275930..0x002759e0 (kind game, layer engine, confidence medium), dominant class core::DriveDestroyDirectoryRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f76db007 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f76db007 {} using namespace fn_f76db007;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f76db007 {
extern "C" void InitOther_002705f0();
} // namespace fn_f76db007
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f76db007 {
class DriveRequest_275930 {
  public:
    virtual void* FnV_00275970(char);
    DriveRequest_275930(int);
};
class DriveDestroyDirectoryRequest : public DriveRequest_275930 {
  public:
    virtual void FnW_00274720();
    char pad[8];
    char name[16];
    char tail;
    DriveDestroyDirectoryRequest(int, const char*);
};
typedef unsigned char byte_275970;
struct O_275970 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T_275970 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[0x10];
    int count;
};
namespace core {
struct DriveDestroyDirectoryRequest {
    virtual DriveDestroyDirectoryRequest* vfunc_0(byte_275970);
    char pad[4];
    T_275970* field8;
};
}


// 0x00275930 FUN_00275930 (53 B): matches/0x00275930.cpp
// sym: ??0DriveDestroyDirectoryRequest@fn_f76db007@@QAE@HPBD@Z
DriveDestroyDirectoryRequest::DriveDestroyDirectoryRequest(int a, const char* s) : DriveRequest_275930(a) {
    InitOther_002705f0();
    strncpy(name, s, 16);
    tail = 0;
}


// 0x00275970 core::DriveDestroyDirectoryRequest::vfunc_0 (102 B): matches/0x00275970.cpp
// sym: ?vfunc_0@DriveDestroyDirectoryRequest@core@fn_f76db007@@UAEPAU123@E@Z
// data: glob_275970 = DAT_0052a1e4
core::DriveDestroyDirectoryRequest* core::DriveDestroyDirectoryRequest::vfunc_0(byte_275970 flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042b9bc);
    ((O_275970*)((char*)field8 + 4))->a();
    field8->count--;
    ((O_275970*)((char*)field8 + 4))->b();
    ((O_275970*)field8)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(O_275970**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}

} // namespace fn_f76db007
