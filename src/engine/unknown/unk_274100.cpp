// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274100..0x002742f0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fdf65e9e {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdf65e9e {} using namespace fn_fdf65e9e;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fdf65e9e {
struct Sub_274100 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_274100 {
    void* v;
    Sub_274100 sub;
    char pad[16];
    int ref;
};
struct FileRequest_274100 {
    void* v;
    char pad[4];
    Inner_274100* p;
    void run();
};
struct Sub_274140 {
    virtual void a();
    virtual void b();
};
struct File_274140 {
    char pad0[4];
    Sub_274140 sub;
    char pad1[0xc];
    int state;
    char pad2[0x124 - 0x18];
    int position;
};
struct Sub_274190 {
    virtual void f();
    virtual void g();
};
struct Inner_274190 {
    void* v;
    Sub_274190 sub;
    char pad[16];
    int ref;
};
struct FileRequest_274190 {
    void* v;
    char pad[4];
    Inner_274190* p;
    void run();
};
class FileIface {
  public:
    virtual void f0();
    virtual void f1();
};
class ParamValue_274210 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
struct Sub_274220 {
    virtual void f();
    virtual void g();
};
struct Inner_274220 {
    void* v;
    Sub_274220 sub;
    char pad[16];
    int ref;
};
struct FileRequest_274220 {
    void* v;
    char pad[4];
    Inner_274220* p;
    void run();
};
class FileOps {
  public:
    virtual void First();
    virtual void Second();
};
class ParamValue_2742a0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
struct Sub_2742b0 {
    virtual void f();
    virtual void g();
};
struct Inner_2742b0 {
    void* v;
    Sub_2742b0 sub;
    char pad[16];
    int ref;
};
struct FileRequest_2742b0 {
    void* v;
    char pad[4];
    Inner_2742b0* p;
    void run();
};


// 0x00274100 FUN_00274100 (53 B): matches/0x00274100.cpp
// sym: ?run@FileRequest_274100@fn_fdf65e9e@@QAEXXZ
void FileRequest_274100::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_fdf65e9e

// 0x00274140 core::FileSetPositionRequest::vfunc_1 (55 B): matches/0x00274140.cpp
// sym: ?vfunc_1@FileSetPositionRequest@core@@UAEHXZ
int core::FileSetPositionRequest::vfunc_1() {
    (*(File_274140 * *)&this->f_08)->position = this->f_0c;
    (*(File_274140 * *)&this->f_08)->sub.a();
    (*(File_274140 * *)&this->f_08)->state = 0;
    (*(File_274140 * *)&this->f_08)->sub.b();
    return 1;
}


// 0x00274180 core::FileSetPositionRequest::vfunc_6 (6 B): matches/0x00274180.cpp
// sym: ?vfunc_6@FileSetPositionRequest@core@@UAEHXZ
// Same code shape as 0x0004df30 (propagated; names are from that function)
int core::FileSetPositionRequest::vfunc_6() {
    return 6;
}

namespace fn_fdf65e9e {

// 0x00274190 FUN_00274190 (53 B): matches/0x00274190.cpp
// sym: ?run@FileRequest_274190@fn_fdf65e9e@@QAEXXZ
void FileRequest_274190::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_fdf65e9e

// 0x002741d0 core::FileGetPositionRequest::vfunc_1 (56 B): matches/0x002741d0.cpp
// sym: ?vfunc_1@FileGetPositionRequest@core@@UAEHXZ
// core::FileGetPositionRequest::vfunc_1 (records.h CoreFile): the file's position (field124) into the caller's
// word, the file's field14 cleared (under its IMutable lock)
int core::FileGetPositionRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = ((CoreFile*)this->f_08)->field124;
    ((FileIface*)&((CoreFile*)this->f_08)->vftableMutable)->f0();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((FileIface*)&((CoreFile*)this->f_08)->vftableMutable)->f1();
    return 1;
}


// 0x00274210 core::FileGetPositionRequest::vfunc_6 (6 B): matches/0x00274210.cpp
// sym: ?vfunc_6@FileGetPositionRequest@core@@UAEHXZ
// Same code shape as 0x0004f4b0 (propagated; names are from that function)
int core::FileGetPositionRequest::vfunc_6() {
    return 7;
}

namespace fn_fdf65e9e {

// 0x00274220 FUN_00274220 (53 B): matches/0x00274220.cpp
// sym: ?run@FileRequest_274220@fn_fdf65e9e@@QAEXXZ
void FileRequest_274220::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_fdf65e9e

// 0x00274260 core::FileGetSizeRequest::vfunc_1 (56 B): matches/0x00274260.cpp
// sym: ?vfunc_1@FileGetSizeRequest@core@@UAEHXZ
// core::FileGetSizeRequest::vfunc_1 (records.h CoreFile): the file's size (field128) into the caller's word, the
// file's field14 cleared (under its IMutable lock)
int core::FileGetSizeRequest::vfunc_1() {
    *(*(int * *)&this->f_0c) = ((CoreFile*)this->f_08)->field128;
    ((FileOps*)&((CoreFile*)this->f_08)->vftableMutable)->First();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((FileOps*)&((CoreFile*)this->f_08)->vftableMutable)->Second();
    return 1;
}


// 0x002742a0 core::FileGetSizeRequest::vfunc_6 (6 B): matches/0x002742a0.cpp
// sym: ?vfunc_6@FileGetSizeRequest@core@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int core::FileGetSizeRequest::vfunc_6() {
    return 8;
}

namespace fn_fdf65e9e {

// 0x002742b0 FUN_002742b0 (53 B): matches/0x002742b0.cpp
// sym: ?run@FileRequest_2742b0@fn_fdf65e9e@@QAEXXZ
void FileRequest_2742b0::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_fdf65e9e
