extern void* __cdecl Allocate(int);
class FormationReadyCondition {
  public:
    void Init(int);
};
void* ConditionFactory_vfunc5() {
    FormationReadyCondition* p = (FormationReadyCondition*)Allocate(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = 0x40daa4;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}