// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::CollisionThrowCondition::vfunc_6 @ 0x0014ec60
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct FightTarget {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
};
namespace hulkfight { namespace motion {
struct CollisionThrowCondition {
    char padding[12];
    unsigned char throwType;
    unsigned char vfunc_6(void*, FightTarget* target, void*);
};
unsigned char CollisionThrowCondition::vfunc_6(void*, FightTarget* target, void*) {
    if (!FUN_00344e74(target, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    char* object = (char*)target->vfunc_3();
    if (!object) return 0;
    return throwType == (unsigned char)object[0x34];
}
}}
