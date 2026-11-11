// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002738e0..0x00273b50 (kind game, layer engine, confidence medium), dominant class core::FileOpenRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff7ceca7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff7ceca7 {} using namespace fn_ff7ceca7;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff7ceca7 {
struct Sub_2738e0 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_2738e0 {
    void* v;
    Sub_2738e0 sub;
    char pad[16];
    int ref;
};
struct FileRequest_2738e0 {
    void* v;
    char pad[4];
    Inner_2738e0* p;
    void run();
};
struct Match { void* FUN_00277cb0(); };
struct Candidate_273920 { bool FUN_00277b40(char*, CoreFileView*); };
struct Iterator_273920 {  Candidate_273920* FUN_00277600(); };
struct Info_273920 { char pad[12]; int value; };
struct Backend_273920 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual int open(char*,int,unsigned int,int*,int*); Iterator_273920* FUN_00272bc0();  int FUN_00272880(); };
struct Lock_273920 { virtual void acquire(); virtual void release(); };


// 0x002738e0 FUN_002738e0 (53 B): matches/0x002738e0.cpp
// sym: ?run@FileRequest_2738e0@fn_ff7ceca7@@QAEXXZ
void FileRequest_2738e0::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_ff7ceca7

// 0x00273920 core::FileOpenRequest::vfunc_1 (533 B): equivalent/0x00273920.cpp
// sym: ?vfunc_1@FileOpenRequest@core@@UAEHXZ
// STATUS: equivalent (tools/equiv.py level 3: 19788 inputs, branch coverage 14/14)
// core::FileOpenRequest::vfunc_1 @ 0x00273920
// core::FileOpenRequest::vfunc_1 (records.h CoreFile): the file is looked up in the drive's cement libraries
// (0x00272bc0's list; a match fills the file's view, 0x00277b40) before the drive opens it itself (slot 8);
// the handle is the view's word 11 (+0x15c), the size field128, the drive's sector info field164, the error field14
int core::FileOpenRequest::vfunc_1() {
 Backend_273920* backend=(Backend_273920*)((CoreFile*)this->f_08)->provider;
 Iterator_273920* it=backend->FUN_00272bc0();
 ((owners::X_2775f0 *)it)->FUN_002775f0(0);
 Candidate_273920* candidate=it->FUN_00277600();
 bool found=false;
 while(candidate) { if(candidate->FUN_00277b40(((CoreFile*)this->f_08)->filename,&((CoreFile*)this->f_08)->view)) { found=true; break; } candidate=it->FUN_00277600(); }
 int status=1;
 if(!found) {
 status=backend->open(((CoreFile*)this->f_08)->filename,this->f_0c,(*(unsigned char *)&this->f_10),(int*)&((CoreFile*)this->f_08)->view.words[11],(int*)&((CoreFile*)this->f_08)->field128);
 if(status==1) { ((CoreFile*)this->f_08)->flag1c=1; Info_273920* info=((Info_273920 *)((owners::ProjectileMissile_2728d0 *)backend)->FUN_002728d0()); ((CoreFile*)this->f_08)->field164=info->value; int result=backend->FUN_00272880(); ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->acquire(); ((CoreFile*)this->f_08)->field14=result; ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->release(); return 1; }
 ((owners::X_2775f0 *)it)->FUN_002775f0(1);
 candidate=it->FUN_00277600();
 while(candidate) { if(candidate->FUN_00277b40(((CoreFile*)this->f_08)->filename,&((CoreFile*)this->f_08)->view)) { found=true; break; } candidate=it->FUN_00277600(); }
 if(!found) { int result=backend->FUN_00272880(); ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->acquire(); ((CoreFile*)this->f_08)->field14=result; ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->release(); return status; }
 }
 CoreFile* source=(CoreFile*)((Match*)&((CoreFile*)this->f_08)->view)->FUN_00277cb0();
 ((CoreFile*)this->f_08)->view.words[11]=source->view.words[11];
 int size=((int)((owners::C_277cd0 *)&((CoreFile*)this->f_08)->view)->FUN_00277cd0()); ((CoreFile*)this->f_08)->field128=size;
 ((CoreFile*)this->f_08)->flag1c=1;
 ((CoreFile*)this->f_08)->field164=source->field164;
 ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->acquire(); ((CoreFile*)this->f_08)->field14=0; ((Lock_273920*)&((CoreFile*)this->f_08)->vftableMutable)->release(); return 1;
}

namespace fn_ff7ceca7 {

// 0x00273b40 core::FileOpenRequest::vfunc_6 (3 B): matches/0x00273b40.cpp
// sym: ?GetZero@fn_ff7ceca7@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_ff7ceca7
