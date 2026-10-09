class pddiObject {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class pddiPrimBuffer : public pddiObject {
  public:
    virtual void v6();
};
class d3dPrimBuffer : public pddiPrimBuffer {
  public:
    virtual void v3();
    virtual void v4();
    virtual void v5(void*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    char pad[0x34 - 4];
};
void d3dPrimBuffer::v5(void* p) {
    *(char*)((char*)this + 0x34) = 0;
    *(char*)((char*)p + 4) = 0;
}