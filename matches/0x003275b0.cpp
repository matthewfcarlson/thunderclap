class pddiPrimBufferStream {
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
    virtual void v9(unsigned int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
};
class d3dPrimBufferStream : public pddiPrimBufferStream {
  public:
    char pad[0x34 - 4];
    unsigned int* member;
    void vfunc_9(unsigned int);
};
void d3dPrimBufferStream::vfunc_9(unsigned int param) {
    *member = param;
}