// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 26/26)
// hulkfight::motion::CollisionSourceNodeCondition::vfunc_6 @ 0x0014e860
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
}}
