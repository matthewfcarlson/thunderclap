extern "C" char DAT_00410c14[];
void* __cdecl alloc28(unsigned int);
struct Sub {
    int a;
    int b;
    void Init();
};
struct Base {
    void Init(int);
};
class ThreatAngleCondition {
  public:
    int vtable;
    char pad4[8];
    int c;
    int f;
    char pad14[4];
    Sub sub;
    char enabled;
    char pad21[7];
};
ThreatAngleCondition* factory_vfunc5() {
    ThreatAngleCondition* p = (ThreatAngleCondition*)alloc28(0x28);
    if (p) {
        ((Base*)p)->Init(0);
        p->vtable = ((int)DAT_00410c14);
        p->c = 0;
        p->f = 0x3fc90fdb;
        p->sub.Init();
        p->enabled = 1;
        return p;
    }
    return 0;
}
