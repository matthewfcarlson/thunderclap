extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_1b120[];
class Ref_1b120 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1b120 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1b120 : public Base_1b120 {
  public:
    char pad_1c[0x18];
    Ref_1b120* m1c;
    char pad_24[0x4];
    Ref_1b120* m24;
    char pad_7c[0x54];
    Ref_1b120* m7c;
    ~Obj_1b120();
};
Obj_1b120::~Obj_1b120() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    vptr = gA_1b120;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
