// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fac1e04c {
#define TREE_TU_END }
namespace fn_fac1e04c {} using namespace fn_fac1e04c;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fac1e04c {
void __cdecl SetTimeBegin_00068310();
void __cdecl SetTimeEnd_00068320();
void __cdecl SetDistance_00068330();
void __cdecl SetDirection_0006b7b0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct ParamBase_711c0 {
 virtual void placeholder();
 char padding[12];
 void (__cdecl *callback)();
 int tail;
};
class CMoveAddYTrack_711c0;
} // namespace fn_fac1e04c
namespace fight {
template<class T> struct ParamFloatConstRange_711c0 : ParamBase_711c0 { virtual void placeholder(); };
}
namespace fn_fac1e04c {
void __cdecl FUN_002347b0(int*,ParamBase_711c0**,int);
void __cdecl FUN_00068520();
void __cdecl FUN_00068530();
void __cdecl FUN_00068540();
class CDrainHealthTrack_717e0;
struct ParamBase_717e0 {
    virtual void slot0();
    char data[12];
};
} // namespace fn_fac1e04c
namespace fight {
template<class T> struct ParamFloatConstRange_717e0 : ParamBase_717e0 {
    virtual void slot0();
    void (__cdecl *callback)();
    unsigned int tail;
};
}
namespace fn_fac1e04c {
void __cdecl FUN_002347b0(void*, void*, int);

} // namespace fn_fac1e04c

// 0x00070d50 FUN_00070d50 (213 B): matches/0x00070d50.cpp [wrapped: conflict: fight::ParamBool; fight::ParamFloatConstRange; fight::ParamString]
// sym: _FUN_00070d50
namespace fn_00070d50 {

extern "C" void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00068250();
void __cdecl FUN_00069730();
void __cdecl FUN_00069750();
void __cdecl FUN_002347b0(void*, void**, int);

class CSoundTrack;
struct FUN_00234960 {
    FUN_00234960(const char* = "timeBegin");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
struct FUN_002349e0 {
    FUN_002349e0(const char* = "sound");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
struct FUN_00234860 {
    FUN_00234860(const char* = "weapon");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
};
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
};
template <class T> struct ParamBool : FUN_00234860 {
    virtual void slot0();
};
} // namespace fight
extern "C" void FUN_00070d50() {
    if (DAT_004dcf3c == 0) {
        void* params[3];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CSoundTrack>));
        if (mem) {
            fight::ParamFloatConstRange<CSoundTrack>* p = new (mem) fight::ParamFloatConstRange<CSoundTrack>;
            p->callback = FUN_00068250;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<CSoundTrack>));
        if (mem) {
            fight::ParamString<CSoundTrack>* p = new (mem) fight::ParamString<CSoundTrack>;
            p->callback = FUN_00069730;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool<CSoundTrack>));
        if (mem) {
            fight::ParamBool<CSoundTrack>* p = new (mem) fight::ParamBool<CSoundTrack>;
            p->callback = FUN_00069750;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004dcf38, params, 3);
    }
    ++DAT_004dcf3c;
}
} // namespace fn_00070d50


// 0x00070e30 FUN_00070e30 (227 B): matches/0x00070e30.cpp [wrapped: conflict: FUN_00234960; FUN_002349e0; fight::ParamEnumConstList; fight::ParamFloatConstRange (+1)]
// sym: _FUN_00070e30
namespace fn_00070e30 {

extern "C" void* __cdecl FUN_0008d690(unsigned int);

void FUN_00068260();
void FUN_00069830();
void FUN_00068270();
struct FUN_00234960 {
    FUN_00234960(const char* = "timeBegin");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    void (*callback)();
    int tail;
};
struct FUN_002349e0 {
    FUN_002349e0(const char* = "string");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    void (*callback)();
    int tail;
};
struct FUN_00234cc0 {
    FUN_00234cc0(const char* = "type");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    int* list;
    int count;
    void (*callback)();
    int tail;
};
class CComboMessageTrack;
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
} // namespace fight
void __cdecl FUN_002347b0(int*, void**, int);
extern "C" void FUN_00070e30() {
    if (!DAT_004dcf44) {
        void* entries[3];
        void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CComboMessageTrack>));
        if (p) {
            fight::ParamFloatConstRange<CComboMessageTrack>* b =
                new (p) fight::ParamFloatConstRange<CComboMessageTrack>;
            b->callback = FUN_00068260;
            entries[0] = b;
        } else
            entries[0] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamString<CComboMessageTrack>));
        if (p) {
            fight::ParamString<CComboMessageTrack>* b = new (p) fight::ParamString<CComboMessageTrack>;
            b->callback = FUN_00069830;
            entries[1] = b;
        } else
            entries[1] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CComboMessageTrack>));
        if (p) {
            fight::ParamEnumConstList<CComboMessageTrack>* b =
                new (p) fight::ParamEnumConstList<CComboMessageTrack>;
            b->list = ((int*)&DAT_00496f8c);
            b->count = 4;
            b->callback = FUN_00068270;
            entries[2] = b;
        } else
            entries[2] = 0;
        FUN_002347b0(&DAT_004dcf40, entries, 3);
    }
    ++DAT_004dcf44;
}
} // namespace fn_00070e30

namespace fn_fac1e04c {

// 0x000711c0 FUN_000711c0 (256 B): equivalent/0x000711c0.cpp
// sym: _FUN_000711c0 @1221447abf14 @wc3c651834cab
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_000711c0 @ 0x000711c0
extern "C" void FUN_000711c0() {
 if (DAT_004dcf5c == 0) {
 ParamBase_711c0* items[4];
 ParamBase_711c0* p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetTimeBegin_00068310; } items[0]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("timeEnd"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetTimeEnd_00068320; } items[1]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("distance"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetDistance_00068330; } items[2]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("direction"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetDirection_0006b7b0; } items[3]=p;
 FUN_002347b0(&DAT_004dcf58,items,4);
 }
 ++DAT_004dcf5c;
}

} // namespace fn_fac1e04c

// 0x00071700 FUN_00071700 (213 B): equivalent/0x00071700.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: _FUN_00071700 @02950758343f @w93bbd69b5607
namespace fn_00071700 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_00071700 @ 0x00071700

extern "C" void* __cdecl FUN_0008d690(unsigned int);

void __cdecl SetTimeBegin_000684f0();
void __cdecl SetDamage_00068500();
void __cdecl SetDamageMax_00068510();
class CDamageTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *getter)();
 int tail;
 void FUN_00234960(const char*);
};
}
void __cdecl FUN_002347b0(unsigned int*, fight::ParamFloatConstRange<CDamageTrack>**, int);
extern "C" void __cdecl FUN_00071700() {
 if (!DAT_004dcf74) {
  typedef fight::ParamFloatConstRange<CDamageTrack> Param;
  Param* params[3];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("timeBegin"); new(p) Param; p->getter = SetTimeBegin_000684f0; }
  params[0] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("damage"); new(p) Param; p->getter = SetDamage_00068500; }
  params[1] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) { p->FUN_00234960("damageMax"); new(p) Param; p->getter = SetDamageMax_00068510; }
  params[2] = p;
  FUN_002347b0(&DAT_004dcf70, params, 3);
 }
 ++DAT_004dcf74;
}
} // namespace fn_00071700

namespace fn_fac1e04c {

// 0x000717e0 FUN_000717e0 (213 B): equivalent/0x000717e0.cpp
// sym: _FUN_000717e0 @57f3a6c404c4 @w4683413f757c
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_000717e0 @ 0x000717e0
extern "C" void __cdecl FUN_000717e0() {
    if (!DAT_004dcf7c) {
        fight::ParamFloatConstRange_717e0<CDrainHealthTrack_717e0>* params[3];
        const char* names[3] = {"timeBegin", "timeEnd", "damage"};
        void (__cdecl *callbacks[3])() = {FUN_00068520,FUN_00068530,FUN_00068540};
        for (int i=0;i<3;++i) {
            void* memory=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_717e0<CDrainHealthTrack_717e0>));
            if (memory) {
                ((fight::ParamValueFloat *)(ParamBase_717e0 *)(((ParamBase_717e0*)memory)))->FUN_00234960(names[i]);
                params[i]=new(memory) fight::ParamFloatConstRange_717e0<CDrainHealthTrack_717e0>;
                params[i]->callback=callbacks[i];
            } else params[i]=0;
        }
        FUN_002347b0(&DAT_004dcf78,params,3);
    }
    ++DAT_004dcf7c;
}

} // namespace fn_fac1e04c
