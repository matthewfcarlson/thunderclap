extern "C" char DAT_00414170[];
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" void* __cdecl alloc(unsigned int);
class Temp {
  public:
    void Init(int);
};
class Tail {
  public:
    void Init();
};
void* Factory_vfunc5(Obj* self) {
    Obj* p = (Obj*)alloc(0x18);
    if (p) {
        ((Temp*)p)->Init(0);
        *(int*)p = ((int)DAT_00414170);
        *(int*)((char*)p + 0xc) = 0;
        ((Tail*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}