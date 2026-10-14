class Inner_dddf0 {
  public:
    void Reset();
    bool Process(void*);
};
class Target_dddf0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    char pad[0x2230 - 4];
    Inner_dddf0* inner;
    char Run(void*);
};
char Target_dddf0::Run(void* arg) {
    inner->Reset();
    bool b = inner->Process(arg);
    if (b)
        V6();
    return b;
}