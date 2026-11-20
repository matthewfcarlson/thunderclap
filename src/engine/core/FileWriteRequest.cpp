// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274020..0x00274100 (kind game, layer engine, confidence medium), dominant class core::FileWriteRequest
#include "tree_prelude.h"
#include "decls/data/records.h"
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
// (drive1, D141) the file is records.h CoreFile (was a 32-bit pad view: natively its words sat 4-12 bytes off)
namespace core {
struct FileWriteRequest {
 virtual void vfunc_0();
 virtual int vfunc_1();
 virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned unknown4;
 CoreFile* file;
 void* buffer;
 unsigned size;
 unsigned flags;
};
}


// 0x00274020 FUN_00274020 (53 B): matches/0x00274020.cpp
// sym: ?run@FileRequest_274020@fn_f015241e@@QAEXXZ
void FileRequest_274020::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    ((Sub_274020*)&((CoreFile*)p)->vftableMutable)->f();
    --((CoreFile*)p)->field18;
    ((Sub_274020*)&((CoreFile*)p)->vftableMutable)->g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}


// 0x00274060 core::FileWriteRequest::vfunc_1 (144 B): equivalent/0x00274060.cpp
// sym: ?vfunc_1@FileWriteRequest@core@fn_f015241e@@UAEHXZ @aa5d99e9e224 @w136a99df9219 @vd64f414da669
// STATUS: equivalent (tools/equiv.py level 3: 19896 inputs, branch coverage 4/4)
// core::FileWriteRequest::vfunc_1 @ 0x00274060
namespace core {
int FileWriteRequest::vfunc_1() {
 unsigned written = (unsigned)(hulk_uintptr)this;
 Backend_274060* backend = (Backend_274060*)file->provider;
 int result = 1;
 if (size != 0) {
 result = backend->write(file->view.tail[1], file->filename, file->field120, file->field124, buffer, size, &written, &file->field128, flags);
 if (result == 1) file->field124 += written;
 }
 unsigned status = backend->FUN_00272880();
 ((Lock_274060*)&file->vftableMutable)->lock();
 file->field14 = status;
 ((Lock_274060*)&file->vftableMutable)->unlock();
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
