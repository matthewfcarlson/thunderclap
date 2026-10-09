class SeqEventContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Init();
};
class SeqEventLogicOr : public SeqEventContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventLogicOr* v4(int);
};
extern void __cdecl FUN_00247550(void*, SeqEventLogicOr*);
extern char g_4e7458;
SeqEventLogicOr* SeqEventLogicOr::v4(int flags) {
    Init();
    if (flags & 1)
        FUN_00247550(&g_4e7458, this);
    return this;
}