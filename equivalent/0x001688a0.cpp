// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// hulkfight::motion::HealthCondition::vfunc_6 @ 0x001688a0
struct FightObject { void* FUN_000592a0(); }; 
struct Fighter { void* FUN_00059a30(); };
extern int DAT_00494b44;
extern int DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, int*, int*, int);
// equiv-conv: FUN_001687a0 ecx esi stack stack
extern int __cdecl FUN_001687a0(void*, void*, int, int);
namespace hulkfight { namespace motion {
struct HealthCondition {
    char pad[12];
    void* context;
    int first;
    int second;
    int vfunc_6(int, FightObject*, int);
};
int HealthCondition::vfunc_6(int unused, FightObject* object, int unused2) {
    if (!FUN_00344e74(object, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    Fighter* fighter = (Fighter*)object->FUN_000592a0();
    void* value = fighter->FUN_00059a30();
    return FUN_001687a0(value, context, second, first);
}
}}
