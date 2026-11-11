// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0630..0x001f0a10 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f1aba5fa {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1aba5fa {} using namespace fn_f1aba5fa;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f1aba5fa {
typedef unsigned __int64 Key_1f0630;
extern int __cdecl FUN_002673a0(const char*, int);
class CSoundCommand_PlayDialogueEvent {
public:
    virtual void* vfunc_0_001f06a0(char);
    virtual void vfunc_1_001ef4f0(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    char flag;
    char pad1d[3];

    CSoundCommand_PlayDialogueEvent(const char* name, const char* sub, float value, int arg);
};
class CSoundCommand_1f06a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f06a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
typedef unsigned __int64 Key_1f06c0;
class CSoundCommand_PlayFightDialogueEvent {
public:
    virtual void* vfunc_0_001f0740(char);
    virtual void vfunc_1_001ef530(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    int f1c;
    char flag;
    char pad21[3];

    CSoundCommand_PlayFightDialogueEvent(const char* name, const char* sub, int extra, float value, int arg);
};
typedef unsigned __int64 Key_1f0760;
class CSoundCommand_PlayMissionDialogueEvent {
public:
    virtual void* vfunc_0_001f07f0(char);
    virtual void vfunc_1_001ef570(unsigned int, unsigned int);
    int f04;
    int f08;
    int f0c;
    unsigned int keyLo, keyHi;
    int id;
    int f1c;
    char text[0x20];
    char flag;
    char pad41[3];

    CSoundCommand_PlayMissionDialogueEvent(const char* name, const char* sub, const char* line, int arg1, float value, int arg2);
};
extern "C" unsigned __int64 getMusic_002672f0(int, int, int);
extern "C" int getEvent_002673a0(int, int);
class CSoundCommand_1f0810 {
  public:
    virtual void f();
    int a, b, c;
    CSoundCommand_1f0810(int x) : a(0), b(0), c(x) {}
};
struct Pair {
  public:
    Pair() : d(0), e(0) {}
    int d;
    int e;
    void set(unsigned __int64 v) {
        d = (int)v;
        e = (int)(v >> 32);
    }
};
class CSoundCommand_PlayMusicEvent : public CSoundCommand_1f0810 {
  public:
    Pair p;
    int f;
    CSoundCommand_PlayMusicEvent(hulk_intptr x, int y, int z);
    virtual void Fng_001ef5b0(int, int);
};
struct Bits {
    int lo, hi;
};
union Value {
    __int64 whole;
    Bits parts;
};
class CSoundCommand_1f0880 {
  public:
    int a, b, c;
    CSoundCommand_1f0880(int z) : a(0), b(0), c(z) {}
};
class CSoundCommand_PlayAmbienceEvent : public CSoundCommand_1f0880 {
  public:
    virtual void* Fn_001f08d0(char);
    Pair pair;
    int f;
    CSoundCommand_PlayAmbienceEvent(hulk_intptr x, int y, int z);
};
} // namespace fn_f1aba5fa
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f1aba5fa {
extern "C" int __cdecl FUN_002673a0(int, int);
typedef unsigned __int64 u64;
u64 __cdecl First_002672f0(int, int, int);
int __cdecl Second_002673a0(int, int);
class CSoundCommand_1f0960 {
  public:
    virtual void Fn();
    int a, b, c;
    CSoundCommand_1f0960(int x) : a(0), b(0), c(x) {}
};
class CSoundCommand_CueNISEvent : public CSoundCommand_1f0960 {
  public:
    Pair p;
    int f;
    CSoundCommand_CueNISEvent(hulk_intptr x, int y, int z);
    virtual void Fn();
};


// 0x001f0630 FUN_001f0630 (112 B): equivalent/0x001f0630.cpp
// sym: ??0CSoundCommand_PlayDialogueEvent@fn_f1aba5fa@@QAE@PBD0MH@Z @f8c74664a7d9 @wf7d02dbfa866
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f0630 @ 0x001f0630
CSoundCommand_PlayDialogueEvent::CSoundCommand_PlayDialogueEvent(const char* name, const char* sub, float value, int arg)
{
    f04 = 0;
    f08 = 0;
    f0c = arg;
    keyLo = 0;
    keyHi = 0;
    Key_1f0630 k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    flag = (value == 1.0f);
}


// 0x001f06a0 CSoundCommand_PlayDialogueEvent::vfunc_0 (31 B): matches/0x001f06a0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f1aba5fa@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001f06c0 FUN_001f06c0 (119 B): equivalent/0x001f06c0.cpp
// sym: ??0CSoundCommand_PlayFightDialogueEvent@fn_f1aba5fa@@QAE@PBD0HMH@Z @882c5fa30a84 @we766cbe93753
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f06c0 @ 0x001f06c0
CSoundCommand_PlayFightDialogueEvent::CSoundCommand_PlayFightDialogueEvent(const char* name, const char* sub, int extra, float value, int arg)
{
    f04 = 0;
    f08 = 0;
    f0c = arg;
    keyLo = 0;
    keyHi = 0;
    Key_1f06c0 k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    f1c = extra;
    flag = (value == 1.0f);
}

} // namespace fn_f1aba5fa

// 0x001f0740 CSoundCommand_PlayFightDialogueEvent::vfunc_0 (31 B): matches/0x001f0740.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f0740@@UAEPAV123@E@Z
namespace fn_001f0740 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f0740 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_004245a4[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0740 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f0740

namespace fn_f1aba5fa {

// 0x001f0760 FUN_001f0760 (136 B): equivalent/0x001f0760.cpp
// sym: ??0CSoundCommand_PlayMissionDialogueEvent@fn_f1aba5fa@@QAE@PBD00HMH@Z @cafdf5ca1397 @w4d95d966bd2e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001f0760 @ 0x001f0760
CSoundCommand_PlayMissionDialogueEvent::CSoundCommand_PlayMissionDialogueEvent(const char* name, const char* sub, const char* line, int arg1, float value, int arg2)
{
    f04 = 0;
    f08 = 0;
    f0c = arg2;
    keyLo = 0;
    keyHi = 0;
    Key_1f0760 k = FUN_002672f0(name, 0, 0);
    keyHi = (unsigned int)(k >> 32);
    keyLo = (unsigned int)k;
    id = FUN_002673a0(sub, 0);
    f1c = arg1;
    char *dst = text;
    char c;
    do {
        c = *line++;
        *dst++ = c;
    } while (c != 0);
    flag = (value == 1.0f);
}

} // namespace fn_f1aba5fa

// 0x001f07f0 CSoundCommand_PlayMissionDialogueEvent::vfunc_0 (31 B): matches/0x001f07f0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f07f0@@UAEPAV123@E@Z
namespace fn_001f07f0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f07f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f07f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f07f0

namespace fn_f1aba5fa {

// 0x001f0810 FUN_001f0810 (73 B): matches/0x001f0810.cpp
// sym: ??0CSoundCommand_PlayMusicEvent@fn_f1aba5fa@@QAE@HHH@Z
CSoundCommand_PlayMusicEvent::CSoundCommand_PlayMusicEvent(hulk_intptr x, int y, int z) : CSoundCommand_1f0810(z) {
    p.set(getMusic_002672f0(x, 0, 0));
    f = getEvent_002673a0(y, 0);
}

} // namespace fn_f1aba5fa

// 0x001f0860 CSoundCommand_PlayMusicEvent::vfunc_0 (31 B): matches/0x001f0860.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f0860@@UAEPAV123@E@Z
namespace fn_001f0860 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f0860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f0860

namespace fn_f1aba5fa {

// 0x001f0880 FUN_001f0880 (73 B): matches/0x001f0880.cpp
// sym: ??0CSoundCommand_PlayAmbienceEvent@fn_f1aba5fa@@QAE@HHH@Z
CSoundCommand_PlayAmbienceEvent::CSoundCommand_PlayAmbienceEvent(hulk_intptr x, int y, int z) : CSoundCommand_1f0880(z) {
    Value v;
    v.whole = FUN_002672f0(x, 0, 0);
    pair.e = v.parts.hi;
    pair.d = v.parts.lo;
    f = FUN_002673a0(y, 0);
}

} // namespace fn_f1aba5fa

// 0x001f08d0 CSoundCommand_PlayAmbienceEvent::vfunc_0 (31 B): matches/0x001f08d0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f08d0@@UAEPAV123@E@Z
namespace fn_001f08d0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f08d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f08d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f08d0


// 0x001f08f0 FUN_001f08f0 (73 B): equivalent/0x001f08f0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ??0CSoundCommand_PlaySFXEvent@fn_001f08f0@@QAE@HHH@Z @25780a11ee3a @w524d0063a4a6
namespace fn_001f08f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f08f0 @ 0x001f08f0
unsigned __int64 __cdecl FUN_002672f0(int, int, int);
int __cdecl FUN_002673a0(int, int);

class CSoundCommand_PlaySFXEvent {
public:
    virtual void* unused_001f0940(char);
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    CSoundCommand_PlaySFXEvent(hulk_intptr first, int second, int third);
};

CSoundCommand_PlaySFXEvent::CSoundCommand_PlaySFXEvent(hulk_intptr first, int second, int third) {
    field04 = 0;
    field08 = 0;
    field0c = third;
    field10 = 0;
    field14 = 0;
    unsigned __int64 result = FUN_002672f0(first, 0, 0);
    field14 = (int)(result >> 32);
    field10 = (int)result;
    field18 = FUN_002673a0(second, 0);
}
} // namespace fn_001f08f0


// 0x001f0940 CSoundCommand_PlaySFXEvent::vfunc_0 (31 B): matches/0x001f0940.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f0940@@UAEPAV123@E@Z
namespace fn_001f0940 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f0940 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0940 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f0940

namespace fn_f1aba5fa {

// 0x001f0960 FUN_001f0960 (73 B): matches/0x001f0960.cpp
// sym: ??0CSoundCommand_CueNISEvent@fn_f1aba5fa@@QAE@HHH@Z
CSoundCommand_CueNISEvent::CSoundCommand_CueNISEvent(hulk_intptr x, int y, int z) : CSoundCommand_1f0960(z) {
    u64 v = First_002672f0(x, 0, 0);
    p.d = (int)v;
    p.e = (int)(v >> 32);
    f = Second_002673a0(y, 0);
}

} // namespace fn_f1aba5fa

// 0x001f09b0 CSoundCommand_CueNISEvent::vfunc_0 (31 B): matches/0x001f09b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f09b0@@UAEPAV123@E@Z
namespace fn_001f09b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f09b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f09b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001f09b0


// 0x001f09d0 FUN_001f09d0 (53 B): matches/0x001f09d0.cpp [wrapped: conflict: FUN_002672f0]
// sym: ??0CSoundCommand_InstallEffect@fn_001f09d0@@QAE@HH@Z
namespace fn_001f09d0 {
typedef unsigned __int64 U64;
U64 __cdecl FUN_002672f0(int, int, int);

class CSoundCommand_1f09d0 {
public:
    virtual void vfunc_0();
    int field4;
    int field8;
    int fieldC;
    CSoundCommand_1f09d0(int c) : field4(0), field8(0), fieldC(c) {}
};

struct SoundId {
    U64 value;
    SoundId(int name) : value(0) { value = FUN_002672f0(name, 0, 0); }
};

class CSoundCommand_InstallEffect : public CSoundCommand_1f09d0 {
public:
    SoundId effect;
    CSoundCommand_InstallEffect(int name, int unused);
    virtual void vfunc_0();
};

CSoundCommand_InstallEffect::CSoundCommand_InstallEffect(int name, int unused)
    : CSoundCommand_1f09d0(0), effect(name)
{
}
} // namespace fn_001f09d0

