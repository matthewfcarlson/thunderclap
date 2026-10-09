class Ref {
  public:
    virtual void Init();
    virtual void Release();
};
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad[0x1c - 4];
    Ref* ref;
    virtual void v7();
    virtual void Changed();
    void Set(Ref*);
};
void Obj::Set(Ref* value) {
    if (ref != value) {
        if (ref)
            ref->Release();
        ref = value;
        value->Init();
        Changed();
    }
}