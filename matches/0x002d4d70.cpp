class Obj_2d4d70 {
  public:
    virtual void Release();
    virtual void AddRef();
};
class pure3d_ParticleEmitter_2d4d70 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void vfunc_25(Obj_2d4d70*);
    char pad[0x84 - 4];
    Obj_2d4d70* member;
};
void pure3d_ParticleEmitter_2d4d70::vfunc_25(Obj_2d4d70* param) {
    if (param != member) {
        if (param)
            param->Release();
        if (member)
            member->AddRef();
        member = param;
    }
}