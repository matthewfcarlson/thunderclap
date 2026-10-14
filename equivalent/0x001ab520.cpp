// STATUS: equivalent (tools/equiv.py level 3: 3056 inputs, branch coverage 26/26)
// hulkfight::scenario::Event_WaypointCondition::vfunc_6 @ 0x001ab520
struct State_1ab520 { char pad0[4]; int type; char pad8[0x4c]; int count17; char pad58[8]; int count16; };
struct Object { State_1ab520* FUN_001d03c0(); };
extern char DAT_00494b44;
extern char DAT_004c13d0;
extern "C" Object* __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace hulkfight { namespace scenario {
struct Event_WaypointCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,void*,void*);
 char pad4[8]; unsigned operation; int threshold;
};
bool Event_WaypointCondition::vfunc_6(void*, void* object, void*) {
 Object* found=FUN_00344e74(object,0,&DAT_00494b44,&DAT_004c13d0,0);
 if (!found) return false;
 State_1ab520* state=found->FUN_001d03c0();
 int value;
 if(state->type==16) value=state->count16;
 else if(state->type==17) value=state->count17;
 else return false;
 switch(operation) {
 case 0:return value<threshold;
 case 1:return value<=threshold;
 case 2:return value==threshold;
 case 3:return value!=threshold;
 case 4:return value>=threshold;
 case 5:return value>threshold;
 default:return false;
 }
}
}}
