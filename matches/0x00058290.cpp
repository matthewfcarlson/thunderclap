// Same code shape as 0x00057c10 (propagated; names are from that function)
typedef unsigned int u32_58290;
extern "C" void* __cdecl Alloc(unsigned int);
struct CCollisionPushbackYAngleCondition {
    u32_58290 vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init(int);
};
extern u32_58290 CCollisionPushbackYAngleCondition_vftable_58290;
class ConditionFactoryTemplate {
  public:
    void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    CCollisionPushbackYAngleCondition* p = (CCollisionPushbackYAngleCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (u32_58290)&CCollisionPushbackYAngleCondition_vftable_58290;
        p->fieldC = 5;
        p->field10 = 0;
        return p;
    }
    return 0;
}