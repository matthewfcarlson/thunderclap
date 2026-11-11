// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274e60..0x002751c0 (kind game, layer engine, confidence medium), dominant class core::FileRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f7190711 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7190711 {} using namespace fn_f7190711;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f7190711 {
struct Inner_274e60 {
    virtual void a();
    virtual void b();
};
struct File {
    virtual void a();
};
extern "C" int* FUN_002705f0();
struct FileRequest_274e60 : CoreRequest {
    CoreRequest* run(hulk_uintptr arg);
};
class Alloc_274eb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
extern void* hulk_at_0042b914[];
extern void* hulk_at_0042b99c[];
class Sub_274eb0 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_274eb0 {
  public:
    virtual void a();
    virtual void b();
    Sub_274eb0 mSub;
    char pad2[0x10];
    int mCount;
};
class FileRequest {
  public:
    void** vt;
    int pad;
    Holder_274eb0* mH;
    FileRequest* Dtor(unsigned char flag);
};
extern "C" char DAT_0042ba00[];
class FileOpenRequest : public CoreRequest {
  public:
    int field;
    unsigned char flag;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileOpenRequest* target(void*, int, unsigned char);
};
struct Lock_274f50 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_274f50 {
    virtual void v0();
    virtual void release();
};
struct Alloc_274f50 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileOpenRequest_274f50 : public CoreRequest {
  public:
    FileOpenRequest_274f50* f0(unsigned char flags);
};
extern "C" char DAT_0042ba20[];
class FileOpenByKeyRequest_274fc0 {
  public:
    hulk_intptr vtable;
    char pad[12 - 4];
    int y;
    int z;
    void Init_00274e60(int);
    FileOpenByKeyRequest_274fc0(hulk_intptr, int, hulk_intptr);
};
extern void Finish_002705f0();
class Alloc_274ff0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
class Sub_274ff0 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_274ff0 {
  public:
    virtual void a();
    virtual void b();
    Sub_274ff0 mSub;
    char pad2[0x10];
    int mCount;
};
class FileOpenByKeyRequest_274ff0 {
  public:
    void** vt;
    int pad;
    Holder_274ff0* mH;
    FileOpenByKeyRequest_274ff0* Dtor(unsigned char flag);
};
extern "C" char DAT_0042ba40[];
void FreeFinish_002705f0();
class SaveGameOpenRequest {
  public:
    hulk_intptr vptr;
    char pad4[8];
    int fieldC;
    unsigned char field10;
    char pad11[3];
    int field14;
    int field18;
    void init_00274e60(int);
    SaveGameOpenRequest* FUN_00275060(int, int, unsigned char, int, int);
};
class Inner_2750a0 {
  public:
    virtual void a();
    virtual void b();
};
class Root_2750a0 {
  public:
    virtual void a();
    virtual void b();
};
struct Manager_2750a0 {
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void q();
    virtual void add(void*);
};
namespace core {
class SaveGameOpenRequest {
  public:
    void* vt;
    int pad;
    Inner_2750a0* inner;
    SaveGameOpenRequest* vfunc_0(int flags);
};
}
extern "C" char DAT_0042ba60[];
class FileCloseRequest_275110 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCloseRequest_275110* Init(void*);
};
struct Lock_275130 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275130 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275130 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileCloseRequest_275130 : public CoreRequest {
  public:
    FileCloseRequest_275130* f0(unsigned char flags);
};
extern "C" char DAT_0042ba80[];
class FileCommitRequest_2751a0 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCommitRequest_2751a0* Init(void*);
};


// 0x00274e60 FUN_00274e60 (80 B): matches/0x00274e60.cpp
// sym: ?run@FileRequest_274e60@fn_f7190711@@QAEPAUCoreRequest@@I@Z
CoreRequest* FileRequest_274e60::run(hulk_uintptr arg) {
    vftable = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vftable = DAT_0042b99c;
    file = (void*)arg;
    FUN_002705f0();
    ((Inner_274e60*)&((CoreFile*)file)->vftableMutable)->a();
    ++((CoreFile*)file)->field18;
    ((Inner_274e60*)&((CoreFile*)file)->vftableMutable)->b();
    ((File*)file)->a();
    return this;
}


// 0x00274eb0 core::FileRequest::vfunc_0 (102 B): matches/0x00274eb0.cpp
// sym: ?Dtor@FileRequest@fn_f7190711@@QAEPAV12@E@Z
// data: gAlloc_274eb0 = DAT_0052a1e4
FileRequest* FileRequest::Dtor(unsigned char flag) {
    vt = hulk_at_0042b99c;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = hulk_at_0042b914;
    if (flag & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_274eb0**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x00274f20 FUN_00274f20 (44 B): matches/0x00274f20.cpp
// sym: ?target@FileOpenRequest@fn_f7190711@@QAEPAV12@PAXHE@Z
FileOpenRequest* FileOpenRequest::target(void* a, int b, unsigned char c) {
    FUN_00274e60((hulk_uintptr)a);
    vftable = DAT_0042ba00;
    field = b;
    flag = c;
    FUN_002705f0();
    return this;
}


// 0x00274f50 core::FileOpenRequest::vfunc_0 (102 B): matches/0x00274f50.cpp
// sym: ?f0@FileOpenRequest_274f50@fn_f7190711@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileOpenRequest_274f50* FileOpenRequest_274f50::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_274f50*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_274f50*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_274f50*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_274f50**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x00274fc0 FUN_00274fc0 (44 B): matches/0x00274fc0.cpp
// sym: ??0FileOpenByKeyRequest_274fc0@fn_f7190711@@QAE@HHH@Z
FileOpenByKeyRequest_274fc0::FileOpenByKeyRequest_274fc0(hulk_intptr x, int yy, hulk_intptr zz) {
    Init_00274e60(x);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042ba20);
    y = yy;
    z = zz;
    Finish_002705f0();
}


// 0x00274ff0 core::FileOpenByKeyRequest::vfunc_0 (102 B): matches/0x00274ff0.cpp
// sym: ?Dtor@FileOpenByKeyRequest_274ff0@fn_f7190711@@QAEPAV12@E@Z
// data: gAlloc_274ff0 = DAT_0052a1e4
FileOpenByKeyRequest_274ff0* FileOpenByKeyRequest_274ff0::Dtor(unsigned char flag) {
    vt = hulk_at_0042b99c;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = hulk_at_0042b914;
    if (flag & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_274ff0**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x00275060 FUN_00275060 (58 B): matches/0x00275060.cpp
// sym: ?FUN_00275060@SaveGameOpenRequest@fn_f7190711@@QAEPAV12@HHEHH@Z
SaveGameOpenRequest* SaveGameOpenRequest::FUN_00275060(int a, int b, unsigned char c, int d, int e) {
    init_00274e60(a);
    fieldC = b;
    vptr = ((hulk_intptr)DAT_0042ba40);
    field10 = c;
    field14 = d;
    field18 = e;
    FreeFinish_002705f0();
    return this;
}


// 0x002750a0 core::SaveGameOpenRequest::vfunc_0 (102 B): matches/0x002750a0.cpp
// sym: ?vfunc_0@SaveGameOpenRequest@core@fn_f7190711@@QAEPAV123@H@Z
// data: g_mgr_2750a0 = DAT_0052a1e4
core::SaveGameOpenRequest* core::SaveGameOpenRequest::vfunc_0(int flags) {
    Inner_2750a0* p = inner;
    *(void**)this = (void*)((hulk_intptr)DAT_0042b99c);
    ((Inner_2750a0*)((char*)p + 4))->a();
    --*(int*)((char*)inner + 0x18);
    ((Inner_2750a0*)((char*)inner + 4))->b();
    ((Root_2750a0*)inner)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flags & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(Manager_2750a0**)&DAT_0052a1e4)->add(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}


// 0x00275110 FUN_00275110 (30 B): matches/0x00275110.cpp
// sym: ?Init@FileCloseRequest_275110@fn_f7190711@@QAEPAV12@PAX@Z
FileCloseRequest_275110* FileCloseRequest_275110::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042ba60;
    FUN_002705f0();
    return this;
}


// 0x00275130 core::FileCloseRequest::vfunc_0 (102 B): matches/0x00275130.cpp
// sym: ?f0@FileCloseRequest_275130@fn_f7190711@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileCloseRequest_275130* FileCloseRequest_275130::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275130*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275130*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275130*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275130**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x002751a0 FUN_002751a0 (30 B): matches/0x002751a0.cpp
// sym: ?Init@FileCommitRequest_2751a0@fn_f7190711@@QAEPAV12@PAX@Z
FileCommitRequest_2751a0* FileCommitRequest_2751a0::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042ba80;
    FUN_002705f0();
    return this;
}

} // namespace fn_f7190711
