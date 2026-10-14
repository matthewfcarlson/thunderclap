extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_1d520[];
class Ref_1d520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1d520 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1d520 : public Base_1d520 {
  public:
    char pad_1c[0x18];
    Ref_1d520* m1c;
    char pad_24[0x4];
    Ref_1d520* m24;
    Ref_1d520* m28;
    ~Obj_1d520();
};
Obj_1d520::~Obj_1d520() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_1d520;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
