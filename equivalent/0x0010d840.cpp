// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 22/22)
// hulkfight::ai::PropsToChuckCondition::vfunc_6 @ 0x0010d840
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Entity;
struct Part { void FUN_00059a30(); };
struct Entity { Part* FUN_000592a0(); };
struct Manager { void FUN_00066530(); int FUN_00065f60(); };
extern Manager* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct PropsToChuckCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Entity*, void*);
 char pad[8]; unsigned operation; int threshold;
};
bool PropsToChuckCondition::vfunc_6(void*, Entity* entity, void*) {
 if (!FUN_00344e74(entity,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 entity->FUN_000592a0()->FUN_00059a30();
 FUN_000678d0()->FUN_00066530();
 int count=FUN_000678d0()->FUN_00065f60();
 switch(operation) {
 case 0: return count < threshold;
 case 1: return count <= threshold;
 case 2: return count == threshold;
 case 3: return count != threshold;
 case 4: return count >= threshold;
 case 5: return count > threshold;
 default: return false;
 }
}
}}
