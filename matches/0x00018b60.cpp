extern "C" void _ReadWriteBarrier();
extern void* gA_18b60[];
class Ref_18b60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_18b60 {
  public:
    void* vptr;
    void Fin();
};
class Obj_18b60 : public Base_18b60 {
  public:
    char pad[0x1c - 4];
    Ref_18b60* m1c;
    ~Obj_18b60();
};
Obj_18b60::~Obj_18b60() {
    vptr = gA_18b60;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
