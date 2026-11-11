// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002737f0..0x002738e0 (kind game, layer engine, confidence high), dominant class core::FileRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fe4fb47f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe4fb47f {} using namespace fn_fe4fb47f;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fe4fb47f {
struct Sub_2737f0 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_2737f0 {
    void* v;
    Sub_2737f0 sub;
    char pad[16];
    int ref;
};
struct FileRequest_2737f0 {
    void* v;
    char pad[4];
    Inner_2737f0* p;
    void run();
};
class Interface_273830 {
  public:
    virtual void First();
    virtual void Second();
};
class Object {
  public:
    char pad[4];
    Interface_273830 iface;
    char pad2[0x0c];
    int value;
};
class Holder_273830 {
  public:
    char pad[8];
    Object* obj;
    int Run(int a, int b);
};
class Request_273860 {
  public:
    char pad[8];
    int field;
};
class ObjV {
  public:
    virtual void a();
    virtual void b();
};
class Inner_273890 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual int h();
    int FUN_00272880();
};
class Inner_2738d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual int f25();
};
class Request_2738d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};


// 0x002737f0 FUN_002737f0 (53 B): matches/0x002737f0.cpp
// sym: ?run@FileRequest_2737f0@fn_fe4fb47f@@QAEXXZ
void FileRequest_2737f0::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}


// 0x00273830 FUN_00273830 (43 B): matches/0x00273830.cpp
// sym: ?Run@Holder_273830@fn_fe4fb47f@@QAEHHH@Z
int Holder_273830::Run(int a, int b) {
    obj->iface.First();
    obj->value = b;
    obj->iface.Second();
    return a;
}

} // namespace fn_fe4fb47f

// 0x00273860 core::FileRequest::vfunc_2 (19 B): matches/0x00273860.cpp
// sym: ?vfunc_2@FileRequest@core@@UAE_NH@Z
bool core::FileRequest::vfunc_2(int value) {
    return value == (*(int *)&this->f_08);
}


// 0x00273880 core::FileRequest::vfunc_3 (7 B): matches/0x00273880.cpp
// sym: ?vfunc_3@FileRequest@core@@UAEHXZ
// the request's drive: its file's (records.h CoreFile provider)
hulk_intptr core::FileRequest::vfunc_3() {
    return (hulk_intptr)((CoreFile*)this->f_08)->provider;
}


// 0x00273890 core::FileRequest::vfunc_4 (63 B): matches/0x00273890.cpp
// sym: ?vfunc_4@FileRequest@core@@UAEHXZ
// core::FileRequest::vfunc_4 (records.h CoreFile): the drive's slot 7, then its error into the file's field14
// (under the file's IMutable lock)
int core::FileRequest::vfunc_4() {
    Inner_273890* p = (Inner_273890*)((CoreFile*)this->f_08)->provider;
    int first = p->h();
    int second = p->FUN_00272880();
    ((ObjV*)&((CoreFile*)this->f_08)->vftableMutable)->a();
    ((CoreFile*)this->f_08)->field14 = second;
    ((ObjV*)&((CoreFile*)this->f_08)->vftableMutable)->b();
    return first;
}


// 0x002738d0 core::FileRequest::vfunc_5 (8 B): matches/0x002738d0.cpp
// sym: ?vfunc_5@FileRequest@core@@UAEPAXXZ
void* core::FileRequest::vfunc_5() {
    return (void*)((*(Inner_2738d0 * *)&this->f_08)->f25());
}

