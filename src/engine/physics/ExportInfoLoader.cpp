// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f4df0..0x002f5130 (kind game, layer engine, confidence medium), dominant class physics::ExportInfoLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f1098e70 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f1098e70 {} using namespace fn_f1098e70;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f1098e70 {
struct Sub_2f4df0 { void FUN_002f7a40(); void FUN_002f7a80(void*); };
struct G_2f4df0 { char pad[HULK_PW_SOLVER]; Sub_2f4df0 sub; };  // (x64t4) decls/physics_world.h
struct Agent_2f4df0 { Agent_2f4df0* FUN_002f8800(); };
extern "C" void __cdecl FUN_002ecb90(int);
extern "C" void __cdecl FUN_002f2e20();
extern "C" void __cdecl FUN_003077c0();
extern "C" void __cdecl FUN_002ed020();
extern "C" void __cdecl FUN_002ef0b0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_f1098e70
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char* dst, const char* fmt, ...);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int memcmp(const void* a, const void* b, unsigned int n);
#endif
namespace fn_f1098e70 {
struct Stream_2f4eb0 {
    char pad0[0xc];
    char open;
    char pad1;
    char binary;
    char FUN_002647e0(void* dest, unsigned count, unsigned size, int flag);
};
struct Reader_2f4eb0 {
    char pad[0x284];
    Stream_2f4eb0* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
void FUN_002ecb70();
struct Frame_2f4eb0 {
    char pad[2];
    unsigned char len1;
    unsigned char len2;
    char unitsName[0x20];
    char tag[0x80];
    char msg[0x64];
};


// 0x002f4df0 FUN_002f4df0 (126 B): equivalent/0x002f4df0.cpp
// sym: _FUN_002f4df0 @069865455171 @w5ac6d837b811
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 4/4)
// FUN_002f4df0 @ 0x002f4df0
extern "C" void FUN_002f4df0(int arg, void* handler){
  (*(unsigned char*)&DAT_0055544c) = 1;
  FUN_002ecb90(arg);
  FUN_002f2e20();
  FUN_003077c0();
  FUN_002ed020();
  FUN_002ef0b0();
  (*(G_2f4df0**)&DAT_00554c14)->sub.FUN_002f7a40();
  if (handler == 0) {
    void* mem = FUN_0008d690(0xc);
    if (mem) handler = ((Agent_2f4df0*)mem)->FUN_002f8800();
  }
  (*(G_2f4df0**)&DAT_00554c14)->sub.FUN_002f7a80(handler);
}

} // namespace fn_f1098e70

// 0x002f4eb0 physics::ExportInfoLoader::vfunc_5 (565 B): equivalent/0x002f4eb0.cpp
// sym: ?vfunc_5@ExportInfoLoader@physics@@UAEXPAX00H@Z @abda00c72a4c @w20b6908e46f4
// STATUS: equivalent (tools/equiv.py level 3: 275 inputs, branch coverage 30/30)
// physics::ExportInfoLoader::vfunc_5 @ 0x002f4eb0
void physics::ExportInfoLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr a3) { hulk_intptr a0 = (hulk_intptr)__p0; hulk_intptr a1 = (hulk_intptr)__p1; Reader_2f4eb0 * r = (Reader_2f4eb0 *)__p2;

    Frame_2f4eb0 f;
    int units;
    bool found;

    r->stream->FUN_002647e0(&f.len1, 1, 1, 1);
    unsigned n = f.len1;
    r->stream->FUN_002647e0(f.tag, n, 1, 1);
    f.tag[n] = 0;
    found = false;
    while (r->FUN_002669f0() && !found) {
        r->FUN_00266a30();
        r->stream->FUN_002647e0(&f.len1, 1, 1, 1);
        n = f.len1;
        r->stream->FUN_002647e0(f.tag, n, 1, 1);
        f.tag[n] = 0;
        if (memcmp(f.tag, "UI Units", 9) == 0) {
            r->stream->FUN_002647e0(&f.len2, 1, 1, 1);
            n = f.len2;
            r->stream->FUN_002647e0(f.unitsName, n, 1, 1);
            f.unitsName[n] = 0;
            found = true;
        }
        r->FUN_00266be0();
    }

    if (memcmp(f.unitsName, "Millimeters", 12) == 0)
        units = 0;
    else if (memcmp(f.unitsName, "Centimeters", 12) == 0)
        units = 1;
    else if (memcmp(f.unitsName, "Meters", 7) == 0)
        units = 2;
    else if (memcmp(f.unitsName, "Kilometers", 11) == 0)
        units = 3;
    else if (memcmp(f.unitsName, "Inches", 7) == 0)
        units = 4;
    else if (memcmp(f.unitsName, "Feet", 5) == 0)
        units = 5;
    else if (memcmp(f.unitsName, "Yards", 6) == 0)
        units = 6;
    else if (memcmp(f.unitsName, "Miles", 6) == 0)
        units = 7;
    else
        units = 8;

    if (DAT_00554c0c == 1) {
        if (DAT_004d2880 == units)
            return;
        if (!(*(char*)&DAT_00554c0d)) {
            sprintf(f.msg, "UI Units used in p3d file, %s, conflict with current settings", f.unitsName);
            return;
        }
        FUN_002ecb70();
    }
    FUN_002ecb90(units);
}


// 0x002f5110 physics::ExportInfoLoader::vfunc_2 (31 B): matches/0x002f5110.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002f5110@@UAEPAV123@E@Z
namespace fn_002f5110 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2f5110 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2f5110 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002f5110

