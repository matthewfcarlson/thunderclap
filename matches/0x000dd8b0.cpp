struct IDollyControllerState {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual float vfunc_7(int);
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
};
struct ControllerState : IDollyControllerState {
    char pad[8];
    float* values;
    float vfunc_7(int index);
};
float ControllerState::vfunc_7(int index) {
    int a = *(int*)(0x4a0d6c + index * 8);
    int b = *(int*)(0x4a0d70 + index * 8);
    return values[a] - values[b];
}