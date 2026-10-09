extern void* prop_vftable;
class Elem {
  public:
    void Fn();
};
class PropMassCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual PropMassCondition* vfunc_5(char flag);
    virtual void v6();
    char pad[0x18 - sizeof(void*)];
    Elem elem;
    void BaseFn();
};
extern void Cleanup(PropMassCondition*);
PropMassCondition* PropMassCondition::vfunc_5(char flag) {
    *(void**)this = &prop_vftable;
    elem.Fn();
    BaseFn();
    if (flag & 1)
        Cleanup(this);
    return this;
}
