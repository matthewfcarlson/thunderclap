extern "C" char DAT_003f710c[];
extern "C" void* __cdecl Allocate(unsigned int);
struct Condition {
    void* vptr;
    unsigned char pad4[8];
    unsigned char enabled;
    unsigned char padD[3];
    int value;
    int last;
    void Initialize(int);
};
struct ConditionFactoryTemplate {
    void* vptr;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    Condition* vfunc_5();
};
Condition* ConditionFactoryTemplate::vfunc_5() {
    Condition* p = (Condition*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        p->vptr = (void*)((int)DAT_003f710c);
        p->enabled = 1;
        p->value = 0;
        p->last = -1;
        return p;
    }
    return 0;
}