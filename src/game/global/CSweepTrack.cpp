// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069b30..0x00069c20 (kind game, layer game, confidence high), dominant class CSweepTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f9999ae0 {
#define TREE_TU_END }
namespace fn_f9999ae0 {} using namespace fn_f9999ae0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9999ae0 {
typedef unsigned int u32_69b50;
extern float hulk_at_003f32e0;
struct Helper_69bf0 {
    int Fnf_0001d420(CSweepTrack*, hulk_intptr);
};
extern "C" Helper_69bf0* __cdecl FUN_0008d690(int);


// 0x00069b30 FUN_00069b30 (19 B): matches/0x00069b30.cpp
// sym: ?FUN_00069b30@fn_f9999ae0@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069b30() {
    FUN_00234810(((char*)&DAT_004dcf60), ((char*)&DAT_004dcf64));
}


// 0x00069b50 CSweepTrack::vfunc_0 (16 B): matches/0x00069b50.cpp
// sym: ?CSweepTrack_vfunc_0@fn_f9999ae0@@YGHH@Z
// data: g_table_69b50 = DAT_004dcf60
int __stdcall CSweepTrack_vfunc_0(int index) {
    return (*(u32_69b50**)&DAT_004dcf60)[index];
}

} // namespace fn_f9999ae0

// 0x00069b60 FUN_00069b60 (53 B): matches/0x00069b60.cpp [wrapped: conflict: CSweepTrack]
// sym: ??0CSweepTrack@fn_00069b60@@QAE@XZ
namespace fn_00069b60 {
class CTrack_69b60 {
  public:
    CTrack_69b60();
    virtual void f0();
};

class CSweepTrack : public CTrack_69b60 {
  public:
    CSweepTrack();
    virtual void f0();
    char pad0[4];
    int m8;
    int m_c;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};

CSweepTrack::CSweepTrack() {
    m_c = 0;
    m_14 = 0;
    m_1c = 0;
    m_20 = 0;
    m_10 = 1.0f;
    m_18 = -1;
    m8 = 1;
}
} // namespace fn_00069b60


// 0x00069ba0 CSweepTrack::vfunc_13 (13 B): matches/0x00069ba0.cpp
// sym: ?vfunc_13@CSweepTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CSweepTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069bb0 CSweepTrack::vfunc_6 (4 B): matches/0x00069bb0.cpp
// sym: ?vfunc_6@CSweepTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CSweepTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069bd0 CSweepTrack::vfunc_7 (28 B): matches/0x00069bd0.cpp
// sym: ?vfunc_7@CSweepTrack@@UAEMXZ
// Same code shape as 0x00069920 (propagated; names are from that function)
hulk_freg CSweepTrack::vfunc_7() {
    hulk_freg d = this->f_10 - this->f_0c;
    if (d < hulk_at_003f32e0)
        d = hulk_at_003f32e0;
    return d;
}


// 0x00069bf0 CSweepTrack::vfunc_12 (40 B): matches/0x00069bf0.cpp
// sym: ?vfunc_12@CSweepTrack@@UAEHH@Z
// Same code shape as 0x00062300 (propagated; names are from that function)
hulk_intptr CSweepTrack::vfunc_12(hulk_intptr a) {
    Helper_69bf0* p = FUN_0008d690(0x2c);
    if (p)
        return p->Fnf_0001d420(this, a);
    return 0;
}

