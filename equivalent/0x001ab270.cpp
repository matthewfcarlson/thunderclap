// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 24/24)
// hulkfight::scenario::Event_CharacterTemplateVariationCondition::vfunc_6 @ 0x001ab270
extern "C" { extern char DAT_00494b44; extern char DAT_004c13d0; void* __cdecl FUN_00344e74(void*,int,void*,void*,int); }
struct Key_1ab270 { char bytes[1]; };
struct Variation { unsigned __int64 FUN_00044370(); };
struct Found_1ab270 { char pad[0x11c]; Variation* variation; };
struct Lookup_1ab270 { Found_1ab270* FUN_00059c10(int); };
struct Registry_1ab270 { Variation* FUN_000238b0(Key_1ab270*); };
struct Group_1ab270 { char pad[4]; Registry_1ab270* registry; };
struct World { char pad[0x20]; Group_1ab270* group; char pad2[0x20]; Lookup_1ab270* lookup; };
extern World* DAT_004dd700;
struct Character_1ab270 { char pad[4]; int kind; char pad2[0x4c]; Key_1ab270 key; int FUN_001c96e0(int); };
struct Event_1ab270 { Character_1ab270* FUN_001d03c0(); };
namespace hulkfight { namespace scenario {
struct Event_CharacterTemplateVariationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,void*,void*);
 char pad[8]; int selector; int mode; int unused; unsigned int expectedLow; unsigned int expectedHigh;
};
bool Event_CharacterTemplateVariationCondition::vfunc_6(void*,void* arg,void*) {
 Event_1ab270* e=(Event_1ab270*)FUN_00344e74(arg,0,&DAT_00494b44,&DAT_004c13d0,0);
 if(!e) return false;
 Character_1ab270* c=e->FUN_001d03c0();
 int id=c->FUN_001c96e0(selector);
 World* w=DAT_004dd700;
 if(!w) return false;
 Found_1ab270* f=w->lookup->FUN_00059c10(id);
 Variation* v;
 if(f) v=f->variation;
 else { if(c->kind<=0 || c->kind>3) return false; v=w->group->registry->FUN_000238b0(&c->key); if(!v) return false; }
 unsigned __int64 value=v->FUN_00044370();
 bool equal=(unsigned int)value==expectedLow && (unsigned int)(value>>32)==expectedHigh;
 if(mode==0) return equal;
 if(mode==1) return !equal;
 return false;
}
}}