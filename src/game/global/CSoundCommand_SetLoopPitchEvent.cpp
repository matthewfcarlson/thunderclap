// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f03a0..0x001f04e0 (kind game, layer game, confidence medium), dominant class CSoundCommand_SetLoopPitchEvent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f43ad3f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f43ad3f1 {} using namespace fn_f43ad3f1;
namespace fn_f43ad3f1 { extern "C" char DAT_004245a4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f43ad3f1 {
typedef unsigned __int64 I64;
} // namespace fn_f43ad3f1
extern "C" I64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f43ad3f1 {
struct Pair {
    int lo, hi;
    Pair() : lo(0), hi(0) {}
    void operator=(I64 v) {
        lo = (int)v;
        hi = (int)(v >> 32);
    }
};
class CSoundCommand_1f03a0 {
  public:
    int a, b, c;
    CSoundCommand_1f03a0() : a(0), b(0), c(0) {}
};
class CSoundCommand_SetLoopPitchEvent : public CSoundCommand_1f03a0 {
  public:
    virtual void* Fn_001f0400(char);
    Pair value;
    int mid, arg1, arg2;
    CSoundCommand_SetLoopPitchEvent(int, int, int, int, int);
};
class CSoundCommand_1f0400 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0400 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001f03a0 FUN_001f03a0 (83 B): matches/0x001f03a0.cpp
// sym: ??0CSoundCommand_SetLoopPitchEvent@fn_f43ad3f1@@QAE@HHHHH@Z
CSoundCommand_SetLoopPitchEvent::CSoundCommand_SetLoopPitchEvent(int x, int y, int z, int w, int unused) {
    value = FUN_002672f0(x, 0, 0);
    mid = FUN_002673a0(y, 0);
    arg1 = z;
    arg2 = w;
}


// 0x001f0400 CSoundCommand_SetLoopPitchEvent::vfunc_0 (31 B): matches/0x001f0400.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f43ad3f1@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f43ad3f1

// 0x001f0420 CSoundCommand_SetLoopPitchEvent::vfunc_1 (183 B): equivalent/0x001f0420.cpp [wrapped: conflict: CSoundCommand_SetLoopPitchEvent]
// sym: ?vfunc_1@CSoundCommand_SetLoopPitchEvent@fn_001f0420@@UAEIII@Z @430b9fced5aa @w198158c71e0a
namespace fn_001f0420 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// CSoundCommand_SetLoopPitchEvent::vfunc_1 @ 0x001f0420

struct SoundKey { unsigned int low, high; };
struct LoopState { SoundKey key; unsigned int eventId; unsigned char pitchActive; char pad[3]; float pitch; float pitchStep; char rest[16]; };
struct SoundInstance { char pad[0x80]; LoopState loops[4]; };
struct Lookup_1f0420 { int FUN_001e98b0(SoundKey*); };
struct Instances { SoundInstance* FUN_001f31a0(unsigned int); };
struct SoundSystem_1f0420 { Instances* instances; Lookup_1f0420* lookup; };
struct CSoundCommand { virtual void vfunc_0(); virtual unsigned int vfunc_1(unsigned int, unsigned int); char pad[12]; };
struct CSoundCommand_SetLoopPitchEvent : CSoundCommand {
 SoundKey key; unsigned int eventId; float pitch; float duration;
 virtual void vfunc_0(); virtual unsigned int vfunc_1(unsigned int instanceId, unsigned int unused);
};
unsigned int CSoundCommand_SetLoopPitchEvent::vfunc_1(unsigned int instanceId, unsigned int unused) {
 if (!(*(SoundSystem_1f0420**)&DAT_004e370c)->lookup->FUN_001e98b0(&key)) return 0;
 SoundInstance* instance = (*(SoundSystem_1f0420**)&DAT_004e370c)->instances->FUN_001f31a0(instanceId);
 if (!instance) return 0;
 for (int i=0; i<4; ++i) {
  LoopState& loop = instance->loops[i];
  if (loop.eventId == eventId && loop.key.low == key.low && loop.key.high == key.high) {
   loop.pitchActive = 1; loop.pitch = pitch;
   unsigned int status;
   if (duration < 0.01f) { loop.pitchStep = 0.0f; status = 0x100; }
   else {
    if (duration == 0.01f) status = 0x4000;
    else if (duration > 0.01f) status = 0;
    else status = 0x4500;
    loop.pitchStep = (pitch - 1.0f) / (duration * 16.666666f);
   }
   return ((hulk_uintptr)instance & 0xffff0000U) | status;
  }
 }
 return (hulk_uintptr)instance;
}
} // namespace fn_001f0420

