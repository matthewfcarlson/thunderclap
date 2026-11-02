class Buffer_27f6f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*);
};
class Conv {
  public:
    void Run(void*, void*);
};
struct Obj_27f6f0 {
    char p0[4];
    void* a;
    unsigned int index;
    char p1[4];
    Buffer_27f6f0* buffer;
    char p2[0x14];
};
extern "C" void __stdcall FUN_0027f6f0(void * self) {
    char local[12];
    if (((Obj_27f6f0 *)self)->index != 0xffff) {
        Conv* c = (Conv*)((char*)*((void**)((char*)((Obj_27f6f0 *)self)->a + 0x1c)) + (((Obj_27f6f0 *)self)->index << 6));
        c->Run((char*)((Obj_27f6f0 *)self) + 0x14, local);
        ((Obj_27f6f0 *)self)->buffer->f8(local);
    } else {
        ((Obj_27f6f0 *)self)->buffer->f8((char*)((Obj_27f6f0 *)self) + 0x14);
    }
}