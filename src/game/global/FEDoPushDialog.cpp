// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1250..0x000f1350 (kind game, layer game, confidence medium), dominant class FEDoPushDialog
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f2672b45 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2672b45 {} using namespace fn_f2672b45;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2672b45 {
class FEParticleSystem {
  public:
    virtual FEParticleSystem* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[0x24];
    struct Ref_f1250* ptr;
};
class Ref_f1250 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void cleanup_0008d330(FEParticleSystem*);
struct DialogManager_f1290 { void FUN_000be230(const char*,const char*,const char*,const char*,const char*,int,int,int); };
struct Owner_f1290 { char pad[4]; DialogManager_f1290* manager; };
struct FEDoAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); };
struct FEDoPushDialog : FEDoAction { char pad04[12]; Owner_f1290* owner; char pad14[32]; char name[32]; char text[256]; char a[32]; char b[32]; char c[32]; int flags; virtual void vfunc_1(); };


// 0x000f1250 FEParticleSystem::vfunc_0 (50 B): matches/0x000f1250.cpp
// sym: ?vfunc_0@FEParticleSystem@fn_f2672b45@@UAEPAV12@E@Z
FEParticleSystem* FEParticleSystem::vfunc_0(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040bfe0);
    _ReadWriteBarrier();
    if (ptr) {
        ptr->Release();
        ptr = 0;
    }
    if (flags & 1)
        cleanup_0008d330(this);
    return this;
}


// 0x000f1290 FEDoPushDialog::vfunc_1 (189 B): equivalent/0x000f1290.cpp
// sym: ?vfunc_1@FEDoPushDialog@fn_f2672b45@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// FEDoPushDialog::vfunc_1 @ 0x000f1290
void FEDoPushDialog::vfunc_1() {
 const char* sources[4] = {text,a,b,c};
 const char* values[4];
 for(int i=0;i<4;++i) { const char* s=sources[i]; values[i]=(s[0]=='-' && s[1]==0)?0:s; }
 owner->manager->FUN_000be230(name,values[0],values[1],values[2],values[3],flags,0,0);
}

} // namespace fn_f2672b45
