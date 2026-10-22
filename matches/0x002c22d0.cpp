extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c22d0[];
class Ref_2c22d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2c22d0 {
  public:
    void* vptr;
    void Fin();
};
class Texture_2c22d0 : public Entity_2c22d0 {
  public:
    char pad[12];
    Ref_2c22d0* m;
    ~Texture_2c22d0();
};
Texture_2c22d0::~Texture_2c22d0() {
    vptr = g_vftable_2c22d0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
