class Obj {
  public:
    virtual void a();
    virtual void b();
};
extern int vtable;
class pure3d_d3dToon2VertexShader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d_d3dToon2VertexShader* vfunc_3(unsigned char);
    char pad[0x7c];
    Obj* p80;
    Obj* p84;
    Obj* p88;
    void helper();
};
void thunk_FUN_00267090(pure3d_d3dToon2VertexShader*);
pure3d_d3dToon2VertexShader* pure3d_d3dToon2VertexShader::vfunc_3(unsigned char flag) {
    *(volatile int*)this = (int)&vtable;
    if (p88)
        p88->b();
    if (p80)
        p80->b();
    if (p84)
        p84->b();
    helper();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}