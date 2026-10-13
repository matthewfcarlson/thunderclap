// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::ai::HulkActionLargestCondition::vfunc_6 @ 0x0010f0f0
struct Key { unsigned first, second; void FUN_0027af00(); void FUN_0027b040(unsigned); };
extern Key DAT_004e0bc0, DAT_004e0bc8;
extern unsigned DAT_004e0bd0;
extern unsigned DAT_00494b44, DAT_00494b60;
void __cdecl FUN_00363e80(); void __cdecl FUN_00363e90();
extern "C" int __cdecl atexit(void (__cdecl *)());
void* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct State { int FUN_00059a30(); };
struct Actor { State* FUN_000592a0(); };
struct Manager { char pad[0x388]; unsigned first,second; void FUN_00067730(); float FUN_00067110(Key*); };
Manager* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct HulkActionLargestCondition { void* vptr; char pad[12]; unsigned parameter; bool vfunc_6(unsigned,Actor*,unsigned); };
bool HulkActionLargestCondition::vfunc_6(unsigned,Actor* actor,unsigned) {
 if (!(DAT_004e0bd0 & 1)) { DAT_004e0bd0 |= 1; DAT_004e0bc8.FUN_0027af00(); atexit(FUN_00363e90); }
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 if (!actor->FUN_000592a0()->FUN_00059a30()) return false;
 FUN_000678d0()->FUN_00067730();
 DAT_004e0bc8.FUN_0027b040(parameter);
 Key key = DAT_004e0bc8;
 FUN_000678d0()->FUN_00067110(&key);
 if (!(DAT_004e0bd0 & 2)) { DAT_004e0bd0 |= 2; DAT_004e0bc0.FUN_0027af00(); atexit(FUN_00363e80); }
 DAT_004e0bc0.FUN_0027b040(parameter);
 unsigned first=DAT_004e0bc0.first, second=DAT_004e0bc0.second;
 Manager* m=FUN_000678d0();
 return first==m->first && second==m->second;
}
} }
