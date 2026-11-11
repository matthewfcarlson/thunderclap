// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0290..0x001f03a0 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayTunableEvent
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f8678f71 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8678f71 {} using namespace fn_f8678f71;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8678f71 {
class CSoundCommand_1f0290 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0290 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
typedef unsigned long U32_1f02b0;
struct Key_1f02b0 { U32_1f02b0 low, high; };
struct Entry_1f02b0 { Key_1f02b0 key; U32_1f02b0 type; char pad[12]; U32_1f02b0 a,b,c; char tail[4]; };
struct Object { char pad[0x80]; Entry_1f02b0 entries[4]; };
struct Lookup_1f02b0 { Object* FUN_001f31a0(U32_1f02b0); };
struct Events_1f02b0 { int FUN_001e98b0(Key_1f02b0*); };
struct Manager_1f02b0 { Lookup_1f02b0* lookup; Events_1f02b0* events; };
struct CSoundCommand_PlayTunableEvent {
 virtual void vfunc_0();
 virtual void vfunc_1(U32_1f02b0, U32_1f02b0);
 char pad[12]; Key_1f02b0 key; U32_1f02b0 type; U32_1f02b0 a,b,c;
};


// 0x001f0290 CSoundCommand_PlayTunableEvent::vfunc_0 (31 B): matches/0x001f0290.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f8678f71@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001f02b0 CSoundCommand_PlayTunableEvent::vfunc_1 (227 B): equivalent/0x001f02b0.cpp
// sym: ?vfunc_1@CSoundCommand_PlayTunableEvent@fn_f8678f71@@UAEXKK@Z @9eb3823f6b4d @wff24f4a3f4ad
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSoundCommand_PlayTunableEvent::vfunc_1 @ 0x001f02b0
void CSoundCommand_PlayTunableEvent::vfunc_1(U32_1f02b0 arg, U32_1f02b0 unused) {
 if (!(*(Manager_1f02b0**)&DAT_004e370c)->events->FUN_001e98b0(&key)) return;
 Object* obj=(*(Manager_1f02b0**)&DAT_004e370c)->lookup->FUN_001f31a0(arg);
 if (!obj) return;
 for(int i=0;i<4;++i) {
  Entry_1f02b0& e=obj->entries[i];
  if(e.type==type && e.key.low==key.low && e.key.high==key.high) return;
 }
 for(int i=0;i<4;++i) {
  unsigned __int64 empty=FUN_002672f0(0,0,0);
  Entry_1f02b0& e=obj->entries[i];
  if(e.key.low==(U32_1f02b0)empty && e.key.high==(U32_1f02b0)(empty>>32)) {
   e.key.low=key.low; e.key.high=key.high; e.type=type;
   e.a=a; e.b=b; e.c=c; return;
  }
 }
}

} // namespace fn_f8678f71
