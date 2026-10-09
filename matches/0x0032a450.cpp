// Same code shape as 0x00333370 (propagated; names are from that function)
struct Data {
    int a, b, c, d, e;
};
class d3dShader {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void vfunc_21(Data*);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    char pad[0x4c];
    Data m;
};
void d3dShader::vfunc_21(Data* out) {
    *out = m;
}