// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014e810..0x0014e910 (kind game, layer game, confidence medium), dominant class hulkfight::motion::CollisionSourceNodeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f7bcb928 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7bcb928 {} using namespace fn_f7bcb928;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7bcb928 {
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Param {
  public:
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
};
namespace hulkfight { namespace motion {
class CollisionSourceIsMissileCondition : public Condition, public Param {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int, void*, int);
    char pad[4];
    unsigned char value;
};
} }
extern int helper(void*, int, void*, void*, int);
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct Source_14e810 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int get();
};
extern unsigned char DAT_00494b44;
extern unsigned char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Node { char pad[0x14]; Node* parent; };
struct State_14e860 { char pad[0x6c]; Node* source; };
struct Input_14e860 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_14e860* slot3();
};
namespace hulkfight { namespace motion {
struct CollisionSourceNodeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Input_14e860*, void*);
 char pad[8]; int comparison; Node* expected; char pad2[8]; unsigned char ancestors;
};
} }


// 0x0014e810 hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_6 (69 B): matches/0x0014e810.cpp
// sym: ?vfunc_6@CollisionSourceIsMissileCondition@motion@hulkfight@fn_f7bcb928@@UAE_NHPAXH@Z
bool hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_6(int, void* p, int) {
    if (helper(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0) == 0)
        return false;
    hulk_intptr x = ((Source_14e810*)p)->get();
    if (!x)
        return false;
    return *(unsigned char*)(x + 0x14) == value;
}


// 0x0014e860 hulkfight::motion::CollisionSourceNodeCondition::vfunc_6 (170 B): equivalent/0x0014e860.cpp
// sym: ?vfunc_6@CollisionSourceNodeCondition@motion@hulkfight@fn_f7bcb928@@UAE_NPAXPAUInput_14e860@4@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 26/26)
// hulkfight::motion::CollisionSourceNodeCondition::vfunc_6 @ 0x0014e860
namespace hulkfight { namespace motion {
bool CollisionSourceNodeCondition::vfunc_6(void*, Input_14e860* input, void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_14e860* state = input->slot3();
 if (!state) return false;
 Node* source = state->source;
 if (!source) return false;
 if (!ancestors) {
  if (comparison == 0) return expected == source;
  if (comparison == 1) return expected != source;
  return false;
 }
 Node* parent = source->parent;
 Node* match = expected;
 while (parent) {
  if (parent == match) return comparison == 0;
  parent = parent->parent;
 }
 return comparison == 1;
}
} }

} // namespace fn_f7bcb928
