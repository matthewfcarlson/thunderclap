class Base {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int arg);
    char pad[0x60];
    int m64;
    void F(int arg);
};
void Base::F(int arg) {
    m64 = arg;
    arg = 0;
    V9(arg);
}
