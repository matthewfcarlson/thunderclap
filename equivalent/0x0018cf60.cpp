// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 22/22)
// hulkfight::motion::VarCompareCondition::vfunc_6 @ 0x0018cf60
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Key_18cf60 { char data[8]; };
struct Values_18cf60 { int FUN_00036e40(Key_18cf60*); };
struct State_18cf60 { Values_18cf60* FUN_00059a30(); };
struct Params { State_18cf60* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct VarCompareCondition {
 char padding[16];
 Key_18cf60 key;
 unsigned comparison;
 int threshold;
 bool vfunc_6(void*, Params*, void*);
};
bool VarCompareCondition::vfunc_6(void*, Params* params, void*) {
 if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_18cf60* state = params->FUN_000592a0();
 Values_18cf60* values = state->FUN_00059a30();
 int value = values->FUN_00036e40(&key);
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return value == threshold;
 case 3: return value != threshold;
 case 4: return value >= threshold;
 case 5: return value > threshold;
 }
 return false;
}
}}
