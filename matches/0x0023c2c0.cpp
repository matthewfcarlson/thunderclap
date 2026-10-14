extern "C" char DAT_00428824[];
void __stdcall AllocRef(int);
void __fastcall InitSub(void* p);

class Ref_23c2c0 {
  public:
    virtual void f();
    char pad[0x24];
    Ref_23c2c0* init();
};

Ref_23c2c0* Ref_23c2c0::init() {
    AllocRef(4);
    *(int*)this = ((int)DAT_00428824);
    InitSub((char*)this + 0x28);
    return this;
}
