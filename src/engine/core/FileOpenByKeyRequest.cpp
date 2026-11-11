// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273b50..0x00273c70 (kind game, layer engine, confidence medium), dominant class core::FileOpenByKeyRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f3859b68 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3859b68 {} using namespace fn_f3859b68;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f3859b68 {
struct Sub_273b50 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273b50 {
    void* v;
    Sub_273b50 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273b50 {
    void* v;
    char pad[4];
    Inner_273b50* p;
    void run();
};
struct Lookup_273b90 {
    File* FUN_00277cb0();
    unsigned FUN_00277cd0();
};
struct Opener {
    bool FUN_002779b0(unsigned key, Lookup_273b90* lookup);
};
struct Manager_273b90 {
    void FUN_002728a0(int);
};
struct Lock_273b90 {
    virtual void lock();
    virtual void unlock();
};
struct File {
    unsigned header;
    Lock_273b90 mutex;
    unsigned field8;
    Manager_273b90* manager;
    char pad10[4];
    unsigned status;
    char pad18[4];
    unsigned char opened;
    char pad1d[0x128 - 0x1d];
    unsigned result;
    Lookup_273b90 lookup;
    char pad12d[0x15c - 0x12d];
    unsigned field15c;
    char pad160[4];
    unsigned field164;
};
namespace core {
struct FileOpenByKeyRequest {
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    unsigned field4;
    File* file;
    unsigned key;
    Opener* opener;
};
}


// 0x00273b50 FUN_00273b50 (53 B): matches/0x00273b50.cpp
// sym: ?run@FileRequest_273b50@fn_f3859b68@@QAEXXZ
void FileRequest_273b50::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}


// 0x00273b90 core::FileOpenByKeyRequest::vfunc_1 (195 B): matches/0x00273b90.cpp
// sym: ?vfunc_1@FileOpenByKeyRequest@core@fn_f3859b68@@UAEHXZ
namespace core {
int FileOpenByKeyRequest::vfunc_1() {
    Manager_273b90* manager = file->manager;
    if (opener->FUN_002779b0(key, &file->lookup)) {
        File* source = file->lookup.FUN_00277cb0();
        file->field15c = source->field15c;
        file->result = file->lookup.FUN_00277cd0();
        file->opened = 1;
        file->field164 = source->field164;
        file->mutex.lock();
        file->status = 0;
        file->mutex.unlock();
        return 1;
    }
    manager->FUN_002728a0(1);
    file->mutex.lock();
    file->status = 1;
    file->mutex.unlock();
    return 0;
}
}


// 0x00273c60 core::FileOpenByKeyRequest::vfunc_6 (3 B): matches/0x00273c60.cpp
// sym: ?GetZero@fn_f3859b68@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f3859b68
