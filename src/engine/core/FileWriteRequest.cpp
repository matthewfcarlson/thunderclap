// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274020..0x00274100 (kind game, layer engine, confidence medium), dominant class core::FileWriteRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f015241e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f015241e {} using namespace fn_f015241e;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f015241e {
struct Sub_274020 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_274020 {
    void* v;
    Sub_274020 sub;
    char pad[16];
    int ref;
};
struct FileRequest_274020 {
    void* v;
    char pad[4];
    Inner_274020* p;
    void run();
};
namespace core {
struct Backend_274060 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual int write(unsigned handle, char* name, unsigned mode, unsigned position, void* buffer, unsigned size, unsigned* written, unsigned* state, unsigned flags);
 unsigned FUN_00272880();
};
}
namespace core {
struct Lock_274060 { virtual void lock(); virtual void unlock(); };
}
namespace core {
struct File {
 unsigned unknown0;
 Lock_274060 lock;
 unsigned unknown8;
 Backend_274060* backend;
 unsigned unknown10;
 unsigned status;
 char padding18[6];
 char name[0x102];
 unsigned mode;
 unsigned position;
 unsigned state;
 char padding12c[0x30];
 unsigned handle;
};
}
namespace core {
struct FileWriteRequest {
 virtual void vfunc_0();
 virtual int vfunc_1();
 virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned unknown4;
 File* file;
 void* buffer;
 unsigned size;
 unsigned flags;
};
}


// 0x00274020 FUN_00274020 (53 B): matches/0x00274020.cpp
// sym: ?run@FileRequest_274020@fn_f015241e@@QAEXXZ
void FileRequest_274020::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}


// 0x00274060 core::FileWriteRequest::vfunc_1 (144 B): equivalent/0x00274060.cpp
// sym: ?vfunc_1@FileWriteRequest@core@fn_f015241e@@UAEHXZ
// STATUS: equivalent (tools/equiv.py level 3: 19896 inputs, branch coverage 4/4)
// core::FileWriteRequest::vfunc_1 @ 0x00274060
namespace core {
int FileWriteRequest::vfunc_1() {
 unsigned written = (unsigned)this;
 Backend_274060* backend = file->backend;
 int result = 1;
 if (size != 0) {
 result = backend->write(file->handle, file->name, file->mode, file->position, buffer, size, &written, &file->state, flags);
 if (result == 1) file->position += written;
 }
 unsigned status = backend->FUN_00272880();
 (&file->lock)->lock();
 file->status = status;
 (&file->lock)->unlock();
 return result;
}
}


// 0x002740f0 core::FileWriteRequest::vfunc_6 (6 B): matches/0x002740f0.cpp
// sym: ?FUN_002740f0@fn_f015241e@@YAHXZ
// Same code shape as 0x0008c580 (propagated; names are from that function)
int FUN_002740f0() {
    return 5;
}

} // namespace fn_f015241e
