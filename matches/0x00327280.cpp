class pddiPrimBuffer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class d3dPrimBuffer : public pddiPrimBuffer {
  public:
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void vfunc_12();
    virtual void v13();
    virtual void v14();
    char pad[0x36 - 4];
};
void d3dPrimBuffer::vfunc_12() {
    *((char*)this + 0x36) = 0;
}