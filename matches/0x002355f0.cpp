extern void* pvtable;
extern void thunk_FUN_00267090(void*);
struct Sub {
    void Init();
};
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueEntity : public ParamValue {
  public:
    virtual ParamValueEntity* v0(unsigned int);
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
    char pad[4];
    Sub sub;
};
ParamValueEntity* ParamValueEntity::v0(unsigned int flags) {
    *(void**)this = &pvtable;
    sub.Init();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}