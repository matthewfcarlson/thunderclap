extern char VT[];
extern void* __cdecl alloc(unsigned int);
class TargetCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Create();
    int x;
    int y;
    int z;
    int w;
    TargetCondition(int);
};
void* TargetCondition::Create() {
    TargetCondition* p = (TargetCondition*)alloc(0x14);
    if (p) {
        p->TargetCondition::TargetCondition(0);
        *(void**)p = VT;
        p->z = 0;
        p->w = 0;
        return p;
    }
    return 0;
}