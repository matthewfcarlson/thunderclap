// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 30/30)
// hulkfight::motion::CollisionTargetNameCondition::vfunc_6 @ 0x0014e760
extern "C" { extern char DAT_00494b44; extern char DAT_00494b60; void* __cdecl FUN_00344e74(void*, int, void*, void*, int); }
struct NameProvider { unsigned __int64 FUN_000443c0(); };
struct NamedData { char pad[8]; unsigned low,high; };
struct Entity { char pad[0xec]; NamedData* name; char gap[0x2c]; NameProvider* provider; };
struct Collision { char pad[8]; Entity* entity; unsigned type; };
struct State { char pad[0x50]; Collision* collision; };
struct Input { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionTargetNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Input*,void*);
 char pad[8]; unsigned mode; unsigned low,high;
};
bool CollisionTargetNameCondition::vfunc_6(void*,Input* input,void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State* state=input->slot3();
 if (!state || !state->collision) return false;
 Collision* collision=state->collision;
 unsigned valueLow=0, valueHigh=0;
 if (collision->type==5) { if (collision->entity && collision->entity->name) { valueLow=collision->entity->name->low; valueHigh=collision->entity->name->high; } }
 else if(collision->type==1) { if(collision->entity && collision->entity->provider) { unsigned __int64 value=collision->entity->provider->FUN_000443c0(); valueLow=(unsigned)value; valueHigh=(unsigned)(value>>32); } }
 if(mode==0) return valueLow==low && valueHigh==high;
 if(mode==1) return valueLow!=low || valueHigh!=high;
 return false;
}
}}
