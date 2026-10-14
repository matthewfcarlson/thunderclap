// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// hulkfight::scenario::Event_CharacterTemplateCondition::vfunc_6 @ 0x001ab1b0
typedef unsigned int uint_1ab1b0;
struct TypeDescriptor_1ab1b0 { uint_1ab1b0 value; }; extern TypeDescriptor_1ab1b0 DAT_00494b44, DAT_004c13d0;
struct Template_1ab1b0;
struct Params { Template_1ab1b0* FUN_001d03c0(); };
extern "C" Params* __cdecl FUN_00344e74(void*,int,TypeDescriptor_1ab1b0*,TypeDescriptor_1ab1b0*,int);
struct Key_1ab1b0 { char data[4]; };
struct Template_1ab1b0 { uint_1ab1b0 unused; int kind; char pad[0x4c]; Key_1ab1b0 key; uint_1ab1b0 FUN_001c96e0(uint_1ab1b0); };
struct Character_1ab1b0 { unsigned __int64 FUN_000443c0(); };
struct Entry_1ab1b0 { char pad[0x11c]; Character_1ab1b0* character; };
struct Registry_1ab1b0 { Entry_1ab1b0* FUN_00059c10(uint_1ab1b0); };
struct Lookup_1ab1b0 { Character_1ab1b0* FUN_001ab0e0(Key_1ab1b0*); };
struct Holder_1ab1b0 { uint_1ab1b0 unused; Lookup_1ab1b0* lookup; };
struct World { char pad0[0x20]; Holder_1ab1b0* holder; char pad1[0x20]; Registry_1ab1b0* registry; }; extern World* DAT_004dd700;
namespace hulkfight { namespace scenario {
struct Event_CharacterTemplateCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(uint_1ab1b0,void*,uint_1ab1b0);
char pad[8]; uint_1ab1b0 templateId; int operation; uint_1ab1b0 unused; uint_1ab1b0 low; uint_1ab1b0 high;
};
bool Event_CharacterTemplateCondition::vfunc_6(uint_1ab1b0,void* params,uint_1ab1b0) {
Params* p=FUN_00344e74(params,0,&DAT_00494b44,&DAT_004c13d0,0);
if(!p) return false;
Template_1ab1b0* t=p->FUN_001d03c0();
uint_1ab1b0 id=t->FUN_001c96e0(templateId);
World* world=DAT_004dd700;
if(!world) return false;
Entry_1ab1b0* entry=world->registry->FUN_00059c10(id);
Character_1ab1b0* character;
if(entry) character=entry->character;
else {
if(t->kind<=0 || t->kind>3) return false;
character=world->holder->lookup->FUN_001ab0e0(&t->key);
if(!character) return false;
}
unsigned __int64 value=character->FUN_000443c0();
if(operation==0) return (uint_1ab1b0)value==low && (uint_1ab1b0)(value>>32)==high;
if(operation==1) return (uint_1ab1b0)value!=low || (uint_1ab1b0)(value>>32)!=high;
return false;
}
}}
