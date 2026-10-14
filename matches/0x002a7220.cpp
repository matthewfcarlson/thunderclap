namespace pure3d {
class Particle {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
};
class ParticleController {
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
    virtual float v20();
    virtual void v21();
    virtual void v22();
    virtual void vfunc_23();
    char pad[0x20 - 4];
    int a20;
    int a24;
    float a28;
    int a2c;
    int a30;
    int a34;
    char a38;
    char pad2[7];
    char a40;
    char pad3[3];
    int a44;
    int a48;
    int a4c;
    Particle** begin;
    Particle** end;
};
void ParticleController::vfunc_23() {
    int x = a44;
    a20 = 0;
    a2c = 0;
    a34 = 0;
    a24 = (a40 != 1);
    a30 = x;
    a28 = v20();
    volatile char* flag = &a38;
    *flag = 1;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i]->f15();
    a4c = 0;
}
} // namespace pure3d