extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
};
class Sub {
  public:
    Sub();
};
class Obj_1233a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern char VT_1233a0[];
class D {
  public:
    D* init(int a, Obj_1233a0* b);
};
D* D::init(int a, Obj_1233a0* b) {
    char* p = (char*)this;
    ((Base*)this)->Base::Base();
    *(void**)p = VT_1233a0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x54) = 0;
    *(int*)(p + 0x58) = 0;
    *(int*)(p + 0x60) = 0;
    *(int*)(p + 0x7c) = 0;
    *(int*)(p + 0x80) = 0;
    *(int*)(p + 0x84) = 0;
    *(int*)(p + 0x8c) = 0;
    *(int*)(p + 0x90) = 0;
    *(int*)(p + 0x94) = 0;
    _ReadWriteBarrier();
    *(int*)(p + 0x9c) = 0;
    ((Sub*)(p + 0xc0))->Sub::Sub();
    *(char*)(p + 0xc8) = 0;
    *(int*)(p + 0xcc) = 0;
    *(int*)(p + 0x7c) = a;
    if (b)
        b->AddRef();
    Obj_1233a0* old = *(Obj_1233a0**)(p + 0x80);
    if (old)
        old->Release();
    *(Obj_1233a0**)(p + 0x80) = b;
    return this;
}
