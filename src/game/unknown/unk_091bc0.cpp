// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00091bc0..0x00092120 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9898967 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9898967 {} using namespace fn_f9898967;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f9898967 {
struct Sub_91bc0 {
    void Init_0027af00();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail_91be0 {
    void Fnf_0027af50();
};
void __cdecl freebuf_0008d340(void*);
void* __cdecl allocbuf_0008d6d0(unsigned int);
} // namespace fn_f9898967
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned __cdecl strlen(const char*);
#endif
namespace fn_f9898967 {
class X {
    char pad[24];
    char* str;

  public:
    void Set(const char* s);
};
class Part_91c80 {
    char pad[16];

  public:
    void Init_0027af00();
};
class CUnlockableBlonskyFile {
  public:
    CUnlockableBlonskyFile();
    char* vf;
    char _m_pad_4[0x4];
    unsigned char enabled;
    char _m_pad_9[0x7];
    Part_91c80 a;
    Part_91c80 b;
    char _m_pad_30[0x38];
    unsigned char f68;
    char _m_pad_69[0x3f];
    unsigned char fa8;
    char _m_pad_a9[0x3];
    void Destroy();
};
class Helper_91cc0 {
  public:
    void Run_0027af50();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
struct Obj_91d00 {
    char pad[0x20];
};
typedef unsigned int u32_91da0;
struct Sub_91da0 {
    char pad[8];
};
class CUnlockable {
  public:
    virtual void* m_vf0_000933a0(int);
    CUnlockable();
    char _m_pad_4[0x4];
    union { u8 f8; u8 member8; };
    char _m_pad_9[0x7];
    Sub_91da0 sub;
    union { u32_91da0 f18; void* m18; int member18; };
    char _m_pad_1c[0x4];
    u8 f20;
    char _m_pad_21[0x3];
    u32_91da0 f24;
    u8 f28;
    char _m_pad_29[0x3];
    void Destroy();
};
extern "C" void __fastcall FUN_0027af00(Sub_91da0*);
extern char hulk_at_0040449c[];
extern char hulk_at_004044ac[];
struct CUnlockableCheat : CUnlockable {};
extern int vtBase_91de0;
extern int vtCheat_91de0;
struct Sub_91de0 {
    void Init_0027af00();
    char pad[8];
};
struct CUnlockableCheat_91de0 {
    int* vptr;
    char p4[4];
    unsigned char flag;
    char p9[7];
    Sub_91de0 sub;
    int field18;
    char p1c[4];
    unsigned char field20;
    char p21[7];
    CUnlockableCheat_91de0* ctor(const char* arg);
};
extern "C" void FUN_00267760(void*, int, const char*, ...);
extern "C" char DAT_004044b4[];
struct Sub_91ea0 {
    void Init_0027af00();
};
class CUnlockableMove {
  public:
    hulk_intptr vf;
    char _m_pad_4[0x14];
    void* ptr;
    char _m_pad_1c[0x2d];
    CUnlockableMove* Ctor();
    void dtor();
};
class Obj_91ef0 {
  public:
    void dtor_0027af50();
};
void rel_0008d340(void*);
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
class C_92040 {
    char pad[0x30];

  public:
    unsigned int value;
};
class C_92050 {
  public:
    char pad[0x38];
};
class C_92090 {
    char pad[0x48];
};


// 0x00091bc0 FUN_00091bc0 (32 B): matches/0x00091bc0.cpp
// sym: ??0CUnlockable@fn_f9898967@@QAE@XZ
CUnlockable::CUnlockable() {
    member8 = 1;
    ((Sub_91bc0*)((char*)this + 0x10))->Init_0027af00();
    member18 = 0;
}


// 0x00091be0 FUN_00091be0 (41 B): matches/0x00091be0.cpp
// sym: ?Destroy@CUnlockable@fn_f9898967@@QAEXXZ
void CUnlockable::Destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail_91be0*)((char*)this + 0x10))->Fnf_0027af50();
}


// 0x00091c20 FUN_00091c20 (81 B): matches/0x00091c20.cpp
// sym: ?Set@X@fn_f9898967@@QAEXPBD@Z
void X::Set(const char* s) {
    if (str) {
        freebuf_0008d340(str);
        str = 0;
    }
    if (s) {
        str = (char*)allocbuf_0008d6d0(strlen(s) + 1);
        strcpy(str, s);
    }
}


// 0x00091c80 FUN_00091c80 (58 B): matches/0x00091c80.cpp
// sym: ??0CUnlockableBlonskyFile@fn_f9898967@@QAE@XZ
CUnlockableBlonskyFile::CUnlockableBlonskyFile() {
    vf = (char*)((hulk_intptr)DAT_0040449c);
    enabled = 1;
    a.Init_0027af00();
    *(int*)((char*)this + 0x18) = 0;
    vf = (char*)((hulk_intptr)DAT_004044a4);
    b.Init_0027af00();
    fa8 = 0;
    f68 = 0;
    *(unsigned char*)((char*)this + 0x28) = 0;
}


// 0x00091cc0 FUN_00091cc0 (55 B): matches/0x00091cc0.cpp
// sym: ?Destroy@CUnlockableBlonskyFile@fn_f9898967@@QAEXXZ
void CUnlockableBlonskyFile::Destroy() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004044a4);
    ((Helper_91cc0*)((char*)this + 0x20))->Run_0027af50();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040449c);
    int p = *(int*)((char*)this + 0x18);
    if (p) {
        thunk_FUN_00267090(p);
        *(int*)((char*)this + 0x18) = 0;
    }
    ((Helper_91cc0*)((char*)this + 0x10))->Run_0027af50();
}


// 0x00091d00 FUN_00091d00 (4 B): matches/0x00091d00.cpp
// sym: ?FUN_00091d00@fn_f9898967@@YIPAXPAUObj_91d00@1@@Z
// Same code shape as 0x000897e0 (propagated; names are from that function)
void* __fastcall FUN_00091d00(Obj_91d00* p) {
    return (char*)p + 0x20;
}

} // namespace fn_f9898967

// 0x00091d20 FUN_00091d20 (4 B): matches/0x00091d20.cpp
// sym: ?FUN_00091d20@C_91d20@owners@@QAEPADXZ
char* owners::C_91d20::FUN_00091d20() {
    return (char*)this + 0x28;
}


// 0x00091d50 FUN_00091d50 (4 B): matches/0x00091d50.cpp
// sym: ?FUN_00091d50@Obj_91d50@owners@@QAEPAU12@XZ
owners::Obj_91d50* owners::Obj_91d50::FUN_00091d50() {
    return (owners::Obj_91d50*)((char*)this + 0x68);
}

namespace fn_f9898967 {

// 0x00091da0 FUN_00091da0 (49 B): matches/0x00091da0.cpp
// sym: ?FUN_00091da0@fn_f9898967@@YIPAUCUnlockableCheat@1@PAU21@@Z
CUnlockableCheat* __fastcall FUN_00091da0(CUnlockableCheat* self) {
    *(void**)self = hulk_at_0040449c;
    self->f8 = 1;
    FUN_0027af00(&self->sub);
    self->f18 = 0;
    self->f20 = 0;
    self->f28 = 0;
    *(void**)self = hulk_at_004044ac;
    self->f24 = 0xffffffff;
    return self;
}


// 0x00091de0 FUN_00091de0 (65 B): matches/0x00091de0.cpp
// sym: ?ctor@CUnlockableCheat_91de0@fn_f9898967@@QAEPAU12@PBD@Z
CUnlockableCheat_91de0* CUnlockableCheat_91de0::ctor(const char* arg) {
    vptr = (int*)&vtBase_91de0;
    flag = 1;
    sub.Init_0027af00();
    field18 = 0;
    field20 = 0;
    vptr = (int*)&vtCheat_91de0;
    FUN_00267760((char*)this + 0x28, 8, "%s", arg);
    return this;
}

} // namespace fn_f9898967

// 0x00091e30 FUN_00091e30 (41 B): matches/0x00091e30.cpp [wrapped: same definition as 0x00091be0 in this TU]
// sym: ?Destroy@CUnlockable@fn_00091e30@@QAEXXZ
namespace fn_00091e30 {
extern "C" char DAT_0040449c[];
// Same code shape as 0x00091be0 (propagated; names are from that function)
class CUnlockable {
  public:
    int pad[6];
    void* m18;
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail_91e30 {
    void Fnf_0027af50();
};
void CUnlockable::Destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail_91e30*)((char*)this + 0x10))->Fnf_0027af50();
}
} // namespace fn_00091e30

namespace fn_f9898967 {

// 0x00091ea0 FUN_00091ea0 (79 B): matches/0x00091ea0.cpp
// sym: ?Ctor@CUnlockableMove@fn_f9898967@@QAEPAV12@XZ
CUnlockableMove* CUnlockableMove::Ctor() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040449c);
    *((char*)this + 8) = 1;
    ((Sub_91ea0*)((char*)this + 0x10))->Init_0027af00();
    *(int*)((char*)this + 0x18) = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004044b4);
    *((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = -1;
    *((char*)this + 0x2c) = 0;
    *((char*)this + 0x2d) = 0;
    *(int*)((char*)this + 0x30) = 0;
    ((Sub_91ea0*)((char*)this + 0x38))->Init_0027af00();
    ((Sub_91ea0*)((char*)this + 0x40))->Init_0027af00();
    *((char*)this + 0x48) = 0;
    return this;
}


// 0x00091ef0 FUN_00091ef0 (63 B): matches/0x00091ef0.cpp
// sym: ?dtor@CUnlockableMove@fn_f9898967@@QAEXXZ
void CUnlockableMove::dtor() {
    vf = ((hulk_intptr)DAT_004044b4);
    ((Obj_91ef0*)((char*)this + 0x40))->dtor_0027af50();
    ((Obj_91ef0*)((char*)this + 0x38))->dtor_0027af50();
    vf = ((hulk_intptr)DAT_0040449c);
    if (ptr) {
        rel_0008d340(ptr);
        ptr = 0;
    }
    ((Obj_91ef0*)((char*)this + 0x10))->dtor_0027af50();
}

} // namespace fn_f9898967

// 0x00091f30 FUN_00091f30 (10 B): matches/0x00091f30.cpp
// sym: ?FUN_00091f30@C_91f30@owners@@QAEXE@Z
void owners::C_91f30::FUN_00091f30(unsigned char x) {
    value = x;
}

namespace fn_f9898967 {

// 0x00091f40 FUN_00091f40 (4 B): matches/0x00091f40.cpp
// sym: ?FUN_00091f40@fn_f9898967@@YIEPAX@Z
unsigned char __fastcall FUN_00091f40(void* p) {
    return *((unsigned char*)p + 0x20);
}

} // namespace fn_f9898967

// 0x00091f70 FUN_00091f70 (4 B): matches/0x00091f70.cpp
// sym: ?FUN_00091f70@Obj_91f70@owners@@QAEHXZ
// Same code shape as 0x00086290 (propagated; names are from that function)
int owners::Obj_91f70::FUN_00091f70() {
    return mValue;
}


// 0x00091f90 FUN_00091f90 (4 B): matches/0x00091f90.cpp
// sym: ?FUN_00091f90@Target_91f90@owners@@QAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
unsigned int owners::Target_91f90::FUN_00091f90() {
    return value;
}


// 0x00091fb0 FUN_00091fb0 (4 B): matches/0x00091fb0.cpp
// sym: ?FUN_00091fb0@A_91fb0@owners@@QAEEXZ
unsigned char owners::A_91fb0::FUN_00091fb0() {
    return pad[0x2c];
}


// 0x00091fe0 FUN_00091fe0 (81 B): equivalent/0x00091fe0.cpp
// sym: ?FUN_00091fe0@Object_91fe0@owners@@QAEXPBD@Z @2f1b2e636ce4 @wac1183891061
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 8/8)
// FUN_00091fe0 @ 0x00091fe0
void owners::Object_91fe0::FUN_00091fe0(const char *value) { if (text) { FUN_0008d340(text); text = 0; } if (value) { const char *end = value; while (*end) ++end; char *dest = (char *)FUN_0008d6d0((unsigned int)(end - value + 1)); text = dest; do { *dest++ = *value; } while (*value++); } }

namespace fn_f9898967 {

// 0x00092040 FUN_00092040 (4 B): matches/0x00092040.cpp
// sym: ?FUN_00092040@fn_f9898967@@YIIPAVC_92040@1@@Z
// Same code shape as 0x000862e0 (propagated; names are from that function)
hulk_uintptr __fastcall FUN_00092040(C_92040* self) {
    return self->value;
}


// 0x00092050 FUN_00092050 (4 B): matches/0x00092050.cpp
// sym: ?FUN_00092050@fn_f9898967@@YIPAVC_92050@1@PAV21@@Z
C_92050* __fastcall FUN_00092050(C_92050* p) {
    return (C_92050*)((char*)p + 0x38);
}


// 0x00092070 FUN_00092070 (4 B): matches/0x00092070.cpp
// sym: ?FUN_00092070@fn_f9898967@@YIPAHPAH@Z
// Same code shape as 0x000897f0 (propagated; names are from that function)
int* __fastcall FUN_00092070(int* p) {
    return (int*)((char*)p + 0x40);
}


// 0x00092090 FUN_00092090 (4 B): matches/0x00092090.cpp
// sym: ?FUN_00092090@fn_f9898967@@YIPAXPAVC_92090@1@@Z
void* __fastcall FUN_00092090(C_92090* self) {
    return (char*)self + 0x48;
}

} // namespace fn_f9898967

// 0x000920c0 FUN_000920c0 (39 B): matches/0x000920c0.cpp [wrapped: conflict: CUnlockable; CUnlockable::CUnlockable]
// sym: ??0CUnlockableJumpMarker@fn_000920c0@@QAE@XZ
namespace fn_000920c0 {
class Sub_920c0 {
  public:
    void Init_0027af00();
    char b[8];
};
class CUnlockable {
  public:
    CUnlockable();
    virtual void V();
    char p4[4];
    unsigned char flag;
    char p9[7];
    Sub_920c0 sub;
    int p18;
    char p1c[4];
    int p20;
};
class CUnlockableJumpMarker : public CUnlockable {
  public:
    CUnlockableJumpMarker();
    virtual void W();
};
inline CUnlockable::CUnlockable() {
    flag = 1;
    sub.Init_0027af00();
}
CUnlockableJumpMarker::CUnlockableJumpMarker() {
    p18 = 0;
    p20 = 0;
}
} // namespace fn_000920c0


// 0x000920f0 FUN_000920f0 (41 B): matches/0x000920f0.cpp [wrapped: same definition as 0x00091be0 in this TU]
// sym: ?Destroy@CUnlockable@fn_000920f0@@QAEXXZ
namespace fn_000920f0 {
extern "C" char DAT_0040449c[];
// Same code shape as 0x00091be0 (propagated; names are from that function)
class CUnlockable {
  public:
    int pad[6];
    void* m18;
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail_920f0 {
    void Fnf_0027af50();
};
void CUnlockable::Destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail_920f0*)((char*)this + 0x10))->Fnf_0027af50();
}
} // namespace fn_000920f0

