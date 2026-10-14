// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5 @ 0x0015c670
struct TypeDescriptor; extern TypeDescriptor DAT_0048d534; extern TypeDescriptor DAT_004b3b20;
struct Motion { char pad0[0x24]; unsigned state; char pad28[0x880]; unsigned a8; unsigned ac; unsigned b0; };
extern void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct List { char pad[0x68]; unsigned count; void* FUN_00222e20(unsigned); };
struct Owner { List* FUN_00059a40(); };
struct Link { char pad[0x10]; Owner* owner; };
struct Character { char pad[0x338]; Link* link; };
struct Access { Character* FUN_00059a30(); };
struct Actor { Access* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct GrappleLocomotionSteerAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, int);
char pad[0x1c]; Actor* actor; Motion* motion;
};
bool GrappleLocomotionSteerAction::vfunc_5(int flag, int unused) {
if (flag) return true;
if (!motion) return false;
Link* link = actor->FUN_000592a0()->FUN_00059a30()->link;
if (!link) return false;
List* list = link->owner->FUN_00059a40();
if (!list) return false;
for (unsigned i=0; i<list->count; ++i) {
Motion* src = (Motion*)FUN_00344e74(list->FUN_00222e20(i),0,&DAT_0048d534,&DAT_004b3b20,0);
if (src) {
motion->state=src->state;
motion->ac=src->ac;
motion->a8=src->a8;
motion->b0=src->b0;
return true;
}
}
return false;
}
} }
