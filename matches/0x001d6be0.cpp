class StateProp {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void vfunc_15();
};
class CSPHulkPropInstance : public StateProp {
  public:
    char pad[0xa0 - sizeof(StateProp)];
    void* member;
    void vfunc_15();
};
class Other_1d6be0 {
  public:
    void f();
};
void CSPHulkPropInstance::vfunc_15() {
    if (member)
        ((Other_1d6be0*)member)->f();
    else
        StateProp::vfunc_15();
}