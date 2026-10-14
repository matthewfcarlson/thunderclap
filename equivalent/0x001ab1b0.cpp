// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_6 @ 0x001ab1b0
typedef unsigned int uint;
struct TypeDescriptor { uint value; }; extern TypeDescriptor DAT_00494b44, DAT_004c13d0;
struct Template;
struct Params { Template* FUN_001d03c0(); };
extern "C" Params* __cdecl FUN_00344e74(void*,int,TypeDescriptor*,TypeDescriptor*,int);
struct Key { char data[4]; };
struct Template { uint unused; int kind; char pad[0x4c]; Key key; uint FUN_001c96e0(uint); };
struct Character { unsigned __int64 FUN_000443c0(); };
struct Entry { char pad[0x11c]; Character* character; };
struct Registry { Entry* FUN_00059c10(uint); };
struct Lookup { Character* FUN_001ab0e0(Key*); };
struct Holder { uint unused; Lookup* lookup; };
struct World { char pad0[0x20]; Holder* holder; char pad1[0x20]; Registry* registry; }; extern World* DAT_004dd700;
namespace hulkfight { namespace scenario {
struct Event_CharacterTemplateCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(uint,void*,uint);
char pad[8]; uint templateId; int operation; uint unused; uint low; uint high;
};
bool Event_CharacterTemplateCondition::vfunc_6(uint,void* params,uint) {
Params* p=FUN_00344e74(params,0,&DAT_00494b44,&DAT_004c13d0,0);
if(!p) return false;
Template* t=p->FUN_001d03c0();
uint id=t->FUN_001c96e0(templateId);
World* world=DAT_004dd700;
if(!world) return false;
Entry* entry=world->registry->FUN_00059c10(id);
Character* character;
if(entry) character=entry->character;
else {
if(t->kind<=0 || t->kind>3) return false;
character=world->holder->lookup->FUN_001ab0e0(&t->key);
if(!character) return false;
}
unsigned __int64 value=character->FUN_000443c0();
if(operation==0) return (uint)value==low && (uint)(value>>32)==high;
if(operation==1) return (uint)value!=low || (uint)(value>>32)!=high;
return false;
}
}}
