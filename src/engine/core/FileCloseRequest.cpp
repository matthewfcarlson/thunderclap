// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273d50..0x00273e20 (kind game, layer engine, confidence high), dominant class core::FileCloseRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f4e0aa71 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4e0aa71 {} using namespace fn_f4e0aa71;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f4e0aa71 {
struct Sub_273d50 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273d50 {
    void* v;
    Sub_273d50 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273d50 {
    void* v;
    char pad[4];
    Inner_273d50* p;
    void run();
};
class pddiObject_273d90 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_273d90 : public pddiObject_273d90 {};
class pddiBaseShader_273d90 : public pddiShader_273d90 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_273d90 : public pddiBaseShader_273d90 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
struct Sink_273da0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Do(int a, char* b);
};
struct Sub_273da0 {
    virtual void Fin();
    virtual void Rel();
};
struct View_273da0 {
    bool FUN_00277ca0();
    void FUN_00277ce0();
};


// 0x00273d50 FUN_00273d50 (53 B): matches/0x00273d50.cpp
// sym: ?run@FileRequest_273d50@fn_f4e0aa71@@QAEXXZ
void FileRequest_273d50::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_f4e0aa71

// 0x00273d90 core::FileCloseRequest::vfunc_4 (6 B): matches/0x00273d90.cpp
// sym: ?vfunc_4@FileCloseRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::FileCloseRequest::vfunc_4() {
    return 1;
}


// 0x00273da0 core::FileCloseRequest::vfunc_1 (110 B): matches/0x00273da0.cpp
// sym: ?vfunc_1@FileCloseRequest@core@@UAEHXZ
// the file's drive: slot 10 closes a handle (core::XboxDrive 0x0026f1d0)
// core::FileCloseRequest::vfunc_1 (records.h CoreFile): closes the drive's handle (the view's word 11) or the view,
// then the file is closed (flag1c) and its error cleared (field14, under its IMutable lock)
int core::FileCloseRequest::vfunc_1() {
    Sink_273da0* s = (Sink_273da0*)((CoreFile*)this->f_08)->provider;
    if (!((View_273da0*)&((CoreFile*)this->f_08)->view)->FUN_00277ca0())
        s->Do((int)((CoreFile*)this->f_08)->view.words[11], ((CoreFile*)this->f_08)->filename);
    else
        ((View_273da0*)&((CoreFile*)this->f_08)->view)->FUN_00277ce0();
    ((CoreFile*)this->f_08)->flag1c = 0;
    ((Sub_273da0*)&((CoreFile*)this->f_08)->vftableMutable)->Fin();
    ((CoreFile*)this->f_08)->field14 = 0;
    ((Sub_273da0*)&((CoreFile*)this->f_08)->vftableMutable)->Rel();
    return 1;
}


// 0x00273e10 core::FileCloseRequest::vfunc_6 (6 B): matches/0x00273e10.cpp
// sym: ?vfunc_6@FileCloseRequest@core@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int core::FileCloseRequest::vfunc_6() {
    return 2;
}

