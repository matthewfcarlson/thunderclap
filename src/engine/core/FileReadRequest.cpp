// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273e20..0x00274020 (kind game, layer engine, confidence medium), dominant class core::FileReadRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9b32c3b {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9b32c3b {} using namespace fn_f9b32c3b;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f9b32c3b {
struct Sub_273e20 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273e20 {
    void* v;
    Sub_273e20 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273e20 {
    void* v;
    char pad[4];
    Inner_273e20* p;
    void run();
};
class Inner_273e60 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual int k(int, int);
    int Fnm_00272880();
};
class Sub_273e60 {
  public:
    virtual void a();
    virtual void b();
};
struct Data_273e60 {
    char pad0[4];
    Sub_273e60 sub;
    char pad8[4];
    Inner_273e60* inner;
    char pad10[4];
    int y;
    char pad18[0x15c - 0x18];
    int field;
};
class ParamValue_273eb0 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
struct Sub_273ec0 {
    virtual void f();
    virtual void g();
};
struct Inner_273ec0 {
    void* v;
    Sub_273ec0 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273ec0 {
    void* v;
    char pad[4];
    Inner_273ec0* p;
    void run();
};
struct Info_273f00 { char pad[12]; uint limit; };
struct Device_273f00 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual int read(uint, char*, uint, uint, void*, uint, uint*, uint);
 Info_273f00* FUN_002728d0(); uint FUN_00272880();
};
struct Lock_273f00 { virtual void enter(); virtual void leave(); };
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,uint);
extern bool __fastcall FUN_00277ca0(int* ptr);
struct FileReadRequest_273f00 : CoreRequest {
 void* buffer; uint size; uint flags;
 int vfunc_1();
};
class ParamValue_274010 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};


// 0x00273e20 FUN_00273e20 (53 B): matches/0x00273e20.cpp
// sym: ?run@FileRequest_273e20@fn_f9b32c3b@@QAEXXZ
void FileRequest_273e20::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_f9b32c3b

// 0x00273e60 core::FileCommitRequest::vfunc_1 (75 B): matches/0x00273e60.cpp
// sym: ?vfunc_1@FileCommitRequest@core@@UAEHXZ
int core::FileCommitRequest::vfunc_1() {
    Data_273e60* d = (*(Data_273e60 *volatile *)&this->f_08);
    Inner_273e60* i = d->inner;
    int x = i->k(d->field, (hulk_intptr)((char*)d + 0x1e));
    int z = i->Fnm_00272880();
    (*(Data_273e60 *volatile *)&this->f_08)->sub.a();
    (*(Data_273e60 *volatile *)&this->f_08)->y = z;
    (*(Data_273e60 *volatile *)&this->f_08)->sub.b();
    return x;
}


// 0x00273eb0 core::FileCommitRequest::vfunc_6 (6 B): matches/0x00273eb0.cpp
// sym: ?vfunc_6@FileCommitRequest@core@@UAEHXZ
// Same code shape as 0x0004f880 (propagated; names are from that function)
int core::FileCommitRequest::vfunc_6() {
    return 3;
}

namespace fn_f9b32c3b {

// 0x00273ec0 FUN_00273ec0 (53 B): matches/0x00273ec0.cpp
// sym: ?run@FileRequest_273ec0@fn_f9b32c3b@@QAEXXZ
void FileRequest_273ec0::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}


// 0x00273f00 core::FileReadRequest::vfunc_1 (266 B): equivalent/0x00273f00.cpp
// sym: ?vfunc_1@FileReadRequest_273f00@fn_f9b32c3b@@QAEHXZ @466f63045287 @w8dbdc455f26a
// STATUS: equivalent (tools/equiv.py level 3: 19905 inputs, branch coverage 10/10)
// core::FileReadRequest::vfunc_1 @ 0x00273f00
// core::FileReadRequest::vfunc_1 (records.h CoreFile): reads at the file's position (field124) up to its length
// (field128) and the drive's limit, through the cement library view when the file has one (0x00277ca0 /
// 0x00278010), else the drive's slot 12; the drive's error goes to the file's field14
int FileReadRequest_273f00::vfunc_1() {
 uint length=((CoreFile*)file)->field128;
 hulk_uintptr count=size;
 Device_273f00* device=(Device_273f00*)((CoreFile*)file)->provider;
 if(((CoreFile*)file)->field124>=length) count=0;
 hulk_uintptr maximum=FUN_0026fd50(length,device->FUN_002728d0()->limit);
 uint position=((CoreFile*)file)->field124;
 if(position+count>maximum) count=maximum-position;
 int result;
 if(count) {
  uint transferred;
  bool useReader=FUN_00277ca0((int*)&((CoreFile*)file)->view);
  CoreFile* current=(CoreFile*)file;
  if(useReader) result=((owners::Obj_278010*)&current->view)->FUN_00278010((hulk_intptr)device,current->view.words[11],(hulk_intptr)current->filename,current->field120,current->field124,(hulk_intptr)buffer,(int)count,(hulk_intptr)&transferred,flags);
  else result=device->read(current->view.words[11],current->filename,current->field120,current->field124,buffer,(uint)count,&transferred,flags);
  if(result==1) ((CoreFile*)file)->field124+=transferred;
 } else result=1;
 uint status=device->FUN_00272880();
 ((Lock_273f00*)&((CoreFile*)file)->vftableMutable)->enter();
 ((CoreFile*)file)->field14=status;
 ((Lock_273f00*)&((CoreFile*)file)->vftableMutable)->leave();
 return result;
}

} // namespace fn_f9b32c3b

// 0x00274010 core::FileReadRequest::vfunc_6 (6 B): matches/0x00274010.cpp
// sym: ?vfunc_6@FileReadRequest@core@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int core::FileReadRequest::vfunc_6() {
    return 4;
}

