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
    virtual void v15();
    virtual void vfunc_16(int, int);
};
class CSPHulkPropInstance : public StateProp {
  public:
    char pad[0x3c];
    int field40;
    virtual void vfunc_16(int, int);
};
class Manager {
  public:
    void helper(CSPHulkPropInstance*, const char*, int, int);
};
struct Root {
    char pad[0x34];
    Manager* mgr;
};
extern Root* gManager;
void CSPHulkPropInstance::vfunc_16(int a, int b) {
    StateProp::vfunc_16(a, b);
    if (field40 == 0)
        gManager->mgr->helper(this, "State_0", 0x42480000, 0);
}