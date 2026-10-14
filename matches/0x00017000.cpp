class CCameraDramaticAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad[0x1C];
    char* mPtr;
};

class Sub_17000 {
  public:
    void Fn(void* arg);
};

class Obj_17000 {
  public:
    char pad[8];
    Sub_17000* sub;
};

extern Obj_17000* gObj_17000;

void CCameraDramaticAction::vfunc_4() {
    if (*(char*)(mPtr + 0x84) != 0) {
        gObj_17000->sub->Fn(gObj_17000);
    }
}
