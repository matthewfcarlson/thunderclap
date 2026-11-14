// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e630..0x0014e760 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionSourceNameCondition
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f8ea6102 {
#define TREE_TU_END }
namespace fn_f8ea6102 {} using namespace fn_f8ea6102;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8ea6102 {
struct Tgt_14e630 {
    char pad[0x4c];
    struct Q {
        char p[0xc];
        int d;
    }* q;
};
class Params_14e630 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual Tgt_14e630* Get();
};
extern char hulk_at_00494b44;
extern char hulk_at_00494b60;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

} // namespace fn_f8ea6102

// 0x0014e630 hulkfight::motion::CollisionSourceTypeCondition::vfunc_6 (122 B): matches/0x0014e630.cpp
// sym: ?vfunc_6@CollisionSourceTypeCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::CollisionSourceTypeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Params_14e630 * p = (Params_14e630 *)__p1;

    if (!FUN_00344e74(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0))
        return false;
    Tgt_14e630* t = p->Get();
    if (!t)
        return false;
    if (!t->q)
        return false;
    int d = t->q->d;
    int c = 0;
    switch (this->type) {
    case 0:
        c = 1;
        break;
    case 1:
        c = 5;
        break;
    }
    switch (this->compare) {
    case 0:
        return c == d;
    case 1:
        return c != d;
    }
    return false;
}


// 0x0014e6b0 hulkfight::motion::CollisionSourceNameCondition::vfunc_6 (170 B): equivalent/0x0014e6b0.cpp [wrapped: conflict: FUN_00344e74; hulkfight::motion::CollisionSourceNameCondition]
// sym: ?vfunc_6@CollisionSourceNameCondition@motion@hulkfight@fn_0014e6b0@@UAE_NIPAUParams@4@I@Z @a7ae23e6c155 @wb64c4dba0eab
namespace fn_0014e6b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 30/30)
// hulkfight::motion::CollisionSourceNameCondition::vfunc_6 @ 0x0014e6b0
typedef unsigned __int64 U64_14e6b0;
extern int DAT_00494b44;
extern int DAT_00494b60;
extern "C++" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct NameProvider_14e6b0 { U64_14e6b0 FUN_000443c0(); };
struct NameData { char pad[8]; unsigned low, high; };
struct SourceObject { char pad0[0xec]; NameData* name; char pad1[0x2c]; NameProvider_14e6b0* provider; };
struct Source_14e6b0 { char pad[8]; SourceObject* object; unsigned type; };
struct Result_14e6b0 { char pad[0x4c]; Source_14e6b0* source; };
struct Params { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Result_14e6b0* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionSourceNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(unsigned, Params*, unsigned);
 char pad[8]; unsigned mode; unsigned low, high;
};
bool CollisionSourceNameCondition::vfunc_6(unsigned, Params* params, unsigned) {
 if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Result_14e6b0* result=params->slot3();
 if (!result || !result->source) return false;
 Source_14e6b0* source=result->source;
 unsigned lo=0, hi=0;
 if (source->type==1) {
  if (source->object && source->object->provider) {
   U64_14e6b0 value=source->object->provider->FUN_000443c0();
   lo=(unsigned)value; hi=(unsigned)(value>>32);
  }
 } else if (source->type==5) {
  if (source->object && source->object->name) {
   lo=source->object->name->low; hi=source->object->name->high;
  }
 }
 if (mode==0) return lo==low && hi==high;
 if (mode==1) return lo!=low || hi!=high;
 return false;
}
}}
} // namespace fn_0014e6b0

