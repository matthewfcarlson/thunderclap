// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 18/18)
// hulkfight::scenario::Event_PathNameCondition::vfunc_6 @ 0x001ab400
extern char DAT_00494b44;
extern char DAT_004c13d0;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Name_1ab400 {
 unsigned first, second;
 void FUN_0027af00();
 void FUN_0027af50();
 void FUN_0027b0e0(void*);
 void FUN_0027af70(Name_1ab400*);
};
struct EventData_1ab400 { char pad[4]; int type; char pad2[12]; unsigned payload[2]; };
struct Event_1ab400 { EventData_1ab400* FUN_001d03c0(); };
namespace hulkfight { namespace scenario {
struct Event_PathNameCondition {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual bool vfunc_6(void*,void*,void*);
 char pad[8]; int operation; unsigned first,second;
};
bool Event_PathNameCondition::vfunc_6(void*, void* input, void*) {
 Event_1ab400* event = (Event_1ab400*)FUN_00344e74(input,0,&DAT_00494b44,&DAT_004c13d0,0);
 if (!event) return false;
 EventData_1ab400* data = event->FUN_001d03c0();
 Name_1ab400 name; name.FUN_0027af00();
 if(data->type == 17) {
 Name_1ab400 temp; temp.FUN_0027b0e0(data->payload); name.FUN_0027af70(&temp); temp.FUN_0027af50();
 } else if(data->type == 16) {
 Name_1ab400 temp; temp.FUN_0027b0e0(data->payload); name.FUN_0027af70(&temp); temp.FUN_0027af50();
 } else { name.FUN_0027af50(); return false; }
 bool result = false;
 if(operation==0) result = name.first == first && name.second == second;
 else if(operation==1) result = name.first != first || name.second != second;
 name.FUN_0027af50();
 return result;
}
}}
