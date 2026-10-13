// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// hulkfight::ai::ThreatDodgeAction::vfunc_5 @ 0x0012bab0
struct Vec { float x,y,z; float FUN_0022d110(); };
struct Position { void FUN_00059a50(Vec*); };
struct Actor { char pad0[0x10]; Position* position; char pad1[0x2064-0x14]; Vec direction; unsigned int mode; Vec direction2; char pad2[0x22a0-0x2080]; Vec reference; bool FUN_00037080(void*,unsigned int); };
struct Link2 { Actor* FUN_00059a30(); };
struct Link { Link2* FUN_000592a0(); };
struct Settings { char pad[0x14]; unsigned int mode; unsigned char flag; char pad2[7]; char data[1]; };
namespace hulkfight { namespace ai { struct ThreatDodgeAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(unsigned int, unsigned int); char pad[0x18]; Settings* settings; Link* link; }; } }
bool hulkfight::ai::ThreatDodgeAction::vfunc_5(unsigned int state,unsigned int unused) {
 if (state != 0) return true;
 if (!link) return false;
 Actor* actor = link->FUN_000592a0()->FUN_00059a30();
 unsigned int flag = (state & 0xffffff00u) | settings->flag;
 if (actor->FUN_00037080(settings->data, flag)) {
 Vec reference = actor->reference;
 Vec position; position.x=0; position.y=0; position.z=0;
 actor->position->FUN_00059a50(&position);
 Vec direction; direction.x=position.x-reference.x; direction.y=0; direction.z=position.z-reference.z;
 direction.FUN_0022d110();
 actor->direction=direction;
 actor->direction2=direction;
 actor->mode=settings->mode;
 }
 return true;
}