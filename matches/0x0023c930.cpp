class SubConditionGroupCondition;
struct Part {
    char pad[12];
    void Init();
};
class SubConditionGroupCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual SubConditionGroupCondition* vfunc_5(int);
    virtual void v6();
    void Finalize();
};
extern void __cdecl DestroySub(SubConditionGroupCondition*);
SubConditionGroupCondition* SubConditionGroupCondition::vfunc_5(int flags) {
    Part* p = (Part*)((char*)this + 12);
    *(unsigned int*)this = 0x4288fc;
    p->Init();
    Finalize();
    if (flags & 1)
        DestroySub(this);
    return this;
}