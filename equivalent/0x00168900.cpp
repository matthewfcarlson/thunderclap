// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// hulkfight::motion::GrappleHealthCondition::vfunc_6 @ 0x00168900
namespace hulkfight { namespace motion {
struct GrappleHealthCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(void*, void*, void*);
    char padding[8];
    int field_c;
    int field_10;
    int field_14;
};
}}
struct GrappleTarget;
GrappleTarget* __cdecl FUN_00048260(void*);
// equiv-conv: FUN_001687a0 ecx esi stack stack
void __cdecl FUN_001687a0(GrappleTarget*, int, int, int);
void hulkfight::motion::GrappleHealthCondition::vfunc_6(void* arg1, void* arg2, void* arg3) {
    GrappleTarget* target = FUN_00048260(arg2);
    FUN_001687a0(target, field_c, field_14, field_10);
}
