// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273c70..0x00273d50 (kind game, layer engine, confidence medium), dominant class core::SaveGameOpenRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1bb87c2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1bb87c2 {} using namespace fn_f1bb87c2;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f1bb87c2 {
struct Sub_273c70 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273c70 {
    void* v;
    Sub_273c70 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273c70 {
    void* v;
    char pad[4];
    Inner_273c70* p;
    void run();
};
struct Info_273cb0 { char pad[12]; unsigned value; };
struct Backend_273cb0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual int open(char*,unsigned,unsigned,unsigned,unsigned,void*,void*);
 unsigned FUN_00272880();
};
struct Lock_273cb0 { virtual void lock(); virtual void unlock(); };
struct State_273cb0 {
 unsigned unknown0;
 Lock_273cb0 guard;
 unsigned unknown8;
 Backend_273cb0* backend;
 unsigned unknown10;
 unsigned status;
 char pad18[4];
 unsigned char opened;
 char pad1d;
 char name[0x128-0x1e];
 char data128[0x15c-0x128];
 unsigned data15c;
 unsigned data160;
 unsigned value164;
};
class pddiObject_273d40 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_273d40 : public pddiObject_273d40 {};
class pddiBaseShader_273d40 : public pddiShader_273d40 {
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
class d3dShader_273d40 : public pddiBaseShader_273d40 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};


// 0x00273c70 FUN_00273c70 (53 B): matches/0x00273c70.cpp
// sym: ?run@FileRequest_273c70@fn_f1bb87c2@@QAEXXZ
void FileRequest_273c70::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_f1bb87c2

// 0x00273cb0 core::SaveGameOpenRequest::vfunc_1 (129 B): equivalent/0x00273cb0.cpp
// sym: ?vfunc_1@SaveGameOpenRequest@core@@UAEHXZ @59bdffe1a33c @wf74e56f32afc
// STATUS: equivalent (tools/equiv.py level 3: 19867 inputs, branch coverage 2/2)
// core::SaveGameOpenRequest::vfunc_1 @ 0x00273cb0
int core::SaveGameOpenRequest::vfunc_1() {
 State_273cb0* s = (*(State_273cb0 * *)&this->f_08);
 Backend_273cb0* backend = s->backend;
 int result = backend->open(s->name,(*(unsigned int *)&this->f_0c),(*(unsigned char *)&this->f_10),(*(unsigned int *)&this->f_14),(*(unsigned int *)&this->f_18),&s->data15c,s->data128);
 if(result == 1) {
 (*(State_273cb0 * *)&this->f_08)->opened = 1;
 Info_273cb0* info = ((Info_273cb0 *)((owners::ProjectileMissile_2728d0 *)backend)->FUN_002728d0());
 (*(State_273cb0 * *)&this->f_08)->value164 = info->value;
 }
 unsigned status = backend->FUN_00272880();
 (&(*(State_273cb0 * *)&this->f_08)->guard)->lock();
 (*(State_273cb0 * *)&this->f_08)->status = status;
 (&(*(State_273cb0 * *)&this->f_08)->guard)->unlock();
 return result;
}


// 0x00273d40 core::SaveGameOpenRequest::vfunc_6 (6 B): matches/0x00273d40.cpp
// sym: ?vfunc_6@SaveGameOpenRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::SaveGameOpenRequest::vfunc_6() {
    return 1;
}

