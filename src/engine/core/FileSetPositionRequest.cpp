// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275230..0x00275430 (kind game, layer engine, confidence medium), dominant class core::FileSetPositionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f05693a4 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f05693a4 {} using namespace fn_f05693a4;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f05693a4 {
extern "C" char DAT_0042baa0[];
extern "C" int* FUN_002705f0();
class FileReadRequest_275230 : public CoreRequest {
  public:
    void* buffer;
    unsigned int count;
    unsigned int flags;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileReadRequest_275230* Init(void*, void*, unsigned int, unsigned int);
};
struct Lock_275270 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275270 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275270 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileReadRequest_275270 : public CoreRequest {
  public:
    FileReadRequest_275270* f0(unsigned char flags);
};
extern "C" char DAT_0042bac0[];
class FileWriteRequest_2752e0 : public CoreRequest {
  public:
    void* buffer;
    unsigned int count;
    unsigned int flags;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileWriteRequest_2752e0* Init(void*, void*, unsigned int, unsigned int);
};
struct Lock_275320 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275320 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275320 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileWriteRequest_275320 : public CoreRequest {
  public:
    FileWriteRequest_275320* f0(unsigned char flags);
};
extern "C" char DAT_0042bae0[];
class FileSetPositionRequest_275390 : public CoreRequest {
  public:
    unsigned int position;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileSetPositionRequest_275390* Init(void*, unsigned int);
};
struct Lock_2753c0 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_2753c0 {
    virtual void v0();
    virtual void release();
};
struct Alloc_2753c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileSetPositionRequest_2753c0 : public CoreRequest {
  public:
    FileSetPositionRequest_2753c0* f0(unsigned char flags);
};


// 0x00275230 FUN_00275230 (51 B): matches/0x00275230.cpp
// sym: ?Init@FileReadRequest_275230@fn_f05693a4@@QAEPAV12@PAX0II@Z
FileReadRequest_275230* FileReadRequest_275230::Init(void* file, void* buffer_, unsigned int count_, unsigned int flags_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042baa0;
    buffer = buffer_;
    count = count_;
    flags = flags_;
    FUN_002705f0();
    return this;
}


// 0x00275270 core::FileReadRequest::vfunc_0 (102 B): matches/0x00275270.cpp
// sym: ?f0@FileReadRequest_275270@fn_f05693a4@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileReadRequest_275270* FileReadRequest_275270::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275270*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275270*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275270*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275270**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x002752e0 FUN_002752e0 (51 B): matches/0x002752e0.cpp
// sym: ?Init@FileWriteRequest_2752e0@fn_f05693a4@@QAEPAV12@PAX0II@Z
FileWriteRequest_2752e0* FileWriteRequest_2752e0::Init(void* file, void* buffer_, unsigned int count_, unsigned int flags_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bac0;
    buffer = buffer_;
    count = count_;
    flags = flags_;
    FUN_002705f0();
    return this;
}


// 0x00275320 core::FileWriteRequest::vfunc_0 (102 B): matches/0x00275320.cpp
// sym: ?f0@FileWriteRequest_275320@fn_f05693a4@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileWriteRequest_275320* FileWriteRequest_275320::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275320*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275320*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275320*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275320**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}


// 0x00275390 FUN_00275390 (37 B): matches/0x00275390.cpp
// sym: ?Init@FileSetPositionRequest_275390@fn_f05693a4@@QAEPAV12@PAXI@Z
FileSetPositionRequest_275390* FileSetPositionRequest_275390::Init(void* file, unsigned int position_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bae0;
    position = position_;
    FUN_002705f0();
    return this;
}


// 0x002753c0 core::FileSetPositionRequest::vfunc_0 (102 B): matches/0x002753c0.cpp
// sym: ?f0@FileSetPositionRequest_2753c0@fn_f05693a4@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileSetPositionRequest_2753c0* FileSetPositionRequest_2753c0::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_2753c0*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_2753c0*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_2753c0*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_2753c0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f05693a4
