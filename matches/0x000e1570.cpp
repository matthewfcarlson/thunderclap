class FEThing_e1570 {
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
    virtual void a12(void*);
};
class FEData {
  public:
    char pad[0x4c];
    FEThing_e1570* obj;
};
class FEPoseAnimation {
  public:
    char pad[0x0c];
    FEData* data;
    void vfunc_4(void*);
};
void FEPoseAnimation::vfunc_4(void* arg) {
    FEThing_e1570* p = data->obj;
    if (p)
        p->a12(arg);
}